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

class Virtual2 implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, Virtual2>();
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

  factory Virtual2.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        Virtual2.fromCppPointer(cppPointer, needsAutoDelete)) as Virtual2;
  }
  Virtual2.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  Virtual2.init() {}
  String getFinalizerName() {
    return "c_Virtual2_Finalizer";
  } //Virtual2()

  Virtual2() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_Virtual2__constructor')
        .asFunction();
    thisCpp = func();
    Virtual2.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // virtualMethod2()
  virtualMethod2() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(1))
        .asFunction();
    func(thisCpp);
  }

  static void virtualMethod2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = Virtual2.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Virtual2::virtualMethod2()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualMethod2();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_Virtual2__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 1:
        return "c_Virtual2__virtualMethod2";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 1:
        return "virtualMethod2";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_Virtual2__registerVirtualMethodCallback')
        .asFunction();
    final callback1 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        Virtual2.virtualMethod2_calledFromC);
    registerCallback(thisCpp, callback1, 1);
  }
}
