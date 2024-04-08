#include "TestBindings_exports.h"
#include <test.h>

extern "C" {
TestBindings_EXPORT int c___globalFunction();
TestBindings_EXPORT int c___receivesStructAsOptionalArgument_EmptyStruct(void *arg1_);
TestBindings_EXPORT int c___receivesStructAsOptionalArgument2_EmptyStruct(void *arg__1_);
TestBindings_EXPORT int c_static___receivingPureAbstract_PureAbstract(void *a_);
TestBindings_EXPORT void *c_static___returnsPureAbstract();
}
