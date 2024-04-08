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

class MyTemplate2<T> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, MyTemplate2>();
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

  factory MyTemplate2.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            MyTemplate2.fromCppPointer(cppPointer, needsAutoDelete))
        as MyTemplate2<T>;
  }
  MyTemplate2.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  MyTemplate2.init() {}
  String getCFunctionName(int id) {
    if (this is MyTemplate2<NonCopiable>) {
      switch (id) {
        case 1130:
          return "c_MyTemplate2_T_NonCopiable_T___constructor";
          break;
        case 1132:
          return "c_MyTemplate2_T_NonCopiable_T___assignsT";
          break;
        case 1133:
          return "c_MyTemplate2_T_NonCopiable_T___count";
          break;
        case 1134:
          return "c_MyTemplate2_T_NonCopiable_T___receivesT_NonCopiable";
          break;
        case 1135:
          return "c_MyTemplate2_T_NonCopiable_T___returnTemplate1";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is MyTemplate2<NonCopiable>) {
      return "c_MyTemplate2_T_NonCopiable_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //MyTemplate2()

  MyTemplate2() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(1130)}')
        .asFunction();
    thisCpp = func();
    MyTemplate2.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // assignsT()
  assignsT() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1132)}')
        .asFunction();
    func(thisCpp);
  } // count() const

  int count() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1133)}')
        .asFunction();
    return func(thisCpp);
  } // receivesT(T arg__1)

  receivesT(T arg__1) {
    if (this is MyTemplate2<NonCopiable>) {
      final void_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(1134)}')
          .asFunction();
      func(
          thisCpp,
          (arg__1 as NonCopiable) == null
              ? ffi.nullptr
              : (arg__1 as NonCopiable).thisCpp);
    }
  } // returnTemplate1()

  MyTemplate2 returnTemplate1() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            '${getCFunctionName(1135)}')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate2<NonCopiable>.fromCppPointer(result, true);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(-2)}')
        .asFunction();
    func(thisCpp);
  }
}
