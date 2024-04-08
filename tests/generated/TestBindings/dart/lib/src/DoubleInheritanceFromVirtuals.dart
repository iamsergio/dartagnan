import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class DoubleInheritanceFromVirtuals extends Virtual1 {
  DoubleInheritanceFromVirtuals.fromCppPointer(var cppPointer,
      [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  DoubleInheritanceFromVirtuals.init() : super.init() {}
  factory DoubleInheritanceFromVirtuals.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    if (Virtual1.isCached(cppPointer)) {
      var instance = Virtual1.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as DoubleInheritanceFromVirtuals;
    }
    return DoubleInheritanceFromVirtuals.fromCppPointer(
        cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_DoubleInheritanceFromVirtuals_Finalizer";
  } //DoubleInheritanceFromVirtuals()

  DoubleInheritanceFromVirtuals() : super.init() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_DoubleInheritanceFromVirtuals__constructor')
        .asFunction();
    thisCpp = func();
    Virtual1.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // virtualMethod1()
  virtualMethod1() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(3))
        .asFunction();
    func(thisCpp);
  }

  static void virtualMethod1_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = Virtual1.s_dartInstanceByCppPtr[thisCpp.address]
        as DoubleInheritanceFromVirtuals;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritanceFromVirtuals::virtualMethod1()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualMethod1();
  } // virtualMethod2()

  virtualMethod2() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(1))
        .asFunction();
    func(thisCpp);
  }

  static void virtualMethod2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = Virtual2.s_dartInstanceByCppPtr[thisCpp.address]
        as DoubleInheritanceFromVirtuals;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DoubleInheritanceFromVirtuals::virtualMethod2()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualMethod2();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_DoubleInheritanceFromVirtuals__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 3:
        return "c_DoubleInheritanceFromVirtuals__virtualMethod1";
      case 1:
        return "c_DoubleInheritanceFromVirtuals__virtualMethod2";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 3:
        return "virtualMethod1";
      case 1:
        return "virtualMethod2";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_DoubleInheritanceFromVirtuals__registerVirtualMethodCallback')
        .asFunction();
    final callback3 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        Virtual1.virtualMethod1_calledFromC);
    registerCallback(thisCpp, callback3, 3);
  }
}
