/// This file is part of Dartagnan.
///
/// SPDX-FileCopyrightText: 2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
/// SPDX-License-Identifier: MIT

import 'dart:io';
import 'dart:io' show Platform;
import 'package:path/path.dart';

import 'utils.dart' as Utils;

String s_buildDir = "";
String s_targetLib = "";
String s_bindingsLib = "";
String s_bindingsBuildDir = "";
bool s_printOnly = false; // Dry run, only prints commands
bool s_addReadabilityTags = false;
bool s_useGDB = false; // Will run shiboken under GDB
bool s_useASAN = false;
bool s_useLSAN = true;
bool s_runShiboken = true;
bool s_useSymbolizationWorkaround = true;

Map<String, String> s_envVars = Map.from(Platform.environment);

final String s_sourcePath = dirname(Platform.script.toFilePath());
final String s_testsPath = "${s_sourcePath}/tests";
final String s_bindingsSourceDir = "${s_testsPath}/generated/";

final String s_testsDartExecutable = "${s_testsPath}/app/bin/main.dart";
final String s_testsDartAOTExecutable = "${s_testsPath}/app/bin/main.aot";

Future<int> runShiboken() async {
  final String cmd =
      "${s_buildDir}/3rdparty/shiboken/sources/shiboken6/generator/shiboken6";
  final args = [
        "--output-directory=${s_testsPath}/generated/",
        "--generator-set=dart",
        "--skip-deprecated",
        "--clang-option=-DDARTAGNAN_BINDINGS_RUN"
      ] +
      Utils.includeArguments() +
      ["bindings_global.h", "typesystem.xml"];

  Map<String, String> env = {
    if (s_addReadabilityTags) 'DARTAGNAN_READABILITY_TAGS': '1'
  };

  return Utils.runCommand(cmd, args,
      workingDirectory: s_testsPath,
      printOnly: s_printOnly,
      useGDB: s_useGDB,
      env: env);
}

Future<int> getPackages() {
  return Utils.getPackages(
      workingDirectory: "${s_testsPath}/app", printOnly: s_printOnly);
}

Future<int> runTests() async {
  if (!File(s_testsDartExecutable).existsSync()) {
    print("File ${s_testsDartExecutable} does not exist!");
    return 1;
  }

  // Build performance improvement:
  // Save the timestamps, so we can restore them for every file which was
  // generated with the same content as before. No point in rebuilding those.
  final savedTimestamps = await Utils.TimeStamps('tests/generated');
  if (!Platform.isWindows)
    savedTimestamps.create(); // Not implemented on windows

  /// If dartagnan already ran, then the tests don't need to
  final bool runCodeFormat =
      !Platform.environment.containsKey('DARTAGNAN_RUNS_CODE_FORMAT');

  // Run shiboken to generate the bindings
  if (s_runShiboken) {
    final shibokenResult = await runShiboken();
    if (shibokenResult != 0) {
      print(
          "Failed to generate the bindings. Shiboken failed with code ${shibokenResult}");
      savedTimestamps.restoreTimeStamps();
      return -1;
    }

    if (runCodeFormat) {
      if (await Utils.runDartFormat(s_bindingsSourceDir,
              printOnly: s_printOnly) !=
          0) {
        print("Failed to run dart format");
        savedTimestamps.restoreTimeStamps();
        return -1;
      }

      if (await Utils.runClangFormat(
              "${s_bindingsSourceDir}/TestBindings/dart/ffi/") !=
          0) {
        print("Failed to run clangformat");
        savedTimestamps.restoreTimeStamps();
        return -1;
      }
    }

    await savedTimestamps.restoreTimeStamps();

    // Build the generated bindings lib
    var cmakeExtraArgs = <String>[];

    if (s_useASAN) {
      cmakeExtraArgs = ["-DECM_ENABLE_SANITIZERS='address;undefined'"];
    }

    if (await Utils.runCommand(
            "cmake",
            [
                  "-B",
                  "${s_bindingsBuildDir}",
                  "-S",
                  "${s_bindingsSourceDir}",
                  "-G",
                  "Ninja",
                  "-DCMAKE_BUILD_TYPE=Debug",
                ] +
                cmakeExtraArgs) !=
        0) {
      print("Fail to configure bindings lib");
      return -1;
    }

    if (await Utils.runCommand("cmake", ["--build", "${s_bindingsBuildDir}"]) !=
        0) {
      print("Fail to build bindings lib");
      return -1;
    }

    if (!File(s_bindingsLib).existsSync()) {
      print("Could not find ${s_bindingsLib}");
      return -1;
    }

    if (await getPackages() != 0) {
      print("Failed to get packages");
      return -1;
    }
  }

  if (await Utils.runCommand(
          "dart", ["compile", "aot-snapshot", s_testsDartExecutable]) !=
      0) {
    print("Failed to compile aot-snapshot");
    return 1;
  }

  var env = s_envVars;
  if (s_useASAN || s_useLSAN) {
    env['LD_PRELOAD'] = '/usr/lib/libasan.so';
    env['ASAN_OPTIONS'] = 'new_delete_type_mismatch=0';

    if (s_printOnly) {
      for (String key in ["LD_PRELOAD", "LSAN_OPTIONS", "ASAN_OPTIONS"])
        print("ENV ${key}=${env[key]}");
    }
  }

  if (Platform.isMacOS) {
    // DYLD_LIBRARY_PATH doesn't work on mac by default anymore
    env['DARTAGNAN_BINDINGSLIB_PATH'] = "${s_bindingsBuildDir}/TestBindings";
    if (s_printOnly) {
      print(
          "ENV DARTAGNAN_BINDINGSLIB_PATH=${env['DARTAGNAN_BINDINGSLIB_PATH']}");
    }
  }

  return Utils.runCommand(
      "dartaotruntime",
      [
        s_testsDartAOTExecutable,
        if (s_useSymbolizationWorkaround) "--symbolization-workaround"
      ],
      env: env,
      printOnly: s_printOnly);
}

void printUsage() {
  print(
      "    Usage: \$ dart run_tests.dart [--asan] [--no-lsan] [--tags] [--no-shiboken] [--symbolization-workaround] <build directory>");
}

bool setupPaths(String buildDir) {
  s_buildDir = Directory(buildDir).absolute.path;
  s_targetLib = "${s_buildDir}/tests/${Utils.normalizedLibName("TestTarget")}";

  s_bindingsBuildDir = "${s_buildDir}/tests/generated/";
  s_bindingsLib =
      "${s_bindingsBuildDir}/TestBindings/${Utils.normalizedLibName("TestBindings")}";

  if (!File(s_targetLib).existsSync()) {
    print("Could not find ${s_targetLib}");
    return false;
  }

  final String libraryPathStr = s_envVars[Utils.s_libraryPathEnvVariable] ?? "";

  var libraryPaths = libraryPathStr.split(Utils.s_listSeparator);
  libraryPaths += [
    "${s_buildDir}/tests/generated/TestBindings/",
    "${s_buildDir}/tests"
  ];

  s_envVars[Utils.s_libraryPathEnvVariable] =
      libraryPaths.join(Utils.s_listSeparator);
  return true;
}

Future<int> main(List<String> args_) async {
  String buildDir = "";

  List<String> args = List.from(args_);
  s_printOnly = args.contains("--print");
  s_useGDB = args.contains("--gdb");
  s_useASAN = args.contains("--asan");
  s_useLSAN = !args.contains("--no-lsan") && Platform.isLinux;
  s_addReadabilityTags = args.contains("--tags");
  s_runShiboken = !args.contains("--no-shiboken");
  s_useSymbolizationWorkaround = args.contains("--symbolization-workaround");

  if (s_useASAN && !Platform.isLinux) {
    print("--asan is only supported on Linux. Patches accepted.");
    return -1;
  }

  if (s_addReadabilityTags && !s_runShiboken) {
    print("--tags requires a shiboken run");
    return -1;
  }

  args.remove("--print");
  args.remove("--gdb");
  args.remove("--asan");
  args.remove("--no-lsan");
  args.remove("--tags");
  args.remove("--no-shiboken");
  args.remove("--symbolization-workaround");

  if (args.length > 1 || args.contains("help") || args.contains("--help")) {
    printUsage();
    return 0;
  } else if (args.length == 1) {
    buildDir = args.first;
  } else {
    print("No build dir was passed. Assuming build-dev/");
    buildDir = "${s_sourcePath}/build-dev";
  }

  if (!setupPaths(buildDir)) {
    print(
        "Did you build the bindings ? Make sure you're using a developer-build, or just pass --preset=dev to cmake when configuring.");
    return -2;
  }

  final int result = await runTests();
  print("");

  if (result == 0) {
    print("Success!! ");
  } else {
    print("Error!! code = $result");
  }

  exit(result);
}
