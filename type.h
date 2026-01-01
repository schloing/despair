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

    static bool is_class_of(const Type* val)
    {
        return val->get_kind() == Type::Kind::INT;
    }
};
} // namespace despair
