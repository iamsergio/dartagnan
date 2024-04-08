#include "POD_c.h"


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
namespace TestBindings_wrappersNS {
POD_wrapper::POD_wrapper()
    : ::TestTargetNS::POD()
{
}
POD_wrapper::POD_wrapper(int a, int b, int c, int d)
    : ::TestTargetNS::POD(a, b, c, d)
{
}
int POD_wrapper::calculate() const
{
    return ::TestTargetNS::POD::calculate();
}
int POD_wrapper::calculateStatic()
{
    return ::TestTargetNS::POD::calculateStatic();
}
int POD_wrapper::doStuffOnMyClass(TestTargetNS::MyBaseClass *myarg)
{
    return ::TestTargetNS::POD::doStuffOnMyClass(myarg);
}
const int &POD_wrapper::intByConstRef() const
{
    return ::TestTargetNS::POD::intByConstRef();
}
int POD_wrapper::receivesConstPointerToPODs(const TestTargetNS::POD *ptrPod1,
                                            const TestTargetNS::POD *ptrPod2)
{
    return ::TestTargetNS::POD::receivesConstPointerToPODs(ptrPod1, ptrPod2);
}
int POD_wrapper::receivesConstRefPODs(const TestTargetNS::POD &pod1, const TestTargetNS::POD &pod2)
{
    return ::TestTargetNS::POD::receivesConstRefPODs(pod1, pod2);
}
void POD_wrapper::receivesNamespaceEnum(int v)
{
    ::TestTargetNS::POD::receivesNamespaceEnum(v);
}
void POD_wrapper::receivesNamespaceEnum1(AnotherNamespace::NamespaceLevelEnum arg__1)
{
    ::TestTargetNS::POD::receivesNamespaceEnum1(arg__1);
}
int POD_wrapper::receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2)
{
    return ::TestTargetNS::POD::receivesPODs(pod1, pod2);
}
int POD_wrapper::receivesPointerToPODs(TestTargetNS::POD *ptrPod1, TestTargetNS::POD *ptrPod2)
{
    return ::TestTargetNS::POD::receivesPointerToPODs(ptrPod1, ptrPod2);
}
int POD_wrapper::receivesRefPODs(TestTargetNS::POD &pod1, TestTargetNS::POD &pod2)
{
    return ::TestTargetNS::POD::receivesRefPODs(pod1, pod2);
}
void POD_wrapper::receivesReservedDartKeyword(int var)
{
    ::TestTargetNS::POD::receivesReservedDartKeyword(var);
}
char POD_wrapper::returnsChar()
{
    return ::TestTargetNS::POD::returnsChar();
}
const char POD_wrapper::returnsConstChar()
{
    return ::TestTargetNS::POD::returnsConstChar();
}
const TestTargetNS::POD &POD_wrapper::returnsConstReferenceToPOD()
{
    return ::TestTargetNS::POD::returnsConstReferenceToPOD();
}
TestTargetNS::POD POD_wrapper::returnsPOD()
{
    return ::TestTargetNS::POD::returnsPOD();
}
TestTargetNS::POD *POD_wrapper::returnsPointerToPOD()
{
    return ::TestTargetNS::POD::returnsPointerToPOD();
}
TestTargetNS::MyBaseClass *POD_wrapper::returnsPointerToPolymorphic()
{
    return ::TestTargetNS::POD::returnsPointerToPolymorphic();
}
TestTargetNS::POD &POD_wrapper::returnsReferenceToPOD()
{
    return ::TestTargetNS::POD::returnsReferenceToPOD();
}
void POD_wrapper::withDefaultAarg(int v)
{
    ::TestTargetNS::POD::withDefaultAarg(v);
}
POD_wrapper::~POD_wrapper()
{
}

}
static TestTargetNS::POD *fromPtr(void *ptr)
{
    return reinterpret_cast<TestTargetNS::POD *>(ptr);
}
static TestBindings_wrappersNS::POD_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::POD_wrapper *>(ptr);
}
extern "C" {
void c_TestTargetNS__POD_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::POD_wrapper *>(cppObj);
}
void *c_TestTargetNS__POD__constructor()
{
    auto ptr = new TestBindings_wrappersNS::POD_wrapper();
    return reinterpret_cast<void *>(ptr);
}
void *c_TestTargetNS__POD__constructor_int_int_int_int(int a, int b, int c, int d)
{
    auto ptr = new TestBindings_wrappersNS::POD_wrapper(a, b, c, d);
    return reinterpret_cast<void *>(ptr);
}
// calculate() const
int c_TestTargetNS__POD__calculate(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->calculate();
    return result;
}
// calculateStatic()
int c_static_TestTargetNS__POD__calculateStatic()
{
    const auto &result = TestBindings_wrappersNS::POD_wrapper::calculateStatic();
    return result;
}
// doStuffOnMyClass(TestTargetNS::MyBaseClass * myarg)
int c_static_TestTargetNS__POD__doStuffOnMyClass_MyBaseClass(void *myarg_)
{
    auto myarg = reinterpret_cast<TestTargetNS::MyBaseClass *>(myarg_);
    const auto &result = TestBindings_wrappersNS::POD_wrapper::doStuffOnMyClass(myarg);
    return result;
}
// intByConstRef() const
int c_TestTargetNS__POD__intByConstRef(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->intByConstRef();
    return result;
}
// receivesConstPointerToPODs(const TestTargetNS::POD * ptrPod1, const TestTargetNS::POD * ptrPod2)
int c_static_TestTargetNS__POD__receivesConstPointerToPODs_POD_POD(void *ptrPod1_, void *ptrPod2_)
{
    auto ptrPod1 = reinterpret_cast<TestTargetNS::POD *>(ptrPod1_);
    auto ptrPod2 = reinterpret_cast<TestTargetNS::POD *>(ptrPod2_);
    const auto &result =
        TestBindings_wrappersNS::POD_wrapper::receivesConstPointerToPODs(ptrPod1, ptrPod2);
    return result;
}
// receivesConstRefPODs(const TestTargetNS::POD & pod1, const TestTargetNS::POD & pod2)
int c_static_TestTargetNS__POD__receivesConstRefPODs_POD_POD(void *pod1_, void *pod2_)
{
    assert(pod1_);
    auto &pod1 = *reinterpret_cast<TestTargetNS::POD *>(pod1_);
    assert(pod2_);
    auto &pod2 = *reinterpret_cast<TestTargetNS::POD *>(pod2_);
    const auto &result = TestBindings_wrappersNS::POD_wrapper::receivesConstRefPODs(pod1, pod2);
    return result;
}
// receivesNamespaceEnum(int v)
void c_TestTargetNS__POD__receivesNamespaceEnum_int(void *thisObj, int v)
{
    fromPtr(thisObj)->receivesNamespaceEnum(v);
}
// receivesNamespaceEnum1(AnotherNamespace::NamespaceLevelEnum arg__1)
void c_TestTargetNS__POD__receivesNamespaceEnum1_NamespaceLevelEnum(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->receivesNamespaceEnum1(
        static_cast<AnotherNamespace::NamespaceLevelEnum>(arg__1));
}
// receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2)
int c_static_TestTargetNS__POD__receivesPODs_POD_POD(void *pod1_, void *pod2_)
{
    assert(pod1_);
    auto &pod1 = *reinterpret_cast<TestTargetNS::POD *>(pod1_);
    assert(pod2_);
    auto &pod2 = *reinterpret_cast<TestTargetNS::POD *>(pod2_);
    const auto &result = TestBindings_wrappersNS::POD_wrapper::receivesPODs(pod1, pod2);
    return result;
}
// receivesPointerToPODs(TestTargetNS::POD * ptrPod1, TestTargetNS::POD * ptrPod2)
int c_static_TestTargetNS__POD__receivesPointerToPODs_POD_POD(void *ptrPod1_, void *ptrPod2_)
{
    auto ptrPod1 = reinterpret_cast<TestTargetNS::POD *>(ptrPod1_);
    auto ptrPod2 = reinterpret_cast<TestTargetNS::POD *>(ptrPod2_);
    const auto &result =
        TestBindings_wrappersNS::POD_wrapper::receivesPointerToPODs(ptrPod1, ptrPod2);
    return result;
}
// receivesRefPODs(TestTargetNS::POD & pod1, TestTargetNS::POD & pod2)
int c_static_TestTargetNS__POD__receivesRefPODs_POD_POD(void *pod1_, void *pod2_)
{
    assert(pod1_);
    auto &pod1 = *reinterpret_cast<TestTargetNS::POD *>(pod1_);
    assert(pod2_);
    auto &pod2 = *reinterpret_cast<TestTargetNS::POD *>(pod2_);
    const auto &result = TestBindings_wrappersNS::POD_wrapper::receivesRefPODs(pod1, pod2);
    return result;
}
// receivesReservedDartKeyword(int var)
void c_TestTargetNS__POD__receivesReservedDartKeyword_int(void *thisObj, int var)
{
    fromPtr(thisObj)->receivesReservedDartKeyword(var);
}
// returnsChar()
char c_static_TestTargetNS__POD__returnsChar()
{
    const auto &result = TestBindings_wrappersNS::POD_wrapper::returnsChar();
    return result;
}
// returnsConstChar()
char c_static_TestTargetNS__POD__returnsConstChar()
{
    const auto &result = TestBindings_wrappersNS::POD_wrapper::returnsConstChar();
    return result;
}
// returnsConstReferenceToPOD()
void *c_static_TestTargetNS__POD__returnsConstReferenceToPOD()
{
    const auto &result = const_cast<void *>(static_cast<const void *>(
        &TestBindings_wrappersNS::POD_wrapper::returnsConstReferenceToPOD()));
    return result;
}
// returnsPOD()
void *c_static_TestTargetNS__POD__returnsPOD()
{
    const auto &result = new Dartagnan::ValueWrapper<TestTargetNS::POD> {
        TestBindings_wrappersNS::POD_wrapper::returnsPOD()
    };
    return result;
}
// returnsPointerToPOD()
void *c_static_TestTargetNS__POD__returnsPointerToPOD()
{
    const auto &result = TestBindings_wrappersNS::POD_wrapper::returnsPointerToPOD();
    return result;
}
// returnsPointerToPolymorphic()
void *c_static_TestTargetNS__POD__returnsPointerToPolymorphic()
{
    const auto &result = TestBindings_wrappersNS::POD_wrapper::returnsPointerToPolymorphic();
    return result;
}
// returnsReferenceToPOD()
void *c_static_TestTargetNS__POD__returnsReferenceToPOD()
{
    const auto &result = &TestBindings_wrappersNS::POD_wrapper::returnsReferenceToPOD();
    return result;
}
// withDefaultAarg(int v)
void c_TestTargetNS__POD__withDefaultAarg_int(void *thisObj, int v)
{
    fromPtr(thisObj)->withDefaultAarg(v);
}
void c_TestTargetNS__POD__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
int c_TestTargetNS__POD___get_v1(void *thisObj)
{
    return fromPtr(thisObj)->v1;
}
int c_TestTargetNS__POD___get_v2(void *thisObj)
{
    return fromPtr(thisObj)->v2;
}
int c_TestTargetNS__POD___get_v3(void *thisObj)
{
    return fromPtr(thisObj)->v3;
}
int c_TestTargetNS__POD___get_v4_const(void *thisObj)
{
    return fromPtr(thisObj)->v4_const;
}
void c_TestTargetNS__POD___set_v1_int(void *thisObj, int v1_)
{
    fromPtr(thisObj)->v1 = v1_;
}
void c_TestTargetNS__POD___set_v2_int(void *thisObj, int v2_)
{
    fromPtr(thisObj)->v2 = v2_;
}
void c_TestTargetNS__POD___set_v3_int(void *thisObj, int v3_)
{
    fromPtr(thisObj)->v3 = v3_;
}
}
