# Dartagnan

![Build Status](https://github.com/iamsergio/dartagnan/actions/workflows/build.yml/badge.svg)

Dartagnan is a POC of C++ Dart bindings generator.
Unlike other generators, Dartagnan preserves OOP semantics when crossing language barrier.
A Dart class can inherit from a C++ class, override virtual methods and still get dynamic dispatch working.
In other words, whether the base class is Dart or C++ is irrelevant from the user's prespective, as inheritance
still works as supposed to.

## Example

```cpp
#include <iostream>

class Animal {
public:
    // non-virtual! for example purposes
    void eat() {
        std::cout << "eat from C++";
        openMouth();
        closeMouth();
    }

    virtual void openMouth() {
        std::cout << "openMouth from C++";
    }

    virtual void closeMouth() {
        std::cout << "closeMouth from C++";
    }
};
```

```dart
class MyDartAlligator extends MyBindings.Animal {
    @override
    void openMouth() {
        print("openMouth from Dart");
    }
}

main() {
    final alligator = MyDartAlligator();

    /// This will call C++ eat() via FFI
    /// which in turn will call into Dart to invoke openMouth()
    /// closeMouth() will be C++ to C++ directly, as it's not overridden in Dart
    alligator.eat();

    // Prints:
    // eat from C++
    // openMouth from Dart
    // closeMouth from C++
}
```

## Problems

- Passing small and trivial-destructible structs to C++ is allocating memory. They should be passed via registers, or at the very least stack.

- C++ is complex, Dartagnan often breaks and needs patches with complex projects.

- The POC code is a mess, specially after shoehorning C++ template support.

- Dartagnan is based on shiboken's Api-extractor, which is a LLVM-based C++ parser. Api extractor brings in Qt as a dependency.

- Rebasing over new shiboken, newer LLVM and newer Qt often causes regressions.
