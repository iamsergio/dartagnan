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

class QVariant implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, QVariant>();
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

  factory QVariant.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QVariant.fromCppPointer(cppPointer, needsAutoDelete)) as QVariant;
  }
  QVariant.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  QVariant.init() {}
  String getFinalizerName() {
    return "c_QVariant_Finalizer";
  } //QVariant()

  QVariant() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            'c_QVariant__constructor')
        .asFunction();
    thisCpp = func();
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(bool b)
  QVariant.ctor2(bool b) {
    final voidstar_Func_bool func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int8_FFI>>(
            'c_QVariant__constructor_bool')
        .asFunction();
    thisCpp = func(b ? 1 : 0);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QByteArray & bytearray)
  QVariant.ctor3(QByteArray bytearray) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QByteArray')
        .asFunction();
    thisCpp = func(bytearray == null ? ffi.nullptr : bytearray.thisCpp);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QHash<QString,QVariant > & hash)
  QVariant.ctor4(QHash hash) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QHash_QString_QVariant')
        .asFunction();
    thisCpp = func(hash == null ? ffi.nullptr : hash.thisCpp);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QList<QString > & stringlist)
  QVariant.ctor5(QList stringlist) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QList_QString')
        .asFunction();
    thisCpp = func(stringlist == null ? ffi.nullptr : stringlist.thisCpp);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QList<QVariant > & list)
  QVariant.ctor6(QList list) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QList_QVariant')
        .asFunction();
    thisCpp = func(list == null ? ffi.nullptr : list.thisCpp);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QMap<QString,QVariant > & map)
  QVariant.ctor7(QMap map) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QMap_QString_QVariant')
        .asFunction();
    thisCpp = func(map == null ? ffi.nullptr : map.thisCpp);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const QString & string)
  QVariant.ctor8(String string) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__constructor_QString')
        .asFunction();
    thisCpp = func(string.toNativeUtf8());
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(const char * str)
  QVariant.ctor9(String? str) {
    final voidstar_Func_string func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_string_FFI>>(
            'c_QVariant__constructor_char')
        .asFunction();
    thisCpp = func(str?.toNativeUtf8() ?? ffi.nullptr);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(double d)
  QVariant.ctor10(double d) {
    final voidstar_Func_double func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Double_FFI>>(
            'c_QVariant__constructor_double')
        .asFunction();
    thisCpp = func(d);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(float f)
  QVariant.ctor11(double f) {
    final voidstar_Func_double func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Double_FFI>>(
            'c_QVariant__constructor_float')
        .asFunction();
    thisCpp = func(f);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QVariant(int i)
  QVariant.ctor12(int i) {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            'c_QVariant__constructor_int')
        .asFunction();
    thisCpp = func(i);
    QVariant.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // clear()
  clear() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>('c_QVariant__clear')
        .asFunction();
    func(thisCpp);
  } // detach()

  detach() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QVariant__detach')
        .asFunction();
    func(thisCpp);
  } // equals(const QVariant & other) const

  bool equals(QVariant other) {
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            'c_QVariant__equals_QVariant')
        .asFunction();
    return func(thisCpp, other == null ? ffi.nullptr : other.thisCpp) != 0;
  }

  static // fromObject(QObject * arg__1)
      QVariant fromObject(QObject? arg__1) {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_static_QVariant__fromObject_QObject')
        .asFunction();
    ffi.Pointer<void> result =
        func(arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
    return QVariant.fromCppPointer(result, true);
  } // isDetached() const

  bool isDetached() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QVariant__isDetached')
        .asFunction();
    return func(thisCpp) != 0;
  } // isNull() const

  bool isNull() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QVariant__isNull')
        .asFunction();
    return func(thisCpp) != 0;
  } // isValid() const

  bool isValid() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QVariant__isValid')
        .asFunction();
    return func(thisCpp) != 0;
  } // setValue(const QVariant & avalue)

  setValue(QVariant avalue) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            'c_QVariant__setValue_QVariant')
        .asFunction();
    func(thisCpp, avalue == null ? ffi.nullptr : avalue.thisCpp);
  } // toBool() const

  bool toBool() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QVariant__toBool')
        .asFunction();
    return func(thisCpp) != 0;
  } // toByteArray() const

  QByteArray toByteArray() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__toByteArray')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QByteArray.fromCppPointer(result, true);
  } // toHash() const

  QHash toHash() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__toHash')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QHash<QString, QVariant>.fromCppPointer(result, true);
  } // toList() const

  QList toList() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__toList')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QList<QVariant>.fromCppPointer(result, true);
  } // toMap() const

  QMap toMap() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__toMap')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QMap<QString, QVariant>.fromCppPointer(result, true);
  } // toStringList() const

  QList toStringList() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            'c_QVariant__toStringList')
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QList<QString>.fromCppPointer(result, true);
  } // typeId() const

  int typeId() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>('c_QVariant__typeId')
        .asFunction();
    return func(thisCpp);
  } // typeName() const

  String typeName() {
    final string_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<string_Func_voidstar_FFI>>(
            'c_QVariant__typeName')
        .asFunction();
    ffi.Pointer<Utf8> result = func(thisCpp);
    return result.toDartString();
  } // userType() const

  int userType() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_QVariant__userType')
        .asFunction();
    return func(thisCpp);
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QVariant__destructor')
        .asFunction();
    func(thisCpp);
  }
}
