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
namespace TestBindings_wrappersNS {namespace ExplicitNamespace2 {SimpleClash_wrapper::SimpleClash_wrapper(int arg__1) : ::NameClashingNS2::SimpleClash(arg__1) {}
int SimpleClash_wrapper::getFoo(){return ::NameClashingNS2::SimpleClash::getFoo();}
int SimpleClash_wrapper::getValueStatic(){return ::NameClashingNS2::SimpleClash::getValueStatic();}
NameClashingNS1::SimpleClash SimpleClash_wrapper::returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s){return ::NameClashingNS2::SimpleClash::returnsAndReceivesFromOtherScope(s);}
NameClashingNS1::SimpleClash SimpleClash_wrapper::returnsFromOtherScope(){return ::NameClashingNS2::SimpleClash::returnsFromOtherScope();}
SimpleClash_wrapper::~SimpleClash_wrapper() {}

}}static NameClashingNS2::SimpleClash* fromPtr(void *ptr)
{return reinterpret_cast<NameClashingNS2::SimpleClash*>(ptr);}static TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper* fromWrapperPtr(void *ptr)
{return reinterpret_cast<TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper*>(ptr);}extern "C" {
 void c_NameClashingNS2__SimpleClash_Finalizer(void *cppObj){delete reinterpret_cast<TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper *>(cppObj);}void * c_NameClashingNS2__SimpleClash__constructor_int(int arg__1)
{
auto ptr = new TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper(arg__1);return reinterpret_cast<void*>(ptr);}
//getFoo()
int c_NameClashingNS2__SimpleClash__getFoo(void *thisObj){const auto &result = fromPtr(thisObj)->getFoo();return result;}
//getValueStatic()
int c_static_NameClashingNS2__SimpleClash__getValueStatic(){const auto &result = TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper::getValueStatic();return result;}
//returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s)
void* c_static_NameClashingNS2__SimpleClash__returnsAndReceivesFromOtherScope_SimpleClash(void* s_){assert(s_);
auto &s = *reinterpret_cast<NameClashingNS1::SimpleClash *>(s_);const auto &result = new Dartagnan::ValueWrapper<NameClashingNS1::SimpleClash>{TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper::returnsAndReceivesFromOtherScope(s)};return result;}
//returnsFromOtherScope()
void* c_static_NameClashingNS2__SimpleClash__returnsFromOtherScope(){const auto &result = new Dartagnan::ValueWrapper<NameClashingNS1::SimpleClash>{TestBindings_wrappersNS::ExplicitNamespace2::SimpleClash_wrapper::returnsFromOtherScope()};return result;}
void c_NameClashingNS2__SimpleClash__destructor(void *thisObj)
{
delete fromPtr(thisObj);}
}
