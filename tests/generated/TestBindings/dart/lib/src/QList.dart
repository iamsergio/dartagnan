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

class QList<T> implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, QList>();
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

  factory QList.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        QList.fromCppPointer(cppPointer, needsAutoDelete)) as QList<T>;
  }
  QList.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  QList.init() {}
  String getCFunctionName(int id) {
    if (this is QList<SimpleStruct>) {
      switch (id) {
        case 543:
          return "c_QList_T_SimpleStruct_T___constructor";
          break;
        case 544:
          return "c_QList_T_SimpleStruct_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_SimpleStruct_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_SimpleStruct_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_SimpleStruct_T___back";
          break;
        case 549:
          return "c_QList_T_SimpleStruct_T___back";
          break;
        case 550:
          return "c_QList_T_SimpleStruct_T___capacity";
          break;
        case 551:
          return "c_QList_T_SimpleStruct_T___clear";
          break;
        case 553:
          return "c_QList_T_SimpleStruct_T___constFirst";
          break;
        case 554:
          return "c_QList_T_SimpleStruct_T___constLast";
          break;
        case 555:
          return "c_QList_T_SimpleStruct_T___count";
          break;
        case 558:
          return "c_QList_T_SimpleStruct_T___detach";
          break;
        case 559:
          return "c_QList_T_SimpleStruct_T___empty";
          break;
        case 560:
          return "c_QList_T_SimpleStruct_T___first";
          break;
        case 561:
          return "c_QList_T_SimpleStruct_T___first";
          break;
        case 562:
          return "c_QList_T_SimpleStruct_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_SimpleStruct_T___front";
          break;
        case 566:
          return "c_QList_T_SimpleStruct_T___front";
          break;
        case 567:
          return "c_QList_T_SimpleStruct_T___isDetached";
          break;
        case 568:
          return "c_QList_T_SimpleStruct_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_SimpleStruct_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_SimpleStruct_T___last";
          break;
        case 571:
          return "c_QList_T_SimpleStruct_T___last";
          break;
        case 572:
          return "c_QList_T_SimpleStruct_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_SimpleStruct_T___length";
          break;
        case 574:
          return "c_QList_T_SimpleStruct_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_SimpleStruct_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_SimpleStruct_T___pop_back";
          break;
        case 585:
          return "c_QList_T_SimpleStruct_T___pop_front";
          break;
        case 586:
          return "c_QList_T_SimpleStruct_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_SimpleStruct_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_SimpleStruct_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_SimpleStruct_T___removeLast";
          break;
        case 590:
          return "c_QList_T_SimpleStruct_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_SimpleStruct_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_SimpleStruct_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_SimpleStruct_T___size";
          break;
        case 595:
          return "c_QList_T_SimpleStruct_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_SimpleStruct_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_SimpleStruct_T___squeeze";
          break;
        case 599:
          return "c_QList_T_SimpleStruct_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_SimpleStruct_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_SimpleStruct_T___toList";
          break;
        case 602:
          return "c_QList_T_SimpleStruct_T___toVector";
          break;
        case 603:
          return "c_QList_T_SimpleStruct_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<double>) {
      switch (id) {
        case 543:
          return "c_QList_T_qreal_T___constructor";
          break;
        case 544:
          return "c_QList_T_qreal_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_qreal_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_qreal_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_qreal_T___back";
          break;
        case 549:
          return "c_QList_T_qreal_T___back";
          break;
        case 550:
          return "c_QList_T_qreal_T___capacity";
          break;
        case 551:
          return "c_QList_T_qreal_T___clear";
          break;
        case 553:
          return "c_QList_T_qreal_T___constFirst";
          break;
        case 554:
          return "c_QList_T_qreal_T___constLast";
          break;
        case 555:
          return "c_QList_T_qreal_T___count";
          break;
        case 558:
          return "c_QList_T_qreal_T___detach";
          break;
        case 559:
          return "c_QList_T_qreal_T___empty";
          break;
        case 560:
          return "c_QList_T_qreal_T___first";
          break;
        case 561:
          return "c_QList_T_qreal_T___first";
          break;
        case 562:
          return "c_QList_T_qreal_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_qreal_T___front";
          break;
        case 566:
          return "c_QList_T_qreal_T___front";
          break;
        case 567:
          return "c_QList_T_qreal_T___isDetached";
          break;
        case 568:
          return "c_QList_T_qreal_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_qreal_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_qreal_T___last";
          break;
        case 571:
          return "c_QList_T_qreal_T___last";
          break;
        case 572:
          return "c_QList_T_qreal_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_qreal_T___length";
          break;
        case 574:
          return "c_QList_T_qreal_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_qreal_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_qreal_T___pop_back";
          break;
        case 585:
          return "c_QList_T_qreal_T___pop_front";
          break;
        case 586:
          return "c_QList_T_qreal_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_qreal_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_qreal_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_qreal_T___removeLast";
          break;
        case 590:
          return "c_QList_T_qreal_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_qreal_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_qreal_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_qreal_T___size";
          break;
        case 595:
          return "c_QList_T_qreal_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_qreal_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_qreal_T___squeeze";
          break;
        case 599:
          return "c_QList_T_qreal_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_qreal_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_qreal_T___toList";
          break;
        case 602:
          return "c_QList_T_qreal_T___toVector";
          break;
        case 603:
          return "c_QList_T_qreal_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<int>) {
      switch (id) {
        case 543:
          return "c_QList_T_int_T___constructor";
          break;
        case 544:
          return "c_QList_T_int_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_int_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_int_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_int_T___back";
          break;
        case 549:
          return "c_QList_T_int_T___back";
          break;
        case 550:
          return "c_QList_T_int_T___capacity";
          break;
        case 551:
          return "c_QList_T_int_T___clear";
          break;
        case 553:
          return "c_QList_T_int_T___constFirst";
          break;
        case 554:
          return "c_QList_T_int_T___constLast";
          break;
        case 555:
          return "c_QList_T_int_T___count";
          break;
        case 558:
          return "c_QList_T_int_T___detach";
          break;
        case 559:
          return "c_QList_T_int_T___empty";
          break;
        case 560:
          return "c_QList_T_int_T___first";
          break;
        case 561:
          return "c_QList_T_int_T___first";
          break;
        case 562:
          return "c_QList_T_int_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_int_T___front";
          break;
        case 566:
          return "c_QList_T_int_T___front";
          break;
        case 567:
          return "c_QList_T_int_T___isDetached";
          break;
        case 568:
          return "c_QList_T_int_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_int_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_int_T___last";
          break;
        case 571:
          return "c_QList_T_int_T___last";
          break;
        case 572:
          return "c_QList_T_int_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_int_T___length";
          break;
        case 574:
          return "c_QList_T_int_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_int_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_int_T___pop_back";
          break;
        case 585:
          return "c_QList_T_int_T___pop_front";
          break;
        case 586:
          return "c_QList_T_int_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_int_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_int_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_int_T___removeLast";
          break;
        case 590:
          return "c_QList_T_int_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_int_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_int_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_int_T___size";
          break;
        case 595:
          return "c_QList_T_int_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_int_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_int_T___squeeze";
          break;
        case 599:
          return "c_QList_T_int_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_int_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_int_T___toList";
          break;
        case 602:
          return "c_QList_T_int_T___toVector";
          break;
        case 603:
          return "c_QList_T_int_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<QVariant>) {
      switch (id) {
        case 543:
          return "c_QList_T_QVariant_T___constructor";
          break;
        case 544:
          return "c_QList_T_QVariant_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_QVariant_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_QVariant_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_QVariant_T___back";
          break;
        case 549:
          return "c_QList_T_QVariant_T___back";
          break;
        case 550:
          return "c_QList_T_QVariant_T___capacity";
          break;
        case 551:
          return "c_QList_T_QVariant_T___clear";
          break;
        case 553:
          return "c_QList_T_QVariant_T___constFirst";
          break;
        case 554:
          return "c_QList_T_QVariant_T___constLast";
          break;
        case 555:
          return "c_QList_T_QVariant_T___count";
          break;
        case 558:
          return "c_QList_T_QVariant_T___detach";
          break;
        case 559:
          return "c_QList_T_QVariant_T___empty";
          break;
        case 560:
          return "c_QList_T_QVariant_T___first";
          break;
        case 561:
          return "c_QList_T_QVariant_T___first";
          break;
        case 562:
          return "c_QList_T_QVariant_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_QVariant_T___front";
          break;
        case 566:
          return "c_QList_T_QVariant_T___front";
          break;
        case 567:
          return "c_QList_T_QVariant_T___isDetached";
          break;
        case 568:
          return "c_QList_T_QVariant_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_QVariant_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_QVariant_T___last";
          break;
        case 571:
          return "c_QList_T_QVariant_T___last";
          break;
        case 572:
          return "c_QList_T_QVariant_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_QVariant_T___length";
          break;
        case 574:
          return "c_QList_T_QVariant_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_QVariant_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_QVariant_T___pop_back";
          break;
        case 585:
          return "c_QList_T_QVariant_T___pop_front";
          break;
        case 586:
          return "c_QList_T_QVariant_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_QVariant_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_QVariant_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_QVariant_T___removeLast";
          break;
        case 590:
          return "c_QList_T_QVariant_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_QVariant_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_QVariant_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_QVariant_T___size";
          break;
        case 595:
          return "c_QList_T_QVariant_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_QVariant_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_QVariant_T___squeeze";
          break;
        case 599:
          return "c_QList_T_QVariant_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_QVariant_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_QVariant_T___toList";
          break;
        case 602:
          return "c_QList_T_QVariant_T___toVector";
          break;
        case 603:
          return "c_QList_T_QVariant_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<QString>) {
      switch (id) {
        case 543:
          return "c_QList_T_QString_T___constructor";
          break;
        case 544:
          return "c_QList_T_QString_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_QString_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_QString_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_QString_T___back";
          break;
        case 549:
          return "c_QList_T_QString_T___back";
          break;
        case 550:
          return "c_QList_T_QString_T___capacity";
          break;
        case 551:
          return "c_QList_T_QString_T___clear";
          break;
        case 553:
          return "c_QList_T_QString_T___constFirst";
          break;
        case 554:
          return "c_QList_T_QString_T___constLast";
          break;
        case 555:
          return "c_QList_T_QString_T___count";
          break;
        case 558:
          return "c_QList_T_QString_T___detach";
          break;
        case 559:
          return "c_QList_T_QString_T___empty";
          break;
        case 560:
          return "c_QList_T_QString_T___first";
          break;
        case 561:
          return "c_QList_T_QString_T___first";
          break;
        case 562:
          return "c_QList_T_QString_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_QString_T___front";
          break;
        case 566:
          return "c_QList_T_QString_T___front";
          break;
        case 567:
          return "c_QList_T_QString_T___isDetached";
          break;
        case 568:
          return "c_QList_T_QString_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_QString_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_QString_T___last";
          break;
        case 571:
          return "c_QList_T_QString_T___last";
          break;
        case 572:
          return "c_QList_T_QString_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_QString_T___length";
          break;
        case 574:
          return "c_QList_T_QString_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_QString_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_QString_T___pop_back";
          break;
        case 585:
          return "c_QList_T_QString_T___pop_front";
          break;
        case 586:
          return "c_QList_T_QString_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_QString_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_QString_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_QString_T___removeLast";
          break;
        case 590:
          return "c_QList_T_QString_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_QString_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_QString_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_QString_T___size";
          break;
        case 595:
          return "c_QList_T_QString_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_QString_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_QString_T___squeeze";
          break;
        case 599:
          return "c_QList_T_QString_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_QString_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_QString_T___toList";
          break;
        case 602:
          return "c_QList_T_QString_T___toVector";
          break;
        case 603:
          return "c_QList_T_QString_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<int>) {
      switch (id) {
        case 543:
          return "c_QList_T_unsigned_int_T___constructor";
          break;
        case 544:
          return "c_QList_T_unsigned_int_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_unsigned_int_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_unsigned_int_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_unsigned_int_T___back";
          break;
        case 549:
          return "c_QList_T_unsigned_int_T___back";
          break;
        case 550:
          return "c_QList_T_unsigned_int_T___capacity";
          break;
        case 551:
          return "c_QList_T_unsigned_int_T___clear";
          break;
        case 553:
          return "c_QList_T_unsigned_int_T___constFirst";
          break;
        case 554:
          return "c_QList_T_unsigned_int_T___constLast";
          break;
        case 555:
          return "c_QList_T_unsigned_int_T___count";
          break;
        case 558:
          return "c_QList_T_unsigned_int_T___detach";
          break;
        case 559:
          return "c_QList_T_unsigned_int_T___empty";
          break;
        case 560:
          return "c_QList_T_unsigned_int_T___first";
          break;
        case 561:
          return "c_QList_T_unsigned_int_T___first";
          break;
        case 562:
          return "c_QList_T_unsigned_int_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_unsigned_int_T___front";
          break;
        case 566:
          return "c_QList_T_unsigned_int_T___front";
          break;
        case 567:
          return "c_QList_T_unsigned_int_T___isDetached";
          break;
        case 568:
          return "c_QList_T_unsigned_int_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_unsigned_int_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_unsigned_int_T___last";
          break;
        case 571:
          return "c_QList_T_unsigned_int_T___last";
          break;
        case 572:
          return "c_QList_T_unsigned_int_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_unsigned_int_T___length";
          break;
        case 574:
          return "c_QList_T_unsigned_int_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_unsigned_int_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_unsigned_int_T___pop_back";
          break;
        case 585:
          return "c_QList_T_unsigned_int_T___pop_front";
          break;
        case 586:
          return "c_QList_T_unsigned_int_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_unsigned_int_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_unsigned_int_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_unsigned_int_T___removeLast";
          break;
        case 590:
          return "c_QList_T_unsigned_int_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_unsigned_int_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_unsigned_int_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_unsigned_int_T___size";
          break;
        case 595:
          return "c_QList_T_unsigned_int_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_unsigned_int_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_unsigned_int_T___squeeze";
          break;
        case 599:
          return "c_QList_T_unsigned_int_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_unsigned_int_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_unsigned_int_T___toList";
          break;
        case 602:
          return "c_QList_T_unsigned_int_T___toVector";
          break;
        case 603:
          return "c_QList_T_unsigned_int_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<QObject>) {
      switch (id) {
        case 543:
          return "c_QList_T_QObject_T___constructor";
          break;
        case 544:
          return "c_QList_T_QObject_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_QObject_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_QObject_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_QObject_T___back";
          break;
        case 549:
          return "c_QList_T_QObject_T___back";
          break;
        case 550:
          return "c_QList_T_QObject_T___capacity";
          break;
        case 551:
          return "c_QList_T_QObject_T___clear";
          break;
        case 553:
          return "c_QList_T_QObject_T___constFirst";
          break;
        case 554:
          return "c_QList_T_QObject_T___constLast";
          break;
        case 555:
          return "c_QList_T_QObject_T___count";
          break;
        case 558:
          return "c_QList_T_QObject_T___detach";
          break;
        case 559:
          return "c_QList_T_QObject_T___empty";
          break;
        case 560:
          return "c_QList_T_QObject_T___first";
          break;
        case 561:
          return "c_QList_T_QObject_T___first";
          break;
        case 562:
          return "c_QList_T_QObject_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_QObject_T___front";
          break;
        case 566:
          return "c_QList_T_QObject_T___front";
          break;
        case 567:
          return "c_QList_T_QObject_T___isDetached";
          break;
        case 568:
          return "c_QList_T_QObject_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_QObject_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_QObject_T___last";
          break;
        case 571:
          return "c_QList_T_QObject_T___last";
          break;
        case 572:
          return "c_QList_T_QObject_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_QObject_T___length";
          break;
        case 574:
          return "c_QList_T_QObject_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_QObject_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_QObject_T___pop_back";
          break;
        case 585:
          return "c_QList_T_QObject_T___pop_front";
          break;
        case 586:
          return "c_QList_T_QObject_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_QObject_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_QObject_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_QObject_T___removeLast";
          break;
        case 590:
          return "c_QList_T_QObject_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_QObject_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_QObject_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_QObject_T___size";
          break;
        case 595:
          return "c_QList_T_QObject_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_QObject_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_QObject_T___squeeze";
          break;
        case 599:
          return "c_QList_T_QObject_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_QObject_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_QObject_T___toList";
          break;
        case 602:
          return "c_QList_T_QObject_T___toVector";
          break;
        case 603:
          return "c_QList_T_QObject_T___value_qsizetype";
          break;
      }
    }
    if (this is QList<QByteArray>) {
      switch (id) {
        case 543:
          return "c_QList_T_QByteArray_T___constructor";
          break;
        case 544:
          return "c_QList_T_QByteArray_T___constructor_qsizetype";
          break;
        case 546:
          return "c_QList_T_QByteArray_T___append_QList_T";
          break;
        case 547:
          return "c_QList_T_QByteArray_T___at_qsizetype";
          break;
        case 548:
          return "c_QList_T_QByteArray_T___back";
          break;
        case 549:
          return "c_QList_T_QByteArray_T___back";
          break;
        case 550:
          return "c_QList_T_QByteArray_T___capacity";
          break;
        case 551:
          return "c_QList_T_QByteArray_T___clear";
          break;
        case 553:
          return "c_QList_T_QByteArray_T___constFirst";
          break;
        case 554:
          return "c_QList_T_QByteArray_T___constLast";
          break;
        case 555:
          return "c_QList_T_QByteArray_T___count";
          break;
        case 558:
          return "c_QList_T_QByteArray_T___detach";
          break;
        case 559:
          return "c_QList_T_QByteArray_T___empty";
          break;
        case 560:
          return "c_QList_T_QByteArray_T___first";
          break;
        case 561:
          return "c_QList_T_QByteArray_T___first";
          break;
        case 562:
          return "c_QList_T_QByteArray_T___first_qsizetype";
          break;
        case 565:
          return "c_QList_T_QByteArray_T___front";
          break;
        case 566:
          return "c_QList_T_QByteArray_T___front";
          break;
        case 567:
          return "c_QList_T_QByteArray_T___isDetached";
          break;
        case 568:
          return "c_QList_T_QByteArray_T___isEmpty";
          break;
        case 569:
          return "c_QList_T_QByteArray_T___isSharedWith_QList_T";
          break;
        case 570:
          return "c_QList_T_QByteArray_T___last";
          break;
        case 571:
          return "c_QList_T_QByteArray_T___last";
          break;
        case 572:
          return "c_QList_T_QByteArray_T___last_qsizetype";
          break;
        case 573:
          return "c_QList_T_QByteArray_T___length";
          break;
        case 574:
          return "c_QList_T_QByteArray_T___mid_qsizetype_qsizetype";
          break;
        case 575:
          return "c_QList_T_QByteArray_T___move_qsizetype_qsizetype";
          break;
        case 584:
          return "c_QList_T_QByteArray_T___pop_back";
          break;
        case 585:
          return "c_QList_T_QByteArray_T___pop_front";
          break;
        case 586:
          return "c_QList_T_QByteArray_T___remove_qsizetype_qsizetype";
          break;
        case 587:
          return "c_QList_T_QByteArray_T___removeAt_qsizetype";
          break;
        case 588:
          return "c_QList_T_QByteArray_T___removeFirst";
          break;
        case 589:
          return "c_QList_T_QByteArray_T___removeLast";
          break;
        case 590:
          return "c_QList_T_QByteArray_T___reserve_qsizetype";
          break;
        case 591:
          return "c_QList_T_QByteArray_T___resize_qsizetype";
          break;
        case 593:
          return "c_QList_T_QByteArray_T___shrink_to_fit";
          break;
        case 594:
          return "c_QList_T_QByteArray_T___size";
          break;
        case 595:
          return "c_QList_T_QByteArray_T___sliced_qsizetype";
          break;
        case 596:
          return "c_QList_T_QByteArray_T___sliced_qsizetype_qsizetype";
          break;
        case 597:
          return "c_QList_T_QByteArray_T___squeeze";
          break;
        case 599:
          return "c_QList_T_QByteArray_T___swapItemsAt_qsizetype_qsizetype";
          break;
        case 600:
          return "c_QList_T_QByteArray_T___takeAt_qsizetype";
          break;
        case 601:
          return "c_QList_T_QByteArray_T___toList";
          break;
        case 602:
          return "c_QList_T_QByteArray_T___toVector";
          break;
        case 603:
          return "c_QList_T_QByteArray_T___value_qsizetype";
          break;
      }
    }
    return "";
  }

  String getFinalizerName() {
    if (this is QList<SimpleStruct>) {
      return "c_QList_T_SimpleStruct_T__Finalizer";
    }
    if (this is QList<double>) {
      return "c_QList_T_qreal_T__Finalizer";
    }
    if (this is QList<int>) {
      return "c_QList_T_int_T__Finalizer";
    }
    if (this is QList<QVariant>) {
      return "c_QList_T_QVariant_T__Finalizer";
    }
    if (this is QList<QString>) {
      return "c_QList_T_QString_T__Finalizer";
    }
    if (this is QList<int>) {
      return "c_QList_T_unsigned_int_T__Finalizer";
    }
    if (this is QList<QObject>) {
      return "c_QList_T_QObject_T__Finalizer";
    }
    if (this is QList<QByteArray>) {
      return "c_QList_T_QByteArray_T__Finalizer";
    }
    print(
        "ERROR: Couldn't find finalizerName for" + this.runtimeType.toString());
    return "";
  } //QList<T>()

  QList() {
    final voidstar_Func_void func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_void_FFI>>(
            '${getCFunctionName(543)}')
        .asFunction();
    thisCpp = func();
    QList.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } //QList<T>(qsizetype size)
  QList.ctor2(int size) {
    final voidstar_Func_int func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_ffi_Int32_FFI>>(
            '${getCFunctionName(544)}')
        .asFunction();
    thisCpp = func(size);
    QList.s_dartInstanceByCppPtr[thisCpp.address] = this;
  } // append(const QList<T > & l)
  append(QList l) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(546)}')
        .asFunction();
    func(thisCpp, l == null ? ffi.nullptr : l.thisCpp);
  } // at(qsizetype i) const

  T at(int i) {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(547)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // back()

  T back() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(548)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // capacity() const

  int capacity() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(550)}')
        .asFunction();
    return func(thisCpp);
  } // clear()

  clear() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(551)}')
        .asFunction();
    func(thisCpp);
  } // constFirst() const

  T constFirst() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(553)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // constLast() const

  T constLast() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(554)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // count() const

  int count() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(555)}')
        .asFunction();
    return func(thisCpp);
  } // detach()

  detach() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(558)}')
        .asFunction();
    func(thisCpp);
  } // empty() const

  bool empty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(559)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // first()

  T first() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(560)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // front()

  T front() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(565)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // isDetached() const

  bool isDetached() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(567)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isEmpty() const

  bool isEmpty() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            '${getCFunctionName(568)}')
        .asFunction();
    return func(thisCpp) != 0;
  } // isSharedWith(const QList<T > & other) const

  bool isSharedWith(QList other) {
    final bool_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_voidstar_FFI>>(
            '${getCFunctionName(569)}')
        .asFunction();
    return func(thisCpp, other == null ? ffi.nullptr : other.thisCpp) != 0;
  } // last()

  T last() {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
              '${getCFunctionName(570)}')
          .asFunction();
      return (func(thisCpp) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // length() const

  int length() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(573)}')
        .asFunction();
    return func(thisCpp);
  } // move(qsizetype from, qsizetype to)

  move(int from, int to) {
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(575)}')
        .asFunction();
    func(thisCpp, from, to);
  } // pop_back()

  pop_back() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(584)}')
        .asFunction();
    func(thisCpp);
  } // pop_front()

  pop_front() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(585)}')
        .asFunction();
    func(thisCpp);
  } // remove(qsizetype i, qsizetype n)

  remove(int i, {int n = 1}) {
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(586)}')
        .asFunction();
    func(thisCpp, i, n);
  } // removeAt(qsizetype i)

  removeAt(int i) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(587)}')
        .asFunction();
    func(thisCpp, i);
  } // removeFirst()

  removeFirst() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(588)}')
        .asFunction();
    func(thisCpp);
  } // removeLast()

  removeLast() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(589)}')
        .asFunction();
    func(thisCpp);
  } // reserve(qsizetype size)

  reserve(int size) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(590)}')
        .asFunction();
    func(thisCpp, size);
  } // resize(qsizetype size)

  resize(int size) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(591)}')
        .asFunction();
    func(thisCpp, size);
  } // resize_internal(qsizetype i)

  resize_internal(int i) {
    final void_Func_voidstar_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_FFI>>(
            '${getCFunctionName(592)}')
        .asFunction();
    func(thisCpp, i);
  } // shrink_to_fit()

  shrink_to_fit() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(593)}')
        .asFunction();
    func(thisCpp);
  } // size() const

  int size() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            '${getCFunctionName(594)}')
        .asFunction();
    return func(thisCpp);
  } // squeeze()

  squeeze() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            '${getCFunctionName(597)}')
        .asFunction();
    func(thisCpp);
  } // swapItemsAt(qsizetype i, qsizetype j)

  swapItemsAt(int i, int j) {
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            '${getCFunctionName(599)}')
        .asFunction();
    func(thisCpp, i, j);
  } // takeAt(qsizetype i)

  T takeAt(int i) {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(600)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    print(
        "Unreachable, but required, due to null safety we need to return something");
    throw Error();
  } // value(qsizetype i) const

  T value(int i) {
    if (this is QList<QByteArray>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QByteArray.fromCppPointer(result, true) as T);
    }
    if (this is QList<QString>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QString.fromCppPointer(result, true) as T);
    }
    if (this is QList<QVariant>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QVariant.fromCppPointer(result, true) as T);
    }
    if (this is QList<SimpleStruct>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (SimpleStruct.fromCppPointer(result, false) as T);
    }
    if (this is QList<QObject>) {
      final voidstar_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<voidstar_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      ffi.Pointer<void> result = func(thisCpp, i);
      return (QObject.fromCppPointer(result, false) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<double>) {
      final double_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<double_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      return (func(thisCpp, i) as T);
    }
    if (this is QList<int>) {
      final int_Func_voidstar_int func = _dylib
          .lookup<ffi.NativeFunction<int_Func_voidstar_ffi_Int32_FFI>>(
              '${getCFunctionName(603)}')
          .asFunction();
      return (func(thisCpp, i) as T);
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
