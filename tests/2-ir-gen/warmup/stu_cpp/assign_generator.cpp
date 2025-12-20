
#include "BasicBlock.hpp"
#include "Constant.hpp"
#include "Function.hpp"
#include "IRBuilder.hpp"
#include "Module.hpp"
#include "Type.hpp"
#include <iostream>
#include <vector>

#define CONST_INT(num) ConstantInt::get(num, module)

int main() {
    auto module = new Module();
    auto builder = new IRBuilder(nullptr, module);
    Type *Int32Type = module->get_int32_type();

    // main 函数
    auto mainFun = Function::create(FunctionType::get(Int32Type, {}), "main", module);
    auto bb = BasicBlock::create(module, "entry", mainFun);
    builder->set_insert_point(bb);

    // int a[10]; -> 在栈上分配 [10 x i32]
    auto *arrayType = ArrayType::get(Int32Type, 10);
    auto aAlloca = builder->create_alloca(arrayType);

    // a[0] = 10;
    // GEP: base为 aAlloca, 索引为 {0, 0}
    auto a0GEP = builder->create_gep(aAlloca, {CONST_INT(0), CONST_INT(0)});
    builder->create_store(CONST_INT(10), a0GEP);

    // a[1] = a[0] * 2;
    // 读取 a[0]
    auto a0Load = builder->create_load(a0GEP);
    // 计算 * 2
    auto mul = builder->create_imul(a0Load, CONST_INT(2));
    // 获取 a[1] 地址
    auto a1GEP = builder->create_gep(aAlloca, {CONST_INT(0), CONST_INT(1)});
    // 存入 a[1]
    builder->create_store(mul, a1GEP);

    // return a[1];
    auto a1Load = builder->create_load(a1GEP);
    builder->create_ret(a1Load);

    std::cout << module->print();
    delete module;
    return 0;
}