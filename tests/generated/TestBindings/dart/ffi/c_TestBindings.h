#include <stdbool.h>

// Virtual2::Virtual2()
void *c_Virtual2__constructor();
// Virtual2::virtualMethod2()
void c_Virtual2__virtualMethod2(void *thisObj);
void c_Virtual2__destructor(void *thisObj);
void c_Virtual2__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_Virtual2_Finalizer(void *cppObj); // Virtual1::Virtual1()
void *c_Virtual1__constructor();
// Virtual1::virtualMethod1()
void c_Virtual1__virtualMethod1(void *thisObj);
void c_Virtual1__destructor(void *thisObj);
void c_Virtual1__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_Virtual1_Finalizer(void *cppObj); // TestTargetNS::namespaceFunctionReturningNamespaceEnum()
int c_static_TestTargetNS__namespaceFunctionReturningNamespaceEnum();
// TestTargetNS::namespaceLevelGlobalFunction()
int c_static_TestTargetNS__namespaceLevelGlobalFunction();
void c_TestTargetNS_Finalizer(void *cppObj); // TestTargetNS::PureAbstract::PureAbstract()
void *c_TestTargetNS__PureAbstract__constructor();
// TestTargetNS::PureAbstract::callVirtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__PureAbstract__callVirtualReceivingPointer_SimpleStruct(void *thisObj, void *s_);
// TestTargetNS::PureAbstract::flagsWithDefaultArgs(QFlags<AnotherNamespace::NamespaceLevelEnum>
// options)
void c_TestTargetNS__PureAbstract__flagsWithDefaultArgs_NamespaceLevelEnums(void *thisObj,
                                                                            int options_);
// TestTargetNS::PureAbstract::foo()
int c_TestTargetNS__PureAbstract__foo(void *thisObj);
// TestTargetNS::PureAbstract::renamedPureVirtual()
void c_TestTargetNS__PureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::PureAbstract::renamedStatic()
void c_static_TestTargetNS__PureAbstract__renamedStatic1();
// TestTargetNS::PureAbstract::returnsInt() const
int c_TestTargetNS__PureAbstract__returnsInt(void *thisObj);
// TestTargetNS::PureAbstract::unnamedOverriddenDefaultArgCase(int myarg)
void c_TestTargetNS__PureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj, int myarg);
// TestTargetNS::PureAbstract::virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__PureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj, void *s_);
// TestTargetNS::PureAbstract::voidPureAbstract()
void c_TestTargetNS__PureAbstract__voidPureAbstract(void *thisObj);
void c_TestTargetNS__PureAbstract__destructor(void *thisObj);
int c_static_TestTargetNS__PureAbstract___get_s_instanceCount();
void c_static_TestTargetNS__PureAbstract___set_s_instanceCount_int(int s_instanceCount_);
void c_TestTargetNS__PureAbstract__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                 int methodId);
void c_TestTargetNS__PureAbstract_Finalizer(void *cppObj); // TestTargetNS::POD::POD()
void *c_TestTargetNS__POD__constructor();
// TestTargetNS::POD::POD(int a, int b, int c, int d)
void *c_TestTargetNS__POD__constructor_int_int_int_int(int a, int b, int c, int d);
// TestTargetNS::POD::calculate() const
int c_TestTargetNS__POD__calculate(void *thisObj);
// TestTargetNS::POD::calculateStatic()
int c_static_TestTargetNS__POD__calculateStatic();
// TestTargetNS::POD::doStuffOnMyClass(TestTargetNS::MyBaseClass * myarg)
int c_static_TestTargetNS__POD__doStuffOnMyClass_MyBaseClass(void *myarg_);
// TestTargetNS::POD::intByConstRef() const
int c_TestTargetNS__POD__intByConstRef(void *thisObj);
// TestTargetNS::POD::receivesConstPointerToPODs(const TestTargetNS::POD * ptrPod1, const
// TestTargetNS::POD * ptrPod2)
int c_static_TestTargetNS__POD__receivesConstPointerToPODs_POD_POD(void *ptrPod1_, void *ptrPod2_);
// TestTargetNS::POD::receivesConstRefPODs(const TestTargetNS::POD & pod1, const TestTargetNS::POD &
// pod2)
int c_static_TestTargetNS__POD__receivesConstRefPODs_POD_POD(void *pod1_, void *pod2_);
// TestTargetNS::POD::receivesNamespaceEnum(int v)
void c_TestTargetNS__POD__receivesNamespaceEnum_int(void *thisObj, int v);
// TestTargetNS::POD::receivesNamespaceEnum1(AnotherNamespace::NamespaceLevelEnum arg__1)
void c_TestTargetNS__POD__receivesNamespaceEnum1_NamespaceLevelEnum(void *thisObj, int arg__1);
// TestTargetNS::POD::receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2)
int c_static_TestTargetNS__POD__receivesPODs_POD_POD(void *pod1_, void *pod2_);
// TestTargetNS::POD::receivesPointerToPODs(TestTargetNS::POD * ptrPod1, TestTargetNS::POD *
// ptrPod2)
int c_static_TestTargetNS__POD__receivesPointerToPODs_POD_POD(void *ptrPod1_, void *ptrPod2_);
// TestTargetNS::POD::receivesRefPODs(TestTargetNS::POD & pod1, TestTargetNS::POD & pod2)
int c_static_TestTargetNS__POD__receivesRefPODs_POD_POD(void *pod1_, void *pod2_);
// TestTargetNS::POD::receivesReservedDartKeyword(int var)
void c_TestTargetNS__POD__receivesReservedDartKeyword_int(void *thisObj, int var);
// TestTargetNS::POD::returnsChar()
char c_static_TestTargetNS__POD__returnsChar();
// TestTargetNS::POD::returnsConstChar()
char c_static_TestTargetNS__POD__returnsConstChar();
// TestTargetNS::POD::returnsConstReferenceToPOD()
void *c_static_TestTargetNS__POD__returnsConstReferenceToPOD();
// TestTargetNS::POD::returnsPOD()
void *c_static_TestTargetNS__POD__returnsPOD();
// TestTargetNS::POD::returnsPointerToPOD()
void *c_static_TestTargetNS__POD__returnsPointerToPOD();
// TestTargetNS::POD::returnsPointerToPolymorphic()
void *c_static_TestTargetNS__POD__returnsPointerToPolymorphic();
// TestTargetNS::POD::returnsReferenceToPOD()
void *c_static_TestTargetNS__POD__returnsReferenceToPOD();
// TestTargetNS::POD::withDefaultAarg(int v)
void c_TestTargetNS__POD__withDefaultAarg_int(void *thisObj, int v);
void c_TestTargetNS__POD__destructor(void *thisObj);
int c_TestTargetNS__POD___get_v1(void *thisObj);
int c_TestTargetNS__POD___get_v2(void *thisObj);
int c_TestTargetNS__POD___get_v3(void *thisObj);
int c_TestTargetNS__POD___get_v4_const(void *thisObj);
void c_TestTargetNS__POD___set_v1_int(void *thisObj, int v1_);
void c_TestTargetNS__POD___set_v2_int(void *thisObj, int v2_);
void c_TestTargetNS__POD___set_v3_int(void *thisObj, int v3_);
void c_TestTargetNS__POD_Finalizer(
    void *cppObj); // TestTargetNS::StructWithStructAsMember::StructWithStructAsMember()
void *c_TestTargetNS__StructWithStructAsMember__constructor();
void c_TestTargetNS__StructWithStructAsMember__destructor(void *thisObj);
void c_TestTargetNS__StructWithStructAsMember_Finalizer(
    void *cppObj); // TestTargetNS::MyBaseClass::MyBaseClass()
void *c_TestTargetNS__MyBaseClass__constructor();
// TestTargetNS::MyBaseClass::MyBaseClass(TestTargetNS::MyBaseClass * mybaseclassptr)
void *c_TestTargetNS__MyBaseClass__constructor_MyBaseClass(void *mybaseclassptr_);
// TestTargetNS::MyBaseClass::addInts(QList<int > arg__1)
void c_TestTargetNS__MyBaseClass__addInts_QList_int(void *thisObj, void *arg__1_);
// TestTargetNS::MyBaseClass::addQObjects(const QList<QObject* > & arg__1)
void c_TestTargetNS__MyBaseClass__addQObjects_QList_QObject(void *thisObj, void *arg__1_);
// TestTargetNS::MyBaseClass::addReals(QList<qreal > arg__1)
void c_TestTargetNS__MyBaseClass__addReals_QList_qreal(void *thisObj, void *arg__1_);
// TestTargetNS::MyBaseClass::anotherOverloadedStatic(int arg__1)
int c_static_TestTargetNS__MyBaseClass__anotherOverloadedStatic_int(int arg__1);
// TestTargetNS::MyBaseClass::bar() const
int c_TestTargetNS__MyBaseClass__bar(void *thisObj);
// TestTargetNS::MyBaseClass::bar2() const
int c_TestTargetNS__MyBaseClass__bar2(void *thisObj);
// TestTargetNS::MyBaseClass::callsVirtual() const
int c_TestTargetNS__MyBaseClass__callsVirtual(void *thisObj);
// TestTargetNS::MyBaseClass::foo() const
int c_TestTargetNS__MyBaseClass__foo(void *thisObj);
// TestTargetNS::MyBaseClass::getBool(int arg__1) const
bool c_TestTargetNS__MyBaseClass__getBool_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::getBoolFalse() const
bool c_TestTargetNS__MyBaseClass__getBoolFalse(void *thisObj);
// TestTargetNS::MyBaseClass::getBoolTrue() const
bool c_TestTargetNS__MyBaseClass__getBoolTrue(void *thisObj);
// TestTargetNS::MyBaseClass::hello()
void c_TestTargetNS__MyBaseClass__hello(void *thisObj);
// TestTargetNS::MyBaseClass::methodReturnsIntTemplate()
void *c_TestTargetNS__MyBaseClass__methodReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyBaseClass::nonVirtualButOverridden() const
int c_TestTargetNS__MyBaseClass__nonVirtualButOverridden(void *thisObj);
// TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(int i) const
int c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int(void *thisObj, int i);
// TestTargetNS::MyBaseClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const
int c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj, int i,
                                                                             int j);
// TestTargetNS::MyBaseClass::nonVirtualReturningStruct() const
void *c_TestTargetNS__MyBaseClass__nonVirtualReturningStruct(void *thisObj);
// TestTargetNS::MyBaseClass::overloadedStatic()
void c_static_TestTargetNS__MyBaseClass__overloadedStatic();
// TestTargetNS::MyBaseClass::overloadedStatic(int arg__1)
void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int(int arg__1);
// TestTargetNS::MyBaseClass::overloadedStatic(int arg__1, int arg__2)
void c_static_TestTargetNS__MyBaseClass__overloadedStatic_int_int(int arg__1, int arg__2);
// TestTargetNS::MyBaseClass::print(const char * msg)
void c_static_TestTargetNS__MyBaseClass__print_char(const char *msg);
// TestTargetNS::MyBaseClass::push(const char * arg__1)
void c_TestTargetNS__MyBaseClass__push_char(void *thisObj, const char *arg__1);
// TestTargetNS::MyBaseClass::receivesAndReturnsQString(const QString & s)
void *c_TestTargetNS__MyBaseClass__receivesAndReturnsQString_QString(void *thisObj, const char *s_);
// TestTargetNS::MyBaseClass::receivesEnum(TestTargetNS::MyBaseClass::MyEnum e)
int c_TestTargetNS__MyBaseClass__receivesEnum_MyEnum(void *thisObj, int e);
// TestTargetNS::MyBaseClass::receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1)
void c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArg_MyEnum(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum
// arg__1)
void c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArgNull_MyEnum(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesFloat(float arg__1)
void c_TestTargetNS__MyBaseClass__receivesFloat_float(void *thisObj, float arg__1);
// TestTargetNS::MyBaseClass::receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1)
void c_TestTargetNS__MyBaseClass__receivesQFlags_NamespaceLevelEnums(void *thisObj, int arg__1_);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg2(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg2_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::receivesintWithDefaultEnumArg3(int arg__1)
void c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg3_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::renamedMethod1()
void c_TestTargetNS__MyBaseClass__renamedMethod2(void *thisObj);
// TestTargetNS::MyBaseClass::renamedVirtual1()
void c_TestTargetNS__MyBaseClass__renamedVirtual2(void *thisObj);
// TestTargetNS::MyBaseClass::returnsConstChar()
const char *c_static_TestTargetNS__MyBaseClass__returnsConstChar();
// TestTargetNS::MyBaseClass::returnsDoubleTemplate()
void *c_static_TestTargetNS__MyBaseClass__returnsDoubleTemplate();
// TestTargetNS::MyBaseClass::returnsInt64() const
qint64 c_TestTargetNS__MyBaseClass__returnsInt64(void *thisObj);
// TestTargetNS::MyBaseClass::returnsIntTemplate()
void *c_static_TestTargetNS__MyBaseClass__returnsIntTemplate();
// TestTargetNS::MyBaseClass::returnsListOfStructPtr()
void *c_static_TestTargetNS__MyBaseClass__returnsListOfStructPtr();
// TestTargetNS::MyBaseClass::returnsQFlags() const
int c_TestTargetNS__MyBaseClass__returnsQFlags(void *thisObj);
// TestTargetNS::MyBaseClass::returnsQString()
void *c_static_TestTargetNS__MyBaseClass__returnsQString();
// TestTargetNS::MyBaseClass::returnsReals() const
void *c_TestTargetNS__MyBaseClass__returnsReals(void *thisObj);
// TestTargetNS::MyBaseClass::returnsSimpleStruct(int value)
void *c_static_TestTargetNS__MyBaseClass__returnsSimpleStruct_int(int value);
// TestTargetNS::MyBaseClass::returnsTemplateWithTwoArgs()
void *c_static_TestTargetNS__MyBaseClass__returnsTemplateWithTwoArgs();
// TestTargetNS::MyBaseClass::returnsVector()
void *c_TestTargetNS__MyBaseClass__returnsVector(void *thisObj);
// TestTargetNS::MyBaseClass::setBool(bool b)
bool c_TestTargetNS__MyBaseClass__setBool_bool(void *thisObj, bool b);
// TestTargetNS::MyBaseClass::sum(int a, int b)
int c_TestTargetNS__MyBaseClass__sum_int_int(void *thisObj, int a, int b);
// TestTargetNS::MyBaseClass::virtualReceivingBool(bool b)
int c_TestTargetNS__MyBaseClass__virtualReceivingBool_bool(void *thisObj, bool b);
// TestTargetNS::MyBaseClass::virtualReceivingCharPtr(char * arg__1)
void c_TestTargetNS__MyBaseClass__virtualReceivingCharPtr_char(void *thisObj, char *arg__1);
// TestTargetNS::MyBaseClass::virtualReceivingInt(int arg__1)
int c_TestTargetNS__MyBaseClass__virtualReceivingInt_int(void *thisObj, int arg__1);
// TestTargetNS::MyBaseClass::virtualReceivingOptionalArgument(int optional)
int c_TestTargetNS__MyBaseClass__virtualReceivingOptionalArgument_int(void *thisObj, int optional);
// TestTargetNS::MyBaseClass::virtualReturningBool(bool b)
bool c_TestTargetNS__MyBaseClass__virtualReturningBool_bool(void *thisObj, bool b);
// TestTargetNS::MyBaseClass::virtualReturningQint64()
qint64 c_TestTargetNS__MyBaseClass__virtualReturningQint64(void *thisObj);
// TestTargetNS::MyBaseClass::virtualReturningStruct() const
void *c_TestTargetNS__MyBaseClass__virtualReturningStruct(void *thisObj);
// TestTargetNS::MyBaseClass::virtualReturnsIntTemplate()
void *c_TestTargetNS__MyBaseClass__virtualReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyBaseClass::virtualWithNoDefaultArgumentInDerived(int optional)
void c_TestTargetNS__MyBaseClass__virtualWithNoDefaultArgumentInDerived_int(void *thisObj,
                                                                            int optional);
// TestTargetNS::MyBaseClass::virtualWithOverload(int i) const
void c_TestTargetNS__MyBaseClass__virtualWithOverload_int(void *thisObj, int i);
// TestTargetNS::MyBaseClass::virtualWithOverload(int i, int j) const
void c_TestTargetNS__MyBaseClass__virtualWithOverload_int_int(void *thisObj, int i, int j);
void c_TestTargetNS__MyBaseClass__destructor(void *thisObj);
int c_static_TestTargetNS__MyBaseClass___get_s_instanceCount();
int c_static_TestTargetNS__MyBaseClass___get_s_staticMember();
int c_static_TestTargetNS__MyBaseClass___get_s_staticConstMember();
void c_static_TestTargetNS__MyBaseClass___set_s_instanceCount_int(int s_instanceCount_);
void c_static_TestTargetNS__MyBaseClass___set_s_staticMember_int(int s_staticMember_);
void c_TestTargetNS__MyBaseClass__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                int methodId);
void c_TestTargetNS__MyBaseClass_Finalizer(
    void *cppObj); // TestTargetNS::MyDerivedClass::MyDerivedClass()
void *c_TestTargetNS__MyDerivedClass__constructor();
// TestTargetNS::MyDerivedClass::alsoCallsVirtual()
int c_TestTargetNS__MyDerivedClass__alsoCallsVirtual(void *thisObj);
// TestTargetNS::MyDerivedClass::anotherOverloadedStatic(int arg__1)
void *c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int(int arg__1);
// TestTargetNS::MyDerivedClass::anotherOverloadedStatic(int arg__1, int arg__2)
void *c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int_int(int arg__1,
                                                                             int arg__2);
// TestTargetNS::MyDerivedClass::bar() const
int c_TestTargetNS__MyDerivedClass__bar(void *thisObj);
// TestTargetNS::MyDerivedClass::bar2() const
int c_TestTargetNS__MyDerivedClass__bar2(void *thisObj);
// TestTargetNS::MyDerivedClass::nonVirtualButOverridden() const
int c_TestTargetNS__MyDerivedClass__nonVirtualButOverridden(void *thisObj);
// TestTargetNS::MyDerivedClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const
int c_TestTargetNS__MyDerivedClass__nonVirtualInBaseButVirtualInDerived_int_int(void *thisObj,
                                                                                int i, int j);
// TestTargetNS::MyDerivedClass::paintEvent()
void c_TestTargetNS__MyDerivedClass__paintEvent(void *thisObj);
// TestTargetNS::MyDerivedClass::receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass * der)
int c_TestTargetNS__MyDerivedClass__receivesDerivedPolymorphic_MyDerivedClass(void *thisObj,
                                                                              void *der_);
// TestTargetNS::MyDerivedClass::receivesEnumFromBaseClassWithDefaultValue(int a)
void c_TestTargetNS__MyDerivedClass__receivesEnumFromBaseClassWithDefaultValue_int(void *thisObj,
                                                                                   int a);
// TestTargetNS::MyDerivedClass::receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p)
int c_TestTargetNS__MyDerivedClass__receivesProtectedEnum_ProtectedEnum(void *thisObj, int p);
// TestTargetNS::MyDerivedClass::renamedVirtual1()
void c_TestTargetNS__MyDerivedClass__renamedVirtual2(void *thisObj);
// TestTargetNS::MyDerivedClass::returnTemplate1()
void *c_TestTargetNS__MyDerivedClass__returnTemplate1(void *thisObj);
// TestTargetNS::MyDerivedClass::returnTemplate2()
void *c_TestTargetNS__MyDerivedClass__returnTemplate2(void *thisObj);
// TestTargetNS::MyDerivedClass::returnsAnotherNamespaceEnum()
int c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceEnum();
// TestTargetNS::MyDerivedClass::returnsAnotherNamespaceStruct()
void *c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceStruct();
// TestTargetNS::MyDerivedClass::returnsConstPointer()
void *c_TestTargetNS__MyDerivedClass__returnsConstPointer(void *thisObj);
// TestTargetNS::MyDerivedClass::setVisible(bool b)
void c_TestTargetNS__MyDerivedClass__setVisible_bool(void *thisObj, bool b);
// TestTargetNS::MyDerivedClass::show()
void c_TestTargetNS__MyDerivedClass__show(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualNotInBase() const
int c_TestTargetNS__MyDerivedClass__virtualNotInBase(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReceivingBool(bool b)
int c_TestTargetNS__MyDerivedClass__virtualReceivingBool_bool(void *thisObj, bool b);
// TestTargetNS::MyDerivedClass::virtualReceivingCharPtr(char * arg__1)
void c_TestTargetNS__MyDerivedClass__virtualReceivingCharPtr_char(void *thisObj, char *arg__1);
// TestTargetNS::MyDerivedClass::virtualReceivingInt(int arg__1)
int c_TestTargetNS__MyDerivedClass__virtualReceivingInt_int(void *thisObj, int arg__1);
// TestTargetNS::MyDerivedClass::virtualReceivingOptionalArgument(int optional)
int c_TestTargetNS__MyDerivedClass__virtualReceivingOptionalArgument_int(void *thisObj,
                                                                         int optional);
// TestTargetNS::MyDerivedClass::virtualReturningBool(bool b)
bool c_TestTargetNS__MyDerivedClass__virtualReturningBool_bool(void *thisObj, bool b);
// TestTargetNS::MyDerivedClass::virtualReturningQint64()
qint64 c_TestTargetNS__MyDerivedClass__virtualReturningQint64(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReturningStruct() const
void *c_TestTargetNS__MyDerivedClass__virtualReturningStruct(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualReturnsIntTemplate()
void *c_TestTargetNS__MyDerivedClass__virtualReturnsIntTemplate(void *thisObj);
// TestTargetNS::MyDerivedClass::virtualWithOverload(int i) const
void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int(void *thisObj, int i);
// TestTargetNS::MyDerivedClass::virtualWithOverload(int i, int j) const
void c_TestTargetNS__MyDerivedClass__virtualWithOverload_int_int(void *thisObj, int i, int j);
void c_TestTargetNS__MyDerivedClass__destructor(void *thisObj);
int c_static_TestTargetNS__MyDerivedClass___get_s_instanceCount();
void c_static_TestTargetNS__MyDerivedClass___set_s_instanceCount_int(int s_instanceCount_);
void c_TestTargetNS__MyDerivedClass__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                   int methodId);
void c_TestTargetNS__MyDerivedClass_Finalizer(
    void *cppObj); // TestTargetNS::DestructorCounter::DestructorCounter()
void *c_TestTargetNS__DestructorCounter__constructor();
// TestTargetNS::DestructorCounter::instanceCount()
int c_static_TestTargetNS__DestructorCounter__instanceCount();
// TestTargetNS::DestructorCounter::newOnTheHeap()
void *c_static_TestTargetNS__DestructorCounter__newOnTheHeap();
// TestTargetNS::DestructorCounter::newOnTheStack()
void *c_static_TestTargetNS__DestructorCounter__newOnTheStack();
void c_TestTargetNS__DestructorCounter__destructor(void *thisObj);
int c_static_TestTargetNS__DestructorCounter___get_s_instanceCount();
void c_static_TestTargetNS__DestructorCounter___set_s_instanceCount_int(int s_instanceCount_);
void c_TestTargetNS__DestructorCounter_Finalizer(
    void *cppObj); // TestTargetNS::DerivedFromPureAbstract::DerivedFromPureAbstract()
void *c_TestTargetNS__DerivedFromPureAbstract__constructor();
// TestTargetNS::DerivedFromPureAbstract::DerivedFromPureAbstract(int arg__1)
void *c_TestTargetNS__DerivedFromPureAbstract__constructor_int(int arg__1);
// TestTargetNS::DerivedFromPureAbstract::foo()
int c_TestTargetNS__DerivedFromPureAbstract__foo(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::indirectionCallsVirtualReceivingStruct(SimpleStruct s)
int c_TestTargetNS__DerivedFromPureAbstract__indirectionCallsVirtualReceivingStruct_SimpleStruct(
    void *thisObj, void *s_);
// TestTargetNS::DerivedFromPureAbstract::nonVirtualCallsVirtual()
int c_TestTargetNS__DerivedFromPureAbstract__nonVirtualCallsVirtual(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::receivesValueStruct(SimpleStruct arg__1)
int c_TestTargetNS__DerivedFromPureAbstract__receivesValueStruct_SimpleStruct(void *thisObj,
                                                                              void *arg__1_);
// TestTargetNS::DerivedFromPureAbstract::renamedPureVirtual()
void c_TestTargetNS__DerivedFromPureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::DerivedFromPureAbstract::unnamedOverriddenDefaultArgCase(int arg__1)
void c_TestTargetNS__DerivedFromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                                  int arg__1);
// TestTargetNS::DerivedFromPureAbstract::virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__DerivedFromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                                  void *s_);
// TestTargetNS::DerivedFromPureAbstract::voidPureAbstract()
void c_TestTargetNS__DerivedFromPureAbstract__voidPureAbstract(void *thisObj);
void c_TestTargetNS__DerivedFromPureAbstract__destructor(void *thisObj);
void c_TestTargetNS__DerivedFromPureAbstract__registerVirtualMethodCallback(void *ptr,
                                                                            void *callback,
                                                                            int methodId);
void c_TestTargetNS__DerivedFromPureAbstract_Finalizer(
    void *cppObj); // TestTargetNS::Derived2FromPureAbstract::Derived2FromPureAbstract()
void *c_TestTargetNS__Derived2FromPureAbstract__constructor();
// TestTargetNS::Derived2FromPureAbstract::foo()
int c_TestTargetNS__Derived2FromPureAbstract__foo(void *thisObj);
// TestTargetNS::Derived2FromPureAbstract::renamedPureVirtual()
void c_TestTargetNS__Derived2FromPureAbstract__renamedPureVirtual1(void *thisObj);
// TestTargetNS::Derived2FromPureAbstract::unnamedOverriddenDefaultArgCase(int myarg)
void c_TestTargetNS__Derived2FromPureAbstract__unnamedOverriddenDefaultArgCase_int(void *thisObj,
                                                                                   int myarg);
// TestTargetNS::Derived2FromPureAbstract::virtualReceivingPointer(SimpleStruct * s)
int c_TestTargetNS__Derived2FromPureAbstract__virtualReceivingPointer_SimpleStruct(void *thisObj,
                                                                                   void *s_);
// TestTargetNS::Derived2FromPureAbstract::voidPureAbstract()
void c_TestTargetNS__Derived2FromPureAbstract__voidPureAbstract(void *thisObj);
void c_TestTargetNS__Derived2FromPureAbstract__destructor(void *thisObj);
void c_TestTargetNS__Derived2FromPureAbstract__registerVirtualMethodCallback(void *ptr,
                                                                             void *callback,
                                                                             int methodId);
void c_TestTargetNS__Derived2FromPureAbstract_Finalizer(
    void *cppObj); // SimpleStruct::SimpleStruct()
void *c_SimpleStruct__constructor();
void c_SimpleStruct__destructor(void *thisObj);
int c_SimpleStruct___get_value(void *thisObj);
void c_SimpleStruct___set_value_int(void *thisObj, int value_);
void c_SimpleStruct_Finalizer(void *cppObj); // SimpleObjectStruct::SimpleObjectStruct()
void *c_SimpleObjectStruct__constructor();
// SimpleObjectStruct::receivesStructWithDefaultArg(SimpleObjectStruct arg__1)
void c_SimpleObjectStruct__receivesStructWithDefaultArg_SimpleObjectStruct(void *thisObj,
                                                                           void *arg__1_);
void c_SimpleObjectStruct__destructor(void *thisObj);
void c_SimpleObjectStruct_Finalizer(void *cppObj);
void c_Qt_Finalizer(void *cppObj); // QVariant::QVariant()
void *c_QVariant__constructor();
// QVariant::QVariant(bool b)
void *c_QVariant__constructor_bool(bool b);
// QVariant::QVariant(const QByteArray & bytearray)
void *c_QVariant__constructor_QByteArray(void *bytearray_);
// QVariant::QVariant(const QHash<QString,QVariant > & hash)
void *c_QVariant__constructor_QHash_QString_QVariant(void *hash_);
// QVariant::QVariant(const QList<QString > & stringlist)
void *c_QVariant__constructor_QList_QString(void *stringlist_);
// QVariant::QVariant(const QList<QVariant > & list)
void *c_QVariant__constructor_QList_QVariant(void *list_);
// QVariant::QVariant(const QMap<QString,QVariant > & map)
void *c_QVariant__constructor_QMap_QString_QVariant(void *map_);
// QVariant::QVariant(const QString & string)
void *c_QVariant__constructor_QString(const char *string_);
// QVariant::QVariant(const char * str)
void *c_QVariant__constructor_char(const char *str);
// QVariant::QVariant(double d)
void *c_QVariant__constructor_double(double d);
// QVariant::QVariant(float f)
void *c_QVariant__constructor_float(float f);
// QVariant::QVariant(int i)
void *c_QVariant__constructor_int(int i);
// QVariant::QVariant(qint64 ll)
void *c_QVariant__constructor_qint64(qint64 ll);
// QVariant::clear()
void c_QVariant__clear(void *thisObj);
// QVariant::detach()
void c_QVariant__detach(void *thisObj);
// QVariant::equals(const QVariant & other) const
bool c_QVariant__equals_QVariant(void *thisObj, void *other_);
// QVariant::fromObject(QObject * arg__1)
void *c_static_QVariant__fromObject_QObject(void *arg__1_);
// QVariant::isDetached() const
bool c_QVariant__isDetached(void *thisObj);
// QVariant::isNull() const
bool c_QVariant__isNull(void *thisObj);
// QVariant::isValid() const
bool c_QVariant__isValid(void *thisObj);
// QVariant::setValue(const QVariant & avalue)
void c_QVariant__setValue_QVariant(void *thisObj, void *avalue_);
// QVariant::toBool() const
bool c_QVariant__toBool(void *thisObj);
// QVariant::toByteArray() const
void *c_QVariant__toByteArray(void *thisObj);
// QVariant::toHash() const
void *c_QVariant__toHash(void *thisObj);
// QVariant::toList() const
void *c_QVariant__toList(void *thisObj);
// QVariant::toMap() const
void *c_QVariant__toMap(void *thisObj);
// QVariant::toStringList() const
void *c_QVariant__toStringList(void *thisObj);
// QVariant::typeId() const
int c_QVariant__typeId(void *thisObj);
// QVariant::typeName() const
const char *c_QVariant__typeName(void *thisObj);
// QVariant::userType() const
int c_QVariant__userType(void *thisObj);
void c_QVariant__destructor(void *thisObj);
void c_QVariant_Finalizer(void *cppObj); // QString::QString()
void *c_QString__constructor();
// QString::QString(const QByteArray & a)
void *c_QString__constructor_QByteArray(void *a_);
// QString::QString(const char * ch)
void *c_QString__constructor_char(const char *ch);
// QString::append(const QByteArray & s)
void *c_QString__append_QByteArray(void *thisObj, void *s_);
// QString::append(const QString & s)
void *c_QString__append_QString(void *thisObj, const char *s_);
// QString::append(const char * s)
void *c_QString__append_char(void *thisObj, const char *s);
// QString::arg(const QString & a, int fieldWidth) const
void *c_QString__arg_QString_int(void *thisObj, const char *a_, int fieldWidth);
// QString::arg(int a, int fieldWidth, int base) const
void *c_QString__arg_int_int_int(void *thisObj, int a, int fieldWidth, int base);
// QString::arg(long a, int fieldwidth, int base) const
void *c_QString__arg_long_int_int(void *thisObj, long a, int fieldwidth, int base);
// QString::arg(qint64 a, int fieldwidth, int base) const
void *c_QString__arg_qint64_int_int(void *thisObj, qint64 a, int fieldwidth, int base);
// QString::arg(short a, int fieldWidth, int base) const
void *c_QString__arg_short_int_int(void *thisObj, short a, int fieldWidth, int base);
// QString::asprintf(const char * format)
void *c_static_QString__asprintf_char(const char *format);
// QString::capacity() const
qsizetype c_QString__capacity(void *thisObj);
// QString::chop(qsizetype n)
void c_QString__chop_qsizetype(void *thisObj, qsizetype n);
// QString::chopped(qsizetype n) const
void *c_QString__chopped_qsizetype(void *thisObj, qsizetype n);
// QString::clear()
void c_QString__clear(void *thisObj);
// QString::compare(const QString & s) const
int c_QString__compare_QString(void *thisObj, const char *s_);
// QString::compare(const QString & s1, const QString & s2)
int c_static_QString__compare_QString_QString(const char *s1_, const char *s2_);
// QString::contains(const QString & s) const
bool c_QString__contains_QString(void *thisObj, const char *s_);
// QString::count() const
qsizetype c_QString__count(void *thisObj);
// QString::count(const QString & s) const
qsizetype c_QString__count_QString(void *thisObj, const char *s_);
// QString::detach()
void c_QString__detach(void *thisObj);
// QString::endsWith(const QString & s) const
bool c_QString__endsWith_QString(void *thisObj, const char *s_);
// QString::first(qsizetype n) const
void *c_QString__first_qsizetype(void *thisObj, qsizetype n);
// QString::fromLatin1(const char * str, qsizetype size)
void *c_static_QString__fromLatin1_char_qsizetype(const char *str, qsizetype size);
// QString::fromLocal8Bit(const char * str, qsizetype size)
void *c_static_QString__fromLocal8Bit_char_qsizetype(const char *str, qsizetype size);
// QString::fromUtf8(const char * utf8, qsizetype size)
void *c_static_QString__fromUtf8_char_qsizetype(const char *utf8, qsizetype size);
// QString::indexOf(const QString & s, qsizetype from) const
qsizetype c_QString__indexOf_QString_qsizetype(void *thisObj, const char *s_, qsizetype from);
// QString::insert(qsizetype i, const QByteArray & s)
void *c_QString__insert_qsizetype_QByteArray(void *thisObj, qsizetype i, void *s_);
// QString::insert(qsizetype i, const QString & s)
void *c_QString__insert_qsizetype_QString(void *thisObj, qsizetype i, const char *s_);
// QString::insert(qsizetype i, const char * s)
void *c_QString__insert_qsizetype_char(void *thisObj, qsizetype i, const char *s);
// QString::isDetached() const
bool c_QString__isDetached(void *thisObj);
// QString::isEmpty() const
bool c_QString__isEmpty(void *thisObj);
// QString::isLower() const
bool c_QString__isLower(void *thisObj);
// QString::isNull() const
bool c_QString__isNull(void *thisObj);
// QString::isRightToLeft() const
bool c_QString__isRightToLeft(void *thisObj);
// QString::isSharedWith(const QString & other) const
bool c_QString__isSharedWith_QString(void *thisObj, const char *other_);
// QString::isSimpleText() const
bool c_QString__isSimpleText(void *thisObj);
// QString::isUpper() const
bool c_QString__isUpper(void *thisObj);
// QString::isValidUtf16() const
bool c_QString__isValidUtf16(void *thisObj);
// QString::last(qsizetype n) const
void *c_QString__last_qsizetype(void *thisObj, qsizetype n);
// QString::lastIndexOf(const QString & s) const
qsizetype c_QString__lastIndexOf_QString(void *thisObj, const char *s_);
// QString::lastIndexOf(const QString & s, qsizetype from) const
qsizetype c_QString__lastIndexOf_QString_qsizetype(void *thisObj, const char *s_, qsizetype from);
// QString::left(qsizetype n) const
void *c_QString__left_qsizetype(void *thisObj, qsizetype n);
// QString::leftJustified(qsizetype width) const
void *c_QString__leftJustified_qsizetype(void *thisObj, qsizetype width);
// QString::length() const
qsizetype c_QString__length(void *thisObj);
// QString::localeAwareCompare(const QString & s) const
int c_QString__localeAwareCompare_QString(void *thisObj, const char *s_);
// QString::localeAwareCompare(const QString & s1, const QString & s2)
int c_static_QString__localeAwareCompare_QString_QString(const char *s1_, const char *s2_);
// QString::mid(qsizetype position, qsizetype n) const
void *c_QString__mid_qsizetype_qsizetype(void *thisObj, qsizetype position, qsizetype n);
// QString::number(int arg__1, int base)
void *c_static_QString__number_int_int(int arg__1, int base);
// QString::number(long arg__1, int base)
void *c_static_QString__number_long_int(long arg__1, int base);
// QString::number(qint64 arg__1, int base)
void *c_static_QString__number_qint64_int(qint64 arg__1, int base);
// QString::prepend(const QByteArray & s)
void *c_QString__prepend_QByteArray(void *thisObj, void *s_);
// QString::prepend(const QString & s)
void *c_QString__prepend_QString(void *thisObj, const char *s_);
// QString::prepend(const char * s)
void *c_QString__prepend_char(void *thisObj, const char *s);
// QString::push_back(const QString & s)
void c_QString__push_back_QString(void *thisObj, const char *s_);
// QString::push_front(const QString & s)
void c_QString__push_front_QString(void *thisObj, const char *s_);
// QString::remove(const QString & s)
void *c_QString__remove_QString(void *thisObj, const char *s_);
// QString::remove(qsizetype i, qsizetype len)
void *c_QString__remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype len);
// QString::repeated(qsizetype times) const
void *c_QString__repeated_qsizetype(void *thisObj, qsizetype times);
// QString::replace(const QString & before, const QString & after)
void *c_QString__replace_QString_QString(void *thisObj, const char *before_, const char *after_);
// QString::replace(qsizetype i, qsizetype len, const QString & after)
void *c_QString__replace_qsizetype_qsizetype_QString(void *thisObj, qsizetype i, qsizetype len,
                                                     const char *after_);
// QString::reserve(qsizetype size)
void c_QString__reserve_qsizetype(void *thisObj, qsizetype size);
// QString::resize(qsizetype size)
void c_QString__resize_qsizetype(void *thisObj, qsizetype size);
// QString::right(qsizetype n) const
void *c_QString__right_qsizetype(void *thisObj, qsizetype n);
// QString::rightJustified(qsizetype width) const
void *c_QString__rightJustified_qsizetype(void *thisObj, qsizetype width);
// QString::section(const QString & in_sep, qsizetype start, qsizetype end) const
void *c_QString__section_QString_qsizetype_qsizetype(void *thisObj, const char *in_sep_,
                                                     qsizetype start, qsizetype end);
// QString::setNum(int arg__1, int base)
void *c_QString__setNum_int_int(void *thisObj, int arg__1, int base);
// QString::setNum(long arg__1, int base)
void *c_QString__setNum_long_int(void *thisObj, long arg__1, int base);
// QString::setNum(qint64 arg__1, int base)
void *c_QString__setNum_qint64_int(void *thisObj, qint64 arg__1, int base);
// QString::setNum(short arg__1, int base)
void *c_QString__setNum_short_int(void *thisObj, short arg__1, int base);
// QString::shrink_to_fit()
void c_QString__shrink_to_fit(void *thisObj);
// QString::simplified()
void *c_QString__simplified(void *thisObj);
// QString::size() const
qsizetype c_QString__size(void *thisObj);
// QString::sliced(qsizetype pos) const
void *c_QString__sliced_qsizetype(void *thisObj, qsizetype pos);
// QString::sliced(qsizetype pos, qsizetype n) const
void *c_QString__sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QString::split(const QString & sep) const
void *c_QString__split_QString(void *thisObj, const char *sep_);
// QString::squeeze()
void c_QString__squeeze(void *thisObj);
// QString::startsWith(const QString & s) const
bool c_QString__startsWith_QString(void *thisObj, const char *s_);
// QString::toCaseFolded()
void *c_QString__toCaseFolded(void *thisObj);
// QString::toHtmlEscaped() const
void *c_QString__toHtmlEscaped(void *thisObj);
// QString::toLatin1()
void *c_QString__toLatin1(void *thisObj);
// QString::toLocal8Bit()
void *c_QString__toLocal8Bit(void *thisObj);
// QString::toLower()
void *c_QString__toLower(void *thisObj);
// QString::toUcs4() const
void *c_QString__toUcs4(void *thisObj);
// QString::toUpper()
void *c_QString__toUpper(void *thisObj);
// QString::toUtf8()
void *c_QString__toUtf8(void *thisObj);
// QString::trimmed()
void *c_QString__trimmed(void *thisObj);
// QString::truncate(qsizetype pos)
void c_QString__truncate_qsizetype(void *thisObj, qsizetype pos);
void c_QString__destructor(void *thisObj);
void c_QString_Finalizer(void *cppObj); // QObject::QObject(QObject * parent)
void *c_QObject__constructor_QObject(void *parent_);
// QObject::blockSignals(bool b)
bool c_QObject__blockSignals_bool(void *thisObj, bool b);
// QObject::children() const
void *c_QObject__children(void *thisObj);
// QObject::customEvent(QEvent * event)
void c_QObject__customEvent_QEvent(void *thisObj, void *event_);
// QObject::deleteLater()
void c_QObject__deleteLater(void *thisObj);
// QObject::destroyed(QObject * arg__1)
void c_QObject__destroyed_QObject(void *thisObj, void *arg__1_);
void c_QObject__onDestroyed_QObject(void *thisObj, void *contextQObject,
                                    void *callback); // QObject::disconnect(const QObject *
                                                     // receiver, const char * member) const
bool c_QObject__disconnect_QObject_char(void *thisObj, void *receiver_, const char *member);
// QObject::disconnect(const QObject * sender, const char * signal, const QObject * receiver, const
// char * member)
bool c_static_QObject__disconnect_QObject_char_QObject_char(void *sender_, const char *signal,
                                                            void *receiver_, const char *member);
// QObject::disconnect(const char * signal, const QObject * receiver, const char * member) const
bool c_QObject__disconnect_char_QObject_char(void *thisObj, const char *signal, void *receiver_,
                                             const char *member);
// QObject::dumpObjectInfo() const
void c_QObject__dumpObjectInfo(void *thisObj);
// QObject::dumpObjectTree() const
void c_QObject__dumpObjectTree(void *thisObj);
// QObject::dynamicPropertyNames() const
void *c_QObject__dynamicPropertyNames(void *thisObj);
// QObject::event(QEvent * event)
bool c_QObject__event_QEvent(void *thisObj, void *event_);
// QObject::eventFilter(QObject * watched, QEvent * event)
bool c_QObject__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// QObject::inherits(const char * classname) const
bool c_QObject__inherits_char(void *thisObj, const char *classname);
// QObject::installEventFilter(QObject * filterObj)
void c_QObject__installEventFilter_QObject(void *thisObj, void *filterObj_);
// QObject::isWidgetType() const
bool c_QObject__isWidgetType(void *thisObj);
// QObject::isWindowType() const
bool c_QObject__isWindowType(void *thisObj);
// QObject::killTimer(int id)
void c_QObject__killTimer_int(void *thisObj, int id);
// QObject::objectName() const
void *c_QObject__objectName(void *thisObj);
// QObject::parent() const
void *c_QObject__parent(void *thisObj);
// QObject::property(const char * name) const
void *c_QObject__property_char(void *thisObj, const char *name);
// QObject::receivers(const char * signal) const
int c_QObject__receivers_char(void *thisObj, const char *signal);
// QObject::removeEventFilter(QObject * obj)
void c_QObject__removeEventFilter_QObject(void *thisObj, void *obj_);
// QObject::sender() const
void *c_QObject__sender(void *thisObj);
// QObject::senderSignalIndex() const
int c_QObject__senderSignalIndex(void *thisObj);
// QObject::setObjectName(const QString & name)
void c_QObject__setObjectName_QString(void *thisObj, const char *name_);
// QObject::setParent(QObject * parent)
void c_QObject__setParent_QObject(void *thisObj, void *parent_);
// QObject::setProperty(const char * name, const QVariant & value)
bool c_QObject__setProperty_char_QVariant(void *thisObj, const char *name, void *value_);
// QObject::signalsBlocked() const
bool c_QObject__signalsBlocked(void *thisObj);
// QObject::startTimer(int interval)
int c_QObject__startTimer_int(void *thisObj, int interval);
// QObject::tr(const char * s, const char * c, int n)
void *c_static_QObject__tr_char_char_int(const char *s, const char *c, int n);
void c_QObject__destructor(void *thisObj);
void c_QObject__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_QObject_Finalizer(void *cppObj); // QMap::QMap<Key, T>()
void *c_QMap_T_QString_QVariant_T___constructor();
// QMap::clear()
void c_QMap_T_QString_QVariant_T___clear(void *thisObj);
// QMap::contains(const Key & key) const
bool c_QMap_T_QString_QVariant_T___contains_QString(void *thisObj, const char *key_);
// QMap::detach()
void c_QMap_T_QString_QVariant_T___detach(void *thisObj);
// QMap::empty() const
bool c_QMap_T_QString_QVariant_T___empty(void *thisObj);
// QMap::first()
void *c_QMap_T_QString_QVariant_T___first(void *thisObj);
// QMap::firstKey() const
const void *c_QMap_T_QString_QVariant_T___firstKey(void *thisObj);
// QMap::insert(const QMap<Key,T > & map)
void c_QMap_T_QString_QVariant_T___insert_QMap_Key_T(void *thisObj, void *map_);
// QMap::isDetached() const
bool c_QMap_T_QString_QVariant_T___isDetached(void *thisObj);
// QMap::isEmpty() const
bool c_QMap_T_QString_QVariant_T___isEmpty(void *thisObj);
// QMap::isSharedWith(const QMap<Key,T > & other) const
bool c_QMap_T_QString_QVariant_T___isSharedWith_QMap_Key_T(void *thisObj, void *other_);
// QMap::key(const T & value, const Key & defaultKey) const
void *c_QMap_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
                                                         const char *defaultKey_);
// QMap::keys() const
void *c_QMap_T_QString_QVariant_T___keys(void *thisObj);
// QMap::keys(const T & value) const
void *c_QMap_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_);
// QMap::last()
void *c_QMap_T_QString_QVariant_T___last(void *thisObj);
// QMap::lastKey() const
const void *c_QMap_T_QString_QVariant_T___lastKey(void *thisObj);
// QMap::take(const Key & key)
void *c_QMap_T_QString_QVariant_T___take_QString(void *thisObj, const char *key_);
// QMap::value(const Key & key, const T & defaultValue) const
void *c_QMap_T_QString_QVariant_T___value_QString_QVariant(void *thisObj, const char *key_,
                                                           void *defaultValue_);
// QMap::values() const
void *c_QMap_T_QString_QVariant_T___values(void *thisObj);
void c_QMap_T_QString_QVariant_T___destructor(void *thisObj);
void c_QMap_T_QString_QVariant_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_SimpleStruct_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_SimpleStruct_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_SimpleStruct_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const void *c_QList_T_SimpleStruct_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
void *c_QList_T_SimpleStruct_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_SimpleStruct_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_SimpleStruct_T___clear(void *thisObj);
// QList::constFirst() const
const void *c_QList_T_SimpleStruct_T___constFirst(void *thisObj);
// QList::constLast() const
const void *c_QList_T_SimpleStruct_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_SimpleStruct_T___count(void *thisObj);
// QList::detach()
void c_QList_T_SimpleStruct_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_SimpleStruct_T___empty(void *thisObj);
// QList::first()
void *c_QList_T_SimpleStruct_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_SimpleStruct_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
void *c_QList_T_SimpleStruct_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_SimpleStruct_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_SimpleStruct_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_SimpleStruct_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
void *c_QList_T_SimpleStruct_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_SimpleStruct_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_SimpleStruct_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_SimpleStruct_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                         qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_SimpleStruct_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                         qsizetype to);
// QList::pop_back()
void c_QList_T_SimpleStruct_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_SimpleStruct_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_SimpleStruct_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_SimpleStruct_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_SimpleStruct_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_SimpleStruct_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_SimpleStruct_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_SimpleStruct_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_SimpleStruct_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_SimpleStruct_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_SimpleStruct_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_SimpleStruct_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                            qsizetype n);
// QList::squeeze()
void c_QList_T_SimpleStruct_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_SimpleStruct_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                qsizetype j);
// QList::takeAt(qsizetype i)
void *c_QList_T_SimpleStruct_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_SimpleStruct_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_SimpleStruct_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
void *c_QList_T_SimpleStruct_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_SimpleStruct_T___destructor(void *thisObj);
void c_QList_T_SimpleStruct_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_qreal_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_qreal_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_qreal_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const qreal c_QList_T_qreal_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
qreal c_QList_T_qreal_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_qreal_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_qreal_T___clear(void *thisObj);
// QList::constFirst() const
const qreal c_QList_T_qreal_T___constFirst(void *thisObj);
// QList::constLast() const
const qreal c_QList_T_qreal_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_qreal_T___count(void *thisObj);
// QList::detach()
void c_QList_T_qreal_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_qreal_T___empty(void *thisObj);
// QList::first()
qreal c_QList_T_qreal_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_qreal_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
qreal c_QList_T_qreal_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_qreal_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_qreal_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_qreal_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
qreal c_QList_T_qreal_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_qreal_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_qreal_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_qreal_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_qreal_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_qreal_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_qreal_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_qreal_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_qreal_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_qreal_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_qreal_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_qreal_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_qreal_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_qreal_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_qreal_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_qreal_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_qreal_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
void c_QList_T_qreal_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_qreal_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
qreal c_QList_T_qreal_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_qreal_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_qreal_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
qreal c_QList_T_qreal_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_qreal_T___destructor(void *thisObj);
void c_QList_T_qreal_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_int_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_int_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_int_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const int c_QList_T_int_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
int c_QList_T_int_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_int_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_int_T___clear(void *thisObj);
// QList::constFirst() const
const int c_QList_T_int_T___constFirst(void *thisObj);
// QList::constLast() const
const int c_QList_T_int_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_int_T___count(void *thisObj);
// QList::detach()
void c_QList_T_int_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_int_T___empty(void *thisObj);
// QList::first()
int c_QList_T_int_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_int_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
int c_QList_T_int_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_int_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_int_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_int_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
int c_QList_T_int_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_int_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_int_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_int_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_int_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_int_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_int_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_int_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_int_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_int_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_int_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_int_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_int_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
void c_QList_T_int_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
int c_QList_T_int_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_int_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_int_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
int c_QList_T_int_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_int_T___destructor(void *thisObj);
void c_QList_T_int_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_QVariant_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_QVariant_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_QVariant_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const void *c_QList_T_QVariant_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
void *c_QList_T_QVariant_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_QVariant_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_QVariant_T___clear(void *thisObj);
// QList::constFirst() const
const void *c_QList_T_QVariant_T___constFirst(void *thisObj);
// QList::constLast() const
const void *c_QList_T_QVariant_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_QVariant_T___count(void *thisObj);
// QList::detach()
void c_QList_T_QVariant_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_QVariant_T___empty(void *thisObj);
// QList::first()
void *c_QList_T_QVariant_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_QVariant_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
void *c_QList_T_QVariant_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_QVariant_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_QVariant_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_QVariant_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
void *c_QList_T_QVariant_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_QVariant_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_QVariant_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QVariant_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_QVariant_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_QVariant_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_QVariant_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_QVariant_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_QVariant_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_QVariant_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_QVariant_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_QVariant_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_QVariant_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_QVariant_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_QVariant_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_QVariant_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QVariant_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
void c_QList_T_QVariant_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QVariant_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                            qsizetype j);
// QList::takeAt(qsizetype i)
void *c_QList_T_QVariant_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_QVariant_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_QVariant_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
void *c_QList_T_QVariant_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_QVariant_T___destructor(void *thisObj);
void c_QList_T_QVariant_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_QString_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_QString_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_QString_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const void *c_QList_T_QString_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
void *c_QList_T_QString_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_QString_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_QString_T___clear(void *thisObj);
// QList::constFirst() const
const void *c_QList_T_QString_T___constFirst(void *thisObj);
// QList::constLast() const
const void *c_QList_T_QString_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_QString_T___count(void *thisObj);
// QList::detach()
void c_QList_T_QString_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_QString_T___empty(void *thisObj);
// QList::first()
void *c_QList_T_QString_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_QString_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
void *c_QList_T_QString_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_QString_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_QString_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_QString_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
void *c_QList_T_QString_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_QString_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_QString_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QString_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_QString_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_QString_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_QString_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_QString_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_QString_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_QString_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_QString_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_QString_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_QString_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_QString_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_QString_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_QString_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QString_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
void c_QList_T_QString_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QString_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
void *c_QList_T_QString_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_QString_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_QString_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
void *c_QList_T_QString_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_QString_T___destructor(void *thisObj);
void c_QList_T_QString_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_unsigned_int_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_unsigned_int_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_unsigned_int_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const unsigned int c_QList_T_unsigned_int_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
unsigned int c_QList_T_unsigned_int_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_unsigned_int_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_unsigned_int_T___clear(void *thisObj);
// QList::constFirst() const
const unsigned int c_QList_T_unsigned_int_T___constFirst(void *thisObj);
// QList::constLast() const
const unsigned int c_QList_T_unsigned_int_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_unsigned_int_T___count(void *thisObj);
// QList::detach()
void c_QList_T_unsigned_int_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_unsigned_int_T___empty(void *thisObj);
// QList::first()
unsigned int c_QList_T_unsigned_int_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_unsigned_int_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
unsigned int c_QList_T_unsigned_int_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_unsigned_int_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_unsigned_int_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_unsigned_int_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
unsigned int c_QList_T_unsigned_int_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_unsigned_int_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_unsigned_int_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_unsigned_int_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                         qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_unsigned_int_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from,
                                                         qsizetype to);
// QList::pop_back()
void c_QList_T_unsigned_int_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_unsigned_int_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_unsigned_int_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_unsigned_int_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_unsigned_int_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_unsigned_int_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_unsigned_int_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_unsigned_int_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_unsigned_int_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_unsigned_int_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_unsigned_int_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_unsigned_int_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                            qsizetype n);
// QList::squeeze()
void c_QList_T_unsigned_int_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_unsigned_int_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                                qsizetype j);
// QList::takeAt(qsizetype i)
unsigned int c_QList_T_unsigned_int_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_unsigned_int_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_unsigned_int_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
unsigned int c_QList_T_unsigned_int_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_unsigned_int_T___destructor(void *thisObj);
void c_QList_T_unsigned_int_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_QObject_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_QObject_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_QObject_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const void *c_QList_T_QObject_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
void *c_QList_T_QObject_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_QObject_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_QObject_T___clear(void *thisObj);
// QList::constFirst() const
const void *c_QList_T_QObject_T___constFirst(void *thisObj);
// QList::constLast() const
const void *c_QList_T_QObject_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_QObject_T___count(void *thisObj);
// QList::detach()
void c_QList_T_QObject_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_QObject_T___empty(void *thisObj);
// QList::first()
void *c_QList_T_QObject_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_QObject_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
void *c_QList_T_QObject_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_QObject_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_QObject_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_QObject_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
void *c_QList_T_QObject_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_QObject_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_QObject_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QObject_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_QObject_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_QObject_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_QObject_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_QObject_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_QObject_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_QObject_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_QObject_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_QObject_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_QObject_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_QObject_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_QObject_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_QObject_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QObject_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QList::squeeze()
void c_QList_T_QObject_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QObject_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype j);
// QList::takeAt(qsizetype i)
void *c_QList_T_QObject_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_QObject_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_QObject_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
void *c_QList_T_QObject_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_QObject_T___destructor(void *thisObj);
void c_QList_T_QObject_T__Finalizer(void *cppObj); // QList::QList<T>()
void *c_QList_T_QByteArray_T___constructor();
// QList::QList<T>(qsizetype size)
void *c_QList_T_QByteArray_T___constructor_qsizetype(qsizetype size);
// QList::append(const QList<T > & l)
void c_QList_T_QByteArray_T___append_QList_T(void *thisObj, void *l_);
// QList::at(qsizetype i) const
const void *c_QList_T_QByteArray_T___at_qsizetype(void *thisObj, qsizetype i);
// QList::back()
void *c_QList_T_QByteArray_T___back(void *thisObj);
// QList::capacity() const
qsizetype c_QList_T_QByteArray_T___capacity(void *thisObj);
// QList::clear()
void c_QList_T_QByteArray_T___clear(void *thisObj);
// QList::constFirst() const
const void *c_QList_T_QByteArray_T___constFirst(void *thisObj);
// QList::constLast() const
const void *c_QList_T_QByteArray_T___constLast(void *thisObj);
// QList::count() const
qsizetype c_QList_T_QByteArray_T___count(void *thisObj);
// QList::detach()
void c_QList_T_QByteArray_T___detach(void *thisObj);
// QList::empty() const
bool c_QList_T_QByteArray_T___empty(void *thisObj);
// QList::first()
void *c_QList_T_QByteArray_T___first(void *thisObj);
// QList::first(qsizetype n) const
void *c_QList_T_QByteArray_T___first_qsizetype(void *thisObj, qsizetype n);
// QList::front()
void *c_QList_T_QByteArray_T___front(void *thisObj);
// QList::isDetached() const
bool c_QList_T_QByteArray_T___isDetached(void *thisObj);
// QList::isEmpty() const
bool c_QList_T_QByteArray_T___isEmpty(void *thisObj);
// QList::isSharedWith(const QList<T > & other) const
bool c_QList_T_QByteArray_T___isSharedWith_QList_T(void *thisObj, void *other_);
// QList::last()
void *c_QList_T_QByteArray_T___last(void *thisObj);
// QList::last(qsizetype n) const
void *c_QList_T_QByteArray_T___last_qsizetype(void *thisObj, qsizetype n);
// QList::length() const
qsizetype c_QList_T_QByteArray_T___length(void *thisObj);
// QList::mid(qsizetype pos, qsizetype len) const
void *c_QList_T_QByteArray_T___mid_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype len);
// QList::move(qsizetype from, qsizetype to)
void c_QList_T_QByteArray_T___move_qsizetype_qsizetype(void *thisObj, qsizetype from, qsizetype to);
// QList::pop_back()
void c_QList_T_QByteArray_T___pop_back(void *thisObj);
// QList::pop_front()
void c_QList_T_QByteArray_T___pop_front(void *thisObj);
// QList::remove(qsizetype i, qsizetype n)
void c_QList_T_QByteArray_T___remove_qsizetype_qsizetype(void *thisObj, qsizetype i, qsizetype n);
// QList::removeAt(qsizetype i)
void c_QList_T_QByteArray_T___removeAt_qsizetype(void *thisObj, qsizetype i);
// QList::removeFirst()
void c_QList_T_QByteArray_T___removeFirst(void *thisObj);
// QList::removeLast()
void c_QList_T_QByteArray_T___removeLast(void *thisObj);
// QList::reserve(qsizetype size)
void c_QList_T_QByteArray_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QList::resize(qsizetype size)
void c_QList_T_QByteArray_T___resize_qsizetype(void *thisObj, qsizetype size);
// QList::shrink_to_fit()
void c_QList_T_QByteArray_T___shrink_to_fit(void *thisObj);
// QList::size() const
qsizetype c_QList_T_QByteArray_T___size(void *thisObj);
// QList::sliced(qsizetype pos) const
void *c_QList_T_QByteArray_T___sliced_qsizetype(void *thisObj, qsizetype pos);
// QList::sliced(qsizetype pos, qsizetype n) const
void *c_QList_T_QByteArray_T___sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos,
                                                          qsizetype n);
// QList::squeeze()
void c_QList_T_QByteArray_T___squeeze(void *thisObj);
// QList::swapItemsAt(qsizetype i, qsizetype j)
void c_QList_T_QByteArray_T___swapItemsAt_qsizetype_qsizetype(void *thisObj, qsizetype i,
                                                              qsizetype j);
// QList::takeAt(qsizetype i)
void *c_QList_T_QByteArray_T___takeAt_qsizetype(void *thisObj, qsizetype i);
// QList::toList() const
void *c_QList_T_QByteArray_T___toList(void *thisObj);
// QList::toVector() const
void *c_QList_T_QByteArray_T___toVector(void *thisObj);
// QList::value(qsizetype i) const
void *c_QList_T_QByteArray_T___value_qsizetype(void *thisObj, qsizetype i);
void c_QList_T_QByteArray_T___destructor(void *thisObj);
void c_QList_T_QByteArray_T__Finalizer(void *cppObj); // QHash::QHash<Key, T>()
void *c_QHash_T_QString_QVariant_T___constructor();
// QHash::capacity() const
qsizetype c_QHash_T_QString_QVariant_T___capacity(void *thisObj);
// QHash::clear()
void c_QHash_T_QString_QVariant_T___clear(void *thisObj);
// QHash::contains(const Key & key) const
bool c_QHash_T_QString_QVariant_T___contains_QString(void *thisObj, const char *key_);
// QHash::count() const
qsizetype c_QHash_T_QString_QVariant_T___count(void *thisObj);
// QHash::count(const Key & key) const
qsizetype c_QHash_T_QString_QVariant_T___count_QString(void *thisObj, const char *key_);
// QHash::detach()
void c_QHash_T_QString_QVariant_T___detach(void *thisObj);
// QHash::empty() const
bool c_QHash_T_QString_QVariant_T___empty(void *thisObj);
// QHash::insert(const QHash<Key,T > & hash)
void c_QHash_T_QString_QVariant_T___insert_QHash_Key_T(void *thisObj, void *hash_);
// QHash::isDetached() const
bool c_QHash_T_QString_QVariant_T___isDetached(void *thisObj);
// QHash::isEmpty() const
bool c_QHash_T_QString_QVariant_T___isEmpty(void *thisObj);
// QHash::isSharedWith(const QHash<Key,T > & other) const
bool c_QHash_T_QString_QVariant_T___isSharedWith_QHash_Key_T(void *thisObj, void *other_);
// QHash::key(const T & value) const
void *c_QHash_T_QString_QVariant_T___key_QVariant(void *thisObj, void *value_);
// QHash::key(const T & value, const Key & defaultKey) const
void *c_QHash_T_QString_QVariant_T___key_QVariant_QString(void *thisObj, void *value_,
                                                          const char *defaultKey_);
// QHash::keys() const
void *c_QHash_T_QString_QVariant_T___keys(void *thisObj);
// QHash::keys(const T & value) const
void *c_QHash_T_QString_QVariant_T___keys_QVariant(void *thisObj, void *value_);
// QHash::load_factor() const
float c_QHash_T_QString_QVariant_T___load_factor(void *thisObj);
// QHash::remove(const Key & key)
bool c_QHash_T_QString_QVariant_T___remove_QString(void *thisObj, const char *key_);
// QHash::reserve(qsizetype size)
void c_QHash_T_QString_QVariant_T___reserve_qsizetype(void *thisObj, qsizetype size);
// QHash::size() const
qsizetype c_QHash_T_QString_QVariant_T___size(void *thisObj);
// QHash::squeeze()
void c_QHash_T_QString_QVariant_T___squeeze(void *thisObj);
// QHash::take(const Key & key)
void *c_QHash_T_QString_QVariant_T___take_QString(void *thisObj, const char *key_);
// QHash::value(const Key & key) const
void *c_QHash_T_QString_QVariant_T___value_QString(void *thisObj, const char *key_);
// QHash::value(const Key & key, const T & defaultValue) const
void *c_QHash_T_QString_QVariant_T___value_QString_QVariant(void *thisObj, const char *key_,
                                                            void *defaultValue_);
// QHash::values() const
void *c_QHash_T_QString_QVariant_T___values(void *thisObj);
void c_QHash_T_QString_QVariant_T___destructor(void *thisObj);
void c_QHash_T_QString_QVariant_T__Finalizer(void *cppObj); // QEvent::accept()
void c_QEvent__accept(void *thisObj);
// QEvent::clone() const
void *c_QEvent__clone(void *thisObj);
// QEvent::ignore()
void c_QEvent__ignore(void *thisObj);
// QEvent::isAccepted() const
bool c_QEvent__isAccepted(void *thisObj);
// QEvent::isInputEvent() const
bool c_QEvent__isInputEvent(void *thisObj);
// QEvent::isPointerEvent() const
bool c_QEvent__isPointerEvent(void *thisObj);
// QEvent::isSinglePointEvent() const
bool c_QEvent__isSinglePointEvent(void *thisObj);
// QEvent::registerEventType(int hint)
int c_static_QEvent__registerEventType_int(int hint);
// QEvent::setAccepted(bool accepted)
void c_QEvent__setAccepted_bool(void *thisObj, bool accepted);
// QEvent::spontaneous() const
bool c_QEvent__spontaneous(void *thisObj);
void c_QEvent__destructor(void *thisObj);
void c_QEvent__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_QEvent_Finalizer(void *cppObj); // QCoreApplication::addLibraryPath(const QString & arg__1)
void c_static_QCoreApplication__addLibraryPath_QString(const char *arg__1_);
// QCoreApplication::applicationDirPath()
void *c_static_QCoreApplication__applicationDirPath();
// QCoreApplication::applicationFilePath()
void *c_static_QCoreApplication__applicationFilePath();
// QCoreApplication::applicationName()
void *c_static_QCoreApplication__applicationName();
// QCoreApplication::applicationNameChanged()
void c_QCoreApplication__applicationNameChanged(void *thisObj);
void c_QCoreApplication__onApplicationNameChanged(
    void *thisObj, void *contextQObject, void *callback); // QCoreApplication::applicationPid()
qint64 c_static_QCoreApplication__applicationPid();
// QCoreApplication::applicationVersion()
void *c_static_QCoreApplication__applicationVersion();
// QCoreApplication::applicationVersionChanged()
void c_QCoreApplication__applicationVersionChanged(void *thisObj);
void c_QCoreApplication__onApplicationVersionChanged(
    void *thisObj, void *contextQObject, void *callback); // QCoreApplication::arguments()
void *c_static_QCoreApplication__arguments();
// QCoreApplication::closingDown()
bool c_static_QCoreApplication__closingDown();
// QCoreApplication::customEvent(QEvent * event)
void c_QCoreApplication__customEvent_QEvent(void *thisObj, void *event_);
// QCoreApplication::event(QEvent * arg__1)
bool c_QCoreApplication__event_QEvent(void *thisObj, void *arg__1_);
// QCoreApplication::eventFilter(QObject * watched, QEvent * event)
bool c_QCoreApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// QCoreApplication::exec()
int c_static_QCoreApplication__exec();
// QCoreApplication::exit(int retcode)
void c_static_QCoreApplication__exit_int(int retcode);
// QCoreApplication::instance()
void *c_static_QCoreApplication__instance();
// QCoreApplication::isQuitLockEnabled()
bool c_static_QCoreApplication__isQuitLockEnabled();
// QCoreApplication::isSetuidAllowed()
bool c_static_QCoreApplication__isSetuidAllowed();
// QCoreApplication::libraryPaths()
void *c_static_QCoreApplication__libraryPaths();
// QCoreApplication::notify(QObject * arg__1, QEvent * arg__2)
bool c_QCoreApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_, void *arg__2_);
// QCoreApplication::organizationDomain()
void *c_static_QCoreApplication__organizationDomain();
// QCoreApplication::organizationDomainChanged()
void c_QCoreApplication__organizationDomainChanged(void *thisObj);
void c_QCoreApplication__onOrganizationDomainChanged(
    void *thisObj, void *contextQObject, void *callback); // QCoreApplication::organizationName()
void *c_static_QCoreApplication__organizationName();
// QCoreApplication::organizationNameChanged()
void c_QCoreApplication__organizationNameChanged(void *thisObj);
void c_QCoreApplication__onOrganizationNameChanged(void *thisObj, void *contextQObject,
                                                   void *callback); // QCoreApplication::postEvent(QObject
                                                                    // * receiver, QEvent * event,
                                                                    // int priority)
void c_static_QCoreApplication__postEvent_QObject_QEvent_int(void *receiver_, void *event_,
                                                             int priority);
// QCoreApplication::processEvents()
void c_static_QCoreApplication__processEvents();
// QCoreApplication::quit()
void c_static_QCoreApplication__quit();
// QCoreApplication::removeLibraryPath(const QString & arg__1)
void c_static_QCoreApplication__removeLibraryPath_QString(const char *arg__1_);
// QCoreApplication::removePostedEvents(QObject * receiver, int eventType)
void c_static_QCoreApplication__removePostedEvents_QObject_int(void *receiver_, int eventType);
// QCoreApplication::sendEvent(QObject * receiver, QEvent * event)
bool c_static_QCoreApplication__sendEvent_QObject_QEvent(void *receiver_, void *event_);
// QCoreApplication::sendPostedEvents(QObject * receiver, int event_type)
void c_static_QCoreApplication__sendPostedEvents_QObject_int(void *receiver_, int event_type);
// QCoreApplication::setApplicationName(const QString & application)
void c_static_QCoreApplication__setApplicationName_QString(const char *application_);
// QCoreApplication::setApplicationVersion(const QString & version)
void c_static_QCoreApplication__setApplicationVersion_QString(const char *version_);
// QCoreApplication::setLibraryPaths(const QList<QString > & arg__1)
void c_static_QCoreApplication__setLibraryPaths_QList_QString(void *arg__1_);
// QCoreApplication::setOrganizationDomain(const QString & orgDomain)
void c_static_QCoreApplication__setOrganizationDomain_QString(const char *orgDomain_);
// QCoreApplication::setOrganizationName(const QString & orgName)
void c_static_QCoreApplication__setOrganizationName_QString(const char *orgName_);
// QCoreApplication::setQuitLockEnabled(bool enabled)
void c_static_QCoreApplication__setQuitLockEnabled_bool(bool enabled);
// QCoreApplication::setSetuidAllowed(bool allow)
void c_static_QCoreApplication__setSetuidAllowed_bool(bool allow);
// QCoreApplication::startingUp()
bool c_static_QCoreApplication__startingUp();
// QCoreApplication::tr(const char * s, const char * c, int n)
void *c_static_QCoreApplication__tr_char_char_int(const char *s, const char *c, int n);
// QCoreApplication::translate(const char * context, const char * key, const char * disambiguation,
// int n)
void *c_static_QCoreApplication__translate_char_char_char_int(const char *context, const char *key,
                                                              const char *disambiguation, int n);
void c_QCoreApplication__destructor(void *thisObj);
void c_QCoreApplication__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_QCoreApplication_Finalizer(void *cppObj); // QGuiApplication::applicationDisplayName()
void *c_static_QGuiApplication__applicationDisplayName();
// QGuiApplication::applicationDisplayNameChanged()
void c_QGuiApplication__applicationDisplayNameChanged(void *thisObj);
void c_QGuiApplication__onApplicationDisplayNameChanged(void *thisObj, void *contextQObject,
                                                        void *callback); // QGuiApplication::customEvent(QEvent
                                                                         // * event)
void c_QGuiApplication__customEvent_QEvent(void *thisObj, void *event_);
// QGuiApplication::desktopFileName()
void *c_static_QGuiApplication__desktopFileName();
// QGuiApplication::desktopSettingsAware()
bool c_static_QGuiApplication__desktopSettingsAware();
// QGuiApplication::devicePixelRatio() const
qreal c_QGuiApplication__devicePixelRatio(void *thisObj);
// QGuiApplication::event(QEvent * arg__1)
bool c_QGuiApplication__event_QEvent(void *thisObj, void *arg__1_);
// QGuiApplication::eventFilter(QObject * watched, QEvent * event)
bool c_QGuiApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// QGuiApplication::exec()
int c_static_QGuiApplication__exec();
// QGuiApplication::focusObject()
void *c_static_QGuiApplication__focusObject();
// QGuiApplication::focusObjectChanged(QObject * focusObject)
void c_QGuiApplication__focusObjectChanged_QObject(void *thisObj, void *focusObject_);
void c_QGuiApplication__onFocusObjectChanged_QObject(
    void *thisObj, void *contextQObject, void *callback); // QGuiApplication::fontDatabaseChanged()
void c_QGuiApplication__fontDatabaseChanged(void *thisObj);
void c_QGuiApplication__onFontDatabaseChanged(void *thisObj, void *contextQObject,
                                              void *callback); // QGuiApplication::isLeftToRight()
bool c_static_QGuiApplication__isLeftToRight();
// QGuiApplication::isRightToLeft()
bool c_static_QGuiApplication__isRightToLeft();
// QGuiApplication::isSavingSession() const
bool c_QGuiApplication__isSavingSession(void *thisObj);
// QGuiApplication::isSessionRestored() const
bool c_QGuiApplication__isSessionRestored(void *thisObj);
// QGuiApplication::lastWindowClosed()
void c_QGuiApplication__lastWindowClosed(void *thisObj);
void c_QGuiApplication__onLastWindowClosed(void *thisObj, void *contextQObject,
                                           void *callback); // QGuiApplication::notify(QObject *
                                                            // arg__1, QEvent * arg__2)
bool c_QGuiApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_, void *arg__2_);
// QGuiApplication::platformName()
void *c_static_QGuiApplication__platformName();
// QGuiApplication::quitOnLastWindowClosed()
bool c_static_QGuiApplication__quitOnLastWindowClosed();
// QGuiApplication::restoreOverrideCursor()
void c_static_QGuiApplication__restoreOverrideCursor();
// QGuiApplication::sessionId() const
void *c_QGuiApplication__sessionId(void *thisObj);
// QGuiApplication::sessionKey() const
void *c_QGuiApplication__sessionKey(void *thisObj);
// QGuiApplication::setApplicationDisplayName(const QString & name)
void c_static_QGuiApplication__setApplicationDisplayName_QString(const char *name_);
// QGuiApplication::setDesktopFileName(const QString & name)
void c_static_QGuiApplication__setDesktopFileName_QString(const char *name_);
// QGuiApplication::setDesktopSettingsAware(bool on)
void c_static_QGuiApplication__setDesktopSettingsAware_bool(bool on);
// QGuiApplication::setQuitOnLastWindowClosed(bool quit)
void c_static_QGuiApplication__setQuitOnLastWindowClosed_bool(bool quit);
// QGuiApplication::sync()
void c_static_QGuiApplication__sync();
// QGuiApplication::tr(const char * s, const char * c, int n)
void *c_static_QGuiApplication__tr_char_char_int(const char *s, const char *c, int n);
void c_QGuiApplication__destructor(void *thisObj);
void c_QGuiApplication__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_QGuiApplication_Finalizer(void *cppObj); // QColor::QColor()
void *c_QColor__constructor();
// QColor::QColor(const QString & name)
void *c_QColor__constructor_QString(const char *name_);
// QColor::QColor(const char * aname)
void *c_QColor__constructor_char(const char *aname);
// QColor::QColor(int r, int g, int b, int a)
void *c_QColor__constructor_int_int_int_int(int r, int g, int b, int a);
// QColor::alpha() const
int c_QColor__alpha(void *thisObj);
// QColor::alphaF() const
float c_QColor__alphaF(void *thisObj);
// QColor::black() const
int c_QColor__black(void *thisObj);
// QColor::blackF() const
float c_QColor__blackF(void *thisObj);
// QColor::blue() const
int c_QColor__blue(void *thisObj);
// QColor::blueF() const
float c_QColor__blueF(void *thisObj);
// QColor::colorNames()
void *c_static_QColor__colorNames();
// QColor::cyan() const
int c_QColor__cyan(void *thisObj);
// QColor::cyanF() const
float c_QColor__cyanF(void *thisObj);
// QColor::darker(int f) const
void *c_QColor__darker_int(void *thisObj, int f);
// QColor::fromCmyk(int c, int m, int y, int k, int a)
void *c_static_QColor__fromCmyk_int_int_int_int_int(int c, int m, int y, int k, int a);
// QColor::fromCmykF(float c, float m, float y, float k, float a)
void *c_static_QColor__fromCmykF_float_float_float_float_float(float c, float m, float y, float k,
                                                               float a);
// QColor::fromHsl(int h, int s, int l, int a)
void *c_static_QColor__fromHsl_int_int_int_int(int h, int s, int l, int a);
// QColor::fromHslF(float h, float s, float l, float a)
void *c_static_QColor__fromHslF_float_float_float_float(float h, float s, float l, float a);
// QColor::fromHsv(int h, int s, int v, int a)
void *c_static_QColor__fromHsv_int_int_int_int(int h, int s, int v, int a);
// QColor::fromHsvF(float h, float s, float v, float a)
void *c_static_QColor__fromHsvF_float_float_float_float(float h, float s, float v, float a);
// QColor::fromRgb(int r, int g, int b, int a)
void *c_static_QColor__fromRgb_int_int_int_int(int r, int g, int b, int a);
// QColor::fromRgbF(float r, float g, float b, float a)
void *c_static_QColor__fromRgbF_float_float_float_float(float r, float g, float b, float a);
// QColor::green() const
int c_QColor__green(void *thisObj);
// QColor::greenF() const
float c_QColor__greenF(void *thisObj);
// QColor::hslHue() const
int c_QColor__hslHue(void *thisObj);
// QColor::hslHueF() const
float c_QColor__hslHueF(void *thisObj);
// QColor::hslSaturation() const
int c_QColor__hslSaturation(void *thisObj);
// QColor::hslSaturationF() const
float c_QColor__hslSaturationF(void *thisObj);
// QColor::hsvHue() const
int c_QColor__hsvHue(void *thisObj);
// QColor::hsvHueF() const
float c_QColor__hsvHueF(void *thisObj);
// QColor::hsvSaturation() const
int c_QColor__hsvSaturation(void *thisObj);
// QColor::hsvSaturationF() const
float c_QColor__hsvSaturationF(void *thisObj);
// QColor::hue() const
int c_QColor__hue(void *thisObj);
// QColor::hueF() const
float c_QColor__hueF(void *thisObj);
// QColor::isValid() const
bool c_QColor__isValid(void *thisObj);
// QColor::isValidColor(const QString & name)
bool c_static_QColor__isValidColor_QString(const char *name_);
// QColor::lighter(int f) const
void *c_QColor__lighter_int(void *thisObj, int f);
// QColor::lightness() const
int c_QColor__lightness(void *thisObj);
// QColor::lightnessF() const
float c_QColor__lightnessF(void *thisObj);
// QColor::magenta() const
int c_QColor__magenta(void *thisObj);
// QColor::magentaF() const
float c_QColor__magentaF(void *thisObj);
// QColor::name() const
void *c_QColor__name(void *thisObj);
// QColor::red() const
int c_QColor__red(void *thisObj);
// QColor::redF() const
float c_QColor__redF(void *thisObj);
// QColor::saturation() const
int c_QColor__saturation(void *thisObj);
// QColor::saturationF() const
float c_QColor__saturationF(void *thisObj);
// QColor::setAlpha(int alpha)
void c_QColor__setAlpha_int(void *thisObj, int alpha);
// QColor::setAlphaF(float alpha)
void c_QColor__setAlphaF_float(void *thisObj, float alpha);
// QColor::setBlue(int blue)
void c_QColor__setBlue_int(void *thisObj, int blue);
// QColor::setBlueF(float blue)
void c_QColor__setBlueF_float(void *thisObj, float blue);
// QColor::setCmyk(int c, int m, int y, int k, int a)
void c_QColor__setCmyk_int_int_int_int_int(void *thisObj, int c, int m, int y, int k, int a);
// QColor::setCmykF(float c, float m, float y, float k, float a)
void c_QColor__setCmykF_float_float_float_float_float(void *thisObj, float c, float m, float y,
                                                      float k, float a);
// QColor::setGreen(int green)
void c_QColor__setGreen_int(void *thisObj, int green);
// QColor::setGreenF(float green)
void c_QColor__setGreenF_float(void *thisObj, float green);
// QColor::setHsl(int h, int s, int l, int a)
void c_QColor__setHsl_int_int_int_int(void *thisObj, int h, int s, int l, int a);
// QColor::setHslF(float h, float s, float l, float a)
void c_QColor__setHslF_float_float_float_float(void *thisObj, float h, float s, float l, float a);
// QColor::setHsv(int h, int s, int v, int a)
void c_QColor__setHsv_int_int_int_int(void *thisObj, int h, int s, int v, int a);
// QColor::setHsvF(float h, float s, float v, float a)
void c_QColor__setHsvF_float_float_float_float(void *thisObj, float h, float s, float v, float a);
// QColor::setNamedColor(const QString & name)
void c_QColor__setNamedColor_QString(void *thisObj, const char *name_);
// QColor::setRed(int red)
void c_QColor__setRed_int(void *thisObj, int red);
// QColor::setRedF(float red)
void c_QColor__setRedF_float(void *thisObj, float red);
// QColor::setRgb(int r, int g, int b, int a)
void c_QColor__setRgb_int_int_int_int(void *thisObj, int r, int g, int b, int a);
// QColor::setRgbF(float r, float g, float b, float a)
void c_QColor__setRgbF_float_float_float_float(void *thisObj, float r, float g, float b, float a);
// QColor::toCmyk() const
void *c_QColor__toCmyk(void *thisObj);
// QColor::toExtendedRgb() const
void *c_QColor__toExtendedRgb(void *thisObj);
// QColor::toHsl() const
void *c_QColor__toHsl(void *thisObj);
// QColor::toHsv() const
void *c_QColor__toHsv(void *thisObj);
// QColor::toRgb() const
void *c_QColor__toRgb(void *thisObj);
// QColor::value() const
int c_QColor__value(void *thisObj);
// QColor::valueF() const
float c_QColor__valueF(void *thisObj);
// QColor::yellow() const
int c_QColor__yellow(void *thisObj);
// QColor::yellowF() const
float c_QColor__yellowF(void *thisObj);
void c_QColor__destructor(void *thisObj);
void c_QColor_Finalizer(void *cppObj); // QByteArray::QByteArray()
void *c_QByteArray__constructor();
// QByteArray::QByteArray(const char * arg__1, qsizetype size)
void *c_QByteArray__constructor_char_qsizetype(const char *arg__1, qsizetype size);
// QByteArray::append(const QByteArray & a)
void *c_QByteArray__append_QByteArray(void *thisObj, void *a_);
// QByteArray::append(const char * s)
void *c_QByteArray__append_char(void *thisObj, const char *s);
// QByteArray::append(const char * s, qsizetype len)
void *c_QByteArray__append_char_qsizetype(void *thisObj, const char *s, qsizetype len);
// QByteArray::at(qsizetype i) const
char c_QByteArray__at_qsizetype(void *thisObj, qsizetype i);
// QByteArray::back() const
char c_QByteArray__back(void *thisObj);
// QByteArray::begin() const
const char *c_QByteArray__begin(void *thisObj);
// QByteArray::capacity() const
qsizetype c_QByteArray__capacity(void *thisObj);
// QByteArray::cbegin() const
const char *c_QByteArray__cbegin(void *thisObj);
// QByteArray::cend() const
const char *c_QByteArray__cend(void *thisObj);
// QByteArray::chop(qsizetype n)
void c_QByteArray__chop_qsizetype(void *thisObj, qsizetype n);
// QByteArray::chopped(qsizetype len) const
void *c_QByteArray__chopped_qsizetype(void *thisObj, qsizetype len);
// QByteArray::clear()
void c_QByteArray__clear(void *thisObj);
// QByteArray::constBegin() const
const char *c_QByteArray__constBegin(void *thisObj);
// QByteArray::constData() const
const char *c_QByteArray__constData(void *thisObj);
// QByteArray::constEnd() const
const char *c_QByteArray__constEnd(void *thisObj);
// QByteArray::count() const
qsizetype c_QByteArray__count(void *thisObj);
// QByteArray::data() const
const char *c_QByteArray__data(void *thisObj);
// QByteArray::detach()
void c_QByteArray__detach(void *thisObj);
// QByteArray::end() const
const char *c_QByteArray__end(void *thisObj);
// QByteArray::first(qsizetype n) const
void *c_QByteArray__first_qsizetype(void *thisObj, qsizetype n);
// QByteArray::fromBase64(const QByteArray & base64)
void *c_static_QByteArray__fromBase64_QByteArray(void *base64_);
// QByteArray::fromHex(const QByteArray & hexEncoded)
void *c_static_QByteArray__fromHex_QByteArray(void *hexEncoded_);
// QByteArray::fromRawData(const char * data, qsizetype size)
void *c_static_QByteArray__fromRawData_char_qsizetype(const char *data, qsizetype size);
// QByteArray::front() const
char c_QByteArray__front(void *thisObj);
// QByteArray::insert(qsizetype i, const QByteArray & data)
void *c_QByteArray__insert_qsizetype_QByteArray(void *thisObj, qsizetype i, void *data_);
// QByteArray::insert(qsizetype i, const char * s)
void *c_QByteArray__insert_qsizetype_char(void *thisObj, qsizetype i, const char *s);
// QByteArray::insert(qsizetype i, const char * s, qsizetype len)
void *c_QByteArray__insert_qsizetype_char_qsizetype(void *thisObj, qsizetype i, const char *s,
                                                    qsizetype len);
// QByteArray::isDetached() const
bool c_QByteArray__isDetached(void *thisObj);
// QByteArray::isEmpty() const
bool c_QByteArray__isEmpty(void *thisObj);
// QByteArray::isLower() const
bool c_QByteArray__isLower(void *thisObj);
// QByteArray::isNull() const
bool c_QByteArray__isNull(void *thisObj);
// QByteArray::isSharedWith(const QByteArray & other) const
bool c_QByteArray__isSharedWith_QByteArray(void *thisObj, void *other_);
// QByteArray::isUpper() const
bool c_QByteArray__isUpper(void *thisObj);
// QByteArray::isValidUtf8() const
bool c_QByteArray__isValidUtf8(void *thisObj);
// QByteArray::last(qsizetype n) const
void *c_QByteArray__last_qsizetype(void *thisObj, qsizetype n);
// QByteArray::left(qsizetype len) const
void *c_QByteArray__left_qsizetype(void *thisObj, qsizetype len);
// QByteArray::length() const
qsizetype c_QByteArray__length(void *thisObj);
// QByteArray::mid(qsizetype index, qsizetype len) const
void *c_QByteArray__mid_qsizetype_qsizetype(void *thisObj, qsizetype index, qsizetype len);
// QByteArray::number(int arg__1, int base)
void *c_static_QByteArray__number_int_int(int arg__1, int base);
// QByteArray::number(long arg__1, int base)
void *c_static_QByteArray__number_long_int(long arg__1, int base);
// QByteArray::number(qint64 arg__1, int base)
void *c_static_QByteArray__number_qint64_int(qint64 arg__1, int base);
// QByteArray::prepend(const QByteArray & a)
void *c_QByteArray__prepend_QByteArray(void *thisObj, void *a_);
// QByteArray::prepend(const char * s)
void *c_QByteArray__prepend_char(void *thisObj, const char *s);
// QByteArray::prepend(const char * s, qsizetype len)
void *c_QByteArray__prepend_char_qsizetype(void *thisObj, const char *s, qsizetype len);
// QByteArray::push_back(const QByteArray & a)
void c_QByteArray__push_back_QByteArray(void *thisObj, void *a_);
// QByteArray::push_back(const char * s)
void c_QByteArray__push_back_char(void *thisObj, const char *s);
// QByteArray::push_front(const QByteArray & a)
void c_QByteArray__push_front_QByteArray(void *thisObj, void *a_);
// QByteArray::push_front(const char * c)
void c_QByteArray__push_front_char(void *thisObj, const char *c);
// QByteArray::remove(qsizetype index, qsizetype len)
void *c_QByteArray__remove_qsizetype_qsizetype(void *thisObj, qsizetype index, qsizetype len);
// QByteArray::repeated(qsizetype times) const
void *c_QByteArray__repeated_qsizetype(void *thisObj, qsizetype times);
// QByteArray::replace(const char * before, qsizetype bsize, const char * after, qsizetype asize)
void *c_QByteArray__replace_char_qsizetype_char_qsizetype(void *thisObj, const char *before,
                                                          qsizetype bsize, const char *after,
                                                          qsizetype asize);
// QByteArray::replace(qsizetype index, qsizetype len, const char * s, qsizetype alen)
void *c_QByteArray__replace_qsizetype_qsizetype_char_qsizetype(void *thisObj, qsizetype index,
                                                               qsizetype len, const char *s,
                                                               qsizetype alen);
// QByteArray::reserve(qsizetype size)
void c_QByteArray__reserve_qsizetype(void *thisObj, qsizetype size);
// QByteArray::resize(qsizetype size)
void c_QByteArray__resize_qsizetype(void *thisObj, qsizetype size);
// QByteArray::right(qsizetype len) const
void *c_QByteArray__right_qsizetype(void *thisObj, qsizetype len);
// QByteArray::setNum(int arg__1, int base)
void *c_QByteArray__setNum_int_int(void *thisObj, int arg__1, int base);
// QByteArray::setNum(long arg__1, int base)
void *c_QByteArray__setNum_long_int(void *thisObj, long arg__1, int base);
// QByteArray::setNum(qint64 arg__1, int base)
void *c_QByteArray__setNum_qint64_int(void *thisObj, qint64 arg__1, int base);
// QByteArray::setNum(short arg__1, int base)
void *c_QByteArray__setNum_short_int(void *thisObj, short arg__1, int base);
// QByteArray::setRawData(const char * a, qsizetype n)
void *c_QByteArray__setRawData_char_qsizetype(void *thisObj, const char *a, qsizetype n);
// QByteArray::shrink_to_fit()
void c_QByteArray__shrink_to_fit(void *thisObj);
// QByteArray::simplified()
void *c_QByteArray__simplified(void *thisObj);
// QByteArray::size() const
qsizetype c_QByteArray__size(void *thisObj);
// QByteArray::sliced(qsizetype pos) const
void *c_QByteArray__sliced_qsizetype(void *thisObj, qsizetype pos);
// QByteArray::sliced(qsizetype pos, qsizetype n) const
void *c_QByteArray__sliced_qsizetype_qsizetype(void *thisObj, qsizetype pos, qsizetype n);
// QByteArray::squeeze()
void c_QByteArray__squeeze(void *thisObj);
// QByteArray::toBase64() const
void *c_QByteArray__toBase64(void *thisObj);
// QByteArray::toLower()
void *c_QByteArray__toLower(void *thisObj);
// QByteArray::toUpper()
void *c_QByteArray__toUpper(void *thisObj);
// QByteArray::trimmed()
void *c_QByteArray__trimmed(void *thisObj);
// QByteArray::truncate(qsizetype pos)
void c_QByteArray__truncate_qsizetype(void *thisObj, qsizetype pos);
void c_QByteArray__destructor(void *thisObj);
void c_QByteArray_Finalizer(void *cppObj); // QApplication::aboutQt()
void c_static_QApplication__aboutQt();
// QApplication::autoSipEnabled() const
bool c_QApplication__autoSipEnabled(void *thisObj);
// QApplication::beep()
void c_static_QApplication__beep();
// QApplication::closeAllWindows()
void c_static_QApplication__closeAllWindows();
// QApplication::cursorFlashTime()
int c_static_QApplication__cursorFlashTime();
// QApplication::customEvent(QEvent * event)
void c_QApplication__customEvent_QEvent(void *thisObj, void *event_);
// QApplication::doubleClickInterval()
int c_static_QApplication__doubleClickInterval();
// QApplication::event(QEvent * arg__1)
bool c_QApplication__event_QEvent(void *thisObj, void *arg__1_);
// QApplication::eventFilter(QObject * watched, QEvent * event)
bool c_QApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// QApplication::exec()
int c_static_QApplication__exec();
// QApplication::keyboardInputInterval()
int c_static_QApplication__keyboardInputInterval();
// QApplication::notify(QObject * arg__1, QEvent * arg__2)
bool c_QApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_, void *arg__2_);
// QApplication::setAutoSipEnabled(const bool enabled)
void c_QApplication__setAutoSipEnabled_bool(void *thisObj, bool enabled);
// QApplication::setCursorFlashTime(int arg__1)
void c_static_QApplication__setCursorFlashTime_int(int arg__1);
// QApplication::setDoubleClickInterval(int arg__1)
void c_static_QApplication__setDoubleClickInterval_int(int arg__1);
// QApplication::setKeyboardInputInterval(int arg__1)
void c_static_QApplication__setKeyboardInputInterval_int(int arg__1);
// QApplication::setStartDragDistance(int l)
void c_static_QApplication__setStartDragDistance_int(int l);
// QApplication::setStartDragTime(int ms)
void c_static_QApplication__setStartDragTime_int(int ms);
// QApplication::setStyleSheet(const QString & sheet)
void c_QApplication__setStyleSheet_QString(void *thisObj, const char *sheet_);
// QApplication::setWheelScrollLines(int arg__1)
void c_static_QApplication__setWheelScrollLines_int(int arg__1);
// QApplication::startDragDistance()
int c_static_QApplication__startDragDistance();
// QApplication::startDragTime()
int c_static_QApplication__startDragTime();
// QApplication::styleSheet() const
void *c_QApplication__styleSheet(void *thisObj);
// QApplication::tr(const char * s, const char * c, int n)
void *c_static_QApplication__tr_char_char_int(const char *s, const char *c, int n);
// QApplication::wheelScrollLines()
int c_static_QApplication__wheelScrollLines();
void c_QApplication__destructor(void *thisObj);
void c_QApplication__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_QApplication_Finalizer(void *cppObj); // PureAbstractWithUnknownType::getValue() const
int c_PureAbstractWithUnknownType__getValue(void *thisObj);
void c_PureAbstractWithUnknownType__destructor(void *thisObj);
void c_PureAbstractWithUnknownType_Finalizer(void *cppObj); // NonCopiable::NonCopiable()
void *c_NonCopiable__constructor();
// NonCopiable::count() const
int c_NonCopiable__count(void *thisObj);
void c_NonCopiable__destructor(void *thisObj);
void c_NonCopiable_Finalizer(void *cppObj);
void c_NameClashingNS2_Finalizer(void *cppObj); // NameClashingNS2::SimpleClash::SimpleClash(int
                                                // arg__1)
void *c_NameClashingNS2__SimpleClash__constructor_int(int arg__1);
// NameClashingNS2::SimpleClash::getFoo()
int c_NameClashingNS2__SimpleClash__getFoo(void *thisObj);
// NameClashingNS2::SimpleClash::getValueStatic()
int c_static_NameClashingNS2__SimpleClash__getValueStatic();
// NameClashingNS2::SimpleClash::returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s)
void *c_static_NameClashingNS2__SimpleClash__returnsAndReceivesFromOtherScope_SimpleClash(void *s_);
// NameClashingNS2::SimpleClash::returnsFromOtherScope()
void *c_static_NameClashingNS2__SimpleClash__returnsFromOtherScope();
void c_NameClashingNS2__SimpleClash__destructor(void *thisObj);
void c_NameClashingNS2__SimpleClash_Finalizer(void *cppObj);
void c_NameClashingNS1_Finalizer(void *cppObj); // NameClashingNS1::SimpleClash::SimpleClash(int
                                                // arg__1)
void *c_NameClashingNS1__SimpleClash__constructor_int(int arg__1);
// NameClashingNS1::SimpleClash::getValue()
int c_NameClashingNS1__SimpleClash__getValue(void *thisObj);
// NameClashingNS1::SimpleClash::getValueStatic()
int c_static_NameClashingNS1__SimpleClash__getValueStatic();
void c_NameClashingNS1__SimpleClash__destructor(void *thisObj);
void c_NameClashingNS1__SimpleClash_Finalizer(void *cppObj); // MyTemplateWithTwoArgs::MyTemplateWithTwoArgs<T0,
                                                             // T1>()
void *c_MyTemplateWithTwoArgs_T_int_double_T___constructor();
// MyTemplateWithTwoArgs::returnInt() const
int c_MyTemplateWithTwoArgs_T_int_double_T___returnInt(void *thisObj);
void c_MyTemplateWithTwoArgs_T_int_double_T___destructor(void *thisObj);
void c_MyTemplateWithTwoArgs_T_int_double_T__Finalizer(void *cppObj); // MyTemplate2::MyTemplate2()
void *c_MyTemplate2_T_NonCopiable_T___constructor();
// MyTemplate2::assignsT()
void c_MyTemplate2_T_NonCopiable_T___assignsT(void *thisObj);
// MyTemplate2::count() const
int c_MyTemplate2_T_NonCopiable_T___count(void *thisObj);
// MyTemplate2::receivesT(T arg__1)
void c_MyTemplate2_T_NonCopiable_T___receivesT_NonCopiable(void *thisObj, void *arg__1_);
// MyTemplate2::returnTemplate1()
void *c_MyTemplate2_T_NonCopiable_T___returnTemplate1(void *thisObj);
void c_MyTemplate2_T_NonCopiable_T___destructor(void *thisObj);
void c_MyTemplate2_T_NonCopiable_T__Finalizer(void *cppObj); // MyTemplate::MyTemplate<T>()
void *c_MyTemplate_T_int_T___constructor();
// MyTemplate::receivesT(T arg__1)
int c_MyTemplate_T_int_T___receivesT_int(void *thisObj, int arg__1);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_int_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_);
// MyTemplate::returnInt() const
int c_MyTemplate_T_int_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
void *c_MyTemplate_T_int_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
void *c_MyTemplate_T_int_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
void *c_MyTemplate_T_int_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
int c_MyTemplate_T_int_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
void *c_MyTemplate_T_int_T___returnsTemplate(void *thisObj);
void c_MyTemplate_T_int_T___destructor(void *thisObj);
void c_MyTemplate_T_int_T__Finalizer(void *cppObj); // MyTemplate::MyTemplate<T>()
void *c_MyTemplate_T_double_T___constructor();
// MyTemplate::receivesT(T arg__1)
int c_MyTemplate_T_double_T___receivesT_double(void *thisObj, double arg__1);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_double_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_);
// MyTemplate::returnInt() const
int c_MyTemplate_T_double_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
void *c_MyTemplate_T_double_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
void *c_MyTemplate_T_double_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
void *c_MyTemplate_T_double_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
double c_MyTemplate_T_double_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
void *c_MyTemplate_T_double_T___returnsTemplate(void *thisObj);
void c_MyTemplate_T_double_T___destructor(void *thisObj);
void c_MyTemplate_T_double_T__Finalizer(void *cppObj); // MyTemplate::MyTemplate<T>()
void *c_MyTemplate_T_EmptyStruct_T___constructor();
// MyTemplate::receivesT(T arg__1)
int c_MyTemplate_T_EmptyStruct_T___receivesT_EmptyStruct(void *thisObj, void *arg__1_);
// MyTemplate::receivesTemplate(MyTemplate<T > arg__1)
int c_MyTemplate_T_EmptyStruct_T___receivesTemplate_MyTemplate_T(void *thisObj, void *arg__1_);
// MyTemplate::returnInt() const
int c_MyTemplate_T_EmptyStruct_T___returnInt(void *thisObj);
// MyTemplate::returnTemplate2()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate2(void *thisObj);
// MyTemplate::returnTemplate3()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate3(void *thisObj);
// MyTemplate::returnTemplate4()
void *c_MyTemplate_T_EmptyStruct_T___returnTemplate4(void *thisObj);
// MyTemplate::returnsT()
void *c_MyTemplate_T_EmptyStruct_T___returnsT(void *thisObj);
// MyTemplate::returnsTemplate()
void *c_MyTemplate_T_EmptyStruct_T___returnsTemplate(void *thisObj);
void c_MyTemplate_T_EmptyStruct_T___destructor(void *thisObj);
void c_MyTemplate_T_EmptyStruct_T__Finalizer(void *cppObj); // MyObject::MyObject(QObject * parent)
void *c_MyObject__constructor_QObject(void *parent_);
// MyObject::customEvent(QEvent * event)
void c_MyObject__customEvent_QEvent(void *thisObj, void *event_);
// MyObject::event(QEvent * event)
bool c_MyObject__event_QEvent(void *thisObj, void *event_);
// MyObject::eventFilter(QObject * watched, QEvent * event)
bool c_MyObject__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// MyObject::pureVirtual()
void c_MyObject__pureVirtual(void *thisObj);
// MyObject::receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo)
void c_MyObject__receivesEnumClassWithDefaultArg_MyNamespacedEnumClass(void *thisObj, int foo);
// MyObject::receivesEnumClassWithDefaultArg(MyEnumClass foo)
void c_MyObject__receivesEnumClassWithDefaultArg_MyEnumClass(void *thisObj, int foo);
// MyObject::returnsEnumClass()
int c_MyObject__returnsEnumClass(void *thisObj);
// MyObject::tr(const char * s, const char * c, int n)
void *c_static_MyObject__tr_char_char_int(const char *s, const char *c, int n);
// MyObject::valueChanged(int arg__1)
void c_MyObject__valueChanged_int(void *thisObj, int arg__1);
void c_MyObject__onValueChanged_int(void *thisObj, void *contextQObject,
                                    void *callback); // MyObject::virtualFunc()
int c_MyObject__virtualFunc(void *thisObj);
// MyObject::virtualMethodReturningConstChar() const
const char *c_MyObject__virtualMethodReturningConstChar(void *thisObj);
// MyObject::virtualReceivingQString(const QString & str)
void c_MyObject__virtualReceivingQString_QString(void *thisObj, const char *str_);
// MyObject::virtualReturningInt() const
int c_MyObject__virtualReturningInt(void *thisObj);
void c_MyObject__destructor(void *thisObj);
void c_MyObject__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_MyObject_Finalizer(void *cppObj); // EmptyStruct::EmptyStruct()
void *c_EmptyStruct__constructor();
void c_EmptyStruct__destructor(void *thisObj);
void c_EmptyStruct_Finalizer(void *cppObj);
void c_EmptyNameSpace_Finalizer(
    void *cppObj); // DoubleInheritanceFromVirtuals::DoubleInheritanceFromVirtuals()
void *c_DoubleInheritanceFromVirtuals__constructor();
// DoubleInheritanceFromVirtuals::virtualMethod1()
void c_DoubleInheritanceFromVirtuals__virtualMethod1(void *thisObj);
// DoubleInheritanceFromVirtuals::virtualMethod2()
void c_DoubleInheritanceFromVirtuals__virtualMethod2(void *thisObj);
void c_DoubleInheritanceFromVirtuals__destructor(void *thisObj);
void c_DoubleInheritanceFromVirtuals__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                    int methodId);
void c_DoubleInheritanceFromVirtuals_Finalizer(
    void *cppObj); // DoubleInheritance::DoubleInheritance()
void *c_DoubleInheritance__constructor();
// DoubleInheritance::customEvent(QEvent * event)
void c_DoubleInheritance__customEvent_QEvent(void *thisObj, void *event_);
// DoubleInheritance::event(QEvent * event)
bool c_DoubleInheritance__event_QEvent(void *thisObj, void *event_);
// DoubleInheritance::eventFilter(QObject * watched, QEvent * event)
bool c_DoubleInheritance__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// DoubleInheritance::nonVirtualCallsVirtualFrom2ndBase() const
int c_DoubleInheritance__nonVirtualCallsVirtualFrom2ndBase(void *thisObj);
// DoubleInheritance::pureVirtual()
void c_DoubleInheritance__pureVirtual(void *thisObj);
// DoubleInheritance::virtualFunc()
int c_DoubleInheritance__virtualFunc(void *thisObj);
// DoubleInheritance::virtualMethodReturningConstChar() const
const char *c_DoubleInheritance__virtualMethodReturningConstChar(void *thisObj);
// DoubleInheritance::virtualReceivingQString(const QString & str)
void c_DoubleInheritance__virtualReceivingQString_QString(void *thisObj, const char *str_);
// DoubleInheritance::virtualReturningInt() const
int c_DoubleInheritance__virtualReturningInt(void *thisObj);
void c_DoubleInheritance__destructor(void *thisObj);
void c_DoubleInheritance__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
void c_DoubleInheritance_Finalizer(void *cppObj); // Cyclic1::Cyclic1(Cyclic2 * arg__1)
void *c_Cyclic1__constructor_Cyclic2(void *arg__1_);
// Cyclic1::getCyclic2() const
void *c_Cyclic1__getCyclic2(void *thisObj);
void c_Cyclic1__destructor(void *thisObj);
void c_Cyclic1_Finalizer(void *cppObj); // Cyclic2::getCyclic1() const
void *c_Cyclic2__getCyclic1(void *thisObj);
void c_Cyclic2__destructor(void *thisObj);
void c_Cyclic2_Finalizer(void *cppObj); // BaseClassWithFinalMethod::BaseClassWithFinalMethod()
void *c_BaseClassWithFinalMethod__constructor();
// BaseClassWithFinalMethod::finalMethod()
void c_BaseClassWithFinalMethod__finalMethod(void *thisObj);
void c_BaseClassWithFinalMethod__destructor(void *thisObj);
void c_BaseClassWithFinalMethod__registerVirtualMethodCallback(void *ptr, void *callback,
                                                               int methodId);
void c_BaseClassWithFinalMethod_Finalizer(void *cppObj); // AnotherNamespace::size(QString s)
void *c_static_AnotherNamespace__size_QString(const char *s_);
void c_AnotherNamespace_Finalizer(
    void *cppObj); // AnotherNamespace::AnotherNamespaceStruct::AnotherNamespaceStruct()
void *c_AnotherNamespace__AnotherNamespaceStruct__constructor();
// AnotherNamespace::AnotherNamespaceStruct::receivesEnumerator(AnotherNamespace::NamespaceLevelEnum
// arg__1)
void c_AnotherNamespace__AnotherNamespaceStruct__receivesEnumerator_NamespaceLevelEnum(
    void *thisObj, int arg__1);
void c_AnotherNamespace__AnotherNamespaceStruct__destructor(void *thisObj);
void c_AnotherNamespace__AnotherNamespaceStruct_Finalizer(void *cppObj);