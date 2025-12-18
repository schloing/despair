#pragma once
#include <variant>

namespace despair {
// FIXME: don't know how to implement lattice

enum TypeLattice {
    TBOT, // bottom (ALL)
    TTOP, // top (ANY)
    TINT,
};

class TypeBase {
public:
    enum TypeLattice type = TTOP;

    TypeBase() = default;
    TypeBase(enum TypeLattice type) : type(type) {};

    virtual bool isConstant();
};

class TypeInteger : public TypeBase {
public:
    long value;

    TypeInteger(long value) : value(value) {}
};

using Type = std::variant<TypeBase, TypeInteger>;
} // namespace despair
