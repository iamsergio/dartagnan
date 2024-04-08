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

class DestructorCounter implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, DestructorCounter>();
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

  factory DestructorCounter.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            DestructorCounter.fromCppPointer(cppPointer, needsAutoDelete))
        as DestructorCounter;
  }
  DestructorCounter.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  DestructorCounter.init() {}
  String getFinalizerName() {
    return "c_TestTargetNS__DestructorCounter_Finalizer";
  }

  static int get s_instanceCount {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__DestructorCounter___get_s_instanceCount')
        .asFunction();
    return func();
  }

  static set s_instanceCount(int s_instanceCount_) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__DestructorCounter___set_s_instanceCount_int')
        .asFunction();
    func(s_instanceCount_);
  } //DestructorCounter()

  DestructorCounter() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__DestructorCounter__constructor')
        .asFunction();
    thisCpp = func();
    DestructorCounter.s_dartInstanceByCppPtr[thisCpp.address] = this;
  }
  static // instanceCount()
      int instanceCount() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__DestructorCounter__instanceCount')
        .asFunction();
    return func();
  }

  static // newOnTheHeap()
      DestructorCounter newOnTheHeap() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__DestructorCounter__newOnTheHeap')
        .asFunction();
    ffi.Pointer<void> result = func();
    return DestructorCounter.fromCppPointer(result, false);
  }

  static // newOnTheStack()
      DestructorCounter newOnTheStack() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__DestructorCounter__newOnTheStack')
        .asFunction();
    ffi.Pointer<void> result = func();
    return DestructorCounter.fromCppPointer(result, true);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__DestructorCounter__destructor')
        .asFunction();
    func(thisCpp);
  }
}
