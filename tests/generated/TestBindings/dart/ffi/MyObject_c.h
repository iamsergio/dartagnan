#include "TestBindings_exports.h"
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>
#include <test.h>

namespace TestBindings_wrappersNS {
class MyObject_wrapper : public ::MyObject
{
public:
    ~MyObject_wrapper();
    MyObject_wrapper(QObject *parent = nullptr);
    virtual void customEvent(QEvent *event);
    virtual void customEvent_nocallback(QEvent *event);
    virtual bool event(QEvent *event);
    virtual bool event_nocallback(QEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual bool eventFilter_nocallback(QObject *watched, QEvent *event);
    virtual void pureVirtual();
    virtual void pureVirtual_nocallback();
    void receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo =
                                             AnotherNamespace::MyNamespacedEnumClass::ValueFoo1);
    void receivesEnumClassWithDefaultArg(MyEnumClass foo = MyEnumClass::ValueFoo);
    MyEnumClass returnsEnumClass();
    static QString tr(const char *s, const char *c, int n);
    void valueChanged(int arg__1);
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
// MyObject::MyObject(QObject * parent)
TestBindings_EXPORT void *c_MyObject__constructor_QObject(void *parent_);
// MyObject::customEvent(QEvent * event)
TestBindings_EXPORT void c_MyObject__customEvent_QEvent(void *thisObj, void *event_);
// MyObject::event(QEvent * event)
TestBindings_EXPORT bool c_MyObject__event_QEvent(void *thisObj, void *event_);
// MyObject::eventFilter(QObject * watched, QEvent * event)
TestBindings_EXPORT bool c_MyObject__eventFilter_QObject_QEvent(void *thisObj, void *watched_,
                                                                void *event_);
// MyObject::pureVirtual()
TestBindings_EXPORT void c_MyObject__pureVirtual(void *thisObj);
// MyObject::receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo)
TestBindings_EXPORT void
c_MyObject__receivesEnumClassWithDefaultArg_MyNamespacedEnumClass(void *thisObj, int foo);
// MyObject::receivesEnumClassWithDefaultArg(MyEnumClass foo)
TestBindings_EXPORT void c_MyObject__receivesEnumClassWithDefaultArg_MyEnumClass(void *thisObj,
                                                                                 int foo);
// MyObject::returnsEnumClass()
TestBindings_EXPORT int c_MyObject__returnsEnumClass(void *thisObj);
// MyObject::tr(const char * s, const char * c, int n)
TestBindings_EXPORT void *c_static_MyObject__tr_char_char_int(const char *s, const char *c, int n);
// MyObject::valueChanged(int arg__1)
TestBindings_EXPORT void c_MyObject__valueChanged_int(void *thisObj, int arg__1);
TestBindings_EXPORT void c_MyObject__onValueChanged_int(void *thisObj, void *contextQObject,
                                                        void *callback); // MyObject::virtualFunc()
TestBindings_EXPORT int c_MyObject__virtualFunc(void *thisObj);
// MyObject::virtualMethodReturningConstChar() const
TestBindings_EXPORT const char *c_MyObject__virtualMethodReturningConstChar(void *thisObj);
// MyObject::virtualReceivingQString(const QString & str)
TestBindings_EXPORT void c_MyObject__virtualReceivingQString_QString(void *thisObj,
                                                                     const char *str_);
// MyObject::virtualReturningInt() const
TestBindings_EXPORT int c_MyObject__virtualReturningInt(void *thisObj);
TestBindings_EXPORT void c_MyObject__destructor(void *thisObj);
TestBindings_EXPORT void c_MyObject__registerVirtualMethodCallback(void *ptr, void *callback,
                                                                   int methodId);
TestBindings_EXPORT void c_MyObject_Finalizer(void *cppObj);
}
