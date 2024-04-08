#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class Virtual2_wrapper : public ::Virtual2
{
public:
    ~Virtual2_wrapper();
    Virtual2_wrapper();
    virtual void virtualMethod2();
    virtual void virtualMethod2_nocallback();
    typedef void (*Callback_virtualMethod2)(void *);
    Callback_virtualMethod2 m_virtualMethod2Callback = nullptr;
};
}
extern "C" {
// Virtual2::Virtual2()
TestBindings_EXPORT void *c_Virtual2__constructor();
// Virtual2::virtualMethod2()
TestBindings_EXPORT void c_Virtual2__virtualMethod2(void *thisObj);
TestBindings_EXPORT void c_Virtual2__destructor(void *thisObj);
TestBindings_EXPORT void c_Virtual2__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                   int methodId);
TestBindings_EXPORT void c_Virtual2_Finalizer(void *cppObj);
}
