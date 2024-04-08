#include "TestBindings_exports.h"
#include <test.h>

extern "C" {
// TestTargetNS::namespaceFunctionReturningNamespaceEnum()
TestBindings_EXPORT int c_static_TestTargetNS__namespaceFunctionReturningNamespaceEnum();
// TestTargetNS::namespaceLevelGlobalFunction()
TestBindings_EXPORT int c_static_TestTargetNS__namespaceLevelGlobalFunction();
TestBindings_EXPORT void c_TestTargetNS_Finalizer(void *cppObj);
}
