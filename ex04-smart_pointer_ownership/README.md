# Smart Pointer Ownership Transfer in C++

This example demonstrates ownership transfer with smart pointers in C++, specifically focusing on `std::unique_ptr`. Since `std::unique_ptr` implements exclusive ownership semantics, it cannot be copied, but its ownership can be transferred using `std::move()`. This example illustrates the proper way to transfer ownership of resources managed by smart pointers.

이 예제는 C++에서 smart pointer를 사용한 ownership 전송을 보여주며, 특히 `std::unique_ptr`에 중점을 둡니다. `std::unique_ptr`은 독점적 ownership 의미론을 구현하므로 복사할 수 없지만, `std::move()`를 사용하여 ownership을 전송할 수 있습니다. 이 예제는 smart pointer가 관리하는 resource의 ownership을 전송하는 올바른 방법을 보여줍니다.

## Files

- **ex04.cpp**: This file contains the C++ code that demonstrates ownership transfer with smart pointers and shows what happens when you try to copy a `std::unique_ptr`.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates ownership transfer with smart pointers:

```cpp
// Create a unique_ptr
auto ptr1(new MyClass());
ptr1->display();

#ifdef IMPLICITLY_DELECTED_COPY_ERROR
    // This would cause a compilation error because unique_ptr cannot be copied
    auto ptr2(ptr1);
#else
    // Transfer ownership from ptr1 to ptr2 using std::move
    auto ptr2 = std::move(ptr1);
#endif

// ptr2 now owns the object, ptr1 is null
ptr2->display();
```

This code shows:
1. How to create a `std::unique_ptr` using direct initialization
2. Why copying a `std::unique_ptr` is not allowed (commented out to prevent compilation errors)
3. How to properly transfer ownership using `std::move()`

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex04-smart_pointer_ownership` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex04-smart_pointer_ownership` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex04.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:

   **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
   ```bash
   make clean
   ```

4. **Test with Error**: If you want to see the compilation error when trying to copy a `std::unique_ptr`, you can compile with:

   **에러 테스트**: `std::unique_ptr`을 복사하려고 할 때 발생하는 컴파일 에러를 보려면 다음과 같이 컴파일합니다:
   ```bash
   make CXXFLAGS="-std=c++14 -Wall -DIMPLICITLY_DELECTED_COPY_ERROR"
   ```
   This will define the preprocessor macro that enables the code that attempts to copy a `std::unique_ptr`.

   이것은 `std::unique_ptr`을 복사하려고 시도하는 코드를 활성화하는 preprocessor macro를 정의합니다.

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex04-smart_pointer_ownership
make
```

This will compile the example and create an executable named `ex04.out`. When you run it, you'll see the output demonstrating how ownership is transferred from one smart pointer to another.

## What You Will Learn

**배울 내용**

- The exclusive ownership semantics of `std::unique_ptr`.
- Why `std::unique_ptr` cannot be copied.
- How to transfer ownership using `std::move()`.
- The behavior of smart pointers after ownership transfer.

- `std::unique_ptr`의 독점적 ownership 의미론
- `std::unique_ptr`을 복사할 수 없는 이유
- `std::move()`를 사용하여 ownership을 전송하는 방법
- Ownership 전송 후 smart pointer의 동작 방식

This example provides practical insights into the ownership model of smart pointers in modern C++, demonstrating how to safely transfer resources without causing memory leaks or double deletions.

이 예제는 modern C++에서 smart pointer의 ownership 모델에 대한 실용적인 통찰을 제공하며, memory leak이나 이중 삭제를 일으키지 않고 resource를 안전하게 전송하는 방법을 보여줍니다.
