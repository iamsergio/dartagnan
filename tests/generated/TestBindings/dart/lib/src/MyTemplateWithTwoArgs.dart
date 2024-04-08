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

class MyTemplateWithTwoArgs<T0, T1> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, MyTemplateWithTwoArgs>();
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

  factory MyTemplateWithTwoArgs.fromCache(var cppPointer,
      [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            MyTemplateWithTwoArgs.fromCppPointer(cppPointer, needsAutoDelete))
        as MyTemplateWithTwoArgs<T0, T1>;
  }
  MyTemplateWithTwoArgs.fromCppPointer(var cppPointer,
      [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  MyTemplateWithTwoArgs.init() {}
  String getCFunctionName(int id) {
    if (this is MyTemplateWithTwoArgs<int, double>) {
      switch (id) {
        case 1128:
          return "c_MyTemplateWithTwoArgs_T_int_double_T___constructor";
          break;
        case 1129:
          return "c_MyTemplateWithTwoArgs_T_int_double_T___returnInt";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is MyTemplateWithTwoArgs<int, double>) {
      return "c_MyTemplateWithTwoArgs_T_int_double_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //MyTemplateWithTwoArgs<T0, T1>()

  MyTemplateWithTwoArgs() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(1128)}')
        .asFunction();
    thisCpp = func();
    MyTemplateWithTwoArgs.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // returnInt() const
  int returnInt() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1129)}')
        .asFunction();
    return func(thisCpp);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(-2)}')
        .asFunction();
    func(thisCpp);
  }
}
