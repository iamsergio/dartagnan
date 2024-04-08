import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class AnotherNamespace_NamespaceLevelEnum {
  static const NamespaceLevelEnum_value1 = 1;
  static const NamespaceLevelEnum_value2 = 2;
}

class AnotherNamespace_MyNamespacedEnumClass {
  static const ValueFoo1 = 0;
} // size(QString s)

QString size(String s) {
  final voidstar_Func_voidstar func = _dylib
      .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
          'c_static_AnotherNamespace__size_QString')
      .asFunction();
  ffi.Pointer<void> result = func(s.toNativeUtf8());
  return QString.fromCppPointer(result, true);
}
