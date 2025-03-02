# NULL vs nullptr in Modern C++

This example demonstrates the difference between `NULL` and `nullptr` in C++. The `nullptr` keyword was introduced in C++11 as a type-safe alternative to `NULL` for representing null pointers. This example illustrates why `nullptr` is preferred over `NULL` in modern C++ code, particularly when dealing with function overloading.

## Files

- **ex31.cpp**: This file contains the C++ code that demonstrates the ambiguity issues with `NULL` and how `nullptr` provides a more type-safe solution.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates the difference between `NULL` and `nullptr`:

```cpp
#include <iostream>

void func(int* ptr) {
    std::cout << "Called func(int*)" << (ptr ? "" : " with null") << "\n";
}

void func(char* ptr) {
    std::cout << "Called func(char*)" << (ptr ? "" : " with null") << "\n";
}

int main() {
    // NULL is problematic due to ambiguity
    func((int*)NULL);    // Explicitly cast to avoid ambiguity
    
    // nullptr also needs explicit casting in this case
    func((int*)nullptr);  // or could use (char*)nullptr to call the other overload

    return 0;
}
```

This code shows:
1. Two overloaded functions that accept different pointer types
2. How `NULL` requires explicit casting to resolve ambiguity
3. How `nullptr` also requires casting in this specific case, but is generally more type-safe

The key issue is that `NULL` is typically defined as `0` or `(void*)0`, which can lead to ambiguity in overloaded functions. In contrast, `nullptr` has its own type (`std::nullptr_t`), making it more type-safe.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex31-null_ptr` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex31.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex31-null_ptr
make
```

This will compile the example and create an executable named `ex31.out`. When you run it, you'll see the output showing which overloaded function was called in each case.

## What You Will Learn

- The difference between `NULL` and `nullptr` in C++
- Why `nullptr` is preferred over `NULL` in modern C++ code
- How `NULL` can lead to ambiguity in overloaded functions
- How to properly use `nullptr` with different pointer types
- The importance of type safety in C++ programming

This example provides practical insights into one of the important improvements in modern C++, demonstrating why `nullptr` is a safer and more predictable alternative to `NULL` for representing null pointers.
