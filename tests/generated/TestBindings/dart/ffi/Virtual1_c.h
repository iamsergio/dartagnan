#include "TestBindings_exports.h"
#include <test.h>

namespace TestBindings_wrappersNS {
class Virtual1_wrapper : public ::Virtual1
{
public:
    ~Virtual1_wrapper();
    Virtual1_wrapper();
    virtual void virtualMethod1();
    virtual void virtualMethod1_nocallback();
    typedef void (*Callback_virtualMethod1)(void *);
    Callback_virtualMethod1 m_virtualMethod1Callback = nullptr;
};
}
extern "C" {
// Virtual1::Virtual1()
TestBindings_EXPORT void *c_Virtual1__constructor();
// Virtual1::virtualMethod1()
TestBindings_EXPORT void c_Virtual1__virtualMethod1(void *thisObj);
TestBindings_EXPORT void c_Virtual1__destructor(void *thisObj);
TestBindings_EXPORT void c_Virtual1__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                   int methodId);
TestBindings_EXPORT void c_Virtual1_Finalizer(void *cppObj);
}
