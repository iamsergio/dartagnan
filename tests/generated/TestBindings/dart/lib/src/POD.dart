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

class POD implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, POD>();
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

  factory POD.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        POD.fromCppPointer(cppPointer, needsAutoDelete)) as POD;
  }
  POD.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  POD.init() {}
  String getFinalizerName() {
    return "c_TestTargetNS__POD_Finalizer";
  }

  int get v1 {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD___get_v1')
        .asFunction();
    return func(thisCpp);
  }

  set v1(int v1_) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD___set_v1_int')
        .asFunction();
    func(thisCpp, v1_);
  }

  int get v2 {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD___get_v2')
        .asFunction();
    return func(thisCpp);
  }

  set v2(int v2_) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD___set_v2_int')
        .asFunction();
    func(thisCpp, v2_);
  }

  int get v3 {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD___get_v3')
        .asFunction();
    return func(thisCpp);
  }

  set v3(int v3_) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD___set_v3_int')
        .asFunction();
    func(thisCpp, v3_);
  }

  int get v4_const {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD___get_v4_const')
        .asFunction();
    return func(thisCpp);
  } //POD()

  POD() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__POD__constructor')
        .asFunction();
    thisCpp = func();
    POD.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //POD(int a, int b, int c, int d)
  POD.ctor2(int a, int b, int c, int d) {
    final voidstar_Func_int_int_int_int func = _dylib
        .lookup<
                ffi.NativeFunction<
                    voidstar_Func_ffi_Int32_ffi_Int32_ffi_Int32_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD__constructor_int_int_int_int')
        .asFunction();
    thisCpp = func(a, b, c, d);
    POD.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // calculate() const
  int calculate() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD__calculate')
        .asFunction();
    return func(thisCpp);
  }

  static // calculateStatic()
      int calculateStatic() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__calculateStatic')
        .asFunction();
    return func();
  }

  static // doStuffOnMyClass(TestTargetNS::MyBaseClass * myarg)
      int doStuffOnMyClass(MyBaseClass? myarg) {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__doStuffOnMyClass_MyBaseClass')
        .asFunction();
    return func(myarg == null ? ffi.nullptr : myarg.thisCpp);
  } // intByConstRef() const

  int intByConstRef() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD__intByConstRef')
        .asFunction();
    return func(thisCpp);
  }

  static // receivesConstPointerToPODs(const TestTargetNS::POD * ptrPod1, const TestTargetNS::POD * ptrPod2)
      int receivesConstPointerToPODs(POD? ptrPod1, POD? ptrPod2) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__receivesConstPointerToPODs_POD_POD')
        .asFunction();
    return func(ptrPod1 == null ? ffi.nullptr : ptrPod1.thisCpp,
        ptrPod2 == null ? ffi.nullptr : ptrPod2.thisCpp);
  }

  static // receivesConstRefPODs(const TestTargetNS::POD & pod1, const TestTargetNS::POD & pod2)
      int receivesConstRefPODs(POD pod1, POD pod2) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__receivesConstRefPODs_POD_POD')
        .asFunction();
    return func(pod1 == null ? ffi.nullptr : pod1.thisCpp,
        pod2 == null ? ffi.nullptr : pod2.thisCpp);
  } // receivesNamespaceEnum(int v)

  receivesNamespaceEnum(
      {int v =
          AnotherNamespace_NamespaceLevelEnum.NamespaceLevelEnum_value1 + 1}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD__receivesNamespaceEnum_int')
        .asFunction();
    func(thisCpp, v);
  } // receivesNamespaceEnum1(AnotherNamespace::NamespaceLevelEnum arg__1)

  receivesNamespaceEnum1(
      {int arg__1 =
          AnotherNamespace_NamespaceLevelEnum.NamespaceLevelEnum_value1}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD__receivesNamespaceEnum1_NamespaceLevelEnum')
        .asFunction();
    func(thisCpp, arg__1);
  }

  static // receivesPODs(TestTargetNS::POD pod1, TestTargetNS::POD pod2)
      int receivesPODs(POD pod1, POD pod2) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__receivesPODs_POD_POD')
        .asFunction();
    return func(pod1 == null ? ffi.nullptr : pod1.thisCpp,
        pod2 == null ? ffi.nullptr : pod2.thisCpp);
  }

  static // receivesPointerToPODs(TestTargetNS::POD * ptrPod1, TestTargetNS::POD * ptrPod2)
      int receivesPointerToPODs(POD? ptrPod1, POD? ptrPod2) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__receivesPointerToPODs_POD_POD')
        .asFunction();
    return func(ptrPod1 == null ? ffi.nullptr : ptrPod1.thisCpp,
        ptrPod2 == null ? ffi.nullptr : ptrPod2.thisCpp);
  }

  static // receivesRefPODs(TestTargetNS::POD & pod1, TestTargetNS::POD & pod2)
      int receivesRefPODs(POD pod1, POD pod2) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            'c_static_TestTargetNS__POD__receivesRefPODs_POD_POD')
        .asFunction();
    return func(pod1 == null ? ffi.nullptr : pod1.thisCpp,
        pod2 == null ? ffi.nullptr : pod2.thisCpp);
  } // receivesReservedDartKeyword(int var)

  receivesReservedDartKeyword(int var_dart) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD__receivesReservedDartKeyword_int')
        .asFunction();
    func(thisCpp, var_dart);
  }

  static // returnsChar()
      String returnsChar() {
    final char_Func_void func = _dylib
        .lookup<ffi.NativeFunction<char_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsChar')
        .asFunction();
    return String.fromCharCode(func());
  }

  static // returnsConstChar()
      String returnsConstChar() {
    final char_Func_void func = _dylib
        .lookup<ffi.NativeFunction<char_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsConstChar')
        .asFunction();
    return String.fromCharCode(func());
  }

  static // returnsConstReferenceToPOD()
      POD returnsConstReferenceToPOD() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsConstReferenceToPOD')
        .asFunction();
    ffi.Pointer<void> result = func();
    return POD.fromCppPointer(result, false);
  }

  static // returnsPOD()
      POD returnsPOD() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsPOD')
        .asFunction();
    ffi.Pointer<void> result = func();
    return POD.fromCppPointer(result, true);
  }

  static // returnsPointerToPOD()
      POD returnsPointerToPOD() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsPointerToPOD')
        .asFunction();
    ffi.Pointer<void> result = func();
    return POD.fromCppPointer(result, false);
  }

  static // returnsPointerToPolymorphic()
      MyBaseClass returnsPointerToPolymorphic() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsPointerToPolymorphic')
        .asFunction();
    ffi.Pointer<void> result = func();
    return MyBaseClass.fromCppPointer(result, false);
  }

  static // returnsReferenceToPOD()
      POD returnsReferenceToPOD() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__POD__returnsReferenceToPOD')
        .asFunction();
    ffi.Pointer<void> result = func();
    return POD.fromCppPointer(result, false);
  } // withDefaultAarg(int v)

  withDefaultAarg({int v = 2}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__POD__withDefaultAarg_int')
        .asFunction();
    func(thisCpp, v);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__POD__destructor')
        .asFunction();
    func(thisCpp);
  }
}
