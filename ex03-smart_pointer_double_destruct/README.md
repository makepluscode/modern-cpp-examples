# Smart Pointer Double Destruction in C++

This example demonstrates a common pitfall when using smart pointers in C++: double destruction. When you manually delete a raw pointer obtained from a smart pointer, it leads to undefined behavior as the smart pointer will attempt to delete the same memory again when it goes out of scope. This example serves as a warning about improper usage of smart pointers and raw pointers together.

이 예제는 C++에서 smart pointer를 사용할 때 흔히 발생하는 함정인 이중 파괴(double destruction)를 보여줍니다. Smart pointer로부터 얻은 raw pointer를 수동으로 delete하면, smart pointer가 scope를 벗어날 때 동일한 메모리를 다시 delete하려고 시도하여 정의되지 않은 동작(undefined behavior)이 발생합니다. 이 예제는 smart pointer와 raw pointer를 함께 부적절하게 사용하는 것에 대한 경고 역할을 합니다.

## Files

- **ex03.cpp**: This file contains the C++ code that demonstrates the double destruction problem when mixing smart pointers with manual memory management.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates the double destruction problem:

```cpp
// Create a smart pointer
auto sharedPtr1 = std::make_shared<MyClass>();
sharedPtr1->display();

// Get a raw pointer from the smart pointer
auto rawPtr = sharedPtr1.get();

// Manually delete the raw pointer (this is incorrect and dangerous)
delete rawPtr;

// When sharedPtr1 goes out of scope, it will try to delete the same memory again
```

This code shows an anti-pattern that should be avoided. The program will likely crash or exhibit undefined behavior because:
1. The raw pointer is manually deleted
2. The smart pointer will attempt to delete the same memory when it goes out of scope

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex03-smart_pointer_double_destruct` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex03-smart_pointer_double_destruct` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex03.out
   ```
   Note: This program may crash or exhibit undefined behavior by design.

   참고: 이 프로그램은 의도적으로 crash하거나 정의되지 않은 동작을 보일 수 있습니다.

3. **Clean Up**: To remove the compiled executable, use the following command:

   **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex03-smart_pointer_double_destruct
make
```

This will compile the example and create an executable named `ex03.out`. When you run it, you'll likely see the program crash or exhibit undefined behavior, demonstrating the dangers of double destruction.

## What You Will Learn

**배울 내용**

- The dangers of mixing smart pointers with manual memory management.
- Why you should never manually delete a raw pointer obtained from a smart pointer.
- How double destruction leads to undefined behavior.
- Best practices for using smart pointers safely.

- Smart pointer와 수동 메모리 관리를 혼용할 때의 위험성
- Smart pointer로부터 얻은 raw pointer를 절대 수동으로 delete해서는 안 되는 이유
- Double destruction이 어떻게 undefined behavior로 이어지는지
- Smart pointer를 안전하게 사용하기 위한 best practice

This example serves as a cautionary tale about the proper use of smart pointers in modern C++, highlighting a common mistake that can lead to serious memory corruption issues.

이 예제는 modern C++에서 smart pointer의 올바른 사용법에 대한 경고 사례로, 심각한 메모리 손상 문제를 일으킬 수 있는 일반적인 실수를 강조합니다.
