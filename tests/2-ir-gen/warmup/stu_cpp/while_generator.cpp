
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
    auto entryBB = BasicBlock::create(module, "entry", mainFun);
    builder->set_insert_point(entryBB);

    // 分配局部变量
    auto aAlloca = builder->create_alloca(Int32Type);
    auto iAlloca = builder->create_alloca(Int32Type);

    // a = 10; i = 0;
    builder->create_store(CONST_INT(10), aAlloca);
    builder->create_store(CONST_INT(0), iAlloca);

    // 循环条件块
    auto condBB = BasicBlock::create(module, "while_cond", mainFun);
    auto bodyBB = BasicBlock::create(module, "while_body", mainFun);
    auto endBB = BasicBlock::create(module, "while_end", mainFun);

    // 从 entry 跳转到 condition
    builder->create_br(condBB);

    // --- Condition Block ---
    builder->set_insert_point(condBB);
    auto iLoad = builder->create_load(iAlloca);
    // i < 10 (signed less than)
    auto icmp = builder->create_icmp_lt(iLoad, CONST_INT(10)); 
    builder->create_cond_br(icmp, bodyBB, endBB);

    // --- Body Block ---
    builder->set_insert_point(bodyBB);
    
    // i = i + 1;
    auto iVal = builder->create_load(iAlloca);
    auto iNext = builder->create_iadd(iVal, CONST_INT(1));
    builder->create_store(iNext, iAlloca);

    // a = a + i; (注意：C语义是顺序执行，此时 i 已经是 i+1 后的值)
    auto aVal = builder->create_load(aAlloca);
    // 再次读取 i (或者直接使用 iNext，但为了模拟非优化IR，通常重新load)
    auto iValNew = builder->create_load(iAlloca); 
    auto aNext = builder->create_iadd(aVal, iValNew);
    builder->create_store(aNext, aAlloca);

    // 跳转回判断条件
    builder->create_br(condBB);

    // --- End Block ---
    builder->set_insert_point(endBB);
    auto result = builder->create_load(aAlloca);
    builder->create_ret(result);

    std::cout << module->print();
    delete module;
    return 0;
}