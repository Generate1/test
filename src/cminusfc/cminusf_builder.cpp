#include "cminusf_builder.hpp"

#define CONST_FP(num) ConstantFP::get((float)num, module.get())
#define CONST_INT(num) ConstantInt::get(num, module.get())

// types
Type *VOID_T;
Type *INT1_T;
Type *INT32_T;
Type *INT32PTR_T;
Type *FLOAT_T;
Type *FLOATPTR_T;

Value* CminusfBuilder::visit(ASTProgram &node) {
    VOID_T = module->get_void_type();
    INT1_T = module->get_int1_type();
    INT32_T = module->get_int32_type();
    INT32PTR_T = module->get_int32_ptr_type();
    FLOAT_T = module->get_float_type();
    FLOATPTR_T = module->get_float_ptr_type();

    Value *ret_val = nullptr;
    for (auto &decl : node.declarations) {
        ret_val = decl->accept(*this);
    }
    return ret_val;
}

Value* CminusfBuilder::visit(ASTNum &node) {
    if (node.type == TYPE_INT)
        return CONST_INT(node.i_val);
    else
        return CONST_FP(node.f_val);
}

Value* CminusfBuilder::visit(ASTVarDeclaration &node) {
    Type *type = nullptr;
    if (node.type == TYPE_INT)
        type = INT32_T;
    else if (node.type == TYPE_FLOAT)
        type = FLOAT_T;
    else
        type = VOID_T;

    if (node.num == nullptr) {
        // Scalar variable
        if (scope.in_global()) {
            auto initializer = ConstantZero::get(type, module.get());
            auto var = GlobalVariable::create(node.id, module.get(), type, false, initializer);
            scope.push(node.id, var);
        } else {
            auto var = builder->create_alloca(type);
            // Move alloca to the entry block start
            auto entryBB = context.func->get_entry_block();
            // 【关键修复1】使用 remove 确保移除的是 var 指令本身，防止链表损坏
            if (var->get_parent() != entryBB) {
                var->get_parent()->get_instructions().remove(static_cast<Instruction*>(var));
                entryBB->get_instructions().push_front(static_cast<Instruction*>(var));
                static_cast<Instruction*>(var)->set_parent(entryBB);
            }
            scope.push(node.id, var);
        }
    } else {
        // Array variable
        auto *array_type = ArrayType::get(type, node.num->i_val);
        if (scope.in_global()) {
            auto initializer = ConstantZero::get(array_type, module.get());
            auto var = GlobalVariable::create(node.id, module.get(), array_type, false, initializer);
            scope.push(node.id, var);
        } else {
            auto var = builder->create_alloca(array_type);
            // Move alloca to the entry block start
            auto entryBB = context.func->get_entry_block();
            // 【关键修复1】同上
            if (var->get_parent() != entryBB) {
                var->get_parent()->get_instructions().remove(static_cast<Instruction*>(var));
                entryBB->get_instructions().push_front(static_cast<Instruction*>(var));
                static_cast<Instruction*>(var)->set_parent(entryBB);
            }
            scope.push(node.id, var);
        }
    }
    return nullptr;
}

Value* CminusfBuilder::visit(ASTFunDeclaration &node) {
    FunctionType *fun_type;
    Type *ret_type;
    std::vector<Type *> param_types;
    if (node.type == TYPE_INT)
        ret_type = INT32_T;
    else if (node.type == TYPE_FLOAT)
        ret_type = FLOAT_T;
    else
        ret_type = VOID_T;

    for (auto &param : node.params) {
        Type *param_type;
        if (param->type == TYPE_INT)
            param_type = INT32_T;
        else if (param->type == TYPE_FLOAT)
            param_type = FLOAT_T;
        else
            param_type = VOID_T;

        if (param->isarray)
            param_type = PointerType::get(param_type);
        
        param_types.push_back(param_type);
    }

    fun_type = FunctionType::get(ret_type, param_types);
    auto func = Function::create(fun_type, node.id, module.get());
    scope.push(node.id, func);
    context.func = func;
    auto funBB = BasicBlock::create(module.get(), "entry", func);
    builder->set_insert_point(funBB);
    scope.enter();
    std::vector<Value *> args;
    for (auto &arg : func->get_args()) {
        args.push_back(&arg);
    }
    for (unsigned int i = 0; i < node.params.size(); ++i) {
        auto param = node.params[i];
        auto arg = args[i];
        auto arg_alloca = builder->create_alloca(arg->get_type());
        builder->create_store(arg, arg_alloca);
        scope.push(param->id, arg_alloca);
    }
    node.compound_stmt->accept(*this);
    if (!builder->get_insert_block()->is_terminated()) 
    {
        if (context.func->get_return_type()->is_void_type())
            builder->create_void_ret();
        else if (context.func->get_return_type()->is_float_type())
            builder->create_ret(CONST_FP(0.));
        else
            builder->create_ret(CONST_INT(0));
    }
    scope.exit();
    return nullptr;
}

Value* CminusfBuilder::visit(ASTParam &node) {
    return nullptr;
}

Value* CminusfBuilder::visit(ASTCompoundStmt &node) {
    scope.enter();
    for (auto &decl : node.local_declarations) {
        decl->accept(*this);
    }

    for (auto &stmt : node.statement_list) {
        stmt->accept(*this);
        if (builder->get_insert_block()->is_terminated())
            break;
    }
    scope.exit();
    return nullptr;
}

Value* CminusfBuilder::visit(ASTExpressionStmt &node) {
    if (node.expression != nullptr)
        node.expression->accept(*this);
    return nullptr;
}

Value* CminusfBuilder::visit(ASTSelectionStmt &node) {
    auto cond = node.expression->accept(*this);
    if (cond->get_type()->is_pointer_type())
        cond = builder->create_load(cond);
    
    if (cond->get_type()->is_integer_type())
        cond = builder->create_icmp_ne(cond, CONST_INT(0));
    else if (cond->get_type()->is_float_type())
        cond = builder->create_fcmp_ne(cond, CONST_FP(0.0));

    auto trueBB = BasicBlock::create(module.get(), "trueBB", context.func);
    // 只有在需要的时候才创建 falseBB，避免空块干扰
    BasicBlock *falseBB = nullptr; 
    auto nextBB = BasicBlock::create(module.get(), "nextBB", context.func);

    if (node.else_statement != nullptr) {
        falseBB = BasicBlock::create(module.get(), "falseBB", context.func);
        builder->create_cond_br(cond, trueBB, falseBB);
    } else {
        builder->create_cond_br(cond, trueBB, nextBB);
    }

    // True Branch
    builder->set_insert_point(trueBB);
    node.if_statement->accept(*this);
    if (!builder->get_insert_block()->is_terminated())
        builder->create_br(nextBB);

    // False Branch
    if (node.else_statement != nullptr) {
        builder->set_insert_point(falseBB);
        node.else_statement->accept(*this);
        if (!builder->get_insert_block()->is_terminated())
            builder->create_br(nextBB);
    }

    builder->set_insert_point(nextBB);
    return nullptr;
}

Value* CminusfBuilder::visit(ASTIterationStmt &node) {
    auto condBB = BasicBlock::create(module.get(), "condBB", context.func);
    auto bodyBB = BasicBlock::create(module.get(), "bodyBB", context.func);
    auto endBB = BasicBlock::create(module.get(), "endBB", context.func);

    if (!builder->get_insert_block()->is_terminated())
        builder->create_br(condBB);

    builder->set_insert_point(condBB);
    auto cond = node.expression->accept(*this);
    if (cond->get_type()->is_pointer_type())
        cond = builder->create_load(cond);

    if (cond->get_type()->is_integer_type())
        cond = builder->create_icmp_ne(cond, CONST_INT(0));
    else if (cond->get_type()->is_float_type())
        cond = builder->create_fcmp_ne(cond, CONST_FP(0.0));
    
    builder->create_cond_br(cond, bodyBB, endBB);

    builder->set_insert_point(bodyBB);
    node.statement->accept(*this);
    if (!builder->get_insert_block()->is_terminated())
        builder->create_br(condBB);

    builder->set_insert_point(endBB);
    return nullptr;
}

Value* CminusfBuilder::visit(ASTReturnStmt &node) {
    if (node.expression == nullptr) {
        builder->create_void_ret();
    } else {
        auto val = node.expression->accept(*this);
        if (val->get_type()->is_pointer_type())
            val = builder->create_load(val);

        auto ret_type = context.func->get_return_type();
        if (ret_type->is_integer_type() && val->get_type()->is_float_type())
            val = builder->create_fptosi(val, INT32_T);
        else if (ret_type->is_float_type() && val->get_type()->is_integer_type())
            val = builder->create_sitofp(val, FLOAT_T);
        
        builder->create_ret(val);
    }
    return nullptr;
}

Value* CminusfBuilder::visit(ASTVar &node) {
    auto var = scope.find(node.id);
    if (node.expression != nullptr) {
        auto idx = node.expression->accept(*this);
        if (idx->get_type()->is_pointer_type())
            idx = builder->create_load(idx);
        
        if (idx->get_type()->is_float_type())
            idx = builder->create_fptosi(idx, INT32_T);

        auto cmp = builder->create_icmp_lt(idx, CONST_INT(0));
        
        // 【关键修复2】使用空字符串，让 IR 生成器自动创建唯一标签，避免重复定义 label_failBB
        auto failBB = BasicBlock::create(module.get(), "", context.func);
        auto passBB = BasicBlock::create(module.get(), "", context.func);
        
        builder->create_cond_br(cmp, failBB, passBB);

        builder->set_insert_point(failBB);
        builder->create_call(static_cast<Function*>(scope.find("neg_idx_except")), {});
        builder->create_br(passBB);

        builder->set_insert_point(passBB);
        
        if (var->get_type()->get_pointer_element_type()->is_array_type()) {
            var = builder->create_gep(var, {CONST_INT(0), idx});
        } else {
            var = builder->create_load(var);
            var = builder->create_gep(var, {idx});
        }
    }
    return var;
}

Value* CminusfBuilder::visit(ASTAssignExpression &node) {
    auto lhs = node.var->accept(*this);
    auto rhs = node.expression->accept(*this);
    
    if (rhs->get_type()->is_pointer_type())
        rhs = builder->create_load(rhs);

    auto lhs_type = lhs->get_type()->get_pointer_element_type();
    if (lhs_type->is_integer_type() && rhs->get_type()->is_float_type())
        rhs = builder->create_fptosi(rhs, INT32_T);
    else if (lhs_type->is_float_type() && rhs->get_type()->is_integer_type())
        rhs = builder->create_sitofp(rhs, FLOAT_T);

    builder->create_store(rhs, lhs);
    return rhs;
}

Value* CminusfBuilder::visit(ASTSimpleExpression &node) {
    auto lhs = node.additive_expression_l->accept(*this);
    if (node.additive_expression_r == nullptr)
        return lhs;
    
    auto rhs = node.additive_expression_r->accept(*this);
    if (lhs->get_type()->is_pointer_type()) lhs = builder->create_load(lhs);
    if (rhs->get_type()->is_pointer_type()) rhs = builder->create_load(rhs);

    bool is_float = lhs->get_type()->is_float_type() || rhs->get_type()->is_float_type();
    Value *cmp;

    if (is_float) {
        if (lhs->get_type()->is_integer_type()) lhs = builder->create_sitofp(lhs, FLOAT_T);
        if (rhs->get_type()->is_integer_type()) rhs = builder->create_sitofp(rhs, FLOAT_T);
        
        switch (node.op) {
            case OP_LE: cmp = builder->create_fcmp_le(lhs, rhs); break;
            case OP_LT: cmp = builder->create_fcmp_lt(lhs, rhs); break;
            case OP_GT: cmp = builder->create_fcmp_gt(lhs, rhs); break;
            case OP_GE: cmp = builder->create_fcmp_ge(lhs, rhs); break;
            case OP_EQ: cmp = builder->create_fcmp_eq(lhs, rhs); break;
            case OP_NEQ: cmp = builder->create_fcmp_ne(lhs, rhs); break;
            default: return nullptr;
        }
    } else {
        switch (node.op) {
            case OP_LE: cmp = builder->create_icmp_le(lhs, rhs); break;
            case OP_LT: cmp = builder->create_icmp_lt(lhs, rhs); break;
            case OP_GT: cmp = builder->create_icmp_gt(lhs, rhs); break;
            case OP_GE: cmp = builder->create_icmp_ge(lhs, rhs); break;
            case OP_EQ: cmp = builder->create_icmp_eq(lhs, rhs); break;
            case OP_NEQ: cmp = builder->create_icmp_ne(lhs, rhs); break;
            default: return nullptr;
        }
    }
    return builder->create_zext(cmp, INT32_T);
}

Value* CminusfBuilder::visit(ASTAdditiveExpression &node) {
    if (node.additive_expression == nullptr) {
        return node.term->accept(*this);
    }
    auto lhs = node.additive_expression->accept(*this);
    auto rhs = node.term->accept(*this);
    
    if (lhs->get_type()->is_pointer_type()) lhs = builder->create_load(lhs);
    if (rhs->get_type()->is_pointer_type()) rhs = builder->create_load(rhs);

    bool is_float = lhs->get_type()->is_float_type() || rhs->get_type()->is_float_type();

    if (is_float) {
        if (lhs->get_type()->is_integer_type()) lhs = builder->create_sitofp(lhs, FLOAT_T);
        if (rhs->get_type()->is_integer_type()) rhs = builder->create_sitofp(rhs, FLOAT_T);
        if (node.op == OP_PLUS) return builder->create_fadd(lhs, rhs);
        else return builder->create_fsub(lhs, rhs);
    } else {
        if (node.op == OP_PLUS) return builder->create_iadd(lhs, rhs);
        else return builder->create_isub(lhs, rhs);
    }
}

Value* CminusfBuilder::visit(ASTTerm &node) {
    if (node.term == nullptr) {
        return node.factor->accept(*this);
    }
    auto lhs = node.term->accept(*this);
    auto rhs = node.factor->accept(*this);
    
    if (lhs->get_type()->is_pointer_type()) lhs = builder->create_load(lhs);
    if (rhs->get_type()->is_pointer_type()) rhs = builder->create_load(rhs);

    bool is_float = lhs->get_type()->is_float_type() || rhs->get_type()->is_float_type();

    if (is_float) {
        if (lhs->get_type()->is_integer_type()) lhs = builder->create_sitofp(lhs, FLOAT_T);
        if (rhs->get_type()->is_integer_type()) rhs = builder->create_sitofp(rhs, FLOAT_T);
        if (node.op == OP_MUL) return builder->create_fmul(lhs, rhs);
        else return builder->create_fdiv(lhs, rhs);
    } else {
        if (node.op == OP_MUL) return builder->create_imul(lhs, rhs);
        else return builder->create_isdiv(lhs, rhs);
    }
}

Value* CminusfBuilder::visit(ASTCall &node) {
    auto func = static_cast<Function *>(scope.find(node.id));
    std::vector<Value *> args;
    auto func_type = func->get_function_type();

    for (size_t i = 0; i < node.args.size(); ++i) {
        auto arg = node.args[i]->accept(*this);
        auto target_type = func_type->get_param_type(i);

        // Handle array decay: [N x T]* -> T*
        if (arg->get_type()->is_pointer_type() && 
            arg->get_type()->get_pointer_element_type()->is_array_type()) {
            arg = builder->create_gep(arg, {CONST_INT(0), CONST_INT(0)});
        }
        // Handle pointer-to-pointer (array param variable): T** -> T*
        else if (arg->get_type()->is_pointer_type() && 
                 arg->get_type()->get_pointer_element_type()->is_pointer_type() &&
                 target_type->is_pointer_type()) {
            arg = builder->create_load(arg);
        }
        
        // Load scalar values if needed
        if (arg->get_type()->is_pointer_type() && !target_type->is_pointer_type()) {
            arg = builder->create_load(arg);
        }

        // Type conversion
        if (target_type->is_integer_type() && arg->get_type()->is_float_type())
            arg = builder->create_fptosi(arg, INT32_T);
        else if (target_type->is_float_type() && arg->get_type()->is_integer_type())
            arg = builder->create_sitofp(arg, FLOAT_T);

        args.push_back(arg);
    }
    return builder->create_call(func, args);
}