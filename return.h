#pragma once
#include <node.h>

namespace despair {
class Return : public IRNode {
public:
    const IRNode* ctrl;
    const IRNode* data;

    Return(IRNode* ctrl, IRNode* data)
        : IRNode({ctrl, data}, RETURN), ctrl(ctrl), data(data) {}

    static bool is_class_of(const IRNode* val)
    {
        return val->get_kind() == IRNode::Kind::RETURN;
    }
};
}
