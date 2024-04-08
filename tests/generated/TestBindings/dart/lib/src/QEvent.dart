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

class QEvent implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, QEvent>();
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

  factory QEvent.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QEvent.fromCppPointer(cppPointer, needsAutoDelete)) as QEvent;
  }
  QEvent.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  QEvent.init() {}
  String getFinalizerName() {
    return "c_QEvent_Finalizer";
  } // accept()

  accept() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>('c_QEvent__accept')
        .asFunction();
    func(thisCpp);
  } // clone() const

  QEvent clone() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(643))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QEvent.fromCppPointer(result, false);
  }

  static ffi.Pointer<void> clone_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance = QEvent.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for QEvent::clone() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.clone();
    return result.thisCpp;
  } // ignore()

  ignore() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>('c_QEvent__ignore')
        .asFunction();
    func(thisCpp);
  } // isAccepted() const

  bool isAccepted() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QEvent__isAccepted')
        .asFunction();
    return func(thisCpp) != 0;
  } // isInputEvent() const

  bool isInputEvent() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QEvent__isInputEvent')
        .asFunction();
    return func(thisCpp) != 0;
  } // isPointerEvent() const

  bool isPointerEvent() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QEvent__isPointerEvent')
        .asFunction();
    return func(thisCpp) != 0;
  } // isSinglePointEvent() const

  bool isSinglePointEvent() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QEvent__isSinglePointEvent')
        .asFunction();
    return func(thisCpp) != 0;
  }

  static // registerEventType(int hint)
      int registerEventType({int hint = -1}) {
    final int_Func_int func = _dylib
        .lookup<ffi.NativeFunction<int_Func_ffi_Int32_FFI>>(
            'c_static_QEvent__registerEventType_int')
        .asFunction();
    return func(hint);
  } // setAccepted(bool accepted)

  setAccepted(bool accepted) {
    final void_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int8_FFI>>(
            cFunctionSymbolName(651))
        .asFunction();
    func(thisCpp, accepted ? 1 : 0);
  }

  static void setAccepted_calledFromC(ffi.Pointer<void> thisCpp, int accepted) {
    var dartInstance = QEvent.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for QEvent::setAccepted(bool accepted)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setAccepted(accepted != 0);
  } // setSpontaneous()

  setSpontaneous() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QEvent__setSpontaneous')
        .asFunction();
    func(thisCpp);
  } // spontaneous() const

  bool spontaneous() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            'c_QEvent__spontaneous')
        .asFunction();
    return func(thisCpp) != 0;
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_QEvent__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 643:
        return "c_QEvent__clone";
      case 651:
        return "c_QEvent__setAccepted_bool";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 643:
        return "clone";
      case 651:
        return "setAccepted";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_QEvent__registerVirtualMethodCallback')
        .asFunction();
    final callback643 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        QEvent.clone_calledFromC);
    registerCallback(thisCpp, callback643, 643);
    final callback651 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int8_FFI>(
            QEvent.setAccepted_calledFromC);
    registerCallback(thisCpp, callback651, 651);
  }
}
