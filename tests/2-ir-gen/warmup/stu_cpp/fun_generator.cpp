
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

    // --- 定义 callee 函数 ---
    std::vector<Type *> calleeArgs(1, Int32Type);
    auto calleeFunType = FunctionType::get(Int32Type, calleeArgs);
    auto calleeFun = Function::create(calleeFunType, "callee", module);
    
    auto entryBB = BasicBlock::create(module, "entry", calleeFun);
    builder->set_insert_point(entryBB);
    
    // 获取参数 a
    std::vector<Value *> args;
    for (auto &arg : calleeFun->get_args()) {
        args.push_back(&arg);
    }
    // (可选) 将参数存入栈中，这是未优化的标准做法，但如果直接用寄存器也可以
    // 这里为了符合实验通常要求，进行 load/store
    auto aAlloca = builder->create_alloca(Int32Type);
    builder->create_store(args[0], aAlloca);
    
    // return 2 * a
    auto aLoad = builder->create_load(aAlloca);
    auto mul = builder->create_imul(CONST_INT(2), aLoad);
    builder->create_ret(mul);

    // --- 定义 main 函数 ---
    auto mainFun = Function::create(FunctionType::get(Int32Type, {}), "main", module);
    auto mainBB = BasicBlock::create(module, "entry", mainFun);
    builder->set_insert_point(mainBB);

    // return callee(110)
    auto call = builder->create_call(calleeFun, {CONST_INT(110)});
    builder->create_ret(call);

    std::cout << module->print();
    delete module;
    return 0;
}