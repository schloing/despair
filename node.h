#pragma once
#include <vector>

#include <type.h>

namespace despair {
class IRNode {
public:
    enum Kind {
        ADD,
        CONST,
        DIVIDE,
        MULTIPLY,
        NEGATE,
        RETURN,
        START,
        SUBTRACT,
        TYPE,
    };
private:
    const Kind kind;
    std::vector<IRNode*> inputs;
    std::vector<IRNode*> outputs;
public:
    IRNode(std::vector<IRNode*> inputs, Kind kind)
        : kind(kind), inputs(inputs), outputs({}) {};

    Kind get_kind() const
    {
        return kind;
    }

    Type* type;
    virtual Type* compute();
    virtual IRNode* peephole();
    virtual ~IRNode() = default;
};

} // namespace despair
