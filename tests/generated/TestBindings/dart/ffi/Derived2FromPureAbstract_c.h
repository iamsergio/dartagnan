#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class Derived2FromPureAbstract_wrapper : public ::TestTargetNS::Derived2FromPureAbstract
{
public:
    ~Derived2FromPureAbstract_wrapper();
    Derived2FromPureAbstract_wrapper();
    virtual int foo();
    virtual int foo_nocallback();
    virtual void renamedPureVirtual();
    virtual void renamedPureVirtual_nocallback();
    virtual void unnamedOverriddenDefaultArgCase(int myarg = 0);
    virtual void unnamedOverriddenDefaultArgCase_nocallback(int myarg = 0);
    virtual int virtualReceivingPointer(SimpleStruct *s);
    virtual int virtualReceivingPointer_nocallback(SimpleStruct *s);
    virtual void voidPureAbstract();
    virtual void voidPureAbstract_nocallback();
    typedef int (*Callback_foo)(void *);
    Callback_foo m_fooCallback = nullptr;
    typedef void (*Callback_renamedPureVirtual1)(void *);
    Callback_renamedPureVirtual1 m_renamedPureVirtual1Callback = nullptr;
    typedef void (*Callback_unnamedOverriddenDefaultArgCase)(void *, int myarg);
    Callback_unnamedOverriddenDefaultArgCase m_unnamedOverriddenDefaultArgCaseCallback = nullptr;
    typedef int (*Callback_virtualReceivingPointer)(void *, SimpleStruct *s);
    Callback_virtualReceivingPointer m_virtualReceivingPointerCallback = nullptr;
    typedef void (*Callback_voidPureAbstract)(void *);
    Callback_voidPureAbstract m_voidPureAbstractCallback = nullptr;
};
}
extern "C" {
// TestTargetNS::Derived2FromPureAbstract::Derived2FromPureAbstract()
TestBindings_EXPORT void *c_TestTargetNS__Derived2FromPureAbstract__constructor();
// TestTargetNS::Derived2FromPureAbstract::foo()
TestBindings_EXPORT int c_TestTargetNS__Derived2FromPureAbstract__foo(void *thisObj);
// TestTargetNS::Derived2FromPureAbstract::renamedPureVirtual()
TestBindings_EXPORT void
c_TestTargetNS__Derived2FromPureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::Derived2FromPureAbstract::unnamedOverriddenDefaultArgCase(int myarg)
TestBindings_EXPORT void
c_TestTargetNS__Derived2FromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                              int myarg);
// TestTargetNS::Derived2FromPureAbstract::virtualReceivingPointer(SimpleStruct * s)
TestBindings_EXPORT int
c_TestTargetNS__Derived2FromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                               void *s_);
// TestTargetNS::Derived2FromPureAbstract::voidPureAbstract()
TestBindings_EXPORT void c_TestTargetNS__Derived2FromPureAbstract__voidPureAbstract(void *thisObj);
TestBindings_EXPORT void c_TestTargetNS__Derived2FromPureAbstract__destructor(void *thisObj);
TestBindings_EXPORT void
c_TestTargetNS__Derived2FromPureAbstract__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                        int methodId);
TestBindings_EXPORT void c_TestTargetNS__Derived2FromPureAbstract_Finalizer(void *cppObj);
}
