# Smart Pointers in Modern C++

Modern C++ introduced smart pointers as part of the C++11 standard to help manage dynamic memory allocation and prevent memory leaks. Smart pointers are wrapper classes that manage the lifetime of dynamically allocated objects through RAII (Resource Acquisition Is Initialization) principles. The three main types of smart pointers in C++ are `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, each serving different ownership semantics and memory management needs.

Modern C++는 동적 메모리 할당을 관리하고 memory leak을 방지하기 위해 C++11 표준의 일부로 smart pointer를 도입했습니다. Smart pointer는 RAII (Resource Acquisition Is Initialization) 원칙을 통해 동적으로 할당된 객체의 생명주기를 관리하는 wrapper class입니다. C++의 세 가지 주요 smart pointer 타입은 `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`이며, 각각 다른 ownership 의미론과 메모리 관리 요구사항을 제공합니다.

## Files

- **ex02.cpp**: This file contains the C++ code that demonstrates the use of `std::unique_ptr` and `std::shared_ptr` to manage object lifetimes.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates various uses of smart pointers:

```cpp
// Unique pointer example
auto uniquePtr = std::make_unique<MyClass>();
uniquePtr->display();
// uniquePtr has exclusive ownership of the MyClass object
// When uniquePtr goes out of scope, the object is automatically deleted

// Shared pointer example
auto sharedPtr1 = std::make_shared<MyClass>();
{
    auto sharedPtr2 = sharedPtr1;
    std::cout << "Shared pointer count: " << sharedPtr1.use_count() << std::endl;
    // Both sharedPtr1 and sharedPtr2 share ownership of the same object
    // The reference count is 2
}
std::cout << "Shared pointer count after block: " << sharedPtr1.use_count() << std::endl;
// After the inner block, sharedPtr2 is destroyed, reducing the reference count to 1
// The object is deleted only when the last shared_ptr (sharedPtr1) goes out of scope
```

Each example shows how smart pointers automatically manage memory, eliminating the need for manual memory management with `new` and `delete`.

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex02-smart_pointer` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex02-smart_pointer` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex02.out
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
cd ex02-smart_pointer
make
```

This will compile the example and create an executable named `ex02.out`. When you run it, you'll see the output demonstrating how smart pointers manage object lifetimes and how reference counting works with shared pointers.

## What You Will Learn

**배울 내용**

- How to use `std::unique_ptr` for exclusive ownership of resources.
- How to use `std::shared_ptr` for shared ownership and reference counting.
- How smart pointers automatically manage memory and prevent memory leaks.
- How to create smart pointers using factory functions like `std::make_unique` and `std::make_shared`.

- resource의 독점적 ownership을 위해 `std::unique_ptr`을 사용하는 방법
- 공유 ownership과 reference counting을 위해 `std::shared_ptr`을 사용하는 방법
- Smart pointer가 자동으로 메모리를 관리하고 memory leak을 방지하는 방법
- `std::make_unique`와 `std::make_shared` 같은 factory function을 사용하여 smart pointer를 생성하는 방법

This example is a practical introduction to smart pointers in modern C++, demonstrating how they can make your code safer by eliminating common memory management errors.

이 예제는 modern C++의 smart pointer에 대한 실용적인 소개이며, 일반적인 메모리 관리 오류를 제거하여 코드를 더 안전하게 만드는 방법을 보여줍니다.
