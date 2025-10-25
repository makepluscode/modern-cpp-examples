# Auto Type Deduction in Modern C++

Modern C++ refers to C++ standards from C++11 onwards, which introduced significant improvements to the language including type inference, smart pointers, and concurrency support. Auto type deduction was introduced in C++11 (released in 2011) as a way to simplify code by allowing the compiler to deduce variable types automatically from their initializers. The primary purpose of `auto` is to reduce verbosity, avoid type errors, and make code more maintainable, especially when working with complex types like iterators or lambda expressions.

Modern C++는 C++11 이후의 표준을 의미하며, type inference(타입 추론), smart pointer, 동시성 지원 등 언어에 중요한 개선사항을 도입했습니다. Auto type deduction은 C++11(2011년 출시)에서 compiler가 initializer로부터 변수 타입을 자동으로 추론하게 함으로써 코드를 간소화하는 방법으로 도입되었습니다. `auto`의 주요 목적은 장황함을 줄이고, 타입 오류를 피하며, 특히 iterator나 lambda expression 같은 복잡한 타입을 다룰 때 코드를 더 유지보수하기 쉽게 만드는 것입니다.

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

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex01-auto_type_deduction` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex01-auto_type_deduction` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex01.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:

   **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
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

**배울 내용**

- How to use the `auto` keyword to simplify variable declarations.
- How `auto` can deduce different types based on the initializer.
- Basic usage of a Makefile to compile and clean a C++ project.

- `auto` keyword를 사용하여 변수 선언을 간소화하는 방법
- `auto`가 initializer를 기반으로 다양한 타입을 추론하는 방법
- C++ project를 컴파일하고 정리하는 Makefile의 기본 사용법

This example is a simple introduction to modern C++ features and helps you understand how type deduction can make your code cleaner and easier to read.

이 예제는 modern C++ 기능에 대한 간단한 소개이며, type deduction이 어떻게 코드를 더 깔끔하고 읽기 쉽게 만들 수 있는지 이해하는 데 도움이 됩니다.
