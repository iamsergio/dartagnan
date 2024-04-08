import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class DerivedFromPureAbstract extends PureAbstract {
  DerivedFromPureAbstract.fromCppPointer(var cppPointer,
      [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  DerivedFromPureAbstract.init() : super.init() {}
  factory DerivedFromPureAbstract.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    if (PureAbstract.isCached(cppPointer)) {
      var instance = PureAbstract.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as DerivedFromPureAbstract;
    }
    return DerivedFromPureAbstract.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_TestTargetNS__DerivedFromPureAbstract_Finalizer";
  } //DerivedFromPureAbstract()

  DerivedFromPureAbstract() : super.init() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__DerivedFromPureAbstract__constructor')
        .asFunction();
    thisCpp = func();
    PureAbstract.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } //DerivedFromPureAbstract(int arg__1)
  DerivedFromPureAbstract.ctor2(int arg__1) : super.init() {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            'c_TestTargetNS__DerivedFromPureAbstract__constructor_int')
        .asFunction();
    thisCpp = func(arg__1);
    PureAbstract.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  }
  static int foo_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::foo()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.foo();
    return result;
  } // indirectionCallsVirtualReceivingStruct(SimpleStruct s)

  int indirectionCallsVirtualReceivingStruct(SimpleStruct s) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__DerivedFromPureAbstract__indirectionCallsVirtualReceivingStruct_SimpleStruct')
        .asFunction();
    return func(thisCpp, s == null ? ffi.nullptr : s.thisCpp);
  } // nonVirtualCallsVirtual()

  int nonVirtualCallsVirtual() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__DerivedFromPureAbstract__nonVirtualCallsVirtual')
        .asFunction();
    return func(thisCpp);
  } // receivesValueStruct(SimpleStruct arg__1)

  int receivesValueStruct(SimpleStruct arg__1) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(193))
        .asFunction();
    return func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  }

  static int receivesValueStruct_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> arg__1) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::receivesValueStruct(SimpleStruct arg__1)! (${thisCpp.address})");
      throw Error();
    }
    final result =
        dartInstance.receivesValueStruct(SimpleStruct.fromCppPointer(arg__1));
    return result;
  }

  static void renamedPureVirtual1_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::renamedPureVirtual()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.renamedPureVirtual1();
  }

  static void unnamedOverriddenDefaultArgCase_calledFromC(
      ffi.Pointer<void> thisCpp, int arg__1) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::unnamedOverriddenDefaultArgCase(int arg__1)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.unnamedOverriddenDefaultArgCase(myarg: arg__1);
  }

  static int virtualReceivingPointer_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? s) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::virtualReceivingPointer(SimpleStruct * s)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingPointer(
        (s == null || s.address == 0) ? null : SimpleStruct.fromCppPointer(s));
    return result;
  }

  static void voidPureAbstract_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address]
        as DerivedFromPureAbstract;
    if (dartInstance == null) {
      print(
          "Dart instance not found for DerivedFromPureAbstract::voidPureAbstract()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.voidPureAbstract();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__DerivedFromPureAbstract__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 13:
        return "c_TestTargetNS__DerivedFromPureAbstract__foo";
      case 193:
        return "c_TestTargetNS__DerivedFromPureAbstract__receivesValueStruct_SimpleStruct";
      case 14:
        return "c_TestTargetNS__DerivedFromPureAbstract__renamedPureVirtual1";
      case 17:
        return "c_TestTargetNS__DerivedFromPureAbstract__unnamedOverriddenDefaultArgCase_int";
      case 18:
        return "c_TestTargetNS__DerivedFromPureAbstract__virtualReceivingPointer_SimpleStruct";
      case 19:
        return "c_TestTargetNS__DerivedFromPureAbstract__voidPureAbstract";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 13:
        return "foo";
      case 193:
        return "receivesValueStruct";
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
            'c_TestTargetNS__DerivedFromPureAbstract__registerVirtualMethodCallback')
        .asFunction();
    const callbackExcept13 = 0;
    final callback13 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        DerivedFromPureAbstract.foo_calledFromC, callbackExcept13);
    registerCallback(thisCpp, callback13, 13);
    const callbackExcept193 = 0;
    final callback193 =
        ffi.Pointer.fromFunction<int_Func_voidstar_voidstar_FFI>(
            DerivedFromPureAbstract.receivesValueStruct_calledFromC,
            callbackExcept193);
    registerCallback(thisCpp, callback193, 193);
    final callback14 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        DerivedFromPureAbstract.renamedPureVirtual1_calledFromC);
    registerCallback(thisCpp, callback14, 14);
    final callback17 = ffi.Pointer.fromFunction<
            void_Func_voidstar_ffi_Int32_FFI>(
        DerivedFromPureAbstract.unnamedOverriddenDefaultArgCase_calledFromC);
    registerCallback(thisCpp, callback17, 17);
    const callbackExcept18 = 0;
    final callback18 = ffi.Pointer.fromFunction<int_Func_voidstar_voidstar_FFI>(
        PureAbstract.virtualReceivingPointer_calledFromC, callbackExcept18);
    registerCallback(thisCpp, callback18, 18);
    final callback19 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        DerivedFromPureAbstract.voidPureAbstract_calledFromC);
    registerCallback(thisCpp, callback19, 19);
  }
}
