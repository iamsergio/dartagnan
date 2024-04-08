#include "TestBindings_exports.h"
#include <test.h>

extern "C" {
TestBindings_EXPORT void c_NameClashingNS1_Finalizer(void *cppObj);
}
