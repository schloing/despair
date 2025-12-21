#pragma once
#include <node.h>

namespace despair {
class Constant : public IRNode {
public:
    const Type* value;

    Constant(IRNode* start, const Type* value)
        : IRNode({start}), value(value) {}

    // FIXME: peephole shouldn't end here
    IRNode* peephole() override
    {
        return nullptr;
    }
};
} // namespace despair
