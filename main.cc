#include <arithmetic.h>
#include <constant.h>
#include <node.h>
#include <return.h>
#include <start.h>

int main()
{
    despair::Start* func = new despair::Start();
    despair::Constant num5 (func, new despair::TypeInteger(5));
    despair::Constant num6 (func, new despair::TypeInteger(6));
    despair::Multiply retvalexpr (&num5, &num6);
    despair::Return retexpr (func, retvalexpr.peephole());

    return 0;
}
