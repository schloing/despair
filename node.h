#pragma once
#include <vector>

#include <type.h>

namespace despair {
class IRNode {
private:
    std::vector<IRNode*> inputs;
    std::vector<IRNode*> outputs;
public:
    IRNode(std::vector<IRNode*> inputs)
        : inputs(inputs), outputs({}) {};

    Type* type;
    virtual Type* compute();
    virtual IRNode* peephole();
};

} // namespace despair
