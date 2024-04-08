#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class POD_wrapper : public ::TestTargetNS::POD
{
public:
    ~POD_wrapper();
    POD_wrapper();
    POD_wrapper(int a, int b, int c, int d);
    int calculate() const;
    static int calculateStatic();
    static int doStuffOnMyClass(TestTargetNS::MyBaseClass *myarg);
    const int &intByConstRef() const;
    static int receivesConstPointerToPODs(const TestTargetNS::POD *ptrPod1,
                                          const TestTargetNS::POD *ptrPod2);
    static int receivesConstRefPODs(const TestTargetNS::POD &pod1, const TestTargetNS::POD &pod2);
    void receivesNamespaceEnum(int v = AnotherNamespace::NamespaceLevelEnum_value1 + 1);
    void receivesNamespaceEnum1(
        AnotherNamespace::NamespaceLevelEnum arg__1 = AnotherNamespace::NamespaceLevelEnum_value1);
    static int receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2);
    static int receivesPointerToPODs(TestTargetNS::POD *ptrPod1, TestTargetNS::POD *ptrPod2);
    static int receivesRefPODs(TestTargetNS::POD &pod1, TestTargetNS::POD &pod2);
    void receivesReservedDartKeyword(int var);
    static char returnsChar();
    static const char returnsConstChar();
    static const TestTargetNS::POD &returnsConstReferenceToPOD();
    static TestTargetNS::POD returnsPOD();
    static TestTargetNS::POD *returnsPointerToPOD();
    static TestTargetNS::MyBaseClass *returnsPointerToPolymorphic();
    static TestTargetNS::POD &returnsReferenceToPOD();
    void withDefaultAarg(int v = 2);
};
}
extern "C" {
// TestTargetNS::POD::POD()
TestBindings_EXPORT void *c_TestTargetNS__POD__constructor();
// TestTargetNS::POD::POD(int a, int b, int c, int d)
TestBindings_EXPORT void *c_TestTargetNS__POD__constructor_int_int_int_int(int a, int b, int c,
                                                                           int d);
// TestTargetNS::POD::calculate() const
TestBindings_EXPORT int c_TestTargetNS__POD__calculate(void *thisObj);
// TestTargetNS::POD::calculateStatic()
TestBindings_EXPORT int c_static_TestTargetNS__POD__calculateStatic();
// TestTargetNS::POD::doStuffOnMyClass(TestTargetNS::MyBaseClass * myarg)
TestBindings_EXPORT int c_static_TestTargetNS__POD__doStuffOnMyClass_MyBaseClass(void *myarg_);
// TestTargetNS::POD::intByConstRef() const
TestBindings_EXPORT int c_TestTargetNS__POD__intByConstRef(void *thisObj);
// TestTargetNS::POD::receivesConstPointerToPODs(const TestTargetNS::POD * ptrPod1, const
// TestTargetNS::POD * ptrPod2)
TestBindings_EXPORT int
c_static_TestTargetNS__POD__receivesConstPointerToPODs_POD_POD(void *ptrPod1_, void *ptrPod2_);
// TestTargetNS::POD::receivesConstRefPODs(const TestTargetNS::POD & pod1, const TestTargetNS::POD &
// pod2)
TestBindings_EXPORT int c_static_TestTargetNS__POD__receivesConstRefPODs_POD_POD(void *pod1_,
                                                                                 void *pod2_);
// TestTargetNS::POD::receivesNamespaceEnum(int v)
TestBindings_EXPORT void c_TestTargetNS__POD__receivesNamespaceEnum_int(void *thisObj, int v);
// TestTargetNS::POD::receivesNamespaceEnum1(AnotherNamespace::NamespaceLevelEnum arg__1)
TestBindings_EXPORT void
c_TestTargetNS__POD__receivesNamespaceEnum1_NamespaceLevelEnum(void *thisObj, int arg__1);
// TestTargetNS::POD::receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2)
TestBindings_EXPORT int c_static_TestTargetNS__POD__receivesPODs_POD_POD(void *pod1_, void *pod2_);
// TestTargetNS::POD::receivesPointerToPODs(TestTargetNS::POD * ptrPod1, TestTargetNS::POD *
// ptrPod2)
TestBindings_EXPORT int c_static_TestTargetNS__POD__receivesPointerToPODs_POD_POD(void *ptrPod1_,
                                                                                  void *ptrPod2_);
// TestTargetNS::POD::receivesRefPODs(TestTargetNS::POD & pod1, TestTargetNS::POD & pod2)
TestBindings_EXPORT int c_static_TestTargetNS__POD__receivesRefPODs_POD_POD(void *pod1_,
                                                                            void *pod2_);
// TestTargetNS::POD::receivesReservedDartKeyword(int var)
TestBindings_EXPORT void c_TestTargetNS__POD__receivesReservedDartKeyword_int(void *thisObj,
                                                                              int var);
// TestTargetNS::POD::returnsChar()
TestBindings_EXPORT char c_static_TestTargetNS__POD__returnsChar();
// TestTargetNS::POD::returnsConstChar()
TestBindings_EXPORT char c_static_TestTargetNS__POD__returnsConstChar();
// TestTargetNS::POD::returnsConstReferenceToPOD()
TestBindings_EXPORT void *c_static_TestTargetNS__POD__returnsConstReferenceToPOD();
// TestTargetNS::POD::returnsPOD()
TestBindings_EXPORT void *c_static_TestTargetNS__POD__returnsPOD();
// TestTargetNS::POD::returnsPointerToPOD()
TestBindings_EXPORT void *c_static_TestTargetNS__POD__returnsPointerToPOD();
// TestTargetNS::POD::returnsPointerToPolymorphic()
TestBindings_EXPORT void *c_static_TestTargetNS__POD__returnsPointerToPolymorphic();
// TestTargetNS::POD::returnsReferenceToPOD()
TestBindings_EXPORT void *c_static_TestTargetNS__POD__returnsReferenceToPOD();
// TestTargetNS::POD::withDefaultAarg(int v)
TestBindings_EXPORT void c_TestTargetNS__POD__withDefaultAarg_int(void *thisObj, int v);
TestBindings_EXPORT void c_TestTargetNS__POD__destructor(void *thisObj);
TestBindings_EXPORT int c_TestTargetNS__POD___get_v1(void *thisObj);
TestBindings_EXPORT int c_TestTargetNS__POD___get_v2(void *thisObj);
TestBindings_EXPORT int c_TestTargetNS__POD___get_v3(void *thisObj);
TestBindings_EXPORT int c_TestTargetNS__POD___get_v4_const(void *thisObj);
TestBindings_EXPORT void c_TestTargetNS__POD___set_v1_int(void *thisObj, int v1_);
TestBindings_EXPORT void c_TestTargetNS__POD___set_v2_int(void *thisObj, int v2_);
TestBindings_EXPORT void c_TestTargetNS__POD___set_v3_int(void *thisObj, int v3_);
TestBindings_EXPORT void c_TestTargetNS__POD_Finalizer(void *cppObj);
}
