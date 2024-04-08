#include "TestTargetNS_c.h"


#include <iostream>

#include <cassert>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
extern "C" {
// namespaceFunctionReturningNamespaceEnum()
int c_static_TestTargetNS__namespaceFunctionReturningNamespaceEnum()
{
    const auto &result = TestTargetNS::namespaceFunctionReturningNamespaceEnum();
    return result;
}
// namespaceLevelGlobalFunction()
int c_static_TestTargetNS__namespaceLevelGlobalFunction()
{
    const auto &result = TestTargetNS::namespaceLevelGlobalFunction();
    return result;
}
}
