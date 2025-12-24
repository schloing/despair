#pragma once
#include <memory>

namespace despair {
class Type {
public:
    enum Kind {
        BOT,
        TOP,
        INT,
        COUNT,
    };
private:
    const Kind kind;
    // TODO: make this less fragile
    // reordering Type::Kind would require fixing the order here
    static constexpr std::string_view str_types[Kind::COUNT] = { "BOT", "TOP", "INT" };
public:
    Type() : kind(Kind::BOT) {}
    explicit Type(Kind kind) : kind(kind) {}

    Kind get_kind() const
    {
        return kind;
    }

    bool is_const() const
    {
        return get_kind() == Kind::TOP;
    }

    static constexpr std::string_view label(Kind kind)
    {
        return str_types[static_cast<size_t>(kind)];
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
