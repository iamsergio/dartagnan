//tag=1052
import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../FinalizerHelpers.dart';

//tag=1051
var _dylib = Library.instance().dylib;
final _finalizer_T_int_T_ =
    _dylib.lookup<ffi.NativeFunction<Dart_WeakPersistentHandleFinalizer_Type>>(
        'dartffi_QVector_T_int_T__Finalizer');

class QVector<T> {
//tag=1060
  static var s_dartInstanceByCppPtr = Map<int, QVector>();
  var _thisCpp = null;
  bool _needsAutoDelete = true;
  get thisCpp => _thisCpp;
  set thisCpp(var ptr) {
    _thisCpp = ptr;
    s_dartInstanceByCppPtr[ptr.address] = this;
    ffi.Pointer<ffi.Void> ptrvoid = ptr.cast<ffi.Void>();
    if (_needsAutoDelete)
      newWeakPersistentHandle?.call(this, ptrvoid, 0, getFinalizer());
  }

  static bool isCached(var cppPointer) {
//tag=1024
    return s_dartInstanceByCppPtr.containsKey(cppPointer.address);
  }

//tag=1061
  factory QVector.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QVector.fromCppPointer(cppPointer, needsAutoDelete)) as QVector<T>;
  }
  QVector.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
//tag=1024
    thisCpp = cppPointer;
  }
//tag=1025
  QVector.init() {}
//tag=1063
  String getCFunctionName(int id) {
    if (this is QVector<int>) {
      switch (id) {
        case 1060:
          return "dartffi_QVector_T_int_T___constructor";
          break;
        case 1063:
          return "dartffi_QVector_T_int_T___constructor_int";
          break;
        case 1064:
          return "dartffi_QVector_T_int_T___constructor_int_int";
          break;
        case 1066:
          return "dartffi_QVector_T_int_T___append_QVector";
          break;
        case 1067:
          return "dartffi_QVector_T_int_T___append_int";
          break;
        case 1068:
          return "dartffi_QVector_T_int_T___at_int";
          break;
        case 1069:
          return "dartffi_QVector_T_int_T___back";
          break;
        case 1070:
          return "dartffi_QVector_T_int_T___back";
          break;
        case 1071:
          return "dartffi_QVector_T_int_T___capacity";
          break;
        case 1072:
          return "dartffi_QVector_T_int_T___clear";
          break;
        case 1073:
          return "dartffi_QVector_T_int_T___constData";
          break;
        case 1074:
          return "dartffi_QVector_T_int_T___constFirst";
          break;
        case 1075:
          return "dartffi_QVector_T_int_T___constLast";
          break;
        case 1076:
          return "dartffi_QVector_T_int_T___contains_int";
          break;
        case 1078:
          return "dartffi_QVector_T_int_T___count";
          break;
        case 1079:
          return "dartffi_QVector_T_int_T___count_int";
          break;
        case 1080:
          return "dartffi_QVector_T_int_T___data";
          break;
        case 1081:
          return "dartffi_QVector_T_int_T___data";
          break;
        case 1084:
          return "dartffi_QVector_T_int_T___detach";
          break;
        case 1085:
          return "dartffi_QVector_T_int_T___empty";
          break;
        case 1086:
          return "dartffi_QVector_T_int_T___endsWith_int";
          break;
        case 1087:
          return "dartffi_QVector_T_int_T___fill_int_int";
          break;
        case 1088:
          return "dartffi_QVector_T_int_T___first";
          break;
        case 1089:
          return "dartffi_QVector_T_int_T___first";
          break;
        case 1091:
          return "dartffi_QVector_T_int_T___front";
          break;
        case 1092:
          return "dartffi_QVector_T_int_T___front";
          break;
        case 1093:
          return "dartffi_QVector_T_int_T___indexOf_int_int";
          break;
        case 1095:
          return "dartffi_QVector_T_int_T___insert_int_int";
          break;
        case 1096:
          return "dartffi_QVector_T_int_T___insert_int_int_int";
          break;
        case 1097:
          return "dartffi_QVector_T_int_T___isDetached";
          break;
        case 1098:
          return "dartffi_QVector_T_int_T___isEmpty";
          break;
        case 1099:
          return "dartffi_QVector_T_int_T___isSharedWith_QVector";
          break;
        case 1100:
          return "dartffi_QVector_T_int_T___last";
          break;
        case 1101:
          return "dartffi_QVector_T_int_T___last";
          break;
        case 1102:
          return "dartffi_QVector_T_int_T___lastIndexOf_int_int";
          break;
        case 1103:
          return "dartffi_QVector_T_int_T___length";
          break;
        case 1104:
          return "dartffi_QVector_T_int_T___mid_int_int";
          break;
        case 1105:
          return "dartffi_QVector_T_int_T___move_int_int";
          break;
        case 1119:
          return "dartffi_QVector_T_int_T___pop_back";
          break;
        case 1120:
          return "dartffi_QVector_T_int_T___pop_front";
          break;
        case 1122:
          return "dartffi_QVector_T_int_T___prepend_int";
          break;
        case 1124:
          return "dartffi_QVector_T_int_T___push_back_int";
          break;
        case 1126:
          return "dartffi_QVector_T_int_T___push_front_int";
          break;
        case 1130:
          return "dartffi_QVector_T_int_T___remove_int";
          break;
        case 1131:
          return "dartffi_QVector_T_int_T___remove_int_int";
          break;
        case 1132:
          return "dartffi_QVector_T_int_T___removeAll_int";
          break;
        case 1133:
          return "dartffi_QVector_T_int_T___removeAt_int";
          break;
        case 1134:
          return "dartffi_QVector_T_int_T___removeFirst";
          break;
        case 1135:
          return "dartffi_QVector_T_int_T___removeLast";
          break;
        case 1136:
          return "dartffi_QVector_T_int_T___removeOne_int";
          break;
        case 1137:
          return "dartffi_QVector_T_int_T___replace_int_int";
          break;
        case 1138:
          return "dartffi_QVector_T_int_T___reserve_int";
          break;
        case 1139:
          return "dartffi_QVector_T_int_T___resize_int";
          break;
        case 1140:
          return "dartffi_QVector_T_int_T___setSharable_bool";
          break;
        case 1141:
          return "dartffi_QVector_T_int_T___shrink_to_fit";
          break;
        case 1142:
          return "dartffi_QVector_T_int_T___size";
          break;
        case 1143:
          return "dartffi_QVector_T_int_T___squeeze";
          break;
        case 1144:
          return "dartffi_QVector_T_int_T___startsWith_int";
          break;
        case 1146:
          return "dartffi_QVector_T_int_T___swapItemsAt_int_int";
          break;
        case 1147:
          return "dartffi_QVector_T_int_T___takeAt_int";
          break;
        case 1148:
          return "dartffi_QVector_T_int_T___takeFirst";
          break;
        case 1149:
          return "dartffi_QVector_T_int_T___takeLast";
          break;
        case 1150:
          return "dartffi_QVector_T_int_T___toList";
          break;
        case 1151:
          return "dartffi_QVector_T_int_T___value_int";
          break;
        case 1152:
          return "dartffi_QVector_T_int_T___value_int_int";
          break;
      }
    }
    return "";
  }

//tag=1065
  dynamic getFinalizer() {
    if (this is QVector<int>) {
      return _finalizer_T_int_T_;
    }
    print("ERROR: Couldn't find finalizer for" + this.runtimeType.toString());
  }

//tag=1023
//QVector<T>()
  QVector() {
//tag=1075
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(1060)}')
        .asFunction();
    thisCpp = func();
  }
//tag=1023
//QVector<T>(int size)
  QVector.ctor2(int size) {
//tag=1075
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            '${getCFunctionName(1063)}')
        .asFunction();
    thisCpp = func(size);
  }
//tag=1023
//QVector<T>(int size, const T & t)
  QVector.ctor3(int size, T t) {
//tag=1075
    if (this is QVector<int>) {
      final voidstar_Func_int_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1064)}')
          .asFunction();
      thisCpp = func(size, (t as int));
    }
  }
//tag=1024

//tag=1027
// append(const QVector<T > & l)
  void append(QVector l) {
//tag=1028
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(1066)}')
        .asFunction();
//tag=1030
    func(thisCpp, l == null ? ffi.nullptr : l.thisCpp);
  }
//tag=1024

//tag=1027
// append(const T & t)
  void append_2(T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1067)}')
          .asFunction();
//tag=1030
      func(thisCpp, (t as int));
    }
  }
//tag=1024

//tag=1027
// at(int i) const
  T at(int i) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1068)}')
          .asFunction();
//tag=1031
      return (func(thisCpp, i) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// back()
  T back() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1069)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// capacity() const
  int capacity() {
//tag=1028
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1071)}')
        .asFunction();
//tag=1031
    return func(thisCpp);
  }
//tag=1024

//tag=1027
// clear()
  void clear() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1072)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// constData() const
  T constData() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1073)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// constFirst() const
  T constFirst() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1074)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// constLast() const
  T constLast() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1075)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// contains(const T & t) const
  bool contains(T t) {
//tag=1028
    if (this is QVector<int>) {
      final bool_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1076)}')
          .asFunction();
//tag=1029
      return func(thisCpp, (t as int)) != 0;
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// copyConstruct(const T * srcFrom, const T * srcTo, T * dstFrom)
  void copyConstruct(T srcFrom, T srcTo, T dstFrom) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int_int func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      void_Func_voidstar_ffi_Int32_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1077)}')
          .asFunction();
//tag=1030
      func(thisCpp, (srcFrom as int), (srcTo as int), (dstFrom as int));
    }
  }
//tag=1024

//tag=1027
// count() const
  int count() {
//tag=1028
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1078)}')
        .asFunction();
//tag=1031
    return func(thisCpp);
  }
//tag=1024

//tag=1027
// count(const T & t) const
  int count_2(T t) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1079)}')
          .asFunction();
//tag=1031
      return func(thisCpp, (t as int));
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// data()
  T data() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1080)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// defaultConstruct(T * from, T * to)
  void defaultConstruct(T from, T to) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1082)}')
          .asFunction();
//tag=1030
      func(thisCpp, (from as int), (to as int));
    }
  }
//tag=1024

//tag=1027
// destruct(T * from, T * to)
  void destruct(T from, T to) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1083)}')
          .asFunction();
//tag=1030
      func(thisCpp, (from as int), (to as int));
    }
  }
//tag=1024

//tag=1027
// detach()
  void detach() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1084)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// empty() const
  bool empty() {
//tag=1028
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(1085)}')
        .asFunction();
//tag=1029
    return func(thisCpp) != 0;
  }
//tag=1024

//tag=1027
// endsWith(const T & t) const
  bool endsWith(T t) {
//tag=1028
    if (this is QVector<int>) {
      final bool_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1086)}')
          .asFunction();
//tag=1029
      return func(thisCpp, (t as int)) != 0;
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// first()
  T first() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1088)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// front()
  T front() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1091)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// indexOf(const T & t, int from) const
  int indexOf(T t, {int from = 0}) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1093)}')
          .asFunction();
//tag=1031
      return func(thisCpp, (t as int), from);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// insert(int i, const T & t)
  void insert(int i, T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1095)}')
          .asFunction();
//tag=1030
      func(thisCpp, i, (t as int));
    }
  }
//tag=1024

//tag=1027
// insert(int i, int n, const T & t)
  void insert_2(int i, int n, T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int_int func = _dylib
          .lookup<
                  ffi.NativeFunction<
                      void_Func_voidstar_ffi_Int32_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1096)}')
          .asFunction();
//tag=1030
      func(thisCpp, i, n, (t as int));
    }
  }
//tag=1024

//tag=1027
// isDetached() const
  bool isDetached() {
//tag=1028
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(1097)}')
        .asFunction();
//tag=1029
    return func(thisCpp) != 0;
  }
//tag=1024

//tag=1027
// isEmpty() const
  bool isEmpty() {
//tag=1028
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(1098)}')
        .asFunction();
//tag=1029
    return func(thisCpp) != 0;
  }
//tag=1024

//tag=1027
// isSharedWith(const QVector<T > & other) const
  bool isSharedWith(QVector other) {
//tag=1028
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(1099)}')
        .asFunction();
//tag=1029
    return func(thisCpp, other == null ? ffi.nullptr : other.thisCpp) != 0;
  }
//tag=1024

//tag=1027
// last()
  T last() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1100)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// lastIndexOf(const T & t, int from) const
  int lastIndexOf(T t, {int from = -1}) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1102)}')
          .asFunction();
//tag=1031
      return func(thisCpp, (t as int), from);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// length() const
  int length() {
//tag=1028
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1103)}')
        .asFunction();
//tag=1031
    return func(thisCpp);
  }
//tag=1024

//tag=1027
// move(int from, int to)
  void move(int from, int to) {
//tag=1028
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(1105)}')
        .asFunction();
//tag=1030
    func(thisCpp, from, to);
  }
//tag=1024

//tag=1027
// pop_back()
  void pop_back() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1119)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// pop_front()
  void pop_front() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1120)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// prepend(const T & t)
  void prepend(T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1122)}')
          .asFunction();
//tag=1030
      func(thisCpp, (t as int));
    }
  }
//tag=1024

//tag=1027
// push_back(const T & t)
  void push_back(T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1124)}')
          .asFunction();
//tag=1030
      func(thisCpp, (t as int));
    }
  }
//tag=1024

//tag=1027
// push_front(const T & t)
  void push_front(T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1126)}')
          .asFunction();
//tag=1030
      func(thisCpp, (t as int));
    }
  }
//tag=1024

//tag=1027
// realloc(int alloc)
  void realloc(int alloc) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1127)}')
        .asFunction();
//tag=1030
    func(thisCpp, alloc);
  }
//tag=1024

//tag=1027
// reallocData(const int size, const int alloc)
  void reallocData(int size, int alloc) {
//tag=1028
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(1128)}')
        .asFunction();
//tag=1030
    func(thisCpp, size, alloc);
  }
//tag=1024

//tag=1027
// reallocData(const int sz)
  void reallocData_2(int sz) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1129)}')
        .asFunction();
//tag=1030
    func(thisCpp, sz);
  }
//tag=1024

//tag=1027
// remove(int i)
  void remove(int i) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1130)}')
        .asFunction();
//tag=1030
    func(thisCpp, i);
  }
//tag=1024

//tag=1027
// remove(int i, int n)
  void remove_2(int i, int n) {
//tag=1028
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(1131)}')
        .asFunction();
//tag=1030
    func(thisCpp, i, n);
  }
//tag=1024

//tag=1027
// removeAll(const T & t)
  int removeAll(T t) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1132)}')
          .asFunction();
//tag=1031
      return func(thisCpp, (t as int));
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// removeAt(int i)
  void removeAt(int i) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1133)}')
        .asFunction();
//tag=1030
    func(thisCpp, i);
  }
//tag=1024

//tag=1027
// removeFirst()
  void removeFirst() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1134)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// removeLast()
  void removeLast() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1135)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// removeOne(const T & t)
  bool removeOne(T t) {
//tag=1028
    if (this is QVector<int>) {
      final bool_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1136)}')
          .asFunction();
//tag=1029
      return func(thisCpp, (t as int)) != 0;
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// replace(int i, const T & t)
  void replace(int i, T t) {
//tag=1028
    if (this is QVector<int>) {
      final void_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1137)}')
          .asFunction();
//tag=1030
      func(thisCpp, i, (t as int));
    }
  }
//tag=1024

//tag=1027
// reserve(int size)
  void reserve(int size) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1138)}')
        .asFunction();
//tag=1030
    func(thisCpp, size);
  }
//tag=1024

//tag=1027
// resize(int size)
  void resize(int size) {
//tag=1028
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(1139)}')
        .asFunction();
//tag=1030
    func(thisCpp, size);
  }
//tag=1024

//tag=1027
// setSharable(bool sharable)
  void setSharable(bool sharable) {
//tag=1028
    final void_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int8_FFI>>(
            '${getCFunctionName(1140)}')
        .asFunction();
//tag=1030
    func(thisCpp, sharable ? 1 : 0);
  }
//tag=1024

//tag=1027
// shrink_to_fit()
  void shrink_to_fit() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1141)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// size() const
  int size() {
//tag=1028
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(1142)}')
        .asFunction();
//tag=1031
    return func(thisCpp);
  }
//tag=1024

//tag=1027
// squeeze()
  void squeeze() {
//tag=1028
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(1143)}')
        .asFunction();
//tag=1030
    func(thisCpp);
  }
//tag=1024

//tag=1027
// startsWith(const T & t) const
  bool startsWith(T t) {
//tag=1028
    if (this is QVector<int>) {
      final bool_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<bool_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1144)}')
          .asFunction();
//tag=1029
      return func(thisCpp, (t as int)) != 0;
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// swapItemsAt(int i, int j)
  void swapItemsAt(int i, int j) {
//tag=1028
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(1146)}')
        .asFunction();
//tag=1030
    func(thisCpp, i, j);
  }
//tag=1024

//tag=1027
// takeAt(int i)
  T takeAt(int i) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1147)}')
          .asFunction();
//tag=1031
      return (func(thisCpp, i) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// takeFirst()
  T takeFirst() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1148)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// takeLast()
  T takeLast() {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(1149)}')
          .asFunction();
//tag=1031
      return (func(thisCpp) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// value(int i) const
  T value(int i) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(1151)}')
          .asFunction();
//tag=1031
      return (func(thisCpp, i) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }
//tag=1024

//tag=1027
// value(int i, const T & defaultValue) const
  T value_2(int i, T defaultValue) {
//tag=1028
    if (this is QVector<int>) {
      final int_Func_voidstar_int_int func = _dylib
          .lookup<
                  ffi
                  .NativeFunction<int_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
              '${getCFunctionName(1152)}')
          .asFunction();
//tag=1031
      return (func(thisCpp, i, (defaultValue as int)) as T);
    } else {
// Unreachable, but required, due to null safety we need to return something
      throw Error();
    }
  }

//tag=1022
  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(-2)}')
        .asFunction();
    func(thisCpp);
  }
}
