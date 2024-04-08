import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class Derived2FromPureAbstract extends PureAbstract {
  Derived2FromPureAbstract.fromCppPointer(var cppPointer,
      [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  Derived2FromPureAbstract.init() : super.init() {}
  factory Derived2FromPureAbstract.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    if (PureAbstract.isCached(cppPointer)) {
      var instance = PureAbstract.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as Derived2FromPureAbstract;
    }
    return Derived2FromPureAbstract.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_TestTargetNS__Derived2FromPureAbstract_Finalizer";
  } //Derived2FromPureAbstract()

  Derived2FromPureAbstract() : super.init() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__Derived2FromPureAbstract__constructor')
        .asFunction();
    thisCpp = func();
    PureAbstract.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // foo()
  int foo() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(13))
        .asFunction();
    return func(thisCpp);
  }

  static int foo_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as Derived2FromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Derived2FromPureAbstract::foo()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.foo();
    return result;
  } // renamedPureVirtual()

  renamedPureVirtual1() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(14))
        .asFunction();
    func(thisCpp);
  }

  static void renamedPureVirtual1_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as Derived2FromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Derived2FromPureAbstract::renamedPureVirtual()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.renamedPureVirtual1();
  }

  static void unnamedOverriddenDefaultArgCase_calledFromC(
      ffi.Pointer<void> thisCpp, int myarg) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as Derived2FromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Derived2FromPureAbstract::unnamedOverriddenDefaultArgCase(int myarg)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.unnamedOverriddenDefaultArgCase(myarg: myarg);
  }

  static int virtualReceivingPointer_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? s) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as Derived2FromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Derived2FromPureAbstract::virtualReceivingPointer(SimpleStruct * s)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingPointer(
        (s == null || s.address == 0) ? null : SimpleStruct.fromCppPointer(s));
    return result;
  } // voidPureAbstract()

  voidPureAbstract() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(19))
        .asFunction();
    func(thisCpp);
  }

  static void voidPureAbstract_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as Derived2FromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Derived2FromPureAbstract::voidPureAbstract()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.voidPureAbstract();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__Derived2FromPureAbstract__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 13:
        return "c_TestTargetNS__Derived2FromPureAbstract__foo";
      case 14:
        return "c_TestTargetNS__Derived2FromPureAbstract__renamedPureVirtual1";
      case 17:
        return "c_TestTargetNS__Derived2FromPureAbstract__unnamedOverriddenDefaultArgCase_int";
      case 18:
        return "c_TestTargetNS__Derived2FromPureAbstract__virtualReceivingPointer_SimpleStruct";
      case 19:
        return "c_TestTargetNS__Derived2FromPureAbstract__voidPureAbstract";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 13:
        return "foo";
      case 14:
        return "renamedPureVirtual1";
      case 17:
        return "unnamedOverriddenDefaultArgCase";
      case 18:
        return "virtualReceivingPointer";
      case 19:
        return "voidPureAbstract";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_TestTargetNS__Derived2FromPureAbstract__registerVirtualMethodCallback')
        .asFunction();
    const callbackExcept13 = 0;
    final callback13 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        PureAbstract.foo_calledFromC, callbackExcept13);
    registerCallback(thisCpp, callback13, 13);
    final callback14 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        PureAbstract.renamedPureVirtual1_calledFromC);
    registerCallback(thisCpp, callback14, 14);
    final callback17 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            PureAbstract.unnamedOverriddenDefaultArgCase_calledFromC);
    registerCallback(thisCpp, callback17, 17);
    const callbackExcept18 = 0;
    final callback18 = ffi.Pointer.fromFunction<int_Func_voidstar_voidstar_FFI>(
        PureAbstract.virtualReceivingPointer_calledFromC, callbackExcept18);
    registerCallback(thisCpp, callback18, 18);
    final callback19 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        PureAbstract.voidPureAbstract_calledFromC);
    registerCallback(thisCpp, callback19, 19);
  }
}
