#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {namespace ExplicitNamespace2 {class SimpleClash_wrapper : public ::NameClashingNS2::SimpleClash {public:
~SimpleClash_wrapper(); SimpleClash_wrapper(int arg__1);int getFoo();static int getValueStatic();static NameClashingNS1::SimpleClash returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s);static NameClashingNS1::SimpleClash returnsFromOtherScope();

};
}}extern "C" {
// NameClashingNS2::SimpleClash::SimpleClash(int arg__1)
TestBindings_EXPORT void * c_NameClashingNS2__SimpleClash__constructor_int(int arg__1);
// NameClashingNS2::SimpleClash::getFoo()
TestBindings_EXPORT int c_NameClashingNS2__SimpleClash__getFoo(void *thisObj);
// NameClashingNS2::SimpleClash::getValueStatic()
TestBindings_EXPORT int c_static_NameClashingNS2__SimpleClash__getValueStatic();
// NameClashingNS2::SimpleClash::returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s)
TestBindings_EXPORT void* c_static_NameClashingNS2__SimpleClash__returnsAndReceivesFromOtherScope_SimpleClash(void* s_);
// NameClashingNS2::SimpleClash::returnsFromOtherScope()
TestBindings_EXPORT void* c_static_NameClashingNS2__SimpleClash__returnsFromOtherScope();
TestBindings_EXPORT void c_NameClashingNS2__SimpleClash__destructor(void *thisObj);
TestBindings_EXPORT  void c_NameClashingNS2__SimpleClash_Finalizer(void *cppObj);}
