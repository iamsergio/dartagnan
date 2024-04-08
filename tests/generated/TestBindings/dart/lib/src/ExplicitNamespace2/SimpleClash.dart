import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import '../TypeHelpers.dart';
import '../../Bindings.dart';
import '../../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../../LibraryLoader.dart';

var _dylib = Library.instance().dylib;
final _finalizerFunc = (String name) {
  return _dylib
      .lookup<ffi.NativeFunction<ffi.Void Function(ffi.Pointer)>>(name);
};

Map<String, ffi.NativeFinalizer> _finalizers = {};

class SimpleClash implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, SimpleClash>();
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

  factory SimpleClash.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        SimpleClash.fromCppPointer(cppPointer, needsAutoDelete)) as SimpleClash;
  }
  SimpleClash.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  SimpleClash.init() {}
  String getFinalizerName() {
    return "c_NameClashingNS2__SimpleClash_Finalizer";
  } //SimpleClash(int arg__1)

  SimpleClash(int arg__1) {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            'c_NameClashingNS2__SimpleClash__constructor_int')
        .asFunction();
    thisCpp = func(arg__1);
    ExplicitNamespace2.SimpleClash.s_dartInstanceByCppPtr[thisCpp.address] =
        this;
  } // getFoo()
  int getFoo() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_NameClashingNS2__SimpleClash__getFoo')
        .asFunction();
    return func(thisCpp);
  }

  static // getValueStatic()
      int getValueStatic() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_NameClashingNS2__SimpleClash__getValueStatic')
        .asFunction();
    return func();
  }

  static // returnsAndReceivesFromOtherScope(NameClashingNS1::SimpleClash s)
      ExplicitNamespace1.SimpleClash returnsAndReceivesFromOtherScope(
          ExplicitNamespace1.SimpleClash s) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_static_NameClashingNS2__SimpleClash__returnsAndReceivesFromOtherScope_SimpleClash')
        .asFunction();
    ffi.Pointer<void> result = func(s == null ? ffi.nullptr : s.thisCpp);
    return ExplicitNamespace1.SimpleClash.fromCppPointer(result, true);
  }

  static // returnsFromOtherScope()
      ExplicitNamespace1.SimpleClash returnsFromOtherScope() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_NameClashingNS2__SimpleClash__returnsFromOtherScope')
        .asFunction();
    ffi.Pointer<void> result = func();
    return ExplicitNamespace1.SimpleClash.fromCppPointer(result, true);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_NameClashingNS2__SimpleClash__destructor')
        .asFunction();
    func(thisCpp);
  }
}
