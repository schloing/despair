#pragma once
#include <node.h>

namespace despair {
class Constant : public IRNode {
public:
    const Type value;

    Constant(IRNode* start, Type value)
        : IRNode({start}, {}), value(value) {}
};
} // namespace despair
