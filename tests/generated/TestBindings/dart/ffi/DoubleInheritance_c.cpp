#include "DoubleInheritance_c.h"


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
DoubleInheritance_wrapper::DoubleInheritance_wrapper()
    : ::DoubleInheritance()
{
}
void DoubleInheritance_wrapper::customEvent(QEvent *event)
{
    if (m_customEventCallback) {
        const void *thisPtr = this;
        m_customEventCallback(const_cast<void *>(thisPtr), event);
    } else {
        ::DoubleInheritance::customEvent(event);
    }
}
void DoubleInheritance_wrapper::customEvent_nocallback(QEvent *event)
{
    ::DoubleInheritance::customEvent(event);
}
bool DoubleInheritance_wrapper::event(QEvent *event)
{
    if (m_eventCallback) {
        const void *thisPtr = this;
        return m_eventCallback(const_cast<void *>(thisPtr), event);
    } else {
        return ::DoubleInheritance::event(event);
    }
}
bool DoubleInheritance_wrapper::event_nocallback(QEvent *event)
{
    return ::DoubleInheritance::event(event);
}
bool DoubleInheritance_wrapper::eventFilter(QObject *watched, QEvent *event)
{
    if (m_eventFilterCallback) {
        const void *thisPtr = this;
        return m_eventFilterCallback(const_cast<void *>(thisPtr), watched, event);
    } else {
        return ::DoubleInheritance::eventFilter(watched, event);
    }
}
bool DoubleInheritance_wrapper::eventFilter_nocallback(QObject *watched, QEvent *event)
{
    return ::DoubleInheritance::eventFilter(watched, event);
}
int DoubleInheritance_wrapper::nonVirtualCallsVirtualFrom2ndBase() const
{
    return ::DoubleInheritance::nonVirtualCallsVirtualFrom2ndBase();
}
void DoubleInheritance_wrapper::pureVirtual()
{
    if (m_pureVirtualCallback) {
        const void *thisPtr = this;
        m_pureVirtualCallback(const_cast<void *>(thisPtr));
    } else {
        std::cerr << "pureVirtual: Warning: Calling pure-virtual\n";
        return;
    }
}
void DoubleInheritance_wrapper::pureVirtual_nocallback()
{
    std::cerr << "pureVirtual: Warning: Calling pure-virtual\n";
    return;
}
int DoubleInheritance_wrapper::virtualFunc()
{
    if (m_virtualFuncCallback) {
        const void *thisPtr = this;
        return m_virtualFuncCallback(const_cast<void *>(thisPtr));
    } else {
        return ::DoubleInheritance::virtualFunc();
    }
}
int DoubleInheritance_wrapper::virtualFunc_nocallback()
{
    return ::DoubleInheritance::virtualFunc();
}
const char *DoubleInheritance_wrapper::virtualMethodReturningConstChar() const
{
    if (m_virtualMethodReturningConstCharCallback) {
        const void *thisPtr = this;
        return m_virtualMethodReturningConstCharCallback(const_cast<void *>(thisPtr));
    } else {
        return ::DoubleInheritance::virtualMethodReturningConstChar();
    }
}
const char *DoubleInheritance_wrapper::virtualMethodReturningConstChar_nocallback() const
{
    return ::DoubleInheritance::virtualMethodReturningConstChar();
}
void DoubleInheritance_wrapper::virtualReceivingQString(const QString &str)
{
    if (m_virtualReceivingQStringCallback) {
        const void *thisPtr = this;
        m_virtualReceivingQStringCallback(const_cast<void *>(thisPtr), str);
    } else {
        ::DoubleInheritance::virtualReceivingQString(str);
    }
}
void DoubleInheritance_wrapper::virtualReceivingQString_nocallback(const QString &str)
{
    ::DoubleInheritance::virtualReceivingQString(str);
}
int DoubleInheritance_wrapper::virtualReturningInt() const
{
    if (m_virtualReturningIntCallback) {
        const void *thisPtr = this;
        return m_virtualReturningIntCallback(const_cast<void *>(thisPtr));
    } else {
        return ::DoubleInheritance::virtualReturningInt();
    }
}
int DoubleInheritance_wrapper::virtualReturningInt_nocallback() const
{
    return ::DoubleInheritance::virtualReturningInt();
}
DoubleInheritance_wrapper::~DoubleInheritance_wrapper()
{
}

}
static DoubleInheritance *fromPtr(void *ptr)
{
    return reinterpret_cast<DoubleInheritance *>(ptr);
}
static TestBindings_wrappersNS::DoubleInheritance_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(ptr);
}
extern "C" {
void c_DoubleInheritance_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(cppObj);
}
void *c_DoubleInheritance__constructor()
{
    auto ptr = new TestBindings_wrappersNS::DoubleInheritance_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// customEvent(QEvent * event)
void c_DoubleInheritance__customEvent_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    fromWrapperPtr(thisObj)->customEvent_nocallback(event);
}
// event(QEvent * event)
bool c_DoubleInheritance__event_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->event_nocallback(event);
        } else {
            return targetPtr->event(event);
        }
    }();
    return result;
}
// eventFilter(QObject * watched, QEvent * event)
bool c_DoubleInheritance__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_)
{
    auto watched = reinterpret_cast<QObject *>(watched_);
    auto event = reinterpret_cast<QEvent *>(event_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->eventFilter_nocallback(watched, event);
        } else {
            return targetPtr->eventFilter(watched, event);
        }
    }();
    return result;
}
// nonVirtualCallsVirtualFrom2ndBase() const
int c_DoubleInheritance__nonVirtualCallsVirtualFrom2ndBase(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->nonVirtualCallsVirtualFrom2ndBase();
    return result;
}
// pureVirtual()
void c_DoubleInheritance__pureVirtual(void *thisObj)
{
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->pureVirtual_nocallback();
        } else {
            return targetPtr->pureVirtual();
        }
    }();
}
void c_DoubleInheritance__onValueChanged_int(void *thisObj, void *contextQObject, void *callback)
{
    auto instance = reinterpret_cast<DoubleInheritance *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &DoubleInheritance::valueChanged, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// virtualFunc()
int c_DoubleInheritance__virtualFunc(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualFunc_nocallback();
        } else {
            return targetPtr->virtualFunc();
        }
    }();
    return result;
}
// virtualMethodReturningConstChar() const
const char *c_DoubleInheritance__virtualMethodReturningConstChar(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualMethodReturningConstChar_nocallback();
        } else {
            return targetPtr->virtualMethodReturningConstChar();
        }
    }();
    return result;
}
// virtualReceivingQString(const QString & str)
void c_DoubleInheritance__virtualReceivingQString_QString(void *thisObj, const char *str_)
{
    const auto str = QString::fromUtf8(str_);
    [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReceivingQString_nocallback(str);
        } else {
            return targetPtr->virtualReceivingQString(str);
        }
    }();
    free(( char * )str_);
}
// virtualReturningInt() const
int c_DoubleInheritance__virtualReturningInt(void *thisObj)
{
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->virtualReturningInt_nocallback();
        } else {
            return targetPtr->virtualReturningInt();
        }
    }();
    return result;
}
void c_DoubleInheritance__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_DoubleInheritance__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 481:
        wrapper->m_customEventCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_customEvent>(callback);
        break;
    case 490:
        wrapper->m_eventCallback =
            reinterpret_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_event>(
                callback);
        break;
    case 491:
        wrapper->m_eventFilterCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_eventFilter>(callback);
        break;
    case 1166:
        wrapper->m_pureVirtualCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_pureVirtual>(callback);
        break;
    case 1181:
        wrapper->m_virtualFuncCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_virtualFunc>(callback);
        break;
    case 1182:
        wrapper->m_virtualMethodReturningConstCharCallback =
            reinterpret_cast<TestBindings_wrappersNS::DoubleInheritance_wrapper::
                                 Callback_virtualMethodReturningConstChar>(callback);
        break;
    case 1183:
        wrapper->m_virtualReceivingQStringCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_virtualReceivingQString>(
            callback);
        break;
    case 1184:
        wrapper->m_virtualReturningIntCallback = reinterpret_cast<
            TestBindings_wrappersNS::DoubleInheritance_wrapper::Callback_virtualReturningInt>(
            callback);
        break;
    }
}
}
