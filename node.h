#pragma once
#include <memory>
#include <vector>

namespace despair {
enum NodeType {
    NONE,
};

enum class NodeDescriptor {
    NONE = 0,
    COMMUTATIVE = 1 << 0,
    CONTROL = 1 << 1,
    BREAKING = 1 << 2,
    CONSTLIKE = 1 << 3,
    USE_MEMORY = 1 << 4,
    CONST_MEMORY = 1 << 5,
};

template <size_t N_INPUTS, size_t N_OUTPUTS>
class Node {
public:
    std::shared_ptr<Node> inputs[N_INPUTS];
    std::shared_ptr<Node> outputs[N_OUTPUTS];
    NodeType type;
    NodeDescriptor descriptor;

    Node()
        : type(NodeType::NONE)
        , descriptor(NodeDescriptor::NONE)
    {
    }
};

class ReturnNode : public Node {
public:
    std::shared_ptr<Node> ctrl;
    std::shared_ptr<Node> expr;

    ReturnNode()
        : ctrl(inputs[0])
        , expr(outputs[1])
    {
    }
};
}; // namespace despair
