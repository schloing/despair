#pragma once
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

#include "type.h"

namespace despair {
enum class IRNodeDescriptor : uint8_t {
    NONE = 0,
    COMMUTATIVE = 1 << 0,
    CONTROL = 1 << 1,
    BREAKING = 1 << 2,
    CONSTLIKE = 1 << 3,
    USE_MEMORY = 1 << 4,
    CONST_MEMORY = 1 << 5,
    DATA = 1 << 6,
};

inline IRNodeDescriptor operator|(IRNodeDescriptor a, IRNodeDescriptor b)
{
    return static_cast<IRNodeDescriptor>(static_cast<int>(a) | static_cast<int>(b));
}

template <size_t N_INPUTS, size_t N_OUTPUTS>
class IRNode {
private:
    size_t nid;

protected:
    std::shared_ptr<IRNode> inputs[N_INPUTS];
    std::shared_ptr<IRNode> outputs[N_OUTPUTS];
    IRNodeDescriptor descriptor;
    despair::Type datatype;

public:
    IRNode() = default;

    virtual std::string label()
    {
        return "IRNode";
    }

    virtual std::string format()
    {
        return "IRNode";
    }

    ~IRNode() = default;
};

class Start : public IRNode<0, 0> {
public:
    Start() = default;
};

// <- _start IRNode
// -> value of constant
class Constant : public IRNode<1, 1> {
public:
    Constant()
    {
        this->descriptor = IRNodeDescriptor::CONSTLIKE | IRNodeDescriptor::DATA;
    }
};

// <- predecessor control IRNode, data IRNode
// -> return value of the function
class Return : public IRNode<2, 1> {
public:
    std::shared_ptr<IRNode> ctrl;
    std::shared_ptr<IRNode> expr;

    Return()
    {
        this->ctrl = this->inputs[0];
        this->expr = this->inputs[1];
    }

    virtual std::string label() override
    {
        return "Return";
    }
};

// <- 2 data nodes
// -> result of add
class Add : public IRNode<2, 1> {
public:
    Add()
    {
    }

    virtual std::string label() override
    {
        return "Add";
    }
};

// <- 2 data nodes
// -> result of subtract
class Subtract : public IRNode<2, 1> {
public:
    Subtract()
    {
    }

    virtual std::string label() override
    {
        return "Subtract";
    }
};

// <- 2 data nodes
// -> result of multiply
class Multiply : public IRNode<2, 1> {
public:
    Multiply()
    {
    }

    virtual std::string label() override
    {
        return "Multiply";
    }
};

// <- 2 data nodes
// -> result of divide
class Divide : public IRNode<2, 1> {
public:
    Divide()
    {
    }

    virtual std::string label() override
    {
        return "Divide";
    }
};

// <- 1 data node
// -> result of unary minus
class Minus : public IRNode<2, 1> {
public:
    Minus()
    {
    }

    virtual std::string label() override
    {
        return "Minus";
    }
};

}; // namespace despair
