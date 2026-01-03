#pragma once
#include <node.h>
#include <optional>
#include <tuple>
#include <rtti.h>

namespace despair {
class ArithmeticBinaryExpr : public IRNode {
public:
    IRNode* a;
    IRNode* b;

    ArithmeticBinaryExpr(IRNode* a, IRNode* b, Kind kind)
        : IRNode({a, b}, kind), a(a), b(b) {}
protected:
    template <typename T>
    std::optional<std::tuple<T*, T*>> get_inputs_of_type() const
    {
        if (auto ai = despair::dyn_cast<T>(a->type),
                 bi = despair::dyn_cast<T>(b->type); ai && bi) {
            return std::make_tuple(ai, bi);
        }

        return std::nullopt;
    }

    template <typename T, typename Op>
    Type* compute_binary(Op op)
    {
        if (auto inputs = get_inputs_of_type<T>()) {
            auto& [ai, bi] = *inputs;
            if (a->type->is_const() && b->type->is_const()) {
                return new T(op(ai->value, bi->value));
            }
        }

        return new Type();
    }
};

class Add : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Add(IRNode* a, IRNode* b)
        : ArithmeticBinaryExpr(a, b, IRNode::Kind::ADD) {};

    Type* compute() override {
        return compute_binary<TypeInteger>([](int x, int y){ return x + y; });
    }

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::ADD;
    }
};

class Subtract : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Subtract(IRNode* a, IRNode* b)
        : ArithmeticBinaryExpr(a, b, IRNode::Kind::SUBTRACT) {};

    Type* compute() override {
        return compute_binary<TypeInteger>([](int x, int y){ return x - y; });
    }

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::SUBTRACT;
    }
};

class Multiply : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Multiply(IRNode* a, IRNode* b)
        : ArithmeticBinaryExpr(a, b, IRNode::Kind::MULTIPLY) {};

    Type* compute() override {
        return compute_binary<TypeInteger>([](int x, int y){ return x * y; });
    }

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::MULTIPLY;
    }
};

class Divide : public ArithmeticBinaryExpr {
public:
    using ArithmeticBinaryExpr::ArithmeticBinaryExpr;

    Divide(IRNode* a, IRNode* b)
        : ArithmeticBinaryExpr(a, b, IRNode::Kind::DIVIDE) {};

    Type* compute() override {
        return compute_binary<TypeInteger>([](int x, int y){ return x / y; });
    }

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::DIVIDE;
    }
};

class Negate : public IRNode {
public:
    IRNode* a;

    Negate(IRNode* a) : IRNode({a}, NEGATE) {}

    Type* compute() override {
        if (auto ai = despair::dyn_cast<TypeInteger>(a->type)) {
            // TODO: add alternative
            if (a->type->is_const()) {
                return new TypeInteger(-ai->value);
            }
        }

        return new Type();
    }

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::NEGATE;
    }
};
} // namespace despair
