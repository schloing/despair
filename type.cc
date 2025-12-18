#include <type.h>

namespace despair {
bool TypeBase::isConstant()
{
    return this->type == TTOP;
}
} // namespace despair
