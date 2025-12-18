#include <constant.h>
#include <node.h>
#include <type.h>

namespace despair {
IRNode* IRNode::peephole()
{
    this->type = compute();

    // FIXME: this line is wrong, assuming TypeInteger means this->type.isConstant()
    // TODO: somehow implement an isConstant()
    if (std::get_if<TypeInteger>(&this->type)) {
        // FIXME
        return new despair::Constant(nullptr, this->type);
    }

    // FIXME
    return nullptr;
}

Type IRNode::compute()
{
    return Type();
}
} // namespace despair
