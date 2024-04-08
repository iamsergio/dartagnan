import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class Cyclic2 extends Cyclic1 {
  Cyclic2.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  Cyclic2.init() : super.init() {}
  factory Cyclic2.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (Cyclic1.isCached(cppPointer)) {
      var instance = Cyclic1.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as Cyclic2;
    }
    return Cyclic2.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_Cyclic2_Finalizer";
  } // getCyclic1() const

  Cyclic1 getCyclic1() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_Cyclic2__getCyclic1')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return Cyclic1.fromCppPointer(result, false);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_Cyclic2__destructor')
        .asFunction();
    func(thisCpp);
  }
}
