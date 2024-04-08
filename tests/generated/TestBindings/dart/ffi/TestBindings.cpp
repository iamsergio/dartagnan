#include "TestBindings.h"

// globalFunction()
int c___globalFunction()
{
    const auto &result = globalFunction();
    return result;
}
// receivesStructAsOptionalArgument(EmptyStruct arg1)
int c___receivesStructAsOptionalArgument_EmptyStruct(void *arg1_)
{
    assert(arg1_);
    auto &arg1 = *reinterpret_cast<EmptyStruct *>(arg1_);
    const auto &result = receivesStructAsOptionalArgument(arg1);
    return result;
}
// receivesStructAsOptionalArgument2(EmptyStruct arg__1)
int c___receivesStructAsOptionalArgument2_EmptyStruct(void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<EmptyStruct *>(arg__1_);
    const auto &result = receivesStructAsOptionalArgument2(arg__1);
    return result;
}
// receivingPureAbstract(TestTargetNS::PureAbstract * a)
int c_static___receivingPureAbstract_PureAbstract(void *a_)
{
    auto a = reinterpret_cast<TestTargetNS::PureAbstract *>(a_);
    const auto &result = ::receivingPureAbstract(a);
    return result;
}
// returnsPureAbstract()
void *c_static___returnsPureAbstract()
{
    const auto &result = ::returnsPureAbstract();
    return result;
}
