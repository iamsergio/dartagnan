#include "TestBindings_exports.h"
#include <qstring.h>
#include <test.h>

extern "C" {
// AnotherNamespace::size(QString s)
TestBindings_EXPORT void *c_static_AnotherNamespace__size_QString(const char *s_);
TestBindings_EXPORT void c_AnotherNamespace_Finalizer(void *cppObj);
}
