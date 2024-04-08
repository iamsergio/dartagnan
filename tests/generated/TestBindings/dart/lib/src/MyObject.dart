import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class MyObject extends QObject {
  MyObject.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  MyObject.init() : super.init() {}
  factory MyObject.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (QObject.isCached(cppPointer)) {
      var instance = QObject.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as MyObject;
    }
    return MyObject.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_MyObject_Finalizer";
  } //MyObject(QObject * parent)

  MyObject({QObject? parent}) : super.init() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_MyObject__constructor_QObject')
        .asFunction();
    thisCpp = func(parent == null ? ffi.nullptr : parent.thisCpp);
    QObject.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  }
  static void customEvent_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::customEvent(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.customEvent((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
  }

  static int event_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::event(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.event((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
    return result ? 1 : 0;
  }

  static int eventFilter_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? watched, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::eventFilter(QObject * watched, QEvent * event)! (${thisCpp.address})");
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
  } // pureVirtual()

  pureVirtual() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(1166))
        .asFunction();
    func(thisCpp);
  }

  static void pureVirtual_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::pureVirtual()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.pureVirtual();
  } // receivesEnumClassWithDefaultArg(AnotherNamespace::MyNamespacedEnumClass foo)

  receivesEnumClassWithDefaultArg(
      {int foo = AnotherNamespace_MyNamespacedEnumClass.ValueFoo1}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_MyObject__receivesEnumClassWithDefaultArg_MyNamespacedEnumClass')
        .asFunction();
    func(thisCpp, foo);
  } // receivesEnumClassWithDefaultArg(MyEnumClass foo)

  receivesEnumClassWithDefaultArg_2({int foo = MyEnumClass.ValueFoo}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_MyObject__receivesEnumClassWithDefaultArg_MyEnumClass')
        .asFunction();
    func(thisCpp, foo);
  } // returnsEnumClass()

  int returnsEnumClass() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_MyObject__returnsEnumClass')
        .asFunction();
    return func(thisCpp);
  }

  static // tr(const char * s, const char * c, int n)
      QString tr(String? s, String? c, int n) {
    final voidstar_Func_string_string_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_string_string_ffi_Int32_FFI>>(
            'c_static_MyObject__tr_char_char_int')
        .asFunction();
    ffi.Pointer<void> result = func(
        s?.toNativeUtf8() ?? ffi.nullptr, c?.toNativeUtf8() ?? ffi.nullptr, n);
    return QString.fromCppPointer(result, true);
  } // valueChanged(int arg__1)

  valueChanged(int arg__1) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_MyObject__valueChanged_int')
        .asFunction();
    func(thisCpp, arg__1);
  }

  void onValueChanged(Function callback, {QObject? context}) {
    final SignalHandler func = _dylib
        .lookup<ffi.NativeFunction<SignalHandler_FFI>>(
            'c_MyObject__onValueChanged_int')
        .asFunction();
    final dartCallback =
        ffi.Pointer.fromFunction<ffi.Void Function(ffi.Pointer<void>)>(
            onValueChanged_callback);
    final callbackMethod = onValueChanged_callback;
    var handlers = signalHandlerersBySignal[callbackMethod] ?? [];
    handlers.add(callback);
    signalHandlerersBySignal[callbackMethod] = handlers;
    ffi.Pointer<void> contextPtr =
        context == null ? ffi.nullptr : context.thisCpp;
    func(thisCpp, contextPtr, dartCallback);
  }

  static void onValueChanged_callback(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    final signalHandlers =
        dartInstance.signalHandlerersBySignal[onValueChanged_callback] ?? [];
    for (var signalHandler in signalHandlers) {
      signalHandler();
    }
  } // virtualFunc()

  int virtualFunc() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(1181))
        .asFunction();
    return func(thisCpp);
  }

  static int virtualFunc_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::virtualFunc()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualFunc();
    return result;
  } // virtualMethodReturningConstChar() const

  String virtualMethodReturningConstChar() {
    final string_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<string_Func_voidstar_FFI>>(
            cFunctionSymbolName(1182))
        .asFunction();
    ffi.Pointer<Utf8> result = func(thisCpp);
    return result.toDartString();
  }

  static ffi.Pointer<Utf8> virtualMethodReturningConstChar_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::virtualMethodReturningConstChar() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualMethodReturningConstChar();
    return result.toNativeUtf8();
  } // virtualReceivingQString(const QString & str)

  virtualReceivingQString(String str) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(1183))
        .asFunction();
    func(thisCpp, str.toNativeUtf8());
  }

  static void virtualReceivingQString_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> str) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::virtualReceivingQString(const QString & str)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance
        .virtualReceivingQString(QString.fromCppPointer(str).toDartString());
  } // virtualReturningInt() const

  int virtualReturningInt() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(1184))
        .asFunction();
    return func(thisCpp);
  }

  static int virtualReturningInt_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as MyObject;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyObject::virtualReturningInt() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningInt();
    return result;
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_MyObject__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 481:
        return "c_MyObject__customEvent_QEvent";
      case 490:
        return "c_MyObject__event_QEvent";
      case 491:
        return "c_MyObject__eventFilter_QObject_QEvent";
      case 1166:
        return "c_MyObject__pureVirtual";
      case 1181:
        return "c_MyObject__virtualFunc";
      case 1182:
        return "c_MyObject__virtualMethodReturningConstChar";
      case 1183:
        return "c_MyObject__virtualReceivingQString_QString";
      case 1184:
        return "c_MyObject__virtualReturningInt";
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
      case 1166:
        return "pureVirtual";
      case 1181:
        return "virtualFunc";
      case 1182:
        return "virtualMethodReturningConstChar";
      case 1183:
        return "virtualReceivingQString";
      case 1184:
        return "virtualReturningInt";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_MyObject__registerVirtualMethodCallback')
        .asFunction();
    final callback481 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            QObject.customEvent_calledFromC);
    registerCallback(thisCpp, callback481, 481);
    const callbackExcept490 = 0;
    final callback490 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_FFI>(
            QObject.event_calledFromC, callbackExcept490);
    registerCallback(thisCpp, callback490, 490);
    const callbackExcept491 = 0;
    final callback491 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_voidstar_voidstar_FFI>(
            QObject.eventFilter_calledFromC, callbackExcept491);
    registerCallback(thisCpp, callback491, 491);
    final callback1166 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        MyObject.pureVirtual_calledFromC);
    registerCallback(thisCpp, callback1166, 1166);
    const callbackExcept1181 = 0;
    final callback1181 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyObject.virtualFunc_calledFromC, callbackExcept1181);
    registerCallback(thisCpp, callback1181, 1181);
    final callback1182 = ffi.Pointer.fromFunction<string_Func_voidstar_FFI>(
        MyObject.virtualMethodReturningConstChar_calledFromC);
    registerCallback(thisCpp, callback1182, 1182);
    final callback1183 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            MyObject.virtualReceivingQString_calledFromC);
    registerCallback(thisCpp, callback1183, 1183);
    const callbackExcept1184 = 0;
    final callback1184 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyObject.virtualReturningInt_calledFromC, callbackExcept1184);
    registerCallback(thisCpp, callback1184, 1184);
  }
}
