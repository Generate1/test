
#include "BasicBlock.hpp"
#include "Constant.hpp"
#include "Function.hpp"
#include "IRBuilder.hpp"
#include "Module.hpp"
#include "Type.hpp"
#include <iostream>
#include <vector>

#define CONST_INT(num) ConstantInt::get(num, module)
#define CONST_FP(num) ConstantFP::get(num, module)

int main() {
    auto module = new Module();
    auto builder = new IRBuilder(nullptr, module);
    Type *Int32Type = module->get_int32_type();
    Type *FloatType = module->get_float_type();

    // main 函数
    auto mainFun = Function::create(FunctionType::get(Int32Type, {}), "main", module);
    auto bb = BasicBlock::create(module, "entry", mainFun);
    builder->set_insert_point(bb);

    // float a = 5.555;
    auto aAlloca = builder->create_alloca(FloatType);
    builder->create_store(CONST_FP(5.555), aAlloca);

    // if (a > 1)
    auto aLoad = builder->create_load(aAlloca);
    // 浮点比较: fcmp ogt (ordered greater than)
    // 注意：C语言中 1 会隐式转换为 1.0
    auto fcmp = builder->create_fcmp_gt(aLoad, CONST_FP(1.0));

    auto trueBB = BasicBlock::create(module, "trueBB", mainFun);
    auto falseBB = BasicBlock::create(module, "falseBB", mainFun);

    builder->create_cond_br(fcmp, trueBB, falseBB);

    // True 分支
    builder->set_insert_point(trueBB);
    builder->create_ret(CONST_INT(233));

    // False 分支 (对应 if 之后的代码)
    builder->set_insert_point(falseBB);
    builder->create_ret(CONST_INT(0));

    std::cout << module->print();
    delete module;
    return 0;
}