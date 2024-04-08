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

class Virtual1 implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, Virtual1>();
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

  factory Virtual1.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        Virtual1.fromCppPointer(cppPointer, needsAutoDelete)) as Virtual1;
  }
  Virtual1.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  Virtual1.init() {}
  String getFinalizerName() {
    return "c_Virtual1_Finalizer";
  } //Virtual1()

  Virtual1() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_Virtual1__constructor')
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
    var dartInstance = Virtual1.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Virtual1::virtualMethod1()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualMethod1();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_Virtual1__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 3:
        return "c_Virtual1__virtualMethod1";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 3:
        return "virtualMethod1";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_Virtual1__registerVirtualMethodCallback')
        .asFunction();
    final callback3 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        Virtual1.virtualMethod1_calledFromC);
    registerCallback(thisCpp, callback3, 3);
  }
}
