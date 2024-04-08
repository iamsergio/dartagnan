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

class QHash<Key, T> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, QHash>();
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

  factory QHash.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QHash.fromCppPointer(cppPointer, needsAutoDelete)) as QHash<Key, T>;
  }
  QHash.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  QHash.init() {}
  String getCFunctionName(int id) {
    if (this is QHash<QString, QVariant>) {
      switch (id) {
        case 604:
          return "c_QHash_T_QString_QVariant_T___constructor";
          break;
        case 608:
          return "c_QHash_T_QString_QVariant_T___capacity";
          break;
        case 609:
          return "c_QHash_T_QString_QVariant_T___clear";
          break;
        case 610:
          return "c_QHash_T_QString_QVariant_T___contains_QString";
          break;
        case 611:
          return "c_QHash_T_QString_QVariant_T___count";
          break;
        case 612:
          return "c_QHash_T_QString_QVariant_T___count_QString";
          break;
        case 613:
          return "c_QHash_T_QString_QVariant_T___detach";
          break;
        case 614:
          return "c_QHash_T_QString_QVariant_T___empty";
          break;
        case 615:
          return "c_QHash_T_QString_QVariant_T___insert_QHash_Key_T";
          break;
        case 616:
          return "c_QHash_T_QString_QVariant_T___isDetached";
          break;
        case 617:
          return "c_QHash_T_QString_QVariant_T___isEmpty";
          break;
        case 618:
          return "c_QHash_T_QString_QVariant_T___isSharedWith_QHash_Key_T";
          break;
        case 619:
          return "c_QHash_T_QString_QVariant_T___key_QVariant";
          break;
        case 620:
          return "c_QHash_T_QString_QVariant_T___key_QVariant_QString";
          break;
        case 622:
          return "c_QHash_T_QString_QVariant_T___keys";
          break;
        case 623:
          return "c_QHash_T_QString_QVariant_T___keys_QVariant";
          break;
        case 624:
          return "c_QHash_T_QString_QVariant_T___load_factor";
          break;
        case 631:
          return "c_QHash_T_QString_QVariant_T___remove_QString";
          break;
        case 632:
          return "c_QHash_T_QString_QVariant_T___reserve_qsizetype";
          break;
        case 633:
          return "c_QHash_T_QString_QVariant_T___size";
          break;
        case 634:
          return "c_QHash_T_QString_QVariant_T___squeeze";
          break;
        case 636:
          return "c_QHash_T_QString_QVariant_T___take_QString";
          break;
        case 637:
          return "c_QHash_T_QString_QVariant_T___value_QString";
          break;
        case 638:
          return "c_QHash_T_QString_QVariant_T___value_QString_QVariant";
          break;
        case 640:
          return "c_QHash_T_QString_QVariant_T___values";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is QHash<QString, QVariant>) {
      return "c_QHash_T_QString_QVariant_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //QHash<Key, T>()

  QHash() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(604)}')
        .asFunction();
    thisCpp = func();
    QHash.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // capacity() const
  int capacity() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(608)}')
        .asFunction();
    return func(thisCpp);
  } // clear()

  clear() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(609)}')
        .asFunction();
    func(thisCpp);
  } // contains(const Key & key) const

  bool contains(Key key) {
    if (this is QHash<QString, QVariant>) {
      final bool_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(610)}')
          .asFunction();
      return func(thisCpp, (key as String).toNativeUtf8()) != 0;
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // count() const

  int count() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(611)}')
        .asFunction();
    return func(thisCpp);
  } // count(const Key & key) const

  int count_2(Key key) {
    if (this is QHash<QString, QVariant>) {
      final int_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(612)}')
          .asFunction();
      return func(thisCpp, (key as String).toNativeUtf8());
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // detach()

  detach() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(613)}')
        .asFunction();
    func(thisCpp);
  } // empty() const

  bool empty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(614)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // insert(const QHash<Key,T > & hash)

  insert(QHash hash) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(615)}')
        .asFunction();
    func(thisCpp, hash == null ? ffi.nullptr : hash.thisCpp);
  } // isDetached() const

  bool isDetached() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(616)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isEmpty() const

  bool isEmpty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(617)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isSharedWith(const QHash<Key,T > & other) const

  bool isSharedWith(QHash other) {
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(618)}')
        .asFunction();
    return func(thisCpp, other == null ? ffi.nullptr : other.thisCpp) != 0;
  } // key(const T & value) const

  Key key(T value) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(619)}')
          .asFunction();
      ffi.Pointer<void> result = func(
          thisCpp,
          (value as QVariant) == null
              ? ffi.nullptr
              : (value as QVariant).thisCpp);
      return (QString.fromCppPointer(result, true) as Key);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // key(const T & value, const Key & defaultKey) const

  Key key_2(T value, Key defaultKey) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar_voidstar func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      voidstar_Func_voidstar_voidstar_voidstar_FFI>>(
              '${getCFunctionName(620)}')
          .asFunction();
      ffi.Pointer<void> result = func(
          thisCpp,
          (value as QVariant) == null
              ? ffi.nullptr
              : (value as QVariant).thisCpp,
          (defaultKey as String).toNativeUtf8());
      return (QString.fromCppPointer(result, true) as Key);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // keyImpl(const T & value) const

  Key keyImpl(T value) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(621)}')
          .asFunction();
      ffi.Pointer<void> result = func(
          thisCpp,
          (value as QVariant) == null
              ? ffi.nullptr
              : (value as QVariant).thisCpp);
      return (QString.fromCppPointer(result, true) as Key);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // load_factor() const

  double load_factor() {
    final double_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
            '${getCFunctionName(624)}')
        .asFunction();
    return func(thisCpp);
  } // remove(const Key & key)

  bool remove(Key key) {
    if (this is QHash<QString, QVariant>) {
      final bool_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(631)}')
          .asFunction();
      return func(thisCpp, (key as String).toNativeUtf8()) != 0;
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // reserve(qsizetype size)

  reserve(int size) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(632)}')
        .asFunction();
    func(thisCpp, size);
  } // size() const

  int size() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(633)}')
        .asFunction();
    return func(thisCpp);
  } // squeeze()

  squeeze() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(634)}')
        .asFunction();
    func(thisCpp);
  } // take(const Key & key)

  T take(Key key) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(636)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, (key as String).toNativeUtf8());
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // value(const Key & key) const

  T value(Key key) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(637)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, (key as String).toNativeUtf8());
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // value(const Key & key, const T & defaultValue) const

  T value_2(Key key, T defaultValue) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar_voidstar func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      voidstar_Func_voidstar_voidstar_voidstar_FFI>>(
              '${getCFunctionName(638)}')
          .asFunction();
      ffi.Pointer<void> result = func(
          thisCpp,
          (key as String).toNativeUtf8(),
          (defaultValue as QVariant) == null
              ? ffi.nullptr
              : (defaultValue as QVariant).thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // valueImpl(const Key & key) const

  T valueImpl(Key key) {
    if (this is QHash<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(639)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, (key as String).toNativeUtf8());
      return (QVariant.fromCppPointer(result, true) as T);
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
