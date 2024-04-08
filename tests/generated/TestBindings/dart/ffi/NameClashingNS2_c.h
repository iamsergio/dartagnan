#include "TestBindings_exports.h"
#include <test.h>

extern "C" {
TestBindings_EXPORT void c_NameClashingNS2_Finalizer(void *cppObj);
}
