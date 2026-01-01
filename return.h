#pragma once
#include <node.h>

namespace despair {
class Return : public IRNode {
public:
    const IRNode* ctrl;
    const IRNode* data;

    Return(IRNode* ctrl, IRNode* data)
        : IRNode({ctrl, data}, RETURN), ctrl(ctrl), data(data) {}
};
}
