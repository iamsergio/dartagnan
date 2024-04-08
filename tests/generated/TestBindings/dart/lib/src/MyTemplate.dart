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

class MyTemplate<T> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, MyTemplate>();
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

  factory MyTemplate.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
            MyTemplate.fromCppPointer(cppPointer, needsAutoDelete))
        as MyTemplate<T>;
  }
  MyTemplate.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  MyTemplate.init() {}
  String getCFunctionName(int id) {
    if (this is MyTemplate<int>) {
      switch (id) {
        case 1136:
          return "c_MyTemplate_T_int_T___constructor";
          break;
        case 1138:
          return "c_MyTemplate_T_int_T___receivesT_int";
          break;
        case 1139:
          return "c_MyTemplate_T_int_T___receivesTemplate_MyTemplate_T";
          break;
        case 1140:
          return "c_MyTemplate_T_int_T___returnInt";
          break;
        case 1141:
          return "c_MyTemplate_T_int_T___returnTemplate2";
          break;
        case 1142:
          return "c_MyTemplate_T_int_T___returnTemplate3";
          break;
        case 1143:
          return "c_MyTemplate_T_int_T___returnTemplate4";
          break;
        case 1144:
          return "c_MyTemplate_T_int_T___returnsT";
          break;
        case 1145:
          return "c_MyTemplate_T_int_T___returnsTemplate";
          break;
      }
    }
    if (this is MyTemplate<double>) {
      switch (id) {
        case 1136:
          return "c_MyTemplate_T_double_T___constructor";
          break;
        case 1138:
          return "c_MyTemplate_T_double_T___receivesT_double";
          break;
        case 1139:
          return "c_MyTemplate_T_double_T___receivesTemplate_MyTemplate_T";
          break;
        case 1140:
          return "c_MyTemplate_T_double_T___returnInt";
          break;
        case 1141:
          return "c_MyTemplate_T_double_T___returnTemplate2";
          break;
        case 1142:
          return "c_MyTemplate_T_double_T___returnTemplate3";
          break;
        case 1143:
          return "c_MyTemplate_T_double_T___returnTemplate4";
          break;
        case 1144:
          return "c_MyTemplate_T_double_T___returnsT";
          break;
        case 1145:
          return "c_MyTemplate_T_double_T___returnsTemplate";
          break;
      }
    }
    if (this is MyTemplate<EmptyStruct>) {
      switch (id) {
        case 1136:
          return "c_MyTemplate_T_EmptyStruct_T___constructor";
          break;
        case 1138:
          return "c_MyTemplate_T_EmptyStruct_T___receivesT_EmptyStruct";
          break;
        case 1139:
          return "c_MyTemplate_T_EmptyStruct_T___receivesTemplate_MyTemplate_T";
          break;
        case 1140:
          return "c_MyTemplate_T_EmptyStruct_T___returnInt";
          break;
        case 1141:
          return "c_MyTemplate_T_EmptyStruct_T___returnTemplate2";
          break;
        case 1142:
          return "c_MyTemplate_T_EmptyStruct_T___returnTemplate3";
          break;
        case 1143:
          return "c_MyTemplate_T_EmptyStruct_T___returnTemplate4";
          break;
        case 1144:
          return "c_MyTemplate_T_EmptyStruct_T___returnsT";
          break;
        case 1145:
          return "c_MyTemplate_T_EmptyStruct_T___returnsTemplate";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is MyTemplate<int>) {
      return "c_MyTemplate_T_int_T__Finalizer";
    }
    if (this is MyTemplate<double>) {
      return "c_MyTemplate_T_double_T__Finalizer";
    }
    if (this is MyTemplate<EmptyStruct>) {
      return "c_MyTemplate_T_EmptyStruct_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //MyTemplate<T>()

  MyTemplate() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(1136)}')
        .asFunction();
    thisCpp = func();
    MyTemplate.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // receivesT(T arg__1)
  int receivesT(T arg__1) {
    if (this is MyTemplate<EmptyStruct>) {
      final int_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(1138)}')
          .asFunction();
      return func(
          thisCpp,
          (arg__1 as EmptyStruct) == null
              ? ffi.nullptr
              : (arg__1 as EmptyStruct).thisCpp);
    }
    if (this is MyTemplate<double>) {
      final int_Func_voidstar_double func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Double_FFI>>(
              '${getCFunctionName(1138)}')
          .asFunction();
      return func(thisCpp, (arg__1 as double));
    }
    if (this is MyTemplate<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1138)}')
          .asFunction();
      return func(thisCpp, (arg__1 as int));
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // receivesTemplate(MyTemplate<T > arg__1)

  int receivesTemplate(MyTemplate arg__1) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(1139)}')
        .asFunction();
    return func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  } // returnInt() const

  int returnInt() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1140)}')
        .asFunction();
    return func(thisCpp);
  } // returnTemplate2()

  MyTemplate returnTemplate2() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            '${getCFunctionName(1141)}')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate<EmptyStruct>.fromCppPointer(result, true);
  } // returnTemplate3()

  MyTemplate returnTemplate3() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            '${getCFunctionName(1142)}')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate<EmptyStruct>.fromCppPointer(result, true);
  } // returnTemplate4()

  MyTemplate returnTemplate4() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            '${getCFunctionName(1143)}')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate<EmptyStruct>.fromCppPointer(result, true);
  } // returnsT()

  T returnsT() {
    if (this is MyTemplate<EmptyStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(1144)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (EmptyStruct.fromCppPointer(result, true) as T);
    }
    if (this is MyTemplate<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(1144)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is MyTemplate<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1144)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(-2)}')
        .asFunction();
    func(thisCpp);
  }
}
