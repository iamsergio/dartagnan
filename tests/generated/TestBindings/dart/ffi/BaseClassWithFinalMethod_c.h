#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class BaseClassWithFinalMethod_wrapper : public ::BaseClassWithFinalMethod
{
public:
    ~BaseClassWithFinalMethod_wrapper();
    BaseClassWithFinalMethod_wrapper();
    typedef void (*Callback_finalMethod)(void *);
    Callback_finalMethod m_finalMethodCallback = nullptr;
};
}
extern "C" {
// BaseClassWithFinalMethod::BaseClassWithFinalMethod()
TestBindings_EXPORT void *c_BaseClassWithFinalMethod__constructor();
// BaseClassWithFinalMethod::finalMethod()
TestBindings_EXPORT void c_BaseClassWithFinalMethod__finalMethod(void *thisObj);
TestBindings_EXPORT void c_BaseClassWithFinalMethod__destructor(void *thisObj);
TestBindings_EXPORT void
c_BaseClassWithFinalMethod__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
TestBindings_EXPORT void c_BaseClassWithFinalMethod_Finalizer(void *cppObj);
}
