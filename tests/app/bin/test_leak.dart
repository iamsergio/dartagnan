import 'package:ffi/ffi.dart';

void main(List<String> args) {
  bool shouldLeak = args.contains("leak") || args.contains("--leak");

  if (shouldLeak) {
    print("Leak!");
    "foo".toNativeUtf8();
  } else {
    print("No leak! Pass --leak to leak.");
  }
}
