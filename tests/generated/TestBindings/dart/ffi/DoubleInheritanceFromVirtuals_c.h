#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class DoubleInheritanceFromVirtuals_wrapper : public ::DoubleInheritanceFromVirtuals
{
public:
    ~DoubleInheritanceFromVirtuals_wrapper();
    DoubleInheritanceFromVirtuals_wrapper();
    virtual void virtualMethod1();
    virtual void virtualMethod1_nocallback();
    virtual void virtualMethod2();
    virtual void virtualMethod2_nocallback();
    typedef void (*Callback_virtualMethod1)(void *);
    Callback_virtualMethod1 m_virtualMethod1Callback = nullptr;
    typedef void (*Callback_virtualMethod2)(void *);
    Callback_virtualMethod2 m_virtualMethod2Callback = nullptr;
};
}
extern "C" {
// DoubleInheritanceFromVirtuals::DoubleInheritanceFromVirtuals()
TestBindings_EXPORT void *c_DoubleInheritanceFromVirtuals__constructor();
// DoubleInheritanceFromVirtuals::virtualMethod1()
TestBindings_EXPORT void c_DoubleInheritanceFromVirtuals__virtualMethod1(void *thisObj);
// DoubleInheritanceFromVirtuals::virtualMethod2()
TestBindings_EXPORT void c_DoubleInheritanceFromVirtuals__virtualMethod2(void *thisObj);
TestBindings_EXPORT void c_DoubleInheritanceFromVirtuals__destructor(void *thisObj);
TestBindings_EXPORT void
c_DoubleInheritanceFromVirtuals__registerVirtualMethodCallback(void *ptr, void *callback,
                                                               int methodId);
TestBindings_EXPORT void c_DoubleInheritanceFromVirtuals_Finalizer(void *cppObj);
}
