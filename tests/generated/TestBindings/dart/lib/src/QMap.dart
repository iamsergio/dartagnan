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

class QMap<Key, T> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, QMap>();
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

  factory QMap.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QMap.fromCppPointer(cppPointer, needsAutoDelete)) as QMap<Key, T>;
  }
  QMap.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  QMap.init() {}
  String getCFunctionName(int id) {
    if (this is QMap<QString, QVariant>) {
      switch (id) {
        case 510:
          return "c_QMap_T_QString_QVariant_T___constructor";
          break;
        case 513:
          return "c_QMap_T_QString_QVariant_T___clear";
          break;
        case 514:
          return "c_QMap_T_QString_QVariant_T___contains_QString";
          break;
        case 517:
          return "c_QMap_T_QString_QVariant_T___detach";
          break;
        case 518:
          return "c_QMap_T_QString_QVariant_T___empty";
          break;
        case 519:
          return "c_QMap_T_QString_QVariant_T___first";
          break;
        case 520:
          return "c_QMap_T_QString_QVariant_T___first";
          break;
        case 521:
          return "c_QMap_T_QString_QVariant_T___firstKey";
          break;
        case 523:
          return "c_QMap_T_QString_QVariant_T___insert_QMap_Key_T";
          break;
        case 524:
          return "c_QMap_T_QString_QVariant_T___isDetached";
          break;
        case 525:
          return "c_QMap_T_QString_QVariant_T___isEmpty";
          break;
        case 526:
          return "c_QMap_T_QString_QVariant_T___isSharedWith_QMap_Key_T";
          break;
        case 527:
          return "c_QMap_T_QString_QVariant_T___key_QVariant_QString";
          break;
        case 528:
          return "c_QMap_T_QString_QVariant_T___keys";
          break;
        case 529:
          return "c_QMap_T_QString_QVariant_T___keys_QVariant";
          break;
        case 530:
          return "c_QMap_T_QString_QVariant_T___last";
          break;
        case 531:
          return "c_QMap_T_QString_QVariant_T___last";
          break;
        case 532:
          return "c_QMap_T_QString_QVariant_T___lastKey";
          break;
        case 538:
          return "c_QMap_T_QString_QVariant_T___take_QString";
          break;
        case 541:
          return "c_QMap_T_QString_QVariant_T___value_QString_QVariant";
          break;
        case 542:
          return "c_QMap_T_QString_QVariant_T___values";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is QMap<QString, QVariant>) {
      return "c_QMap_T_QString_QVariant_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //QMap<Key, T>()

  QMap() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(510)}')
        .asFunction();
    thisCpp = func();
    QMap.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // clear()
  clear() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(513)}')
        .asFunction();
    func(thisCpp);
  } // contains(const Key & key) const

  bool contains(Key key) {
    if (this is QMap<QString, QVariant>) {
      final bool_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(514)}')
          .asFunction();
      return func(thisCpp, (key as String).toNativeUtf8()) != 0;
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // detach()

  detach() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(517)}')
        .asFunction();
    func(thisCpp);
  } // empty() const

  bool empty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(518)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // first()

  T first() {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(519)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // firstKey() const

  Key firstKey() {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(521)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as Key);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // insert(const QMap<Key,T > & map)

  insert(QMap map) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(523)}')
        .asFunction();
    func(thisCpp, map == null ? ffi.nullptr : map.thisCpp);
  } // isDetached() const

  bool isDetached() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(524)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isEmpty() const

  bool isEmpty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(525)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isSharedWith(const QMap<Key,T > & other) const

  bool isSharedWith(QMap other) {
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(526)}')
        .asFunction();
    return func(thisCpp, other == null ? ffi.nullptr : other.thisCpp) != 0;
  } // key(const T & value, const Key & defaultKey) const

  Key key(T value, {required Key defaultKey}) {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar_voidstar func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      voidstar_Func_voidstar_voidstar_voidstar_FFI>>(
              '${getCFunctionName(527)}')
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
  } // last()

  T last() {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(530)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // lastKey() const

  Key lastKey() {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(532)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as Key);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // take(const Key & key)

  T take(Key key) {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
              '${getCFunctionName(538)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, (key as String).toNativeUtf8());
      return (QVariant.fromCppPointer(result, true) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // value(const Key & key, const T & defaultValue) const

  T value(Key key, {required T defaultValue}) {
    if (this is QMap<QString, QVariant>) {
      final voidstar_Func_voidstar_voidstar_voidstar func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      voidstar_Func_voidstar_voidstar_voidstar_FFI>>(
              '${getCFunctionName(541)}')
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
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(-2)}')
        .asFunction();
    func(thisCpp);
  }
}
