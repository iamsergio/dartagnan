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

class PureAbstractWithUnknownType implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, PureAbstractWithUnknownType>();
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

  factory PureAbstractWithUnknownType.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        PureAbstractWithUnknownType.fromCppPointer(
            cppPointer, needsAutoDelete)) as PureAbstractWithUnknownType;
  }
  PureAbstractWithUnknownType.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  PureAbstractWithUnknownType.init() {}
  String getFinalizerName() {
    return "c_PureAbstractWithUnknownType_Finalizer";
  } //PureAbstractWithUnknownType()

  PureAbstractWithUnknownType() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_PureAbstractWithUnknownType__constructor')
        .asFunction();
    thisCpp = func();
    PureAbstractWithUnknownType.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // getValue() const
  int getValue() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_PureAbstractWithUnknownType__getValue')
        .asFunction();
    return func(thisCpp);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_PureAbstractWithUnknownType__destructor')
        .asFunction();
    func(thisCpp);
  }
}
