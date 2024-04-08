#include "TestBindings_exports.h"
#include <qcoreevent.h>
#include <qobject.h>
#include <qstring.h>
#include <test.h>

namespace TestBindings_wrappersNS {
class DoubleInheritance_wrapper : public ::DoubleInheritance
{
public:
    ~DoubleInheritance_wrapper();
    DoubleInheritance_wrapper();
    virtual void customEvent(QEvent *event);
    virtual void customEvent_nocallback(QEvent *event);
    virtual bool event(QEvent *event);
    virtual bool event_nocallback(QEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual bool eventFilter_nocallback(QObject *watched, QEvent *event);
    int nonVirtualCallsVirtualFrom2ndBase() const;
    virtual void pureVirtual();
    virtual void pureVirtual_nocallback();
    virtual int virtualFunc();
    virtual int virtualFunc_nocallback();
    virtual const char *virtualMethodReturningConstChar() const;
    virtual const char *virtualMethodReturningConstChar_nocallback() const;
    virtual void virtualReceivingQString(const QString &str);
    virtual void virtualReceivingQString_nocallback(const QString &str);
    virtual int virtualReturningInt() const;
    virtual int virtualReturningInt_nocallback() const;
    typedef void (*Callback_customEvent)(void *, QEvent *event);
    Callback_customEvent m_customEventCallback = nullptr;
    typedef bool (*Callback_event)(void *, QEvent *event);
    Callback_event m_eventCallback = nullptr;
    typedef bool (*Callback_eventFilter)(void *, QObject *watched, QEvent *event);
    Callback_eventFilter m_eventFilterCallback = nullptr;
    typedef void (*Callback_pureVirtual)(void *);
    Callback_pureVirtual m_pureVirtualCallback = nullptr;
    typedef int (*Callback_virtualFunc)(void *);
    Callback_virtualFunc m_virtualFuncCallback = nullptr;
    typedef const char *(*Callback_virtualMethodReturningConstChar)(void *);
    Callback_virtualMethodReturningConstChar m_virtualMethodReturningConstCharCallback = nullptr;
    typedef void (*Callback_virtualReceivingQString)(void *, const QString &str);
    Callback_virtualReceivingQString m_virtualReceivingQStringCallback = nullptr;
    typedef int (*Callback_virtualReturningInt)(void *);
    Callback_virtualReturningInt m_virtualReturningIntCallback = nullptr;
};
}
extern "C" {
// DoubleInheritance::DoubleInheritance()
TestBindings_EXPORT void *c_DoubleInheritance__constructor();
// DoubleInheritance::customEvent(QEvent * event)
TestBindings_EXPORT void c_DoubleInheritance__customEvent_QEvent(void *thisObj, void *event_);
// DoubleInheritance::event(QEvent * event)
TestBindings_EXPORT bool c_DoubleInheritance__event_QEvent(void *thisObj, void *event_);
// DoubleInheritance::eventFilter(QObject * watched, QEvent * event)
TestBindings_EXPORT bool
c_DoubleInheritance__eventFilter_QObject_QEvent(void *thisObj, void *watched_, void *event_);
// DoubleInheritance::nonVirtualCallsVirtualFrom2ndBase() const
TestBindings_EXPORT int c_DoubleInheritance__nonVirtualCallsVirtualFrom2ndBase(void *thisObj);
// DoubleInheritance::pureVirtual()
TestBindings_EXPORT void c_DoubleInheritance__pureVirtual(void *thisObj);
// DoubleInheritance::virtualFunc()
TestBindings_EXPORT int c_DoubleInheritance__virtualFunc(void *thisObj);
// DoubleInheritance::virtualMethodReturningConstChar() const
TestBindings_EXPORT const char *c_DoubleInheritance__virtualMethodReturningConstChar(void *thisObj);
// DoubleInheritance::virtualReceivingQString(const QString & str)
TestBindings_EXPORT void c_DoubleInheritance__virtualReceivingQString_QString(void *thisObj,
                                                                              const char *str_);
// DoubleInheritance::virtualReturningInt() const
TestBindings_EXPORT int c_DoubleInheritance__virtualReturningInt(void *thisObj);
TestBindings_EXPORT void c_DoubleInheritance__destructor(void *thisObj);
TestBindings_EXPORT void
c_DoubleInheritance__registerVirtualMethodCallback(void *ptr, void *callback, int methodId);
TestBindings_EXPORT void c_DoubleInheritance_Finalizer(void *cppObj);
}
