import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;
final _finalizerFunc = (String name) {
  return _dylib
      .lookup<ffi.NativeFunction<ffi.Void Function(ffi.Pointer)>>(name);
};

Map<String, ffi.NativeFinalizer> _finalizers = {};

class PureAbstract implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, PureAbstract>();
  var _thisCpp = null;
  bool _needsAutoDelete = false;
  get thisCpp => _thisCpp;
  set thisCpp(var ptr) {
    _thisCpp = ptr;
    ffi.Pointer<ffi.Void> ptrvoid = ptr.cast<ffi.Void>();
    if (_needsAutoDelete) {
      final String finalizerName = getFinalizerName();
      if (!_finalizers.keys.contains(runtimeType)) {
        _finalizers[finalizerName] =
            ffi.NativeFinalizer(_finalizerFunc(finalizerName).cast());
      }
      _finalizers[finalizerName]!.attach(this, ptrvoid);
    }
  }

  static bool isCached(var cppPointer) {
    return s_dartInstanceByCppPtr.containsKey(cppPointer.address);
  }

  factory PureAbstract.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            PureAbstract.fromCppPointer(cppPointer, needsAutoDelete))
        as PureAbstract;
  }
  PureAbstract.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  PureAbstract.init() {}
  String getFinalizerName() {
    return "c_TestTargetNS__PureAbstract_Finalizer";
  }

  static int get s_instanceCount {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__PureAbstract___get_s_instanceCount')
        .asFunction();
    return func();
  }

  static set s_instanceCount(int s_instanceCount_) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__PureAbstract___set_s_instanceCount_int')
        .asFunction();
    func(s_instanceCount_);
  } //PureAbstract()

  PureAbstract() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__PureAbstract__constructor')
        .asFunction();
    thisCpp = func();
    PureAbstract.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // callVirtualReceivingPointer(SimpleStruct * s)
  int callVirtualReceivingPointer(SimpleStruct? s) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__PureAbstract__callVirtualReceivingPointer_SimpleStruct')
        .asFunction();
    return func(thisCpp, s == null ? ffi.nullptr : s.thisCpp);
  } // flagsWithDefaultArgs(QFlags<AnotherNamespace::NamespaceLevelEnum> options)

  flagsWithDefaultArgs({int options = 0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__PureAbstract__flagsWithDefaultArgs_NamespaceLevelEnums')
        .asFunction();
    func(thisCpp, options);
  } // foo()

  int foo() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(13))
        .asFunction();
    return func(thisCpp);
  }

  static int foo_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for PureAbstract::foo()! (${thisCpp.address})");
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
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for PureAbstract::renamedPureVirtual()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.renamedPureVirtual1();
  }

  static // renamedStatic()
      renamedStatic1() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_TestTargetNS__PureAbstract__renamedStatic1')
        .asFunction();
    func();
  } // returnsInt() const

  int returnsInt() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__PureAbstract__returnsInt')
        .asFunction();
    return func(thisCpp);
  } // unnamedOverriddenDefaultArgCase(int myarg)

  unnamedOverriddenDefaultArgCase({int myarg = 0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            cFunctionSymbolName(17))
        .asFunction();
    func(thisCpp, myarg);
  }

  static void unnamedOverriddenDefaultArgCase_calledFromC(
      ffi.Pointer<void> thisCpp, int myarg) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for PureAbstract::unnamedOverriddenDefaultArgCase(int myarg)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.unnamedOverriddenDefaultArgCase(myarg: myarg);
  } // virtualReceivingPointer(SimpleStruct * s)

  int virtualReceivingPointer(SimpleStruct? s) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(18))
        .asFunction();
    return func(thisCpp, s == null ? ffi.nullptr : s.thisCpp);
  }

  static int virtualReceivingPointer_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? s) {
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for PureAbstract::virtualReceivingPointer(SimpleStruct * s)! (${thisCpp.address})");
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
    var dartInstance = PureAbstract.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for PureAbstract::voidPureAbstract()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.voidPureAbstract();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__PureAbstract__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 13:
        return "c_TestTargetNS__PureAbstract__foo";
      case 14:
        return "c_TestTargetNS__PureAbstract__renamedPureVirtual1";
      case 17:
        return "c_TestTargetNS__PureAbstract__unnamedOverriddenDefaultArgCase_int";
      case 18:
        return "c_TestTargetNS__PureAbstract__virtualReceivingPointer_SimpleStruct";
      case 19:
        return "c_TestTargetNS__PureAbstract__voidPureAbstract";
    }
    return "";
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
            'c_TestTargetNS__PureAbstract__registerVirtualMethodCallback')
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
