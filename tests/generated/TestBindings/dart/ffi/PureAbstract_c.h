#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class PureAbstract_wrapper : public ::TestTargetNS::PureAbstract
{
public:
    ~PureAbstract_wrapper();
    PureAbstract_wrapper();
    int callVirtualReceivingPointer(SimpleStruct *s);
    void flagsWithDefaultArgs(QFlags<AnotherNamespace::NamespaceLevelEnum> options = {});
    virtual int foo();
    virtual int foo_nocallback();
    virtual void renamedPureVirtual();
    virtual void renamedPureVirtual_nocallback();
    static void renamedStatic();
    int returnsInt() const;
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
// TestTargetNS::PureAbstract::PureAbstract()
TestBindings_EXPORT void *c_TestTargetNS__PureAbstract__constructor();
// TestTargetNS::PureAbstract::callVirtualReceivingPointer(SimpleStruct * s)
TestBindings_EXPORT int
c_TestTargetNS__PureAbstract__callVirtualReceivingPointer_SimpleStruct(void *thisObj, void *s_);
// TestTargetNS::PureAbstract::flagsWithDefaultArgs(QFlags<AnotherNamespace::NamespaceLevelEnum>
// options)
TestBindings_EXPORT void
c_TestTargetNS__PureAbstract__flagsWithDefaultArgs_NamespaceLevelEnums(void *thisObj, int options_);
// TestTargetNS::PureAbstract::foo()
TestBindings_EXPORT int c_TestTargetNS__PureAbstract__foo(void *thisObj);
// TestTargetNS::PureAbstract::renamedPureVirtual()
TestBindings_EXPORT void c_TestTargetNS__PureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::PureAbstract::renamedStatic()
TestBindings_EXPORT void c_static_TestTargetNS__PureAbstract__renamedStatic1();
// TestTargetNS::PureAbstract::returnsInt() const
TestBindings_EXPORT int c_TestTargetNS__PureAbstract__returnsInt(void *thisObj);
// TestTargetNS::PureAbstract::unnamedOverriddenDefaultArgCase(int myarg)
TestBindings_EXPORT void
c_TestTargetNS__PureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj, int myarg);
// TestTargetNS::PureAbstract::virtualReceivingPointer(SimpleStruct * s)
TestBindings_EXPORT int
c_TestTargetNS__PureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj, void *s_);
// TestTargetNS::PureAbstract::voidPureAbstract()
TestBindings_EXPORT void c_TestTargetNS__PureAbstract__voidPureAbstract(void *thisObj);
TestBindings_EXPORT void c_TestTargetNS__PureAbstract__destructor(void *thisObj);
TestBindings_EXPORT int c_static_TestTargetNS__PureAbstract___get_s_instanceCount();
TestBindings_EXPORT void
c_static_TestTargetNS__PureAbstract___set_s_instanceCount_int(int s_instanceCount_);
TestBindings_EXPORT void c_TestTargetNS__PureAbstract__registerVirtualMethodCallback(void *ptr,
                                                                                     void *callback,
                                                                                     int methodId);
TestBindings_EXPORT void c_TestTargetNS__PureAbstract_Finalizer(void *cppObj);
}
