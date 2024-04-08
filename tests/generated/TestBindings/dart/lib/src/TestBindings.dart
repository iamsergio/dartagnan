import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class GlobalEnum {
  static const GlobalEnum_Value = 30;
}

class MyEnumClass {
  static const Value = 1;
  static const ValueFoo = 2;
} // globalFunction()

int globalFunction() {
  final int_Func_void func = _dylib
      .lookup<ffi.NativeFunction<int_Func_void_FFI>>('c___globalFunction')
      .asFunction();
  return func();
} // receivesStructAsOptionalArgument(EmptyStruct arg1)

int receivesStructAsOptionalArgument({required EmptyStruct arg1}) {
  final int_Func_voidstar func = _dylib
      .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
          'c___receivesStructAsOptionalArgument_EmptyStruct')
      .asFunction();
  return func(arg1 == null ? ffi.nullptr : arg1.thisCpp);
} // receivesStructAsOptionalArgument2(EmptyStruct arg__1)

int receivesStructAsOptionalArgument2({required EmptyStruct arg__1}) {
  final int_Func_voidstar func = _dylib
      .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
          'c___receivesStructAsOptionalArgument2_EmptyStruct')
      .asFunction();
  return func(arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
} // receivingPureAbstract(TestTargetNS::PureAbstract * a)

int receivingPureAbstract(PureAbstract? a) {
  final int_Func_voidstar func = _dylib
      .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
          'c_static___receivingPureAbstract_PureAbstract')
      .asFunction();
  return func(a == null ? ffi.nullptr : a.thisCpp);
} // returnsPureAbstract()

PureAbstract returnsPureAbstract() {
  final voidstar_Func_void func = _dylib
      .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
          'c_static___returnsPureAbstract')
      .asFunction();
  ffi.Pointer<void> result = func();
  return PureAbstract.fromCppPointer(result, false);
}
