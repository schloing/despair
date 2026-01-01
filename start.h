#pragma once
#include <node.h>

namespace despair {
class Start : public IRNode {
public:
    Start() : IRNode({}, START) {};
};
}
