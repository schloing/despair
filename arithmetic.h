#pragma once
#include <node.h>

namespace despair {
class ArithmeticBinaryExpr : public IRNode {
public:
    IRNode* a;
    IRNode* b;

    ArithmeticBinaryExpr(IRNode* a, IRNode* b)
        : IRNode({a, b}), a(a), b(a) {}
};

// FIXME: too repetitive, bring common functionality into a wrapper in ArithmeticBinaryExpr or sum shi
class Add : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Type* compute() override {
        if (auto ai = dyn_cast<TypeInteger>(a->type);
            auto bi = dyn_cast<TypeInteger>(b->type)) {
            // TODO: add alternative
            if (a->type->is_const() && b->type->is_const()) {
                return new TypeInteger(ai->value + bi->value);
            }
        }

        return new Type();
    }
};

class Subtract : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Type* compute() override {
        if (auto ai = dyn_cast<TypeInteger>(a->type);
            auto bi = dyn_cast<TypeInteger>(b->type)) {
            // TODO: add alternative
            if (a->type->is_const() && b->type->is_const()) {
                return new TypeInteger(ai->value - bi->value);
            }
        }

        return new Type();
    }
};

class Multiply : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Type* compute() override {
        if (auto ai = dyn_cast<TypeInteger>(a->type);
            auto bi = dyn_cast<TypeInteger>(b->type)) {
            // TODO: add alternative
            if (a->type->is_const() && b->type->is_const()) {
                return new TypeInteger(ai->value * bi->value);
            }
        }

        return new Type();
    }
};

class Divide : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Type* compute() override {
        if (auto ai = dyn_cast<TypeInteger>(a->type);
            auto bi = dyn_cast<TypeInteger>(b->type)) {
            // TODO: add alternative
            if (a->type->is_const() && b->type->is_const()) {
                return new TypeInteger(ai->value / bi->value);
            }
        }

        return new Type();
    }
};

class Negate : public IRNode {
public:
    IRNode* a;

    Negate(IRNode* a) : IRNode({a}) {}

    Type* compute() override {
        if (auto ai = dyn_cast<TypeInteger>(a->type)) {
            // TODO: add alternative
            if (a->type->is_const()) {
                return new TypeInteger(-ai->value);
            }
        }

        return new Type();
    }
};
} // namespace despair
