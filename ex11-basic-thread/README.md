# Basic Thread Usage in Modern C++

This example demonstrates the fundamental usage of threads in modern C++ using the `std::thread` class introduced in C++11. Multithreading allows programs to perform multiple operations concurrently, improving performance and responsiveness in many applications. This example shows how to create, execute, and synchronize basic threads.

이 예제는 C++11에서 도입된 `std::thread` class를 사용하여 modern C++에서 thread의 기본적인 사용법을 보여줍니다. Multithreading은 프로그램이 여러 작업을 동시에 수행할 수 있게 하여 많은 application에서 성능과 응답성을 향상시킵니다. 이 예제는 기본 thread를 생성하고, 실행하고, 동기화하는 방법을 보여줍니다.

## Files

- **ex11.cpp**: This file contains the C++ code that demonstrates how to create and manage multiple threads using the C++ Standard Library.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates basic thread creation and synchronization:

```cpp
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    auto say_hello = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Hello from thread 1!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for 100ms
        }
    };

    auto say_goodbye = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Goodbye from thread 2!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for 100ms
        }
    };

    std::thread t1(say_hello);   // Create and execute first thread
    std::thread t2(say_goodbye); // Create and execute second thread

    t1.join(); // Main thread waits for t1 to finish
    t2.join(); // Main thread waits for t2 to finish

    return 0;
}
```

This code shows:
1. How to define thread functions using lambda expressions
2. How to create and start threads with `std::thread`
3. How to make a thread sleep for a specified duration using `std::this_thread::sleep_for`
4. How to wait for threads to complete using the `join()` method

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex11-basic-thread` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex11-basic-thread` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```
   Note: The Makefile includes the `-pthread` flag required for threading.

   참고: Makefile에는 threading에 필요한 `-pthread` flag가 포함되어 있습니다.

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex11.out
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
cd ex11-basic-thread
make
```

This will compile the example and create an executable named `ex11.out`. When you run it, you'll see the output from both threads interleaved, demonstrating concurrent execution.

## What You Will Learn

**배울 내용**

- How to create and start threads using `std::thread`
- How to define thread functions using lambda expressions
- How to synchronize threads using `join()`
- How to use `std::this_thread::sleep_for` to pause thread execution
- Basic concepts of concurrent programming in C++

- `std::thread`를 사용하여 thread를 생성하고 시작하는 방법
- Lambda expression을 사용하여 thread function을 정의하는 방법
- `join()`을 사용하여 thread를 동기화하는 방법
- `std::this_thread::sleep_for`를 사용하여 thread 실행을 일시 중지하는 방법
- C++에서 동시성 프로그래밍의 기본 개념

This example provides a practical introduction to multithreading in modern C++, demonstrating how to create and manage concurrent operations in your programs.

이 예제는 modern C++의 multithreading에 대한 실용적인 소개를 제공하며, 프로그램에서 동시 작업을 생성하고 관리하는 방법을 보여줍니다.
