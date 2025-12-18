#include <arithmetic.h>
#include <constant.h>
#include <node.h>
#include <return.h>
#include <start.h>

int main()
{
    despair::Start func;
    despair::TypeInteger retval (5);
    despair::Constant retconstexpr (static_cast<despair::IRNode*>(&func), retval);
    despair::Return retexpr (&func, retconstexpr.peephole());

    return 0;
}
