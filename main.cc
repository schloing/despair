#include <arithmetic.h>
#include <constant.h>
#include <node.h>
#include <return.h>
#include <start.h>

int main()
{
    despair::Constant num5 (new despair::Start(), new despair::TypeInteger(5));
    despair::Constant num6 (new despair::Start(), new despair::TypeInteger(6));
    despair::Multiply retvalexpr (&num5, &num6);
    despair::Return retexpr (new despair::Start(), retvalexpr.peephole());

    return 0;
}
