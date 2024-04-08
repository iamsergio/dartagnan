#include "TestBindings_exports.h"
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>
#include <test.h>
#include <vector>

namespace TestBindings_wrappersNS {
class MyDerivedClass_wrapper : public ::TestTargetNS::MyDerivedClass
{
public:
    ~MyDerivedClass_wrapper();
    using ::TestTargetNS::MyBaseClass::ProtectedEnum;
    MyDerivedClass_wrapper();
    int alsoCallsVirtual();
    static const TestTargetNS::MyDerivedClass *anotherOverloadedStatic(int arg__1);
    static const TestTargetNS::MyDerivedClass *anotherOverloadedStatic(int arg__1, int arg__2);
    virtual int bar() const;
    virtual int bar_nocallback() const;
    virtual int bar2() const;
    virtual int bar2_nocallback() const;
    int nonVirtualButOverridden() const;
    virtual int nonVirtualInBaseButVirtualInDerived(int i, int j) const;
    virtual int nonVirtualInBaseButVirtualInDerived_nocallback(int i, int j) const;
    virtual void paintEvent();
    virtual void paintEvent_nocallback();
    virtual int receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass *der);
    virtual int receivesDerivedPolymorphic_nocallback(TestTargetNS::MyDerivedClass *der);
    void receivesEnumFromBaseClassWithDefaultValue(
        int a = TestTargetNS::MyBaseClass::MyEnum::MyEnumerator0);
    int receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p);
    virtual void renamedVirtual1();
    virtual void renamedVirtual1_nocallback();
    MyTemplate2<NonCopiable *> returnTemplate1();
    const MyTemplate2<NonCopiable *> &returnTemplate2();
    static AnotherNamespace::NamespaceLevelEnum returnsAnotherNamespaceEnum();
    static AnotherNamespace::AnotherNamespaceStruct returnsAnotherNamespaceStruct();
    const TestTargetNS::MyDerivedClass *returnsConstPointer();
    virtual void setVisible(bool b);
    virtual void setVisible_nocallback(bool b);
    void show();
    virtual int virtualNotInBase() const;
    virtual int virtualNotInBase_nocallback() const;
    virtual int virtualReceivingBool(bool b);
    virtual int virtualReceivingBool_nocallback(bool b);
    virtual void virtualReceivingCharPtr(char *arg__1);
    virtual void virtualReceivingCharPtr_nocallback(char *arg__1);
    virtual int virtualReceivingInt(int arg__1);
    virtual int virtualReceivingInt_nocallback(int arg__1);
    virtual int virtualReceivingOptionalArgument(int optional = 1);
    virtual int virtualReceivingOptionalArgument_nocallback(int optional = 1);
    virtual bool virtualReturningBool(bool b);
    virtual bool virtualReturningBool_nocallback(bool b);
    virtual qint64 virtualReturningQint64();
    virtual qint64 virtualReturningQint64_nocallback();
    virtual SimpleStruct virtualReturningStruct() const;
    virtual SimpleStruct virtualReturningStruct_nocallback() const;
    virtual MyTemplate<int> virtualReturnsIntTemplate();
    virtual MyTemplate<int> virtualReturnsIntTemplate_nocallback();
    virtual void virtualWithOverload(int i) const;
    virtual void virtualWithOverload_nocallback(int i) const;
    virtual void virtualWithOverload(int i, int j) const;
    virtual void virtualWithOverload_nocallback(int i, int j) const;
    typedef int (*Callback_bar)(void *);
    Callback_bar m_barCallback = nullptr;
    typedef int (*Callback_bar2)(void *);
    Callback_bar2 m_bar2Callback = nullptr;
    typedef int (*Callback_nonVirtualInBaseButVirtualInDerived_2)(void *, int i, int j);
    Callback_nonVirtualInBaseButVirtualInDerived_2 m_nonVirtualInBaseButVirtualInDerived_2Callback =
        nullptr;
    typedef void (*Callback_paintEvent)(void *);
    Callback_paintEvent m_paintEventCallback = nullptr;
    typedef int (*Callback_receivesDerivedPolymorphic)(void *, TestTargetNS::MyDerivedClass *der);
    Callback_receivesDerivedPolymorphic m_receivesDerivedPolymorphicCallback = nullptr;
    typedef void (*Callback_renamedVirtual2)(void *);
    Callback_renamedVirtual2 m_renamedVirtual2Callback = nullptr;
    typedef void (*Callback_setVisible)(void *, bool b);
    Callback_setVisible m_setVisibleCallback = nullptr;
    typedef int (*Callback_virtualNotInBase)(void *);
    Callback_virtualNotInBase m_virtualNotInBaseCallback = nullptr;
    typedef int (*Callback_virtualReceivingBool)(void *, bool b);
    Callback_virtualReceivingBool m_virtualReceivingBoolCallback = nullptr;
    typedef void (*Callback_virtualReceivingCharPtr)(void *, char *arg__1);
    Callback_virtualReceivingCharPtr m_virtualReceivingCharPtrCallback = nullptr;
    typedef int (*Callback_virtualReceivingInt)(void *, int arg__1);
    Callback_virtualReceivingInt m_virtualReceivingIntCallback = nullptr;
    typedef int (*Callback_virtualReceivingOptionalArgument)(void *, int optional);
    Callback_virtualReceivingOptionalArgument m_virtualReceivingOptionalArgumentCallback = nullptr;
    typedef bool (*Callback_virtualReturningBool)(void *, bool b);
    Callback_virtualReturningBool m_virtualReturningBoolCallback = nullptr;
    typedef qint64 (*Callback_virtualReturningQint64)(void *);
    Callback_virtualReturningQint64 m_virtualReturningQint64Callback = nullptr;
    typedef SimpleStruct *(*Callback_virtualReturningStruct)(void *);
    Callback_virtualReturningStruct m_virtualReturningStructCallback = nullptr;
    typedef MyTemplate<int> *(*Callback_virtualReturnsIntTemplate)(void *);
    Callback_virtualReturnsIntTemplate m_virtualReturnsIntTemplateCallback = nullptr;
    typedef void (*Callback_virtualWithOverload)(void *, int i);
    Callback_virtualWithOverload m_virtualWithOverloadCallback = nullptr;
    typedef void (*Callback_virtualWithOverload_2)(void *, int i, int j);
    Callback_virtualWithOverload_2 m_virtualWithOverload_2Callback = nullptr;
};
}
extern "C" {
// TestTargetNS::MyDerivedClass::MyDerivedClass()
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__constructor();
// TestTargetNS::MyDerivedClass::alsoCallsVirtual()
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__alsoCallsVirtual(void *thisObj);
// TestTargetNS::MyDerivedClass::anotherOverloadedStatic(int arg__1)
TestBindings_EXPORT void *
c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int(int arg__1);
// TestTargetNS::MyDerivedClass::anotherOverloadedStatic(int arg__1, int arg__2)
TestBindings_EXPORT void *
c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int_int(int arg__1, int arg__2);
// TestTargetNS::MyDerivedClass::bar() const
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__bar(void *thisObj);
// TestTargetNS::MyDerivedClass::bar2() const
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__bar2(void *thisObj);
// TestTargetNS::MyDerivedClass::nonVirtualButOverridden() const
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__nonVirtualButOverridden(void *thisObj);
// TestTargetNS::MyDerivedClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const
TestBindings_EXPORT int
c_TestTargetNS__MyDerivedClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj, int i,
                                                                            int j);
// TestTargetNS::MyDerivedClass::paintEvent()
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__paintEvent(void *thisObj);
// TestTargetNS::MyDerivedClass::receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass * der)
TestBindings_EXPORT int
c_TestTargetNS__MyDerivedClass__receivesDerivedPolymorphic_MyDerivedClass(void *thisObj,
                                                                          void *der_);
// TestTargetNS::MyDerivedClass::receivesEnumFromBaseClassWithDefaultValue(int a)
TestBindings_EXPORT void
c_TestTargetNS__MyDerivedClass__receivesEnumFromBaseClassWithDefaultValue_int(void *thisObj, int a);
// TestTargetNS::MyDerivedClass::receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p)
TestBindings_EXPORT int
c_TestTargetNS__MyDerivedClass__receivesProtectedEnum_ProtectedEnum(void *thisObj, int p);
// TestTargetNS::MyDerivedClass::renamedVirtual1()
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__renamedVirtual2(void *thisObj);
// TestTargetNS::MyDerivedClass::returnTemplate1()
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__returnTemplate1(void *thisObj);
// TestTargetNS::MyDerivedClass::returnTemplate2()
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__returnTemplate2(void *thisObj);
// TestTargetNS::MyDerivedClass::returnsAnotherNamespaceEnum()
TestBindings_EXPORT int c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceEnum();
// TestTargetNS::MyDerivedClass::returnsAnotherNamespaceStruct()
TestBindings_EXPORT void *c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceStruct();
// TestTargetNS::MyDerivedClass::returnsConstPointer()
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__returnsConstPointer(void *thisObj);
// TestTargetNS::MyDerivedClass::setVisible(bool b)
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__setVisible_bool(void *thisObj, bool b);
// TestTargetNS::MyDerivedClass::show()
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__show(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualNotInBase() const
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__virtualNotInBase(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReceivingBool(bool b)
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__virtualReceivingBool_bool(void *thisObj,
                                                                                  bool b);
// TestTargetNS::MyDerivedClass::virtualReceivingCharPtr(char * arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__virtualReceivingCharPtr_char(void *thisObj,
                                                                                      char *arg__1);
// TestTargetNS::MyDerivedClass::virtualReceivingInt(int arg__1)
TestBindings_EXPORT int c_TestTargetNS__MyDerivedClass__virtualReceivingInt_int(void *thisObj,
                                                                                int arg__1);
// TestTargetNS::MyDerivedClass::virtualReceivingOptionalArgument(int optional)
TestBindings_EXPORT int
c_TestTargetNS__MyDerivedClass__virtualReceivingOptionalArgument_int(void *thisObj, int optional);
// TestTargetNS::MyDerivedClass::virtualReturningBool(bool b)
TestBindings_EXPORT bool c_TestTargetNS__MyDerivedClass__virtualReturningBool_bool(void *thisObj,
                                                                                   bool b);
// TestTargetNS::MyDerivedClass::virtualReturningQint64()
TestBindings_EXPORT qint64 c_TestTargetNS__MyDerivedClass__virtualReturningQint64(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReturningStruct() const
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__virtualReturningStruct(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReturnsIntTemplate()
TestBindings_EXPORT void *c_TestTargetNS__MyDerivedClass__virtualReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualWithOverload(int i) const
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int(void *thisObj,
                                                                                 int i);
// TestTargetNS::MyDerivedClass::virtualWithOverload(int i, int j) const
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int_int(void *thisObj,
                                                                                     int i, int j);
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass__destructor(void *thisObj);
TestBindings_EXPORT int c_static_TestTargetNS__MyDerivedClass___get_s_instanceCount();
TestBindings_EXPORT void
c_static_TestTargetNS__MyDerivedClass___set_s_instanceCount_int(int s_instanceCount_);
TestBindings_EXPORT void
c_TestTargetNS__MyDerivedClass__registerVirtualMethodCallback(void *ptr, void *callback,
                                                              int methodId);
TestBindings_EXPORT void c_TestTargetNS__MyDerivedClass_Finalizer(void *cppObj);
}
