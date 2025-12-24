#include <constant.h>
#include <node.h>
#include <type.h>

namespace despair {
IRNode* IRNode::peephole()
{
    Type* t = compute();

    if (t && t->is_const()) {
        return new despair::Constant(nullptr, t);
    }

    type = t;

    return this;
}

Type* IRNode::compute()
{
    return new Type();
}
} // namespace despair
