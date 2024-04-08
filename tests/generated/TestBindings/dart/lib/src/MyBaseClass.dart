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

class MyBaseClass_MyEnum {
  static const MyEnumerator0 = 0;
  static const MyEnumerator1 = 1;
  static const MyEnumerator3 = 3;
}

class MyBaseClass_ProtectedEnum {
  static const ProtectedEnum_V1 = 1;
}

class MyBaseClass implements ffi.Finalizable {
  // Anonymous enum
  static const AnonymousEnumerator1 = 1;
  static const AnonymousEnumerator2 = 2;
  static const AnonymousEnumerator3 = 3;
  static var s_dartInstanceByCppPtr = Map<int, MyBaseClass>();
  var _thisCpp = null;
  bool _needsAutoDelete = false;
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

  factory MyBaseClass.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        MyBaseClass.fromCppPointer(cppPointer, needsAutoDelete)) as MyBaseClass;
  }
  MyBaseClass.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  MyBaseClass.init() {}
  String getFinalizerName() {
    return "c_TestTargetNS__MyBaseClass_Finalizer";
  }

  static int get s_instanceCount {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass___get_s_instanceCount')
        .asFunction();
    return func();
  }

  static set s_instanceCount(int s_instanceCount_) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass___set_s_instanceCount_int')
        .asFunction();
    func(s_instanceCount_);
  }

  static int get s_staticMember {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass___get_s_staticMember')
        .asFunction();
    return func();
  }

  static set s_staticMember(int s_staticMember_) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass___set_s_staticMember_int')
        .asFunction();
    func(s_staticMember_);
  }

  static int get s_staticConstMember {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass___get_s_staticConstMember')
        .asFunction();
    return func();
  } //MyBaseClass()

  MyBaseClass() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__MyBaseClass__constructor')
        .asFunction();
    thisCpp = func();
    MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } //MyBaseClass(TestTargetNS::MyBaseClass * mybaseclassptr)
  MyBaseClass.ctor2(MyBaseClass? mybaseclassptr) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__constructor_MyBaseClass')
        .asFunction();
    thisCpp =
        func(mybaseclassptr == null ? ffi.nullptr : mybaseclassptr.thisCpp);
    MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // addInts(QList<int > arg__1)
  addInts(QList arg__1) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__addInts_QList_int')
        .asFunction();
    func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  } // addQObjects(const QList<QObject* > & arg__1)

  addQObjects(QList arg__1) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__addQObjects_QList_QObject')
        .asFunction();
    func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  } // addReals(QList<qreal > arg__1)

  addReals(QList arg__1) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__addReals_QList_qreal')
        .asFunction();
    func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  }

  static // anotherOverloadedStatic(int arg__1)
      int anotherOverloadedStatic(int arg__1) {
    final int_Func_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__anotherOverloadedStatic_int')
        .asFunction();
    return func(arg__1);
  } // bar() const

  int bar() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(51))
        .asFunction();
    return func(thisCpp);
  }

  static int bar_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::bar() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.bar();
    return result;
  } // bar2() const

  int bar2() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(52))
        .asFunction();
    return func(thisCpp);
  }

  static int bar2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::bar2() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.bar2();
    return result;
  } // callsVirtual() const

  int callsVirtual() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__callsVirtual')
        .asFunction();
    return func(thisCpp);
  } // foo() const

  int foo() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__foo')
        .asFunction();
    return func(thisCpp);
  } // getBool(int arg__1) const

  bool getBool(int arg__1) {
    final bool_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__getBool_int')
        .asFunction();
    return func(thisCpp, arg__1) != 0;
  } // getBoolFalse() const

  bool getBoolFalse() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__getBoolFalse')
        .asFunction();
    return func(thisCpp) != 0;
  } // getBoolTrue() const

  bool getBoolTrue() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__getBoolTrue')
        .asFunction();
    return func(thisCpp) != 0;
  } // hello()

  hello() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__hello')
        .asFunction();
    func(thisCpp);
  } // methodReturnsIntTemplate()

  MyTemplate methodReturnsIntTemplate() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__methodReturnsIntTemplate')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate<int>.fromCppPointer(result, true);
  } // nonVirtualButOverridden() const

  int nonVirtualButOverridden() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__nonVirtualButOverridden')
        .asFunction();
    return func(thisCpp);
  } // nonVirtualInBaseButVirtualInDerived(int i) const

  int nonVirtualInBaseButVirtualInDerived(int i) {
    final int_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int')
        .asFunction();
    return func(thisCpp, i);
  } // nonVirtualInBaseButVirtualInDerived(int i, int j) const

  int nonVirtualInBaseButVirtualInDerived_2(int i, int j) {
    final int_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            cFunctionSymbolName(63))
        .asFunction();
    return func(thisCpp, i, j);
  }

  static int nonVirtualInBaseButVirtualInDerived_2_calledFromC(
      ffi.Pointer<void> thisCpp, int i, int j) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.nonVirtualInBaseButVirtualInDerived_2(i, j);
    return result;
  } // nonVirtualReturningStruct() const

  SimpleStruct nonVirtualReturningStruct() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__nonVirtualReturningStruct')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return SimpleStruct.fromCppPointer(result, true);
  }

  static // overloadedStatic()
      overloadedStatic() {
    final void_Func_void func = _dylib
        .lookup<ffi.NativeFunction<void_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__overloadedStatic')
        .asFunction();
    func();
  }

  static // overloadedStatic(int arg__1)
      overloadedStatic_2(int arg__1) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__overloadedStatic_int')
        .asFunction();
    func(arg__1);
  }

  static // overloadedStatic(int arg__1, int arg__2)
      overloadedStatic_3(int arg__1, int arg__2) {
    final void_Func_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__overloadedStatic_int_int')
        .asFunction();
    func(arg__1, arg__2);
  }

  static // print(const char * msg)
      print(String? msg) {
    final void_Func_string func = _dylib
        .lookup<ffi.NativeFunction<void_Func_string_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__print_char')
        .asFunction();
    func(msg?.toNativeUtf8() ?? ffi.nullptr);
  } // push(const char * arg__1)

  push(String? arg__1) {
    final void_Func_voidstar_string func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_string_FFI>>(
            'c_TestTargetNS__MyBaseClass__push_char')
        .asFunction();
    func(thisCpp, arg__1?.toNativeUtf8() ?? ffi.nullptr);
  } // receivesAndReturnsQString(const QString & s)

  QString receivesAndReturnsQString(String s) {
    final voidstar_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesAndReturnsQString_QString')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp, s.toNativeUtf8());
    return QString.fromCppPointer(result, true);
  } // receivesEnum(TestTargetNS::MyBaseClass::MyEnum e)

  int receivesEnum(int e) {
    final int_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesEnum_MyEnum')
        .asFunction();
    return func(thisCpp, e);
  } // receivesEnumWithDefaultArg(TestTargetNS::MyBaseClass::MyEnum arg__1)

  receivesEnumWithDefaultArg({int arg__1 = MyBaseClass_MyEnum.MyEnumerator0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArg_MyEnum')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesEnumWithDefaultArgNull(TestTargetNS::MyBaseClass::MyEnum arg__1)

  receivesEnumWithDefaultArgNull({int arg__1 = 0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesEnumWithDefaultArgNull_MyEnum')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesFloat(float arg__1)

  receivesFloat(double arg__1) {
    final void_Func_voidstar_double func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Double_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesFloat_float')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesQFlags(QFlags<AnotherNamespace::NamespaceLevelEnum> arg__1)

  receivesQFlags(int arg__1) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesQFlags_NamespaceLevelEnums')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesintWithDefaultEnumArg(int arg__1)

  receivesintWithDefaultEnumArg(
      {int arg__1 = MyBaseClass_MyEnum.MyEnumerator0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg_int')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesintWithDefaultEnumArg2(int arg__1)

  receivesintWithDefaultEnumArg2(
      {int arg__1 = MyBaseClass.AnonymousEnumerator1}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg2_int')
        .asFunction();
    func(thisCpp, arg__1);
  } // receivesintWithDefaultEnumArg3(int arg__1)

  receivesintWithDefaultEnumArg3(
      {int arg__1 = MyBaseClass_MyEnum.MyEnumerator0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__receivesintWithDefaultEnumArg3_int')
        .asFunction();
    func(thisCpp, arg__1);
  } // renamedMethod1()

  renamedMethod2() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__renamedMethod2')
        .asFunction();
    func(thisCpp);
  } // renamedVirtual1()

  renamedVirtual2() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(86))
        .asFunction();
    func(thisCpp);
  }

  static void renamedVirtual2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::renamedVirtual1()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.renamedVirtual2();
  }

  static // returnsConstChar()
      String returnsConstChar() {
    final string_Func_void func = _dylib
        .lookup<ffi.NativeFunction<string_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsConstChar')
        .asFunction();
    ffi.Pointer<Utf8> result = func();
    return result.toDartString();
  }

  static // returnsDoubleTemplate()
      MyTemplate returnsDoubleTemplate() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsDoubleTemplate')
        .asFunction();
    ffi.Pointer<void> result = func();
    return MyTemplate<double>.fromCppPointer(result, true);
  }

  static // returnsIntTemplate()
      MyTemplate returnsIntTemplate() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsIntTemplate')
        .asFunction();
    ffi.Pointer<void> result = func();
    return MyTemplate<int>.fromCppPointer(result, true);
  }

  static // returnsListOfStructPtr()
      QList returnsListOfStructPtr() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsListOfStructPtr')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QList<SimpleStruct>.fromCppPointer(result, true);
  } // returnsQFlags() const

  int returnsQFlags() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__returnsQFlags')
        .asFunction();
    return func(thisCpp);
  }

  static // returnsQString()
      QString returnsQString() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsQString')
        .asFunction();
    ffi.Pointer<void> result = func();
    return QString.fromCppPointer(result, true);
  } // returnsReals() const

  QList returnsReals() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__returnsReals')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QList<double>.fromCppPointer(result, true);
  }

  static // returnsSimpleStruct(int value)
      SimpleStruct returnsSimpleStruct(int value) {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsSimpleStruct_int')
        .asFunction();
    ffi.Pointer<void> result = func(value);
    return SimpleStruct.fromCppPointer(result, true);
  }

  static // returnsTemplateWithTwoArgs()
      MyTemplateWithTwoArgs returnsTemplateWithTwoArgs() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyBaseClass__returnsTemplateWithTwoArgs')
        .asFunction();
    ffi.Pointer<void> result = func();
    return MyTemplateWithTwoArgs<int, double>.fromCppPointer(result, true);
  } // returnsVector()

  QList returnsVector() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__returnsVector')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QList<int>.fromCppPointer(result, true);
  } // setBool(bool b)

  bool setBool(bool b) {
    final bool_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int8_FFI>>(
            'c_TestTargetNS__MyBaseClass__setBool_bool')
        .asFunction();
    return func(thisCpp, b ? 1 : 0) != 0;
  } // sum(int a, int b)

  int sum(int a, int b) {
    final int_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyBaseClass__sum_int_int')
        .asFunction();
    return func(thisCpp, a, b);
  } // virtualReceivingBool(bool b)

  int virtualReceivingBool(bool b) {
    final int_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int8_FFI>>(
            cFunctionSymbolName(103))
        .asFunction();
    return func(thisCpp, b ? 1 : 0);
  }

  static int virtualReceivingBool_calledFromC(
      ffi.Pointer<void> thisCpp, int b) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReceivingBool(bool b)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingBool(b != 0);
    return result;
  } // virtualReceivingCharPtr(char * arg__1)

  virtualReceivingCharPtr(String? arg__1) {
    final void_Func_voidstar_string func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_string_FFI>>(
            cFunctionSymbolName(104))
        .asFunction();
    func(thisCpp, arg__1?.toNativeUtf8() ?? ffi.nullptr);
  }

  static void virtualReceivingCharPtr_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<Utf8>? arg__1) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReceivingCharPtr(char * arg__1)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualReceivingCharPtr(arg__1.toString());
  } // virtualReceivingInt(int arg__1)

  int virtualReceivingInt(int arg__1) {
    final int_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
            cFunctionSymbolName(105))
        .asFunction();
    return func(thisCpp, arg__1);
  }

  static int virtualReceivingInt_calledFromC(
      ffi.Pointer<void> thisCpp, int arg__1) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReceivingInt(int arg__1)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingInt(arg__1);
    return result;
  } // virtualReceivingOptionalArgument(int optional)

  int virtualReceivingOptionalArgument({int optional = 1}) {
    final int_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
            cFunctionSymbolName(106))
        .asFunction();
    return func(thisCpp, optional);
  }

  static int virtualReceivingOptionalArgument_calledFromC(
      ffi.Pointer<void> thisCpp, int optional) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReceivingOptionalArgument(int optional)! (${thisCpp.address})");
      throw Error();
    }
    final result =
        dartInstance.virtualReceivingOptionalArgument(optional: optional);
    return result;
  } // virtualReturningBool(bool b)

  bool virtualReturningBool(bool b) {
    final bool_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int8_FFI>>(
            cFunctionSymbolName(107))
        .asFunction();
    return func(thisCpp, b ? 1 : 0) != 0;
  }

  static int virtualReturningBool_calledFromC(
      ffi.Pointer<void> thisCpp, int b) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReturningBool(bool b)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningBool(b != 0);
    return result ? 1 : 0;
  } // virtualReturningStruct() const

  SimpleStruct virtualReturningStruct() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(109))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return SimpleStruct.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> virtualReturningStruct_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReturningStruct() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningStruct();
    return result.thisCpp;
  } // virtualReturnsIntTemplate()

  MyTemplate virtualReturnsIntTemplate() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(110))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate<int>.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> virtualReturnsIntTemplate_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualReturnsIntTemplate()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturnsIntTemplate();
    return result.thisCpp;
  } // virtualWithNoDefaultArgumentInDerived(int optional)

  virtualWithNoDefaultArgumentInDerived({int optional = 1}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            cFunctionSymbolName(111))
        .asFunction();
    func(thisCpp, optional);
  }

  static void virtualWithNoDefaultArgumentInDerived_calledFromC(
      ffi.Pointer<void> thisCpp, int optional) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualWithNoDefaultArgumentInDerived(int optional)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualWithNoDefaultArgumentInDerived(optional: optional);
  } // virtualWithOverload(int i) const

  virtualWithOverload(int i) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            cFunctionSymbolName(112))
        .asFunction();
    func(thisCpp, i);
  }

  static void virtualWithOverload_calledFromC(
      ffi.Pointer<void> thisCpp, int i) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualWithOverload(int i) const! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualWithOverload(i);
  } // virtualWithOverload(int i, int j) const

  virtualWithOverload_2(int i, int j) {
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            cFunctionSymbolName(113))
        .asFunction();
    func(thisCpp, i, j);
  }

  static void virtualWithOverload_2_calledFromC(
      ffi.Pointer<void> thisCpp, int i, int j) {
    var dartInstance = MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyBaseClass::virtualWithOverload(int i, int j) const! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualWithOverload_2(i, j);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyBaseClass__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 51:
        return "c_TestTargetNS__MyBaseClass__bar";
      case 52:
        return "c_TestTargetNS__MyBaseClass__bar2";
      case 63:
        return "c_TestTargetNS__MyBaseClass__nonVirtualInBaseButVirtualInDerived_int_int";
      case 86:
        return "c_TestTargetNS__MyBaseClass__renamedVirtual2";
      case 103:
        return "c_TestTargetNS__MyBaseClass__virtualReceivingBool_bool";
      case 104:
        return "c_TestTargetNS__MyBaseClass__virtualReceivingCharPtr_char";
      case 105:
        return "c_TestTargetNS__MyBaseClass__virtualReceivingInt_int";
      case 106:
        return "c_TestTargetNS__MyBaseClass__virtualReceivingOptionalArgument_int";
      case 107:
        return "c_TestTargetNS__MyBaseClass__virtualReturningBool_bool";
      case 109:
        return "c_TestTargetNS__MyBaseClass__virtualReturningStruct";
      case 110:
        return "c_TestTargetNS__MyBaseClass__virtualReturnsIntTemplate";
      case 111:
        return "c_TestTargetNS__MyBaseClass__virtualWithNoDefaultArgumentInDerived_int";
      case 112:
        return "c_TestTargetNS__MyBaseClass__virtualWithOverload_int";
      case 113:
        return "c_TestTargetNS__MyBaseClass__virtualWithOverload_int_int";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 51:
        return "bar";
      case 52:
        return "bar2";
      case 63:
        return "nonVirtualInBaseButVirtualInDerived_2";
      case 86:
        return "renamedVirtual2";
      case 103:
        return "virtualReceivingBool";
      case 104:
        return "virtualReceivingCharPtr";
      case 105:
        return "virtualReceivingInt";
      case 106:
        return "virtualReceivingOptionalArgument";
      case 107:
        return "virtualReturningBool";
      case 109:
        return "virtualReturningStruct";
      case 110:
        return "virtualReturnsIntTemplate";
      case 111:
        return "virtualWithNoDefaultArgumentInDerived";
      case 112:
        return "virtualWithOverload";
      case 113:
        return "virtualWithOverload_2";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_TestTargetNS__MyBaseClass__registerVirtualMethodCallback')
        .asFunction();
    const callbackExcept51 = 0;
    final callback51 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyBaseClass.bar_calledFromC, callbackExcept51);
    registerCallback(thisCpp, callback51, 51);
    const callbackExcept52 = 0;
    final callback52 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyBaseClass.bar2_calledFromC, callbackExcept52);
    registerCallback(thisCpp, callback52, 52);
    const callbackExcept63 = 0;
    final callback63 =
        ffi.Pointer.fromFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            MyBaseClass.nonVirtualInBaseButVirtualInDerived_2_calledFromC,
            callbackExcept63);
    registerCallback(thisCpp, callback63, 63);
    final callback86 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        MyBaseClass.renamedVirtual2_calledFromC);
    registerCallback(thisCpp, callback86, 86);
    const callbackExcept103 = 0;
    final callback103 =
        ffi.Pointer.fromFunction<int_Func_voidstar_ffi_Int8_FFI>(
            MyBaseClass.virtualReceivingBool_calledFromC, callbackExcept103);
    registerCallback(thisCpp, callback103, 103);
    final callback104 = ffi.Pointer.fromFunction<void_Func_voidstar_string_FFI>(
        MyBaseClass.virtualReceivingCharPtr_calledFromC);
    registerCallback(thisCpp, callback104, 104);
    const callbackExcept105 = 0;
    final callback105 =
        ffi.Pointer.fromFunction<int_Func_voidstar_ffi_Int32_FFI>(
            MyBaseClass.virtualReceivingInt_calledFromC, callbackExcept105);
    registerCallback(thisCpp, callback105, 105);
    const callbackExcept106 = 0;
    final callback106 =
        ffi.Pointer.fromFunction<int_Func_voidstar_ffi_Int32_FFI>(
            MyBaseClass.virtualReceivingOptionalArgument_calledFromC,
            callbackExcept106);
    registerCallback(thisCpp, callback106, 106);
    const callbackExcept107 = 0;
    final callback107 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_ffi_Int8_FFI>(
            MyBaseClass.virtualReturningBool_calledFromC, callbackExcept107);
    registerCallback(thisCpp, callback107, 107);
    final callback109 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        MyBaseClass.virtualReturningStruct_calledFromC);
    registerCallback(thisCpp, callback109, 109);
    final callback110 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        MyBaseClass.virtualReturnsIntTemplate_calledFromC);
    registerCallback(thisCpp, callback110, 110);
    final callback111 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            MyBaseClass.virtualWithNoDefaultArgumentInDerived_calledFromC);
    registerCallback(thisCpp, callback111, 111);
    final callback112 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            MyBaseClass.virtualWithOverload_calledFromC);
    registerCallback(thisCpp, callback112, 112);
    final callback113 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            MyBaseClass.virtualWithOverload_2_calledFromC);
    registerCallback(thisCpp, callback113, 113);
  }
}
