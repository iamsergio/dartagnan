#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class DerivedFromPureAbstract_wrapper : public ::TestTargetNS::DerivedFromPureAbstract
{
public:
    ~DerivedFromPureAbstract_wrapper();
    DerivedFromPureAbstract_wrapper();
    DerivedFromPureAbstract_wrapper(int arg__1);
    virtual int foo();
    virtual int foo_nocallback();
    int indirectionCallsVirtualReceivingStruct(SimpleStruct s);
    int nonVirtualCallsVirtual();
    virtual int receivesValueStruct(SimpleStruct arg__1);
    virtual int receivesValueStruct_nocallback(SimpleStruct arg__1);
    virtual void renamedPureVirtual();
    virtual void renamedPureVirtual_nocallback();
    virtual void unnamedOverriddenDefaultArgCase(int arg__1 = 0);
    virtual void unnamedOverriddenDefaultArgCase_nocallback(int arg__1 = 0);
    virtual int virtualReceivingPointer(SimpleStruct *s);
    virtual int virtualReceivingPointer_nocallback(SimpleStruct *s);
    virtual void voidPureAbstract();
    virtual void voidPureAbstract_nocallback();
    typedef int (*Callback_foo)(void *);
    Callback_foo m_fooCallback = nullptr;
    typedef int (*Callback_receivesValueStruct)(void *, SimpleStruct *arg__1);
    Callback_receivesValueStruct m_receivesValueStructCallback = nullptr;
    typedef void (*Callback_renamedPureVirtual1)(void *);
    Callback_renamedPureVirtual1 m_renamedPureVirtual1Callback = nullptr;
    typedef void (*Callback_unnamedOverriddenDefaultArgCase)(void *, int arg__1);
    Callback_unnamedOverriddenDefaultArgCase m_unnamedOverriddenDefaultArgCaseCallback = nullptr;
    typedef int (*Callback_virtualReceivingPointer)(void *, SimpleStruct *s);
    Callback_virtualReceivingPointer m_virtualReceivingPointerCallback = nullptr;
    typedef void (*Callback_voidPureAbstract)(void *);
    Callback_voidPureAbstract m_voidPureAbstractCallback = nullptr;
};
}
extern "C" {
// TestTargetNS::DerivedFromPureAbstract::DerivedFromPureAbstract()
TestBindings_EXPORT void *c_TestTargetNS__DerivedFromPureAbstract__constructor();
// TestTargetNS::DerivedFromPureAbstract::DerivedFromPureAbstract(int arg__1)
TestBindings_EXPORT void *c_TestTargetNS__DerivedFromPureAbstract__constructor_int(int arg__1);
// TestTargetNS::DerivedFromPureAbstract::foo()
TestBindings_EXPORT int c_TestTargetNS__DerivedFromPureAbstract__foo(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::indirectionCallsVirtualReceivingStruct(SimpleStruct s)
TestBindings_EXPORT int
c_TestTargetNS__DerivedFromPureAbstract__indirectionCallsVirtualReceivingStruct_SimpleStruct(
    void *thisObj, void *s_);
// TestTargetNS::DerivedFromPureAbstract::nonVirtualCallsVirtual()
TestBindings_EXPORT int
c_TestTargetNS__DerivedFromPureAbstract__nonVirtualCallsVirtual(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::receivesValueStruct(SimpleStruct arg__1)
TestBindings_EXPORT int
c_TestTargetNS__DerivedFromPureAbstract__receivesValueStruct_SimpleStruct(void *thisObj,
                                                                          void *arg__1_);
// TestTargetNS::DerivedFromPureAbstract::renamedPureVirtual()
TestBindings_EXPORT void
c_TestTargetNS__DerivedFromPureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::unnamedOverriddenDefaultArgCase(int arg__1)
TestBindings_EXPORT void
c_TestTargetNS__DerivedFromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                             int arg__1);
// TestTargetNS::DerivedFromPureAbstract::virtualReceivingPointer(SimpleStruct * s)
TestBindings_EXPORT int
c_TestTargetNS__DerivedFromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                              void *s_);
// TestTargetNS::DerivedFromPureAbstract::voidPureAbstract()
TestBindings_EXPORT void c_TestTargetNS__DerivedFromPureAbstract__voidPureAbstract(void *thisObj);
TestBindings_EXPORT void c_TestTargetNS__DerivedFromPureAbstract__destructor(void *thisObj);
TestBindings_EXPORT void
c_TestTargetNS__DerivedFromPureAbstract__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                       int methodId);
TestBindings_EXPORT void c_TestTargetNS__DerivedFromPureAbstract_Finalizer(void *cppObj);
}
