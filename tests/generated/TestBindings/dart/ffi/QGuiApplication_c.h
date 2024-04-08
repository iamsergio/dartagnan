#include "TestBindings_exports.h"
#include <qcoreapplication.h>
#include <qcoreevent.h>
#include <qguiapplication.h>
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>

namespace TestBindings_wrappersNS {
class QGuiApplication_wrapper : public ::QGuiApplication
{
public:
    ~QGuiApplication_wrapper();
    static QString applicationDisplayName();
    void applicationDisplayNameChanged();
    virtual void customEvent(QEvent *event);
    virtual void customEvent_nocallback(QEvent *event);
    static QString desktopFileName();
    static bool desktopSettingsAware();
    qreal devicePixelRatio() const;
    virtual bool event(QEvent *arg__1);
    virtual bool event_nocallback(QEvent *arg__1);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual bool eventFilter_nocallback(QObject *watched, QEvent *event);
    static int exec();
    static QObject *focusObject();
    void focusObjectChanged(QObject *focusObject);
    void fontDatabaseChanged();
    static bool isLeftToRight();
    static bool isRightToLeft();
    bool isSavingSession() const;
    bool isSessionRestored() const;
    void lastWindowClosed();
    virtual bool notify(QObject *arg__1, QEvent *arg__2);
    virtual bool notify_nocallback(QObject *arg__1, QEvent *arg__2);
    static QString platformName();
    static bool quitOnLastWindowClosed();
    static void restoreOverrideCursor();
    QString sessionId() const;
    QString sessionKey() const;
    static void setApplicationDisplayName(const QString &name);
    static void setDesktopFileName(const QString &name);
    static void setDesktopSettingsAware(bool on);
    static void setQuitOnLastWindowClosed(bool quit);
    static void sync();
    static QString tr(const char *s, const char *c, int n);
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
// QGuiApplication::applicationDisplayName()
TestBindings_EXPORT void *c_static_QGuiApplication__applicationDisplayName();
// QGuiApplication::applicationDisplayNameChanged()
TestBindings_EXPORT void c_QGuiApplication__applicationDisplayNameChanged(void *thisObj);
TestBindings_EXPORT void
c_QGuiApplication__onApplicationDisplayNameChanged(void *thisObj, void *contextQObject,
                                                   void *callback); // QGuiApplication::customEvent(QEvent
                                                                    // * event)
TestBindings_EXPORT void c_QGuiApplication__customEvent_QEvent(void *thisObj, void *event_);
// QGuiApplication::desktopFileName()
TestBindings_EXPORT void *c_static_QGuiApplication__desktopFileName();
// QGuiApplication::desktopSettingsAware()
TestBindings_EXPORT bool c_static_QGuiApplication__desktopSettingsAware();
// QGuiApplication::devicePixelRatio() const
TestBindings_EXPORT qreal c_QGuiApplication__devicePixelRatio(void *thisObj);
// QGuiApplication::event(QEvent * arg__1)
TestBindings_EXPORT bool c_QGuiApplication__event_QEvent(void *thisObj, void *arg__1_);
// QGuiApplication::eventFilter(QObject * watched, QEvent * event)
TestBindings_EXPORT bool
c_QGuiApplication__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// QGuiApplication::exec()
TestBindings_EXPORT int c_static_QGuiApplication__exec();
// QGuiApplication::focusObject()
TestBindings_EXPORT void *c_static_QGuiApplication__focusObject();
// QGuiApplication::focusObjectChanged(QObject * focusObject)
TestBindings_EXPORT void c_QGuiApplication__focusObjectChanged_QObject(void *thisObj,
                                                                       void *focusObject_);
TestBindings_EXPORT void c_QGuiApplication__onFocusObjectChanged_QObject(
    void *thisObj, void *contextQObject, void *callback); // QGuiApplication::fontDatabaseChanged()
TestBindings_EXPORT void c_QGuiApplication__fontDatabaseChanged(void *thisObj);
TestBindings_EXPORT void
c_QGuiApplication__onFontDatabaseChanged(void *thisObj, void *contextQObject,
                                         void *callback); // QGuiApplication::isLeftToRight()
TestBindings_EXPORT bool c_static_QGuiApplication__isLeftToRight();
// QGuiApplication::isRightToLeft()
TestBindings_EXPORT bool c_static_QGuiApplication__isRightToLeft();
// QGuiApplication::isSavingSession() const
TestBindings_EXPORT bool c_QGuiApplication__isSavingSession(void *thisObj);
// QGuiApplication::isSessionRestored() const
TestBindings_EXPORT bool c_QGuiApplication__isSessionRestored(void *thisObj);
// QGuiApplication::lastWindowClosed()
TestBindings_EXPORT void c_QGuiApplication__lastWindowClosed(void *thisObj);
TestBindings_EXPORT void c_QGuiApplication__onLastWindowClosed(void *thisObj, void *contextQObject,
                                                               void *callback); // QGuiApplication::notify(QObject
                                                                                // * arg__1, QEvent
                                                                                // * arg__2)
TestBindings_EXPORT bool c_QGuiApplication__notify_QObject_QEvent(void *thisObj, void *arg__1_,
                                                                  void *arg__2_);
// QGuiApplication::platformName()
TestBindings_EXPORT void *c_static_QGuiApplication__platformName();
// QGuiApplication::quitOnLastWindowClosed()
TestBindings_EXPORT bool c_static_QGuiApplication__quitOnLastWindowClosed();
// QGuiApplication::restoreOverrideCursor()
TestBindings_EXPORT void c_static_QGuiApplication__restoreOverrideCursor();
// QGuiApplication::sessionId() const
TestBindings_EXPORT void *c_QGuiApplication__sessionId(void *thisObj);
// QGuiApplication::sessionKey() const
TestBindings_EXPORT void *c_QGuiApplication__sessionKey(void *thisObj);
// QGuiApplication::setApplicationDisplayName(const QString & name)
TestBindings_EXPORT void
c_static_QGuiApplication__setApplicationDisplayName_QString(const char *name_);
// QGuiApplication::setDesktopFileName(const QString & name)
TestBindings_EXPORT void c_static_QGuiApplication__setDesktopFileName_QString(const char *name_);
// QGuiApplication::setDesktopSettingsAware(bool on)
TestBindings_EXPORT void c_static_QGuiApplication__setDesktopSettingsAware_bool(bool on);
// QGuiApplication::setQuitOnLastWindowClosed(bool quit)
TestBindings_EXPORT void c_static_QGuiApplication__setQuitOnLastWindowClosed_bool(bool quit);
// QGuiApplication::sync()
TestBindings_EXPORT void c_static_QGuiApplication__sync();
// QGuiApplication::tr(const char * s, const char * c, int n)
TestBindings_EXPORT void *c_static_QGuiApplication__tr_char_char_int(const char *s, const char *c,
                                                                     int n);
TestBindings_EXPORT void c_QGuiApplication__destructor(void *thisObj);
TestBindings_EXPORT void c_QGuiApplication__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                          int methodId);
TestBindings_EXPORT void c_QGuiApplication_Finalizer(void *cppObj);
}
