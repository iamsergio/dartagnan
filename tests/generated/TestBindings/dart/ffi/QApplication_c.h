#include "TestBindings_exports.h"
#include <qapplication.h>
#include <qcoreevent.h>
#include <qobject.h>
#include <qstring.h>

namespace TestBindings_wrappersNS {
class QApplication_wrapper : public ::QApplication
{
public:
    ~QApplication_wrapper();
    static void aboutQt();
    bool autoSipEnabled() const;
    static void beep();
    static void closeAllWindows();
    static int cursorFlashTime();
    virtual void customEvent(QEvent *event);
    virtual void customEvent_nocallback(QEvent *event);
    static int doubleClickInterval();
    virtual bool event(QEvent *arg__1);
    virtual bool event_nocallback(QEvent *arg__1);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual bool eventFilter_nocallback(QObject *watched, QEvent *event);
    static int exec();
    static int keyboardInputInterval();
    virtual bool notify(QObject *arg__1, QEvent *arg__2);
    virtual bool notify_nocallback(QObject *arg__1, QEvent *arg__2);
    void setAutoSipEnabled(const bool enabled);
    static void setCursorFlashTime(int arg__1);
    static void setDoubleClickInterval(int arg__1);
    static void setKeyboardInputInterval(int arg__1);
    static void setStartDragDistance(int l);
    static void setStartDragTime(int ms);
    void setStyleSheet(const QString &sheet);
    static void setWheelScrollLines(int arg__1);
    static int startDragDistance();
    static int startDragTime();
    QString styleSheet() const;
    static QString tr(const char *s, const char *c, int n);
    static int wheelScrollLines();
    typedef void (*Callback_customEvent)(void *, QEvent *event);
    Callback_customEvent m_customEventCallback = nullptr;
    typedef bool (*Callback_event)(void *, QEvent *arg__1);
    Callback_event m_eventCallback = nullptr;
    typedef bool (*Callback_eventFilter)(void *, QObject *watched, QEvent *event);
    Callback_eventFilter m_eventFilterCallback = nullptr;
    typedef bool (*Callback_notify)(void *, QObject *arg__1, QEvent *arg__2);
    Callback_notify m_notifyCallback = nullptr;
};
}
extern "C" {
// QApplication::aboutQt()
TestBindings_EXPORT void c_static_QApplication__aboutQt();
// QApplication::autoSipEnabled() const
TestBindings_EXPORT bool c_QApplication__autoSipEnabled(void *thisObj);
// QApplication::beep()
TestBindings_EXPORT void c_static_QApplication__beep();
// QApplication::closeAllWindows()
TestBindings_EXPORT void c_static_QApplication__closeAllWindows();
// QApplication::cursorFlashTime()
TestBindings_EXPORT int c_static_QApplication__cursorFlashTime();
// QApplication::customEvent(QEvent * event)
TestBindings_EXPORT void c_QApplication__customEvent_QEvent(void *thisObj, void *event_);
// QApplication::doubleClickInterval()
TestBindings_EXPORT int c_static_QApplication__doubleClickInterval();
// QApplication::event(QEvent * arg__1)
TestBindings_EXPORT bool c_QApplication__event_QEvent(void *thisObj, void *arg__1_);
// QApplication::eventFilter(QObject * watched, QEvent * event)
TestBindings_EXPORT bool c_QApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_,
                                                                    void *event_);
// QApplication::exec()
TestBindings_EXPORT int c_static_QApplication__exec();
// QApplication::keyboardInputInterval()
TestBindings_EXPORT int c_static_QApplication__keyboardInputInterval();
// QApplication::notify(QObject * arg__1, QEvent * arg__2)
TestBindings_EXPORT bool c_QApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_,
                                                               void *arg__2_);
// QApplication::setAutoSipEnabled(const bool enabled)
TestBindings_EXPORT void c_QApplication__setAutoSipEnabled_bool(void *thisObj, bool enabled);
// QApplication::setCursorFlashTime(int arg__1)
TestBindings_EXPORT void c_static_QApplication__setCursorFlashTime_int(int arg__1);
// QApplication::setDoubleClickInterval(int arg__1)
TestBindings_EXPORT void c_static_QApplication__setDoubleClickInterval_int(int arg__1);
// QApplication::setKeyboardInputInterval(int arg__1)
TestBindings_EXPORT void c_static_QApplication__setKeyboardInputInterval_int(int arg__1);
// QApplication::setStartDragDistance(int l)
TestBindings_EXPORT void c_static_QApplication__setStartDragDistance_int(int l);
// QApplication::setStartDragTime(int ms)
TestBindings_EXPORT void c_static_QApplication__setStartDragTime_int(int ms);
// QApplication::setStyleSheet(const QString & sheet)
TestBindings_EXPORT void c_QApplication__setStyleSheet_QString(void *thisObj, const char *sheet_);
// QApplication::setWheelScrollLines(int arg__1)
TestBindings_EXPORT void c_static_QApplication__setWheelScrollLines_int(int arg__1);
// QApplication::startDragDistance()
TestBindings_EXPORT int c_static_QApplication__startDragDistance();
// QApplication::startDragTime()
TestBindings_EXPORT int c_static_QApplication__startDragTime();
// QApplication::styleSheet() const
TestBindings_EXPORT void *c_QApplication__styleSheet(void *thisObj);
// QApplication::tr(const char * s, const char * c, int n)
TestBindings_EXPORT void *c_static_QApplication__tr_char_char_int(const char *s, const char *c,
                                                                  int n);
// QApplication::wheelScrollLines()
TestBindings_EXPORT int c_static_QApplication__wheelScrollLines();
TestBindings_EXPORT void c_QApplication__destructor(void *thisObj);
TestBindings_EXPORT void c_QApplication__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                       int methodId);
TestBindings_EXPORT void c_QApplication_Finalizer(void *cppObj);
}
