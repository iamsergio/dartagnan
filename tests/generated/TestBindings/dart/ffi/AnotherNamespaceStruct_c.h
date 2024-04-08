#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class AnotherNamespaceStruct_wrapper : public ::AnotherNamespace::AnotherNamespaceStruct
{
public:
    ~AnotherNamespaceStruct_wrapper();
    AnotherNamespaceStruct_wrapper();
    void receivesEnumerator(AnotherNamespace::NamespaceLevelEnum arg__1 =
                                AnotherNamespace::NamespaceLevelEnum::NamespaceLevelEnum_value2);
};
}
extern "C" {
// AnotherNamespace::AnotherNamespaceStruct::AnotherNamespaceStruct()
TestBindings_EXPORT void *c_AnotherNamespace__AnotherNamespaceStruct__constructor();
// AnotherNamespace::AnotherNamespaceStruct::receivesEnumerator(AnotherNamespace::NamespaceLevelEnum
// arg__1)
TestBindings_EXPORT void
c_AnotherNamespace__AnotherNamespaceStruct__receivesEnumerator_NamespaceLevelEnum(void *thisObj,
                                                                                  int arg__1);
TestBindings_EXPORT void c_AnotherNamespace__AnotherNamespaceStruct__destructor(void *thisObj);
TestBindings_EXPORT void c_AnotherNamespace__AnotherNamespaceStruct_Finalizer(void *cppObj);
}
