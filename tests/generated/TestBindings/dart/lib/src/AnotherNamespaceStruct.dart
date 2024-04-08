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

class AnotherNamespaceStruct implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, AnotherNamespaceStruct>();
  var _thisCpp = null;
  bool _needsAutoDelete = true;
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

  factory AnotherNamespaceStruct.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            AnotherNamespaceStruct.fromCppPointer(cppPointer, needsAutoDelete))
        as AnotherNamespaceStruct;
  }
  AnotherNamespaceStruct.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  AnotherNamespaceStruct.init() {}
  String getFinalizerName() {
    return "c_AnotherNamespace__AnotherNamespaceStruct_Finalizer";
  } //AnotherNamespaceStruct()

  AnotherNamespaceStruct() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_AnotherNamespace__AnotherNamespaceStruct__constructor')
        .asFunction();
    thisCpp = func();
    AnotherNamespaceStruct.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // receivesEnumerator(AnotherNamespace::NamespaceLevelEnum arg__1)
  receivesEnumerator(
      {int arg__1 =
          AnotherNamespace_NamespaceLevelEnum.NamespaceLevelEnum_value2}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_AnotherNamespace__AnotherNamespaceStruct__receivesEnumerator_NamespaceLevelEnum')
        .asFunction();
    func(thisCpp, arg__1);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_AnotherNamespace__AnotherNamespaceStruct__destructor')
        .asFunction();
    func(thisCpp);
  }
}
