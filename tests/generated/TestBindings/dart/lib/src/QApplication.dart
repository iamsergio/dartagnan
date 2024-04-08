import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class QApplication extends QGuiApplication {
  QApplication.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  QApplication.init() : super.init() {}
  factory QApplication.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (QObject.isCached(cppPointer)) {
      var instance = QObject.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as QApplication;
    }
    return QApplication.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_QApplication_Finalizer";
  }

  static // aboutQt()
      aboutQt() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_QApplication__aboutQt')
        .asFunction();
    func();
  } // autoSipEnabled() const

  bool autoSipEnabled() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QApplication__autoSipEnabled')
        .asFunction();
    return func(thisCpp) != 0;
  }

  static // beep()
      beep() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_QApplication__beep')
        .asFunction();
    func();
  }

  static // closeAllWindows()
      closeAllWindows() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_QApplication__closeAllWindows')
        .asFunction();
    func();
  }

  static // cursorFlashTime()
      int cursorFlashTime() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__cursorFlashTime')
        .asFunction();
    return func();
  }

  static void customEvent_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QApplication::customEvent(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.customEvent((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
  }

  static // doubleClickInterval()
      int doubleClickInterval() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__doubleClickInterval')
        .asFunction();
    return func();
  }

  static int event_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? arg__1) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QApplication::event(QEvent * arg__1)! (${thisCpp.address})");
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QApplication::eventFilter(QObject * watched, QEvent * event)! (${thisCpp.address})");
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
            'c_static_QApplication__exec')
        .asFunction();
    return func();
  }

  static // keyboardInputInterval()
      int keyboardInputInterval() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__keyboardInputInterval')
        .asFunction();
    return func();
  }

  static int notify_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? arg__1, ffi.Pointer<void>? arg__2) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as QApplication;
    if (dartInstance == null) {
      print(
          "Dart instance not found for QApplication::notify(QObject * arg__1, QEvent * arg__2)! (${thisCpp.address})");
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
  } // setAutoSipEnabled(const bool enabled)

  setAutoSipEnabled(bool enabled) {
    final void_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int8_FFI>>(
            'c_QApplication__setAutoSipEnabled_bool')
        .asFunction();
    func(thisCpp, enabled ? 1 : 0);
  }

  static // setCursorFlashTime(int arg__1)
      setCursorFlashTime(int arg__1) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setCursorFlashTime_int')
        .asFunction();
    func(arg__1);
  }

  static // setDoubleClickInterval(int arg__1)
      setDoubleClickInterval(int arg__1) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setDoubleClickInterval_int')
        .asFunction();
    func(arg__1);
  }

  static // setKeyboardInputInterval(int arg__1)
      setKeyboardInputInterval(int arg__1) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setKeyboardInputInterval_int')
        .asFunction();
    func(arg__1);
  }

  static // setStartDragDistance(int l)
      setStartDragDistance(int l) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setStartDragDistance_int')
        .asFunction();
    func(l);
  }

  static // setStartDragTime(int ms)
      setStartDragTime(int ms) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setStartDragTime_int')
        .asFunction();
    func(ms);
  } // setStyleSheet(const QString & sheet)

  setStyleSheet(String sheet) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_QApplication__setStyleSheet_QString')
        .asFunction();
    func(thisCpp, sheet.toNativeUtf8());
  }

  static // setWheelScrollLines(int arg__1)
      setWheelScrollLines(int arg__1) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_QApplication__setWheelScrollLines_int')
        .asFunction();
    func(arg__1);
  }

  static // startDragDistance()
      int startDragDistance() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__startDragDistance')
        .asFunction();
    return func();
  }

  static // startDragTime()
      int startDragTime() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__startDragTime')
        .asFunction();
    return func();
  } // styleSheet() const

  QString styleSheet() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QApplication__styleSheet')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QString.fromCppPointer(result, true);
  }

  static // tr(const char * s, const char * c, int n)
      QString tr(String? s, String? c, int n) {
    final voidstar_Func_string_string_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_string_string_ffi_Int32_FFI>>(
            'c_static_QApplication__tr_char_char_int')
        .asFunction();
    ffi.Pointer<void> result = func(
        s?.toNativeUtf8() ?? ffi.nullptr, c?.toNativeUtf8() ?? ffi.nullptr, n);
    return QString.fromCppPointer(result, true);
  }

  static // wheelScrollLines()
      int wheelScrollLines() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_QApplication__wheelScrollLines')
        .asFunction();
    return func();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QApplication__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 481:
        return "c_QApplication__customEvent_QEvent";
      case 490:
        return "c_QApplication__event_QEvent";
      case 491:
        return "c_QApplication__eventFilter_QObject_QEvent";
      case 688:
        return "c_QApplication__notify_QObject_QEvent";
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
            'c_QApplication__registerVirtualMethodCallback')
        .asFunction();
    final callback481 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            QObject.customEvent_calledFromC);
    registerCallback(thisCpp, callback481, 481);
    const callbackExcept490 = 0;
    final callback490 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_FFI>(
            QApplication.event_calledFromC, callbackExcept490);
    registerCallback(thisCpp, callback490, 490);
    const callbackExcept491 = 0;
    final callback491 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_voidstar_FFI>(
            QObject.eventFilter_calledFromC, callbackExcept491);
    registerCallback(thisCpp, callback491, 491);
    const callbackExcept688 = 0;
    final callback688 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_voidstar_FFI>(
            QApplication.notify_calledFromC, callbackExcept688);
    registerCallback(thisCpp, callback688, 688);
  }
}
