#pragma once
#include <memory>

namespace despair {
// FIXME: don't know how to implement lattice

class Type {
public:
    enum Kind {
        BOT,
        TOP,
        INT,
    };
private:
    const Kind kind;
public:
    Type() : kind(Kind::BOT) {}
    explicit Type(Kind kind) : kind(kind) {}

    Kind get_kind() const
    {
        return kind;
    }

    bool is_const() const
    {
        return this->get_kind() == Kind::TOP;
    }

    virtual ~Type() = default;
};

class TypeInteger : public Type {
public:
    long value;

    TypeInteger(long value)
        : Type(Type::Kind::INT), value(value) {}

    static bool is_class_of(Type* val)
    {
        return val->get_kind() == Type::Kind::INT;
    }
};

template <typename To, typename From>
bool is_instance_of(From* Val) {
    return To::is_class_of(Val);
}

template <typename To, typename From>
To* dyn_cast(From* Val) {
    return is_instance_of<To>(Val) ? static_cast<To*>(Val) : nullptr;
}
} // namespace despair
