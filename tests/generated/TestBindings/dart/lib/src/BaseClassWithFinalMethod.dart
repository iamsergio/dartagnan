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

class BaseClassWithFinalMethod implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, BaseClassWithFinalMethod>();
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

  factory BaseClassWithFinalMethod.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        BaseClassWithFinalMethod.fromCppPointer(
            cppPointer, needsAutoDelete)) as BaseClassWithFinalMethod;
  }
  BaseClassWithFinalMethod.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  BaseClassWithFinalMethod.init() {}
  String getFinalizerName() {
    return "c_BaseClassWithFinalMethod_Finalizer";
  } //BaseClassWithFinalMethod()

  BaseClassWithFinalMethod() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_BaseClassWithFinalMethod__constructor')
        .asFunction();
    thisCpp = func();
    BaseClassWithFinalMethod.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // finalMethod()
  finalMethod() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(1200))
        .asFunction();
    func(thisCpp);
  }

  static void finalMethod_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        BaseClassWithFinalMethod.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for BaseClassWithFinalMethod::finalMethod()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.finalMethod();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_BaseClassWithFinalMethod__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 1200:
        return "c_BaseClassWithFinalMethod__finalMethod";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 1200:
        return "finalMethod";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_BaseClassWithFinalMethod__registerVirtualMethodCallback')
        .asFunction();
    final callback1200 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        BaseClassWithFinalMethod.finalMethod_calledFromC);
    registerCallback(thisCpp, callback1200, 1200);
  }
}
