# NULL vs nullptr in Modern C++

This example demonstrates the difference between `NULL` and `nullptr` in C++. The `nullptr` keyword was introduced in C++11 as a type-safe alternative to `NULL` for representing null pointers. This example illustrates why `nullptr` is preferred over `NULL` in modern C++ code, particularly when dealing with function overloading.

이 예제는 C++에서 `NULL`과 `nullptr`의 차이를 보여줍니다. `nullptr` 키워드는 C++11에서 null pointer를 나타내기 위한 타입 안전한 `NULL`의 대안으로 도입되었습니다. 이 예제는 특히 함수 오버로딩을 다룰 때 Modern C++ 코드에서 `NULL`보다 `nullptr`이 선호되는 이유를 설명합니다.

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

## 컴파일 및 실행 방법

1. **코드 컴파일**: 터미널을 열고 `ex31-null_ptr` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **실행 파일 실행**: 컴파일 후 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex31.out
   ```

3. **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
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

## 배우게 될 내용

- C++에서 `NULL`과 `nullptr`의 차이점
- Modern C++ 코드에서 `NULL`보다 `nullptr`이 선호되는 이유
- `NULL`이 오버로드된 함수에서 모호성을 유발하는 방법
- 다양한 pointer 타입과 함께 `nullptr`을 올바르게 사용하는 방법
- C++ 프로그래밍에서 타입 안전성의 중요성

이 예제는 Modern C++의 중요한 개선 사항 중 하나에 대한 실용적인 통찰을 제공하며, null pointer를 나타내는 데 있어 `nullptr`이 `NULL`보다 더 안전하고 예측 가능한 대안인 이유를 보여줍니다.
