import 'package:DartBindingsTest/Tests.dart';

void main(List<String> args) {
  runTests();

  if (args.contains("--symbolization-workaround")) {
    Future.delayed(Duration(seconds: 5), () {
      throw "Aborting so dart doesn't dlclose the library, otherwise lsan doesn't show readable symbols";
    });
  }
}
