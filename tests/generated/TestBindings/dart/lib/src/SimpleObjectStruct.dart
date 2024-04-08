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

class SimpleObjectStruct implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, SimpleObjectStruct>();
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

  factory SimpleObjectStruct.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            SimpleObjectStruct.fromCppPointer(cppPointer, needsAutoDelete))
        as SimpleObjectStruct;
  }
  SimpleObjectStruct.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  SimpleObjectStruct.init() {}
  String getFinalizerName() {
    return "c_SimpleObjectStruct_Finalizer";
  } //SimpleObjectStruct()

  SimpleObjectStruct() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_SimpleObjectStruct__constructor')
        .asFunction();
    thisCpp = func();
    SimpleObjectStruct.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // receivesStructWithDefaultArg(SimpleObjectStruct arg__1)
  receivesStructWithDefaultArg({required SimpleObjectStruct arg__1}) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_SimpleObjectStruct__receivesStructWithDefaultArg_SimpleObjectStruct')
        .asFunction();
    func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_SimpleObjectStruct__destructor')
        .asFunction();
    func(thisCpp);
  }
}
