#pragma once
#include <vector>

#include <type.h>

namespace despair {
class IRNode {
public:
    const std::vector<IRNode*> inputs;
    const std::vector<IRNode*> outputs;
    Type type;

    IRNode(std::vector<IRNode*> inputs, std::vector<IRNode*> outputs)
        : inputs(std::move(inputs)), outputs(std::move(outputs)), type(TypeBase()) {}

    virtual Type compute();
    virtual IRNode* peephole();
};
} // namespace despair
