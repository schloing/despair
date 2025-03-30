#pragma once

#include "node.h"

namespace despair {
class Parser {
private:
    IRNode parseStatement();
    IRNode parseExpression();
    IRNode parsePrimary();

public:
    IRNode _start;

    Parser() = default;
};
}
