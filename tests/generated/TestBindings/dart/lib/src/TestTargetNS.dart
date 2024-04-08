import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class TestTargetNS_NameSpaceLevelEnum {
  static const NameSpaceLevelEnum_Value = 41;
} // namespaceFunctionReturningNamespaceEnum()

int namespaceFunctionReturningNamespaceEnum() {
  final int_Func_void func = _dylib
      .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
          'c_static_TestTargetNS__namespaceFunctionReturningNamespaceEnum')
      .asFunction();
  return func();
} // namespaceLevelGlobalFunction()

int namespaceLevelGlobalFunction() {
  final int_Func_void func = _dylib
      .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
          'c_static_TestTargetNS__namespaceLevelGlobalFunction')
      .asFunction();
  return func();
}
