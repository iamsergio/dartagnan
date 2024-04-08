import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class QGuiApplication extends QCoreApplication {
  QGuiApplication.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  QGuiApplication.init() : super.init() {}
  factory QGuiApplication.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (QObject.isCached(cppPointer)) {
      var instance = QObject.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as QGuiApplication;
    }
    return QGuiApplication.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_QGuiApplication_Finalizer";
  }

  static // applicationDisplayName()
      QString applicationDisplayName() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_QGuiApplication__applicationDisplayName')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QString.fromCppPointer(result, true);
  } // applicationDisplayNameChanged()

  applicationDisplayNameChanged() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QGuiApplication__applicationDisplayNameChanged')
        .asFunction();
    func(thisCpp);
  }

  void onApplicationDisplayNameChanged(Function callback, {QObject? context}) {
    final SignalHandler func = _dylib
        .lookup<ffi.NativeFunction<SignalHandler_FFI>>(
            'c_QGuiApplication__onApplicationDisplayNameChanged')
        .asFunction();
    final dartCallback =
        ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(
            onApplicationDisplayNameChanged_callback);
    final callbackMethod = onApplicationDisplayNameChanged_callback;
    var handlers = signalHandlerersBySignal[callbackMethod] ?? [];
    handlers.add(callback);
    signalHandlerersBySignal[callbackMethod] = handlers;
    ffi.Pointer<void> contextPtr =
        context == null ? ffi.nullptr : context.thisCpp;
    func(thisCpp, contextPtr, dartCallback);
  }

  static void onApplicationDisplayNameChanged_callback(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    final signalHandlers = dartInstance.signalHandlerersBySignal[
            onApplicationDisplayNameChanged_callback] ??
        [];
    for (var signalHandler in signalHandlers) {
      signalHandler();
    }
  }

  static void customEvent_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QGuiApplication::customEvent(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.customEvent((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
  }

  static // desktopFileName()
      QString desktopFileName() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_QGuiApplication__desktopFileName')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QString.fromCppPointer(result, true);
  }

  static // desktopSettingsAware()
      bool desktopSettingsAware() {
    final bool_Func_void func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_void_FFI>>(
            'c_static_QGuiApplication__desktopSettingsAware')
        .asFunction();
    return func() != 0;
  } // devicePixelRatio() const

  double devicePixelRatio() {
    final double_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
            'c_QGuiApplication__devicePixelRatio')
        .asFunction();
    return func(thisCpp);
  }

  static int event_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? arg__1) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QGuiApplication::event(QEvent * arg__1)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.event((arg__1 == null || arg__1.address == 0)
        ? null
        : QEvent.fromCppPointer(arg__1));
    return result ? 1 : 0;
  }

  static int eventFilter_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? watched, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QGuiApplication::eventFilter(QObject * watched, QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.eventFilter(
        (watched == null || watched.address == 0)
            ? null
            : QObject.fromCppPointer(watched),
        (event == null || event.address == 0)
            ? null
            : QEvent.fromCppPointer(event));
    return result ? 1 : 0;
  }

  static // exec()
      int exec() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QGuiApplication__exec')
        .asFunction();
    return func();
  }

  static // focusObject()
      QObject focusObject() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_QGuiApplication__focusObject')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QObject.fromCppPointer(result, false);
  } // focusObjectChanged(QObject * focusObject)

  focusObjectChanged(QObject? focusObject) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_QGuiApplication__focusObjectChanged_QObject')
        .asFunction();
    func(thisCpp, focusObject == null ? ffi.nullptr : focusObject.thisCpp);
  }

  void onFocusObjectChanged(Function callback, {QObject? context}) {
    final SignalHandler func = _dylib
        .lookup<ffi.NativeFunction<SignalHandler_FFI>>(
            'c_QGuiApplication__onFocusObjectChanged_QObject')
        .asFunction();
    final dartCallback =
        ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(
            onFocusObjectChanged_callback);
    final callbackMethod = onFocusObjectChanged_callback;
    var handlers = signalHandlerersBySignal[callbackMethod] ?? [];
    handlers.add(callback);
    signalHandlerersBySignal[callbackMethod] = handlers;
    ffi.Pointer<void> contextPtr =
        context == null ? ffi.nullptr : context.thisCpp;
    func(thisCpp, contextPtr, dartCallback);
  }

  static void onFocusObjectChanged_callback(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    final signalHandlers =
        dartInstance.signalHandlerersBySignal[onFocusObjectChanged_callback] ??
            [];
    for (var signalHandler in signalHandlers) {
      signalHandler();
    }
  } // fontDatabaseChanged()

  fontDatabaseChanged() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QGuiApplication__fontDatabaseChanged')
        .asFunction();
    func(thisCpp);
  }

  void onFontDatabaseChanged(Function callback, {QObject? context}) {
    final SignalHandler func = _dylib
        .lookup<ffi.NativeFunction<SignalHandler_FFI>>(
            'c_QGuiApplication__onFontDatabaseChanged')
        .asFunction();
    final dartCallback =
        ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(
            onFontDatabaseChanged_callback);
    final callbackMethod = onFontDatabaseChanged_callback;
    var handlers = signalHandlerersBySignal[callbackMethod] ?? [];
    handlers.add(callback);
    signalHandlerersBySignal[callbackMethod] = handlers;
    ffi.Pointer<void> contextPtr =
        context == null ? ffi.nullptr : context.thisCpp;
    func(thisCpp, contextPtr, dartCallback);
  }

  static void onFontDatabaseChanged_callback(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    final signalHandlers =
        dartInstance.signalHandlerersBySignal[onFontDatabaseChanged_callback] ??
            [];
    for (var signalHandler in signalHandlers) {
      signalHandler();
    }
  }

  static // isLeftToRight()
      bool isLeftToRight() {
    final bool_Func_void func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_void_FFI>>(
            'c_static_QGuiApplication__isLeftToRight')
        .asFunction();
    return func() != 0;
  }

  static // isRightToLeft()
      bool isRightToLeft() {
    final bool_Func_void func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_void_FFI>>(
            'c_static_QGuiApplication__isRightToLeft')
        .asFunction();
    return func() != 0;
  } // isSavingSession() const

  bool isSavingSession() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QGuiApplication__isSavingSession')
        .asFunction();
    return func(thisCpp) != 0;
  } // isSessionRestored() const

  bool isSessionRestored() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QGuiApplication__isSessionRestored')
        .asFunction();
    return func(thisCpp) != 0;
  } // lastWindowClosed()

  lastWindowClosed() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QGuiApplication__lastWindowClosed')
        .asFunction();
    func(thisCpp);
  }

  void onLastWindowClosed(Function callback, {QObject? context}) {
    final SignalHandler func = _dylib
        .lookup<ffi.NativeFunction<SignalHandler_FFI>>(
            'c_QGuiApplication__onLastWindowClosed')
        .asFunction();
    final dartCallback =
        ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(
            onLastWindowClosed_callback);
    final callbackMethod = onLastWindowClosed_callback;
    var handlers = signalHandlerersBySignal[callbackMethod] ?? [];
    handlers.add(callback);
    signalHandlerersBySignal[callbackMethod] = handlers;
    ffi.Pointer<void> contextPtr =
        context == null ? ffi.nullptr : context.thisCpp;
    func(thisCpp, contextPtr, dartCallback);
  }

  static void onLastWindowClosed_callback(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    final signalHandlers =
        dartInstance.signalHandlerersBySignal[onLastWindowClosed_callback] ??
            [];
    for (var signalHandler in signalHandlers) {
      signalHandler();
    }
  }

  static int notify_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? arg__1, ffi.Pointer<void>? arg__2) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QGuiApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QGuiApplication::notify(QObject * arg__1, QEvent * arg__2)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.notify(
        (arg__1 == null || arg__1.address == 0)
            ? null
            : QObject.fromCppPointer(arg__1),
        (arg__2 == null || arg__2.address == 0)
            ? null
            : QEvent.fromCppPointer(arg__2));
    return result ? 1 : 0;
  }

  static // platformName()
      QString platformName() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_QGuiApplication__platformName')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QString.fromCppPointer(result, true);
  }

  static // quitOnLastWindowClosed()
      bool quitOnLastWindowClosed() {
    final bool_Func_void func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_void_FFI>>(
            'c_static_QGuiApplication__quitOnLastWindowClosed')
        .asFunction();
    return func() != 0;
  }

  static // restoreOverrideCursor()
      restoreOverrideCursor() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_QGuiApplication__restoreOverrideCursor')
        .asFunction();
    func();
  } // sessionId() const

  QString sessionId() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QGuiApplication__sessionId')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QString.fromCppPointer(result, true);
  } // sessionKey() const

  QString sessionKey() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QGuiApplication__sessionKey')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QString.fromCppPointer(result, true);
  }

  static // setApplicationDisplayName(const QString & name)
      setApplicationDisplayName(String name) {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_static_QGuiApplication__setApplicationDisplayName_QString')
        .asFunction();
    func(name.toNativeUtf8());
  }

  static // setDesktopFileName(const QString & name)
      setDesktopFileName(String name) {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_static_QGuiApplication__setDesktopFileName_QString')
        .asFunction();
    func(name.toNativeUtf8());
  }

  static // setDesktopSettingsAware(bool on)
      setDesktopSettingsAware(bool on) {
    final void_Func_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int8_FFI>>(
            'c_static_QGuiApplication__setDesktopSettingsAware_bool')
        .asFunction();
    func(on ? 1 : 0);
  }

  static // setQuitOnLastWindowClosed(bool quit)
      setQuitOnLastWindowClosed(bool quit) {
    final void_Func_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int8_FFI>>(
            'c_static_QGuiApplication__setQuitOnLastWindowClosed_bool')
        .asFunction();
    func(quit ? 1 : 0);
  }

  static // sync()
      sync() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_QGuiApplication__sync')
        .asFunction();
    func();
  }

  static // tr(const char * s, const char * c, int n)
      QString tr(String? s, String? c, int n) {
    final voidstar_Func_string_string_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_string_string_ffi_Int32_FFI>>(
            'c_static_QGuiApplication__tr_char_char_int')
        .asFunction();
    ffi.Pointer<void> result = func(
        s?.toNativeUtf8() ?? ffi.nullptr, c?.toNativeUtf8() ?? ffi.nullptr, n);
    return QString.fromCppPointer(result, true);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QGuiApplication__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 481:
        return "c_QGuiApplication__customEvent_QEvent";
      case 490:
        return "c_QGuiApplication__event_QEvent";
      case 491:
        return "c_QGuiApplication__eventFilter_QObject_QEvent";
      case 688:
        return "c_QGuiApplication__notify_QObject_QEvent";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 481:
        return "customEvent";
      case 490:
        return "event";
      case 491:
        return "eventFilter";
      case 688:
        return "notify";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_QGuiApplication__registerVirtualMethodCallback')
        .asFunction();
    final callback481 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            QObject.customEvent_calledFromC);
    registerCallback(thisCpp, callback481, 481);
    const callbackExcept490 = 0;
    final callback490 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_FFI>(
            QGuiApplication.event_calledFromC, callbackExcept490);
    registerCallback(thisCpp, callback490, 490);
    const callbackExcept491 = 0;
    final callback491 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_voidstar_FFI>(
            QObject.eventFilter_calledFromC, callbackExcept491);
    registerCallback(thisCpp, callback491, 491);
    const callbackExcept688 = 0;
    final callback688 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_voidstar_FFI>(
            QGuiApplication.notify_calledFromC, callbackExcept688);
    registerCallback(thisCpp, callback688, 688);
  }
}
