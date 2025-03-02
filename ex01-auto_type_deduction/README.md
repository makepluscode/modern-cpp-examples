# Auto Type Deduction in Modern C++

Modern C++ refers to C++ standards from C++11 onwards, which introduced significant improvements to the language including type inference, smart pointers, and concurrency support. Auto type deduction was introduced in C++11 (released in 2011) as a way to simplify code by allowing the compiler to deduce variable types automatically from their initializers. The primary purpose of `auto` is to reduce verbosity, avoid type errors, and make code more maintainable, especially when working with complex types like iterators or lambda expressions.

## Files

- **ex01.cpp**: This file contains the C++ code that demonstrates the use of `auto` for different types of variables, including integers, floating-point numbers, strings, and vectors.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates various uses of `auto` type deduction:

```cpp
// Integer type deduction
auto integer = 42;
// The compiler automatically deduces 'integer' as int

// Floating-point type deduction
auto floating_point = 3.14;
// The compiler deduces 'floating_point' as double

// String type deduction
auto text = std::string("Hello, World!");
// The compiler deduces 'text' as std::string

// Vector container type deduction
auto numbers = std::vector<int>{1, 2, 3, 4, 5};
// The compiler deduces 'numbers' as std::vector<int>

// Range-based for loop with auto
for (auto num : numbers) {
    std::cout << num << " ";
}
// 'num' is deduced as int, the element type of the vector
```

Each example shows how the compiler automatically determines the appropriate type based on the initialization expression, eliminating the need to explicitly specify types.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex01-auto_type_deduction` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex01.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex01-auto_type_deduction
make
```

This will compile the example and create an executable named `ex01.out`. When you run it, you'll see the output demonstrating the different variable types that were automatically deduced by the compiler.

## What You Will Learn

- How to use the `auto` keyword to simplify variable declarations.
- How `auto` can deduce different types based on the initializer.
- Basic usage of a Makefile to compile and clean a C++ project.

This example is a simple introduction to modern C++ features and helps you understand how type deduction can make your code cleaner and easier to read.
