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

        return new Type(Type::Kind::BOT);
    }
};
} // namespace despair
