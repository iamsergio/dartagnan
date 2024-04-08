import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class DoubleInheritance extends SimpleStruct {
  DoubleInheritance.fromCppPointer(var cppPointer,
      [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  DoubleInheritance.init() : super.init() {}
  factory DoubleInheritance.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    if (SimpleStruct.isCached(cppPointer)) {
      var instance = SimpleStruct.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as DoubleInheritance;
    }
    return DoubleInheritance.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_DoubleInheritance_Finalizer";
  } //DoubleInheritance()

  DoubleInheritance() : super.init() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_DoubleInheritance__constructor')
        .asFunction();
    thisCpp = func();
    SimpleStruct.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // customEvent(QEvent * event)
  customEvent(QEvent? event) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(481))
        .asFunction();
    func(thisCpp, event == null ? ffi.nullptr : event.thisCpp);
  }

  static void customEvent_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::customEvent(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.customEvent((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
  } // event(QEvent * event)

  bool event(QEvent? event) {
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(490))
        .asFunction();
    return func(thisCpp, event == null ? ffi.nullptr : event.thisCpp) != 0;
  }

  static int event_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::event(QEvent * event)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.event((event == null || event.address == 0)
        ? null
        : QEvent.fromCppPointer(event));
    return result ? 1 : 0;
  } // eventFilter(QObject * watched, QEvent * event)

  bool eventFilter(QObject? watched, QEvent? event) {
    final bool_Func_voidstar_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(491))
        .asFunction();
    return func(thisCpp, watched == null ? ffi.nullptr : watched.thisCpp,
            event == null ? ffi.nullptr : event.thisCpp) !=
        0;
  }

  static int eventFilter_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? watched, ffi.Pointer<void>? event) {
    var dartInstance =
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::eventFilter(QObject * watched, QEvent * event)! (${thisCpp.address})");
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
  } // nonVirtualCallsVirtualFrom2ndBase() const

  int nonVirtualCallsVirtualFrom2ndBase() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_DoubleInheritance__nonVirtualCallsVirtualFrom2ndBase')
        .asFunction();
    return func(thisCpp);
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::pureVirtual()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.pureVirtual();
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::virtualFunc()! (${thisCpp.address})");
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::virtualMethodReturningConstChar() const! (${thisCpp.address})");
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::virtualReceivingQString(const QString & str)! (${thisCpp.address})");
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
        QObject.s_dartInstanceByCppPtr[thisCpp.address] as DoubleInheritance;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritance::virtualReturningInt() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningInt();
    return result;
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_DoubleInheritance__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 481:
        return "c_DoubleInheritance__customEvent_QEvent";
      case 490:
        return "c_DoubleInheritance__event_QEvent";
      case 491:
        return "c_DoubleInheritance__eventFilter_QObject_QEvent";
      case 1166:
        return "c_DoubleInheritance__pureVirtual";
      case 1181:
        return "c_DoubleInheritance__virtualFunc";
      case 1182:
        return "c_DoubleInheritance__virtualMethodReturningConstChar";
      case 1183:
        return "c_DoubleInheritance__virtualReceivingQString_QString";
      case 1184:
        return "c_DoubleInheritance__virtualReturningInt";
    }
    return "";
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
            'c_DoubleInheritance__registerVirtualMethodCallback')
        .asFunction();
  }
}
