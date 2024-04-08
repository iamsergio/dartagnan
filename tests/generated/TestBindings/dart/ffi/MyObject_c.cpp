#include "MyObject_c.h"


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
namespace TestBindings_wrappersNS {
MyObject_wrapper::MyObject_wrapper(QObject *parent)
    : ::MyObject(parent)
{
}
void MyObject_wrapper::customEvent(QEvent *event)
{
    if (m_customEventCallback) {
        const void *thisPtr = this;
        m_customEventCallback(const_cast<void *>(thisPtr), event);
    } else {
        ::MyObject::customEvent(event);
    }
}
void MyObject_wrapper::customEvent_nocallback(QEvent *event)
{
    ::MyObject::customEvent(event);
}
bool MyObject_wrapper::event(QEvent *event)
{
    if (m_eventCallback) {
        const void *thisPtr = this;
        return m_eventCallback(const_cast<void *>(thisPtr), event);
    } else {
        return ::MyObject::event(event);
    }
}
bool MyObject_wrapper::event_nocallback(QEvent *event)
{
    return ::MyObject::event(event);
}
bool MyObject_wrapper::eventFilter(QObject *watched, QEvent *event)
{
    if (m_eventFilterCallback) {
        const void *thisPtr = this;
        return m_eventFilterCallback(const_cast<void *>(thisPtr), watched, event);
    } else {
        return ::MyObject::eventFilter(watched, event);
    }
}
bool MyObject_wrapper::eventFilter_nocallback(QObject *watched, QEvent *event)
{
    return ::MyObject::eventFilter(watched, event);
}
void MyObject_wrapper::pureVirtual()
{
    if (m_pureVirtualCallback) {
        const void *thisPtr = this;
        m_pureVirtualCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "pureVirtual: Warning: Calling pure-virtual\n";
        return;
    }
}
void MyObject_wrapper::pureVirtual_nocallback()
{
    std::cerr << "pureVirtual: Warning: Calling pure-virtual\n";
    return;
}
void MyObject_wrapper::receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo)
{
    ::MyObject::receivesEnumClassWithDefaultArg(foo);
}
void MyObject_wrapper::receivesEnumClassWithDefaultArg(MyEnumClass foo)
{
    ::MyObject::receivesEnumClassWithDefaultArg(foo);
}
MyEnumClass MyObject_wrapper::returnsEnumClass()
{
    return ::MyObject::returnsEnumClass();
}
QString MyObject_wrapper::tr(const char *s, const char *c, int n)
{
    return ::MyObject::tr(s, c, n);
}
void MyObject_wrapper::valueChanged(int arg__1)
{
    ::MyObject::valueChanged(arg__1);
}
int MyObject_wrapper::virtualFunc()
{
    if (m_virtualFuncCallback) {
        const void *thisPtr = this;
        return m_virtualFuncCallback(const_cast<void *>(thisPtr));
    } else {
        return ::MyObject::virtualFunc();
    }
}
int MyObject_wrapper::virtualFunc_nocallback()
{
    return ::MyObject::virtualFunc();
}
const char *MyObject_wrapper::virtualMethodReturningConstChar() const
{
    if (m_virtualMethodReturningConstCharCallback) {
        const void *thisPtr = this;
        return m_virtualMethodReturningConstCharCallback(const_cast<void *>(thisPtr));
    } else {
        return ::MyObject::virtualMethodReturningConstChar();
    }
}
const char *MyObject_wrapper::virtualMethodReturningConstChar_nocallback() const
{
    return ::MyObject::virtualMethodReturningConstChar();
}
void MyObject_wrapper::virtualReceivingQString(const QString &str)
{
    if (m_virtualReceivingQStringCallback) {
        const void *thisPtr = this;
        m_virtualReceivingQStringCallback(const_cast<void *>(thisPtr), str);
    } else {
        ::MyObject::virtualReceivingQString(str);
    }
}
void MyObject_wrapper::virtualReceivingQString_nocallback(const QString &str)
{
    ::MyObject::virtualReceivingQString(str);
}
int MyObject_wrapper::virtualReturningInt() const
{
    if (m_virtualReturningIntCallback) {
        const void *thisPtr = this;
        return m_virtualReturningIntCallback(const_cast<void *>(thisPtr));
    } else {
        return ::MyObject::virtualReturningInt();
    }
}
int MyObject_wrapper::virtualReturningInt_nocallback() const
{
    return ::MyObject::virtualReturningInt();
}
MyObject_wrapper::~MyObject_wrapper()
{
}

}
static MyObject *fromPtr(void *ptr)
{
    return reinterpret_cast<MyObject *>(ptr);
}
static TestBindings_wrappersNS::MyObject_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper *>(ptr);
}
extern "C" {
void c_MyObject_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper *>(cppObj);
}
void *c_MyObject__constructor_QObject(void *parent_)
{
    auto parent = reinterpret_cast<QObject *>(parent_);
    auto ptr = new TestBindings_wrappersNS::MyObject_wrapper(parent);
    return reinterpret_cast<void *>(ptr);
}
// customEvent(QEvent * event)
void c_MyObject__customEvent_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    fromWrapperPtr(thisObj)->customEvent_nocallback(event);
}
void c_MyObject__onDestroyed_QObject(void *thisObj, void *contextQObject, void *callback)
{
    auto instance = reinterpret_cast<MyObject *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &MyObject::destroyed, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// event(QEvent * event)
bool c_MyObject__event_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->event_nocallback(event);
        } else {
            return targetPtr->event(event);
        }
    }();
    return result;
}
// eventFilter(QObject * watched, QEvent * event)
bool c_MyObject__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_)
{
    auto watched = reinterpret_cast<QObject *>(watched_);
    auto event = reinterpret_cast<QEvent *>(event_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->eventFilter_nocallback(watched, event);
        } else {
            return targetPtr->eventFilter(watched, event);
        }
    }();
    return result;
}
// pureVirtual()
void c_MyObject__pureVirtual(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->pureVirtual_nocallback();
        } else {
            return targetPtr->pureVirtual();
        }
    }();
}
// receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo)
void c_MyObject__receivesEnumClassWithDefaultArg_MyNamespacedEnumClass(void *thisObj, int foo)
{
    fromPtr(thisObj)->receivesEnumClassWithDefaultArg(
        static_cast<AnotherNamespace::MyNamespacedEnumClass>(foo));
}
// receivesEnumClassWithDefaultArg(MyEnumClass foo)
void c_MyObject__receivesEnumClassWithDefaultArg_MyEnumClass(void *thisObj, int foo)
{
    fromPtr(thisObj)->receivesEnumClassWithDefaultArg(static_cast<MyEnumClass>(foo));
}
// returnsEnumClass()
int c_MyObject__returnsEnumClass(void *thisObj)
{
    const auto &result = int(fromPtr(thisObj)->returnsEnumClass());
    return result;
}
// tr(const char * s, const char * c, int n)
void *c_static_MyObject__tr_char_char_int(const char *s, const char *c, int n)
{
    const auto &result =
        new Dartagnan::ValueWrapper<QString> { TestBindings_wrappersNS::MyObject_wrapper::tr(s, c,
                                                                                             n) };
    free(( char * )s);
    free(( char * )c);
    return result;
}
// valueChanged(int arg__1)
void c_MyObject__valueChanged_int(void *thisObj, int arg__1)
{
    fromPtr(thisObj)->valueChanged(arg__1);
}
void c_MyObject__onValueChanged_int(void *thisObj, void *contextQObject, void *callback)
{
    auto instance = reinterpret_cast<MyObject *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &MyObject::valueChanged, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// virtualFunc()
int c_MyObject__virtualFunc(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualFunc_nocallback();
        } else {
            return targetPtr->virtualFunc();
        }
    }();
    return result;
}
// virtualMethodReturningConstChar() const
const char *c_MyObject__virtualMethodReturningConstChar(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethodReturningConstChar_nocallback();
        } else {
            return targetPtr->virtualMethodReturningConstChar();
        }
    }();
    return result;
}
// virtualReceivingQString(const QString & str)
void c_MyObject__virtualReceivingQString_QString(void *thisObj, const char *str_)
{
    const auto str = QString::fromUtf8(str_);
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingQString_nocallback(str);
        } else {
            return targetPtr->virtualReceivingQString(str);
        }
    }();
    free(( char * )str_);
}
// virtualReturningInt() const
int c_MyObject__virtualReturningInt(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::MyObject_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningInt_nocallback();
        } else {
            return targetPtr->virtualReturningInt();
        }
    }();
    return result;
}
void c_MyObject__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_MyObject__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 481:
        wrapper->m_customEventCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper::Callback_customEvent>(
                callback);
        break;
    case 490:
        wrapper->m_eventCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper::Callback_event>(callback);
        break;
    case 491:
        wrapper->m_eventFilterCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper::Callback_eventFilter>(
                callback);
        break;
    case 1166:
        wrapper->m_pureVirtualCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper::Callback_pureVirtual>(
                callback);
        break;
    case 1181:
        wrapper->m_virtualFuncCallback =
            reinterpret_cast<TestBindings_wrappersNS::MyObject_wrapper::Callback_virtualFunc>(
                callback);
        break;
    case 1182:
        wrapper->m_virtualMethodReturningConstCharCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyObject_wrapper::Callback_virtualMethodReturningConstChar>(
            callback);
        break;
    case 1183:
        wrapper->m_virtualReceivingQStringCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyObject_wrapper::Callback_virtualReceivingQString>(callback);
        break;
    case 1184:
        wrapper->m_virtualReturningIntCallback = reinterpret_cast<
            TestBindings_wrappersNS::MyObject_wrapper::Callback_virtualReturningInt>(callback);
        break;
    }
}
}
