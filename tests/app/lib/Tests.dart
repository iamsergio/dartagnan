/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

import 'dart:math';

import 'package:TestBindings/Bindings.dart' as TestTargetNS;
import 'package:TestBindings/Bindings.dart';
import 'package:TestBindings/Bindings_ExplicitNamespace1.dart'
    as ExplicitNamespace1;
import 'package:TestBindings/Bindings_ExplicitNamespace2.dart'
    as ExplicitNamespace2;
import 'package:ffi/ffi.dart';
import 'package:test/test.dart';

class Level3Derived extends TestTargetNS.MyDerivedClass {
  int bar() {
    return 50;
  }

  int virtualInBaseDerivedAndDart() {
    return 200;
  }
}

class DartDerived extends TestTargetNS.MyBaseClass {
  int bar() {
    // overrides MyBaseClass.bar()
    return 100;
  }

  SimpleStruct virtualReturningStruct() {
    var s = SimpleStruct();
    s.value = 51;
    return s;
  }
}

class DerivedFromPureAbstract extends PureAbstract {
  DerivedFromPureAbstract() : super() {}

  int virtualReceivingPointer(SimpleStruct? s) {
    if (s == null) return 0;
    return 1;
  }
}

class Level3DerivedFromPureAbstract
    extends TestTargetNS.DerivedFromPureAbstract {
  Level3DerivedFromPureAbstract() : super() {}
  Level3DerivedFromPureAbstract.ctor2(int v) : super.ctor2(v) {}

  int foo() {
    return 200;
  }

  @override
  int receivesValueStruct(SimpleStruct s) {
    // dereference, to check that it doesn't crash
    print(s.value);
    return 2;
  }
}

void runTests() {
  var mybaseclass = TestTargetNS.MyBaseClass();

  test('static-method-return-int', () {
    expect(TestTargetNS.POD.calculateStatic(), 42);
  });

  test('method-return-int', () {
    final result = mybaseclass.foo();
    expect(result, 42);
  });

  test('method-return-bool-false', () {
    expect(mybaseclass.getBoolFalse(), false);
  });

  test('method-return-bool-true', () {
    expect(mybaseclass.getBoolTrue(), true);
  });

  mybaseclass.hello();

  /// [const-char] Pass to static
  TestTargetNS.MyBaseClass.print("Hello-World");

  test('POD-pointer-return-int', () {
    POD podPtr = POD.returnsPointerToPOD();
    expect(podPtr.calculate(), 6);
    podPtr.release();
  });

  test('POD-ref-return-int', () {
    POD podRef = POD.returnsReferenceToPOD();
    expect(podRef.calculate(), 6);
  });

  test('POD-value-return-int', () {
    POD podValue = POD.returnsPOD();
    expect(podValue.calculate(), 6000);
  });

  test('POD-value-return-const-ref-int', () {
    expect(POD().intByConstRef(), 1);
  });

  test('static-method-returning-const-char-ptr', () {
    String actual = TestTargetNS.MyBaseClass.returnsConstChar();
    expect(actual, "Hello");
  });

  test('method-returning-enum', () {
    expect(mybaseclass.receivesEnum(MyBaseClass_MyEnum.MyEnumerator3), 30);
  });

  test('anonymous-enum', () {
    expect(MyBaseClass.AnonymousEnumerator1, 1);
    expect(MyBaseClass.AnonymousEnumerator2, 2);
    expect(MyBaseClass.AnonymousEnumerator3, 3);
  });

  test('namespace-function-returning-namespace-enum', () {
    expect(TestTargetNS.namespaceFunctionReturningNamespaceEnum(),
        TestTargetNS.TestTargetNS_NameSpaceLevelEnum.NameSpaceLevelEnum_Value);
  });

  test('receives-two-ints', () {
    expect(mybaseclass.sum(1, 2), 3);
  });

  test('receives-two-ints', () {
    expect(mybaseclass.setBool(true), true);
  });

  test('receives-bool', () {
    expect(mybaseclass.setBool(false), false);
  });

  test('returns-QString', () {
    expect(TestTargetNS.MyBaseClass.returnsQString().toDartString(), "hello");
  });

  test('receives-QString', () {
    final c = MyBaseClass();
    final QString s = c.receivesAndReturnsQString("hello");
    expect(s.size(), 5);
    expect(s.toDartString(), "hello");

    c.release();
  });

  test('returns-char', () {
    expect(POD.returnsChar(), "c");
  });

  test('receives-two-pods-by-value', () {
    final a = POD();
    final b = POD();
    expect(TestTargetNS.POD.receivesPODs(a, b), 3);
  });

  test('receives-two-pods-by-const-ref', () {
    final a = POD();
    final b = POD();
    expect(TestTargetNS.POD.receivesConstRefPODs(a, b), 3);
  });

  test('receives-two-pods-by-ptr', () {
    final a = POD();
    final b = POD();
    expect(TestTargetNS.POD.receivesPointerToPODs(a, b), 3);
  });

  test('receives-two-pods-by-const-ptr', () {
    final a = POD();
    final b = POD();
    expect(TestTargetNS.POD.receivesConstPointerToPODs(a, b), 3);
  });

  test('receives-two-pods-by-ref', () {
    final a = POD();
    final b = POD();
    expect(TestTargetNS.POD.receivesRefPODs(a, b), 20);
    expect(a.v1, 10);
  });

  test('read-int-members', () {
    final a = POD();
    expect(a.v1, 1);
    expect(a.v2, 2);
    expect(a.v3, 3);
    expect(a.v4_const, 4);
  });

  test('read-set-int-members', () {
    final a = POD();
    expect(a.v1, 1);
    final int newValue = 41;
    a.v1 = newValue;
    expect(a.v1, newValue);
  });

  test('namespace-level-function', () {
    expect(TestTargetNS.namespaceLevelGlobalFunction(), 41);
  });

  test('global-enum', () {
    expect(GlobalEnum.GlobalEnum_Value, 30);
  });

  test('globalFunction', () {
    expect(globalFunction(), 42);
  });

  test('virtual-derived-in-dart', () {
    var dartDerived = DartDerived();
    expect(dartDerived.callsVirtual(), 100);
    SimpleStruct simpleStruct = dartDerived.nonVirtualReturningStruct();
    expect(simpleStruct.value, 51);
    dartDerived.release();
  });
  test('virtual-returning-bool', () {
    expect(mybaseclass.virtualReturningBool(true), true);
    expect(mybaseclass.virtualReturningBool(false), false);
  });

  test('function-returns-pure-virtual', () {
    TestTargetNS.PureAbstract abstract = TestTargetNS.returnsPureAbstract();
    expect(abstract.foo(), 42);
    expect(receivingPureAbstract(abstract), 42);
    abstract.release();
  });

  test('virtuals-calling-themselves-in-infinit-loop', () {
    var derived = MyDerivedClass();
    derived.show(); // Would crash before.
    expect(true, true);
    derived.release();
  });

  test('virtual-with-optional-arg', () {
    expect(mybaseclass.virtualReceivingOptionalArgument(optional: 10), 10);
  });

  test('instance-created-in-cpp', () {
    // The C++ creates a new MyDerivedClass and passes it by argument.
    // Dart's fromCache() will fail and it will create a dart wrapper instance
    var derived = MyDerivedClass();
    expect(derived.alsoCallsVirtual(), 10);
    derived.release();
  });

  test('static-member', () {
    // Tests that classes can have static members and they work
    expect(MyBaseClass.s_staticMember, 1);
    MyBaseClass.s_staticMember = 10;
    expect(MyBaseClass.s_staticMember, 10);
  });

  test('destructors-are-called', () {
    // 1. Allocate in C++ and release manually in dart
    expect(DestructorCounter.s_instanceCount, 0);
    var instance = DestructorCounter.newOnTheHeap();
    expect(DestructorCounter.s_instanceCount, 1);
    instance.release();
    expect(DestructorCounter.s_instanceCount, 0);
    DestructorCounter.newOnTheStack();
    expect(DestructorCounter.s_instanceCount, 1);

    final anotherInstance = DestructorCounter();
    expect(DestructorCounter.s_instanceCount, 2);

// Gets to 0 when the isolate shutsdown
  });

  test("template", () {
    var intTemplate = TestTargetNS.MyTemplate<int>();
    expect(intTemplate.returnInt(), 1);
  });

  test("template-with-two-args", () {
    var t = TestTargetNS.MyTemplateWithTwoArgs<int, double>();
    expect(t.returnInt(), 1);
  });

  test("template-with-template-receiving-template", () {
    var t = MyTemplate<int>();
    expect(t.receivesTemplate(t), 30);
  });

  test("returns-QList", () {
    final vector = mybaseclass.returnsVector();
    expect(vector.size(), 3);
    // expect(vector.contains(2), true); TODO
    vector.clear();
    expect(vector.size(), 0);
    expect(vector.isEmpty(), true);
    // expect(vector.contains(2), false); TODO

    for (int i = 0; i < vector.size(); ++i) {
      expect(vector.at(i), i + 1);
    }
  });

  test("returns-template-argument-as-ptr", () {
    // Tests that QList::at works if T is a pointer. We had a crash regarding this.
    final list = MyBaseClass.returnsListOfStructPtr();
    final SimpleStruct s = list.at(0);
    expect(s.value, 1);
    s.release();
  });

  test("signal-handler", () {
    var obj = MyObject(parent: null);
    bool signalReceived = false;
    obj.onValueChanged(() {
      signalReceived = true;
    });
    obj.valueChanged(5);
    expect(signalReceived, true);
    obj.release();
  });

  test('StructAsDefaultArg', () {
    var s = SimpleObjectStruct();
    s.receivesStructWithDefaultArg(arg__1: s);
  });

  test('ctor-pointer-arg-is-nullable', () {
    var c = MyBaseClass.ctor2(null);
    c.release();
  });

  test('overridden-non-virtual', () {
    var derived = MyDerivedClass();
    expect(mybaseclass.nonVirtualButOverridden(), 1);
    expect(derived.nonVirtualButOverridden(), 2);
    derived.release();
  });

  test('derived-from-abstract-class', () {
    var v = DerivedFromPureAbstract();
    expect(v.returnsInt(), 5);

    expect(v.callVirtualReceivingPointer(null), 0);

    v.release();
  });

  test('protected-enum', () {
    var derived = MyDerivedClass();
    expect(derived.receivesProtectedEnum(1), 1);
    derived.release();
  });

  test('injected-method', () {
    // Tests that we can do an <inject add-function in typesystem.xml
    var obj = new QObject();
    var v = QVariant.fromObject(obj);
    expect(v.isNull(), false);
    obj.release();
  });

  test('3-level-derived', () {
    // Tests that C++ can call our virtual callbacks, even when having a bigger hierarchy
    var derived = Level3DerivedFromPureAbstract();
    expect(derived.nonVirtualCallsVirtual(), 200);
    derived.release();

    var derived2 = Level3DerivedFromPureAbstract.ctor2(1);
    expect(derived2.nonVirtualCallsVirtual(), 200);
    derived2.release();
  });

  test('callback-with-value-struct-argument', () {
    /// There was a bug where C++ couldn't pass structs to our dart methods by argument
    /// This calls indirectionCallsVirtualReceivingStruct() which is implemented in C++
    /// And calls a virtual C++ overridden in dart. Should return 2, as that's our
    /// dart implementation, while 1 would be the C++ impl in test.h
    var derived = Level3DerivedFromPureAbstract();
    var simple = SimpleStruct();
    simple.value = 42;
    expect(derived.indirectionCallsVirtualReceivingStruct(simple), 2);
    derived.release();
  });

  test('virtual-in-second-base-not-supported', () {
    // We don't support virtual functions from second base class yet
    var doubleInheritance = DoubleInheritance();
    expect(doubleInheritance.nonVirtualCallsVirtualFrom2ndBase(), 42);
  });

  test('test-scoped-class', () {
    expect(ExplicitNamespace1.SimpleClash.getValueStatic(), 1);
  });

  test('test-scoped-class2', () {
    expect(ExplicitNamespace2.SimpleClash.getValueStatic(), 2);
  });

  test('test-scoped-clash', () {
    expect(
        ExplicitNamespace2.SimpleClash.returnsFromOtherScope().getValue(), 1);

    expect(
        ExplicitNamespace2.SimpleClash.returnsAndReceivesFromOtherScope(
                new ExplicitNamespace1.SimpleClash(1))
            .getValue(),
        1);
  });

  test('repeated-finalizer', () {
    // Tests that all the 3 structs are not leaked
    final struct1 = MyBaseClass.returnsSimpleStruct(1);
    final struct2 = MyBaseClass.returnsSimpleStruct(2);
    final struct3 = MyBaseClass.returnsSimpleStruct(3);
    expect(struct1.value, 1);
    expect(struct2.value, 2);
    expect(struct3.value, 3);
  });

  test('cleanup', () {
    mybaseclass.release();
  });
}
