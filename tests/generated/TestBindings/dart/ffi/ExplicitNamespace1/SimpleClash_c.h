#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {namespace ExplicitNamespace1 {class SimpleClash_wrapper : public ::NameClashingNS1::SimpleClash {public:
~SimpleClash_wrapper(); SimpleClash_wrapper(int arg__1);int getValue();static int getValueStatic();

};
}}extern "C" {
// NameClashingNS1::SimpleClash::SimpleClash(int arg__1)
TestBindings_EXPORT void * c_NameClashingNS1__SimpleClash__constructor_int(int arg__1);
// NameClashingNS1::SimpleClash::getValue()
TestBindings_EXPORT int c_NameClashingNS1__SimpleClash__getValue(void *thisObj);
// NameClashingNS1::SimpleClash::getValueStatic()
TestBindings_EXPORT int c_static_NameClashingNS1__SimpleClash__getValueStatic();
TestBindings_EXPORT void c_NameClashingNS1__SimpleClash__destructor(void *thisObj);
TestBindings_EXPORT  void c_NameClashingNS1__SimpleClash_Finalizer(void *cppObj);}
