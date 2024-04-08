import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../Bindings_ExplicitNamespace1.dart' as ExplicitNamespace1;
import '../Bindings_ExplicitNamespace2.dart' as ExplicitNamespace2;
import '../LibraryLoader.dart';

var _dylib = Library.instance().dylib;

class MyDerivedClass extends MyBaseClass {
  MyDerivedClass.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  MyDerivedClass.init() : super.init() {}
  factory MyDerivedClass.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (MyBaseClass.isCached(cppPointer)) {
      var instance = MyBaseClass.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as MyDerivedClass;
    }
    return MyDerivedClass.fromCppPointer(cppPointer, needsAutoDelete);
  }
  String getFinalizerName() {
    return "c_TestTargetNS__MyDerivedClass_Finalizer";
  }

  static int get s_instanceCount {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass___get_s_instanceCount')
        .asFunction();
    return func();
  }

  static set s_instanceCount(int s_instanceCount_) {
    final void_Func_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass___set_s_instanceCount_int')
        .asFunction();
    func(s_instanceCount_);
  } //MyDerivedClass()

  MyDerivedClass() : super.init() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_TestTargetNS__MyDerivedClass__constructor')
        .asFunction();
    thisCpp = func();
    MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  } // alsoCallsVirtual()
  int alsoCallsVirtual() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__alsoCallsVirtual')
        .asFunction();
    return func(thisCpp);
  }

  static // anotherOverloadedStatic(int arg__1)
      MyDerivedClass anotherOverloadedStatic(int arg__1) {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int')
        .asFunction();
    ffi.Pointer<void> result = func(arg__1);
    return MyDerivedClass.fromCppPointer(result, false);
  }

  static // anotherOverloadedStatic(int arg__1, int arg__2)
      MyDerivedClass anotherOverloadedStatic_1(int arg__1, int arg__2) {
    final voidstar_Func_int_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_ffi_Int32_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass__anotherOverloadedStatic_int_int')
        .asFunction();
    ffi.Pointer<void> result = func(arg__1, arg__2);
    return MyDerivedClass.fromCppPointer(result, false);
  }

  static int bar_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::bar() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.bar();
    return result;
  }

  static int bar2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::bar2() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.bar2();
    return result;
  } // nonVirtualButOverridden() const

  int nonVirtualButOverridden() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__nonVirtualButOverridden')
        .asFunction();
    return func(thisCpp);
  }

  static int nonVirtualInBaseButVirtualInDerived_2_calledFromC(
      ffi.Pointer<void> thisCpp, int i, int j) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::nonVirtualInBaseButVirtualInDerived(int i, int j) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.nonVirtualInBaseButVirtualInDerived_2(i, j);
    return result;
  } // paintEvent()

  paintEvent() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(135))
        .asFunction();
    func(thisCpp);
  }

  static void paintEvent_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::paintEvent()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.paintEvent();
  } // receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass * der)

  int receivesDerivedPolymorphic(MyDerivedClass? der) {
    final int_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(143))
        .asFunction();
    return func(thisCpp, der == null ? ffi.nullptr : der.thisCpp);
  }

  static int receivesDerivedPolymorphic_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? der) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::receivesDerivedPolymorphic(TestTargetNS::MyDerivedClass * der)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.receivesDerivedPolymorphic(
        (der == null || der.address == 0)
            ? null
            : MyDerivedClass.fromCppPointer(der));
    return result;
  } // receivesEnumFromBaseClassWithDefaultValue(int a)

  receivesEnumFromBaseClassWithDefaultValue(
      {int a = MyBaseClass_MyEnum.MyEnumerator0}) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyDerivedClass__receivesEnumFromBaseClassWithDefaultValue_int')
        .asFunction();
    func(thisCpp, a);
  } // receivesProtectedEnum(TestTargetNS::MyBaseClass::ProtectedEnum p)

  int receivesProtectedEnum(int p) {
    final int_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
            'c_TestTargetNS__MyDerivedClass__receivesProtectedEnum_ProtectedEnum')
        .asFunction();
    return func(thisCpp, p);
  }

  static void renamedVirtual2_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::renamedVirtual1()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.renamedVirtual2();
  } // returnTemplate1()

  MyTemplate2 returnTemplate1() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__returnTemplate1')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate2<NonCopiable>.fromCppPointer(result, true);
  } // returnTemplate2()

  MyTemplate2 returnTemplate2() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__returnTemplate2')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyTemplate2<NonCopiable>.fromCppPointer(result, false);
  }

  static // returnsAnotherNamespaceEnum()
      int returnsAnotherNamespaceEnum() {
    final int_Func_void func = _dylib
        .lookup<ffi.NativeFunction<int_Func_void_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceEnum')
        .asFunction();
    return func();
  }

  static // returnsAnotherNamespaceStruct()
      AnotherNamespaceStruct returnsAnotherNamespaceStruct() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_static_TestTargetNS__MyDerivedClass__returnsAnotherNamespaceStruct')
        .asFunction();
    ffi.Pointer<void> result = func();
    return AnotherNamespaceStruct.fromCppPointer(result, true);
  } // returnsConstPointer()

  MyDerivedClass returnsConstPointer() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__returnsConstPointer')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return MyDerivedClass.fromCppPointer(result, false);
  } // setVisible(bool b)

  setVisible(bool b) {
    final void_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int8_FFI>>(
            cFunctionSymbolName(176))
        .asFunction();
    func(thisCpp, b ? 1 : 0);
  }

  static void setVisible_calledFromC(ffi.Pointer<void> thisCpp, int b) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::setVisible(bool b)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setVisible(b != 0);
  } // show()

  show() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__show')
        .asFunction();
    func(thisCpp);
  } // virtualNotInBase() const

  int virtualNotInBase() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(181))
        .asFunction();
    return func(thisCpp);
  }

  static int virtualNotInBase_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualNotInBase() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualNotInBase();
    return result;
  }

  static int virtualReceivingBool_calledFromC(
      ffi.Pointer<void> thisCpp, int b) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReceivingBool(bool b)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingBool(b != 0);
    return result;
  }

  static void virtualReceivingCharPtr_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<Utf8>? arg__1) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReceivingCharPtr(char * arg__1)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualReceivingCharPtr(arg__1.toString());
  }

  static int virtualReceivingInt_calledFromC(
      ffi.Pointer<void> thisCpp, int arg__1) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReceivingInt(int arg__1)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReceivingInt(arg__1);
    return result;
  }

  static int virtualReceivingOptionalArgument_calledFromC(
      ffi.Pointer<void> thisCpp, int optional) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReceivingOptionalArgument(int optional)! (${thisCpp.address})");
      throw Error();
    }
    final result =
        dartInstance.virtualReceivingOptionalArgument(optional: optional);
    return result;
  }

  static int virtualReturningBool_calledFromC(
      ffi.Pointer<void> thisCpp, int b) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReturningBool(bool b)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningBool(b != 0);
    return result ? 1 : 0;
  }

  static ffi.Pointer<void> virtualReturningStruct_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReturningStruct() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturningStruct();
    return result.thisCpp;
  }

  static ffi.Pointer<void> virtualReturnsIntTemplate_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualReturnsIntTemplate()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.virtualReturnsIntTemplate();
    return result.thisCpp;
  }

  static void virtualWithOverload_calledFromC(
      ffi.Pointer<void> thisCpp, int i) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualWithOverload(int i) const! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualWithOverload(i);
  }

  static void virtualWithOverload_2_calledFromC(
      ffi.Pointer<void> thisCpp, int i, int j) {
    var dartInstance =
        MyBaseClass.s_dartInstanceByCppPtr[thisCpp.address] as MyDerivedClass;
    if (dartInstance == null) {
      print(
          "Dart instance not found for MyDerivedClass::virtualWithOverload(int i, int j) const! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.virtualWithOverload_2(i, j);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_TestTargetNS__MyDerivedClass__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 51:
        return "c_TestTargetNS__MyDerivedClass__bar";
      case 52:
        return "c_TestTargetNS__MyDerivedClass__bar2";
      case 63:
        return "c_TestTargetNS__MyDerivedClass__nonVirtualInBaseButVirtualInDerived_int_int";
      case 135:
        return "c_TestTargetNS__MyDerivedClass__paintEvent";
      case 143:
        return "c_TestTargetNS__MyDerivedClass__receivesDerivedPolymorphic_MyDerivedClass";
      case 86:
        return "c_TestTargetNS__MyDerivedClass__renamedVirtual2";
      case 176:
        return "c_TestTargetNS__MyDerivedClass__setVisible_bool";
      case 181:
        return "c_TestTargetNS__MyDerivedClass__virtualNotInBase";
      case 103:
        return "c_TestTargetNS__MyDerivedClass__virtualReceivingBool_bool";
      case 104:
        return "c_TestTargetNS__MyDerivedClass__virtualReceivingCharPtr_char";
      case 105:
        return "c_TestTargetNS__MyDerivedClass__virtualReceivingInt_int";
      case 106:
        return "c_TestTargetNS__MyDerivedClass__virtualReceivingOptionalArgument_int";
      case 107:
        return "c_TestTargetNS__MyDerivedClass__virtualReturningBool_bool";
      case 109:
        return "c_TestTargetNS__MyDerivedClass__virtualReturningStruct";
      case 110:
        return "c_TestTargetNS__MyDerivedClass__virtualReturnsIntTemplate";
      case 112:
        return "c_TestTargetNS__MyDerivedClass__virtualWithOverload_int";
      case 113:
        return "c_TestTargetNS__MyDerivedClass__virtualWithOverload_int_int";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 51:
        return "bar";
      case 52:
        return "bar2";
      case 63:
        return "nonVirtualInBaseButVirtualInDerived_2";
      case 135:
        return "paintEvent";
      case 143:
        return "receivesDerivedPolymorphic";
      case 86:
        return "renamedVirtual2";
      case 176:
        return "setVisible";
      case 181:
        return "virtualNotInBase";
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
            'c_TestTargetNS__MyDerivedClass__registerVirtualMethodCallback')
        .asFunction();
    const callbackExcept51 = 0;
    final callback51 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyDerivedClass.bar_calledFromC, callbackExcept51);
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
    final callback135 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        MyDerivedClass.paintEvent_calledFromC);
    registerCallback(thisCpp, callback135, 135);
    const callbackExcept143 = 0;
    final callback143 =
        ffi.Pointer.fromFunction<int_Func_voidstar_voidstar_FFI>(
            MyDerivedClass.receivesDerivedPolymorphic_calledFromC,
            callbackExcept143);
    registerCallback(thisCpp, callback143, 143);
    final callback86 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        MyBaseClass.renamedVirtual2_calledFromC);
    registerCallback(thisCpp, callback86, 86);
    final callback176 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int8_FFI>(
            MyDerivedClass.setVisible_calledFromC);
    registerCallback(thisCpp, callback176, 176);
    const callbackExcept181 = 0;
    final callback181 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        MyDerivedClass.virtualNotInBase_calledFromC, callbackExcept181);
    registerCallback(thisCpp, callback181, 181);
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
