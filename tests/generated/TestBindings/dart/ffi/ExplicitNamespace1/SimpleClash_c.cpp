#include "SimpleClash_c.h"


#include <iostream>

#include <cassert>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
namespace TestBindings_wrappersNS {namespace ExplicitNamespace1 {SimpleClash_wrapper::SimpleClash_wrapper(int arg__1) : ::NameClashingNS1::SimpleClash(arg__1) {}
int SimpleClash_wrapper::getValue(){return ::NameClashingNS1::SimpleClash::getValue();}
int SimpleClash_wrapper::getValueStatic(){return ::NameClashingNS1::SimpleClash::getValueStatic();}
SimpleClash_wrapper::~SimpleClash_wrapper() {}

}}static NameClashingNS1::SimpleClash* fromPtr(void *ptr)
{return reinterpret_cast<NameClashingNS1::SimpleClash*>(ptr);}static TestBindings_wrappersNS::ExplicitNamespace1::SimpleClash_wrapper* fromWrapperPtr(void *ptr)
{return reinterpret_cast<TestBindings_wrappersNS::ExplicitNamespace1::SimpleClash_wrapper*>(ptr);}extern "C" {
 void c_NameClashingNS1__SimpleClash_Finalizer(void *cppObj){delete reinterpret_cast<TestBindings_wrappersNS::ExplicitNamespace1::SimpleClash_wrapper *>(cppObj);}void * c_NameClashingNS1__SimpleClash__constructor_int(int arg__1)
{
auto ptr = new TestBindings_wrappersNS::ExplicitNamespace1::SimpleClash_wrapper(arg__1);return reinterpret_cast<void*>(ptr);}
//getValue()
int c_NameClashingNS1__SimpleClash__getValue(void *thisObj){const auto &result = fromPtr(thisObj)->getValue();return result;}
//getValueStatic()
int c_static_NameClashingNS1__SimpleClash__getValueStatic(){const auto &result = TestBindings_wrappersNS::ExplicitNamespace1::SimpleClash_wrapper::getValueStatic();return result;}
void c_NameClashingNS1__SimpleClash__destructor(void *thisObj)
{
delete fromPtr(thisObj);}
}
