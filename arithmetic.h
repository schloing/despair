#pragma once
#include <node.h>

namespace despair {
class ArithmeticBinaryExpr : public IRNode {
public:
    const IRNode* a;
    const IRNode* b;

    ArithmeticBinaryExpr(IRNode* a, IRNode* b)
        : IRNode({a, b}, {}), a(a), b(a) {}

};

class Multiply : public ArithmeticBinaryExpr {
public:
    Type compute() override {
        if (auto* ai = std::get_if<TypeInteger>(&a->type);
            auto* bi = std::get_if<TypeInteger>(&b->type)) {
            return TypeInteger(ai->value * bi->value);
        }

        return TypeBase(TypeLattice::TBOT);
    }
};
} // namespace despair
