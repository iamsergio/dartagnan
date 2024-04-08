#include "QApplication_c.h"


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
void QApplication_wrapper::aboutQt()
{
    ::QApplication::aboutQt();
}
bool QApplication_wrapper::autoSipEnabled() const
{
    return ::QApplication::autoSipEnabled();
}
void QApplication_wrapper::beep()
{
    ::QApplication::beep();
}
void QApplication_wrapper::closeAllWindows()
{
    ::QApplication::closeAllWindows();
}
int QApplication_wrapper::cursorFlashTime()
{
    return ::QApplication::cursorFlashTime();
}
void QApplication_wrapper::customEvent(QEvent *event)
{
    if (m_customEventCallback) {
        const void *thisPtr = this;
        m_customEventCallback(const_cast<void *>(thisPtr), event);
    } else {
        ::QApplication::customEvent(event);
    }
}
void QApplication_wrapper::customEvent_nocallback(QEvent *event)
{
    ::QApplication::customEvent(event);
}
int QApplication_wrapper::doubleClickInterval()
{
    return ::QApplication::doubleClickInterval();
}
bool QApplication_wrapper::event(QEvent *arg__1)
{
    if (m_eventCallback) {
        const void *thisPtr = this;
        return m_eventCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::QApplication::event(arg__1);
    }
}
bool QApplication_wrapper::event_nocallback(QEvent *arg__1)
{
    return ::QApplication::event(arg__1);
}
bool QApplication_wrapper::eventFilter(QObject *watched, QEvent *event)
{
    if (m_eventFilterCallback) {
        const void *thisPtr = this;
        return m_eventFilterCallback(const_cast<void *>(thisPtr), watched, event);
    } else {
        return ::QApplication::eventFilter(watched, event);
    }
}
bool QApplication_wrapper::eventFilter_nocallback(QObject *watched, QEvent *event)
{
    return ::QApplication::eventFilter(watched, event);
}
int QApplication_wrapper::exec()
{
    return ::QApplication::exec();
}
int QApplication_wrapper::keyboardInputInterval()
{
    return ::QApplication::keyboardInputInterval();
}
bool QApplication_wrapper::notify(QObject *arg__1, QEvent *arg__2)
{
    if (m_notifyCallback) {
        const void *thisPtr = this;
        return m_notifyCallback(const_cast<void *>(thisPtr), arg__1, arg__2);
    } else {
        return ::QApplication::notify(arg__1, arg__2);
    }
}
bool QApplication_wrapper::notify_nocallback(QObject *arg__1, QEvent *arg__2)
{
    return ::QApplication::notify(arg__1, arg__2);
}
void QApplication_wrapper::setAutoSipEnabled(const bool enabled)
{
    ::QApplication::setAutoSipEnabled(enabled);
}
void QApplication_wrapper::setCursorFlashTime(int arg__1)
{
    ::QApplication::setCursorFlashTime(arg__1);
}
void QApplication_wrapper::setDoubleClickInterval(int arg__1)
{
    ::QApplication::setDoubleClickInterval(arg__1);
}
void QApplication_wrapper::setKeyboardInputInterval(int arg__1)
{
    ::QApplication::setKeyboardInputInterval(arg__1);
}
void QApplication_wrapper::setStartDragDistance(int l)
{
    ::QApplication::setStartDragDistance(l);
}
void QApplication_wrapper::setStartDragTime(int ms)
{
    ::QApplication::setStartDragTime(ms);
}
void QApplication_wrapper::setStyleSheet(const QString &sheet)
{
    ::QApplication::setStyleSheet(sheet);
}
void QApplication_wrapper::setWheelScrollLines(int arg__1)
{
    ::QApplication::setWheelScrollLines(arg__1);
}
int QApplication_wrapper::startDragDistance()
{
    return ::QApplication::startDragDistance();
}
int QApplication_wrapper::startDragTime()
{
    return ::QApplication::startDragTime();
}
QString QApplication_wrapper::styleSheet() const
{
    return ::QApplication::styleSheet();
}
QString QApplication_wrapper::tr(const char *s, const char *c, int n)
{
    return ::QApplication::tr(s, c, n);
}
int QApplication_wrapper::wheelScrollLines()
{
    return ::QApplication::wheelScrollLines();
}
QApplication_wrapper::~QApplication_wrapper()
{
}

}
static QApplication *fromPtr(void *ptr)
{
    return reinterpret_cast<QApplication *>(ptr);
}
static TestBindings_wrappersNS::QApplication_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper *>(ptr);
}
extern "C" {
void c_QApplication_Finalizer(void *cppObj)
{
    delete reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper *>(cppObj);
} // aboutQt()
void c_static_QApplication__aboutQt()
{
    TestBindings_wrappersNS::QApplication_wrapper::aboutQt();
}
void c_QApplication__onApplicationDisplayNameChanged(void *thisObj, void *contextQObject,
                                                     void *callback)
{
    auto instance = reinterpret_cast<QApplication *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &QApplication::applicationDisplayNameChanged,
                     context ? context : instance, [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// autoSipEnabled() const
bool c_QApplication__autoSipEnabled(void *thisObj)
{
    const auto &result = fromPtr(thisObj)->autoSipEnabled();
    return result;
}
// beep()
void c_static_QApplication__beep()
{
    TestBindings_wrappersNS::QApplication_wrapper::beep();
}
// closeAllWindows()
void c_static_QApplication__closeAllWindows()
{
    TestBindings_wrappersNS::QApplication_wrapper::closeAllWindows();
}
// cursorFlashTime()
int c_static_QApplication__cursorFlashTime()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::cursorFlashTime();
    return result;
}
// customEvent(QEvent * event)
void c_QApplication__customEvent_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    fromWrapperPtr(thisObj)->customEvent_nocallback(event);
}
// doubleClickInterval()
int c_static_QApplication__doubleClickInterval()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::doubleClickInterval();
    return result;
}
// event(QEvent * arg__1)
bool c_QApplication__event_QEvent(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<QEvent *>(arg__1_);
    const auto &result = fromWrapperPtr(thisObj)->event_nocallback(arg__1);
    return result;
}
// eventFilter(QObject * watched, QEvent * event)
bool c_QApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_)
{
    auto watched = reinterpret_cast<QObject *>(watched_);
    auto event = reinterpret_cast<QEvent *>(event_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::QApplication_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->eventFilter_nocallback(watched, event);
        } else {
            return targetPtr->eventFilter(watched, event);
        }
    }();
    return result;
}
// exec()
int c_static_QApplication__exec()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::exec();
    return result;
}
void c_QApplication__onFocusObjectChanged_QObject(void *thisObj, void *contextQObject,
                                                  void *callback)
{
    auto instance = reinterpret_cast<QApplication *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &QApplication::focusObjectChanged, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
void c_QApplication__onFontDatabaseChanged(void *thisObj, void *contextQObject, void *callback)
{
    auto instance = reinterpret_cast<QApplication *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &QApplication::fontDatabaseChanged, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// keyboardInputInterval()
int c_static_QApplication__keyboardInputInterval()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::keyboardInputInterval();
    return result;
}
void c_QApplication__onLastWindowClosed(void *thisObj, void *contextQObject, void *callback)
{
    auto instance = reinterpret_cast<QApplication *>(thisObj);
    auto context = reinterpret_cast<QObject *>(contextQObject);
    QObject::connect(instance, &QApplication::lastWindowClosed, context ? context : instance,
                     [thisObj, callback] {
                         typedef void (*SignalHandler_callback)(void *);
                         auto dartCallback = reinterpret_cast<SignalHandler_callback>(callback);
                         dartCallback(thisObj);
                     });
}
// notify(QObject * arg__1, QEvent * arg__2)
bool c_QApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_, void *arg__2_)
{
    auto arg__1 = reinterpret_cast<QObject *>(arg__1_);
    auto arg__2 = reinterpret_cast<QEvent *>(arg__2_);
    const auto &result = [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr = dynamic_cast<TestBindings_wrappersNS::QApplication_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->notify_nocallback(arg__1, arg__2);
        } else {
            return targetPtr->notify(arg__1, arg__2);
        }
    }();
    return result;
}
// setAutoSipEnabled(const bool enabled)
void c_QApplication__setAutoSipEnabled_bool(void *thisObj, bool enabled)
{
    fromPtr(thisObj)->setAutoSipEnabled(enabled);
}
// setCursorFlashTime(int arg__1)
void c_static_QApplication__setCursorFlashTime_int(int arg__1)
{
    TestBindings_wrappersNS::QApplication_wrapper::setCursorFlashTime(arg__1);
}
// setDoubleClickInterval(int arg__1)
void c_static_QApplication__setDoubleClickInterval_int(int arg__1)
{
    TestBindings_wrappersNS::QApplication_wrapper::setDoubleClickInterval(arg__1);
}
// setKeyboardInputInterval(int arg__1)
void c_static_QApplication__setKeyboardInputInterval_int(int arg__1)
{
    TestBindings_wrappersNS::QApplication_wrapper::setKeyboardInputInterval(arg__1);
}
// setStartDragDistance(int l)
void c_static_QApplication__setStartDragDistance_int(int l)
{
    TestBindings_wrappersNS::QApplication_wrapper::setStartDragDistance(l);
}
// setStartDragTime(int ms)
void c_static_QApplication__setStartDragTime_int(int ms)
{
    TestBindings_wrappersNS::QApplication_wrapper::setStartDragTime(ms);
}
// setStyleSheet(const QString & sheet)
void c_QApplication__setStyleSheet_QString(void *thisObj, const char *sheet_)
{
    const auto sheet = QString::fromUtf8(sheet_);
    fromPtr(thisObj)->setStyleSheet(sheet);
    free(( char * )sheet_);
}
// setWheelScrollLines(int arg__1)
void c_static_QApplication__setWheelScrollLines_int(int arg__1)
{
    TestBindings_wrappersNS::QApplication_wrapper::setWheelScrollLines(arg__1);
}
// startDragDistance()
int c_static_QApplication__startDragDistance()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::startDragDistance();
    return result;
}
// startDragTime()
int c_static_QApplication__startDragTime()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::startDragTime();
    return result;
}
// styleSheet() const
void *c_QApplication__styleSheet(void *thisObj)
{
    const auto &result = new Dartagnan::ValueWrapper<QString> { fromPtr(thisObj)->styleSheet() };
    return result;
}
// tr(const char * s, const char * c, int n)
void *c_static_QApplication__tr_char_char_int(const char *s, const char *c, int n)
{
    const auto &result = new Dartagnan::ValueWrapper<QString> {
        TestBindings_wrappersNS::QApplication_wrapper::tr(s, c, n)
    };
    free(( char * )s);
    free(( char * )c);
    return result;
}
// wheelScrollLines()
int c_static_QApplication__wheelScrollLines()
{
    const auto &result = TestBindings_wrappersNS::QApplication_wrapper::wheelScrollLines();
    return result;
}
void c_QApplication__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_QApplication__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 481:
        wrapper->m_customEventCallback =
            reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper::Callback_customEvent>(
                callback);
        break;
    case 490:
        wrapper->m_eventCallback =
            reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper::Callback_event>(
                callback);
        break;
    case 491:
        wrapper->m_eventFilterCallback =
            reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper::Callback_eventFilter>(
                callback);
        break;
    case 688:
        wrapper->m_notifyCallback =
            reinterpret_cast<TestBindings_wrappersNS::QApplication_wrapper::Callback_notify>(
                callback);
        break;
    }
}
}
