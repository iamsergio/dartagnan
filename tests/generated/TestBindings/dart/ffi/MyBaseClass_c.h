#include "TestBindings_exports.h"
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>
#include <test.h>

namespace TestBindings_wrappersNS {
class MyBaseClass_wrapper : public ::TestTargetNS::MyBaseClass
{
public:
    ~MyBaseClass_wrapper();
    using ::TestTargetNS::MyBaseClass::ProtectedEnum;
    MyBaseClass_wrapper();
    MyBaseClass_wrapper(TestTargetNS::MyBaseClass *mybaseclassptr);
    void addInts(QList<int> arg__1);
    void addQObjects(const QList<QObject *> &arg__1);
    void addReals(QList<qreal> arg__1);
    static int anotherOverloadedStatic(int arg__1);
    virtual int bar() const;
    virtual int bar_nocallback() const;
    virtual int bar2() const;
    virtual int bar2_nocallback() const;
    int callsVirtual() const;
    int foo() const;
    bool getBool(int arg__1) const;
    bool getBoolFalse() const;
    bool getBoolTrue() const;
    void hello();
    MyTemplate<int> methodReturnsIntTemplate();
    int nonVirtualButOverridden() const;
    int nonVirtualInBaseButVirtualInDerived(int i) const;
    virtual int nonVirtualInBaseButVirtualInDerived(int i, int j) const;
    virtual int nonVirtualInBaseButVirtualInDerived_nocallback(int i, int j) const;
    SimpleStruct nonVirtualReturningStruct() const;
    static void overloadedStatic();
    static void overloadedStatic(int arg__1);
    static void overloadedStatic(int arg__1, int arg__2);
    static void print(const char *msg);
    void push(const char *arg__1);
    QString receivesAndReturnsQString(const QString &s);
    int receivesEnum(TestTargetNS::MyBaseClass::MyEnum e);
    void receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1 =
                                        TestTargetNS::MyBaseClass::MyEnum::MyEnumerator0);
    void receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum arg__1 = {});
    void receivesFloat(float arg__1);
    void receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1);
    void
    receivesintWithDefaultEnumArg(int arg__1 = TestTargetNS::MyBaseClass::MyEnum::MyEnumerator0);
    void
    receivesintWithDefaultEnumArg2(int arg__1 = TestTargetNS::MyBaseClass::AnonymousEnumerator1);
    void
    receivesintWithDefaultEnumArg3(int arg__1 = TestTargetNS::MyBaseClass::MyEnum::MyEnumerator0);
    void renamedMethod1();
    virtual void renamedVirtual1();
    virtual void renamedVirtual1_nocallback();
    static const char *returnsConstChar();
    static MyTemplate<double> returnsDoubleTemplate();
    qint64 returnsInt64() const;
    static MyTemplate<int> returnsIntTemplate();
    static QList<SimpleStruct *> returnsListOfStructPtr();
    QFlags<AnotherNamespace::NamespaceLevelEnum> returnsQFlags() const;
    static QString returnsQString();
    QList<qreal> returnsReals() const;
    static SimpleStruct returnsSimpleStruct(int value);
    static MyTemplateWithTwoArgs<int, double> returnsTemplateWithTwoArgs();
    QList<int> returnsVector();
    bool setBool(bool b);
    int sum(int a, int b);
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
    virtual void virtualWithNoDefaultArgumentInDerived(int optional = 1);
    virtual void virtualWithNoDefaultArgumentInDerived_nocallback(int optional = 1);
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
    typedef void (*Callback_renamedVirtual2)(void *);
    Callback_renamedVirtual2 m_renamedVirtual2Callback = nullptr;
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
    typedef void (*Callback_virtualWithNoDefaultArgumentInDerived)(void *, int optional);
    Callback_virtualWithNoDefaultArgumentInDerived m_virtualWithNoDefaultArgumentInDerivedCallback =
        nullptr;
    typedef void (*Callback_virtualWithOverload)(void *, int i);
    Callback_virtualWithOverload m_virtualWithOverloadCallback = nullptr;
    typedef void (*Callback_virtualWithOverload_2)(void *, int i, int j);
    Callback_virtualWithOverload_2 m_virtualWithOverload_2Callback = nullptr;
};
}
extern "C" {
// TestTargetNS::MyBaseClass::MyBaseClass()
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__constructor();
// TestTargetNS::MyBaseClass::MyBaseClass(TestTargetNS::MyBaseClass * mybaseclassptr)
TestBindings_EXPORT void *
c_TestTargetNS__MyBaseClass__constructor_MyBaseClass(void *mybaseclassptr_);
// TestTargetNS::MyBaseClass::addInts(QList<int > arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__addInts_QList_int(void *thisObj,
                                                                        void *arg__1_);
// TestTargetNS::MyBaseClass::addQObjects(const QList<QObject* > & arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__addQObjects_QList_QObject(void *thisObj,
                                                                                void *arg__1_);
// TestTargetNS::MyBaseClass::addReals(QList<qreal > arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__addReals_QList_qreal(void *thisObj,
                                                                           void *arg__1_);
// TestTargetNS::MyBaseClass::anotherOverloadedStatic(int arg__1)
TestBindings_EXPORT int c_static_TestTargetNS__MyBaseClass__anotherOverloadedStatic_int(int arg__1);
// TestTargetNS::MyBaseClass::bar() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__bar(void *thisObj);
// TestTargetNS::MyBaseClass::bar2() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__bar2(void *thisObj);
// TestTargetNS::MyBaseClass::callsVirtual() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__callsVirtual(void *thisObj);
// TestTargetNS::MyBaseClass::foo() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__foo(void *thisObj);
// TestTargetNS::MyBaseClass::getBool(int arg__1) const
TestBindings_EXPORT bool c_TestTargetNS__MyBaseClass__getBool_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::getBoolFalse() const
TestBindings_EXPORT bool c_TestTargetNS__MyBaseClass__getBoolFalse(void *thisObj);
// TestTargetNS::MyBaseClass::getBoolTrue() const
TestBindings_EXPORT bool c_TestTargetNS__MyBaseClass__getBoolTrue(void *thisObj);
// TestTargetNS::MyBaseClass::hello()
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__hello(void *thisObj);
// TestTargetNS::MyBaseClass::methodReturnsIntTemplate()
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__methodReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyBaseClass::nonVirtualButOverridden() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__nonVirtualButOverridden(void *thisObj);
// TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(int i) const
TestBindings_EXPORT int
c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int(void *thisObj, int i);
// TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const
TestBindings_EXPORT int
c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj, int i,
                                                                         int j);
// TestTargetNS::MyBaseClass::nonVirtualReturningStruct() const
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__nonVirtualReturningStruct(void *thisObj);
// TestTargetNS::MyBaseClass::overloadedStatic()
TestBindings_EXPORT void c_static_TestTargetNS__MyBaseClass__overloadedStatic();
// TestTargetNS::MyBaseClass::overloadedStatic(int arg__1)
TestBindings_EXPORT void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int(int arg__1);
// TestTargetNS::MyBaseClass::overloadedStatic(int arg__1, int arg__2)
TestBindings_EXPORT void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int_int(int arg__1,
                                                                                      int arg__2);
// TestTargetNS::MyBaseClass::print(const char * msg)
TestBindings_EXPORT void c_static_TestTargetNS__MyBaseClass__print_char(const char *msg);
// TestTargetNS::MyBaseClass::push(const char * arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__push_char(void *thisObj, const char *arg__1);
// TestTargetNS::MyBaseClass::receivesAndReturnsQString(const QString & s)
TestBindings_EXPORT void *
c_TestTargetNS__MyBaseClass__receivesAndReturnsQString_QString(void *thisObj, const char *s_);
// TestTargetNS::MyBaseClass::receivesEnum(TestTargetNS::MyBaseClass::MyEnum e)
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__receivesEnum_MyEnum(void *thisObj, int e);
// TestTargetNS::MyBaseClass::receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArg_MyEnum(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum
// arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArgNull_MyEnum(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesFloat(float arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__receivesFloat_float(void *thisObj,
                                                                          float arg__1);
// TestTargetNS::MyBaseClass::receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesQFlags_NamespaceLevelEnums(void *thisObj, int arg__1_);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg(int arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg2(int arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg2_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg3(int arg__1)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg3_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::renamedMethod1()
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__renamedMethod2(void *thisObj);
// TestTargetNS::MyBaseClass::renamedVirtual1()
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__renamedVirtual2(void *thisObj);
// TestTargetNS::MyBaseClass::returnsConstChar()
TestBindings_EXPORT const char *c_static_TestTargetNS__MyBaseClass__returnsConstChar();
// TestTargetNS::MyBaseClass::returnsDoubleTemplate()
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsDoubleTemplate();
// TestTargetNS::MyBaseClass::returnsInt64() const
TestBindings_EXPORT qint64 c_TestTargetNS__MyBaseClass__returnsInt64(void *thisObj);
// TestTargetNS::MyBaseClass::returnsIntTemplate()
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsIntTemplate();
// TestTargetNS::MyBaseClass::returnsListOfStructPtr()
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsListOfStructPtr();
// TestTargetNS::MyBaseClass::returnsQFlags() const
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__returnsQFlags(void *thisObj);
// TestTargetNS::MyBaseClass::returnsQString()
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsQString();
// TestTargetNS::MyBaseClass::returnsReals() const
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__returnsReals(void *thisObj);
// TestTargetNS::MyBaseClass::returnsSimpleStruct(int value)
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsSimpleStruct_int(int value);
// TestTargetNS::MyBaseClass::returnsTemplateWithTwoArgs()
TestBindings_EXPORT void *c_static_TestTargetNS__MyBaseClass__returnsTemplateWithTwoArgs();
// TestTargetNS::MyBaseClass::returnsVector()
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__returnsVector(void *thisObj);
// TestTargetNS::MyBaseClass::setBool(bool b)
TestBindings_EXPORT bool c_TestTargetNS__MyBaseClass__setBool_bool(void *thisObj, bool b);
// TestTargetNS::MyBaseClass::sum(int a, int b)
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__sum_int_int(void *thisObj, int a, int b);
// TestTargetNS::MyBaseClass::virtualReceivingBool(bool b)
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__virtualReceivingBool_bool(void *thisObj,
                                                                               bool b);
// TestTargetNS::MyBaseClass::virtualReceivingCharPtr(char * arg__1)
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__virtualReceivingCharPtr_char(void *thisObj,
                                                                                   char *arg__1);
// TestTargetNS::MyBaseClass::virtualReceivingInt(int arg__1)
TestBindings_EXPORT int c_TestTargetNS__MyBaseClass__virtualReceivingInt_int(void *thisObj,
                                                                             int arg__1);
// TestTargetNS::MyBaseClass::virtualReceivingOptionalArgument(int optional)
TestBindings_EXPORT int
c_TestTargetNS__MyBaseClass__virtualReceivingOptionalArgument_int(void *thisObj, int optional);
// TestTargetNS::MyBaseClass::virtualReturningBool(bool b)
TestBindings_EXPORT bool c_TestTargetNS__MyBaseClass__virtualReturningBool_bool(void *thisObj,
                                                                                bool b);
// TestTargetNS::MyBaseClass::virtualReturningQint64()
TestBindings_EXPORT qint64 c_TestTargetNS__MyBaseClass__virtualReturningQint64(void *thisObj);
// TestTargetNS::MyBaseClass::virtualReturningStruct() const
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__virtualReturningStruct(void *thisObj);
// TestTargetNS::MyBaseClass::virtualReturnsIntTemplate()
TestBindings_EXPORT void *c_TestTargetNS__MyBaseClass__virtualReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyBaseClass::virtualWithNoDefaultArgumentInDerived(int optional)
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__virtualWithNoDefaultArgumentInDerived_int(void *thisObj, int optional);
// TestTargetNS::MyBaseClass::virtualWithOverload(int i) const
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__virtualWithOverload_int(void *thisObj, int i);
// TestTargetNS::MyBaseClass::virtualWithOverload(int i, int j) const
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__virtualWithOverload_int_int(void *thisObj,
                                                                                  int i, int j);
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass__destructor(void *thisObj);
TestBindings_EXPORT int c_static_TestTargetNS__MyBaseClass___get_s_instanceCount();
TestBindings_EXPORT int c_static_TestTargetNS__MyBaseClass___get_s_staticMember();
TestBindings_EXPORT int c_static_TestTargetNS__MyBaseClass___get_s_staticConstMember();
TestBindings_EXPORT void
c_static_TestTargetNS__MyBaseClass___set_s_instanceCount_int(int s_instanceCount_);
TestBindings_EXPORT void
c_static_TestTargetNS__MyBaseClass___set_s_staticMember_int(int s_staticMember_);
TestBindings_EXPORT void
c_TestTargetNS__MyBaseClass__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
TestBindings_EXPORT void c_TestTargetNS__MyBaseClass_Finalizer(void *cppObj);
}
