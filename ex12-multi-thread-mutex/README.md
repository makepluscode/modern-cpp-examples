# Multi-Threading with Mutex in C++

This example demonstrates how to use mutexes in C++ to protect shared resources in a multi-threaded environment. When multiple threads access and modify shared data concurrently, race conditions can occur, leading to unpredictable results. Mutexes (mutual exclusion objects) provide a synchronization mechanism to ensure that only one thread can access the shared resource at a time.

이 예제는 multi-thread 환경에서 공유 resource를 보호하기 위해 C++에서 mutex를 사용하는 방법을 보여줍니다. 여러 thread가 공유 data에 동시에 접근하고 수정할 때 race condition이 발생하여 예측할 수 없는 결과가 나올 수 있습니다. Mutex(mutual exclusion object)는 한 번에 하나의 thread만 공유 resource에 접근할 수 있도록 보장하는 동기화 mechanism을 제공합니다.

## Files

- **ex12.cpp**: This file contains the C++ code that demonstrates how to use `std::mutex` and `std::lock_guard` to protect a shared counter in a multi-threaded environment.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates mutex-based thread synchronization:

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void increment(int& counter, std::mutex& mtx) {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Synchronize using mutex
        ++counter; // Safely increment counter
    }
}

int main() {
    int counter = 0; // Shared resource
    std::mutex mtx;  // Mutex object

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment, std::ref(counter), std::ref(mtx)); // Create multiple threads
    }

    for (auto& t : threads) {
        t.join(); // Wait for all threads to finish
    }

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
```

This code shows:
1. How to create a shared resource (counter) that multiple threads will access
2. How to use `std::mutex` to protect the shared resource
3. How to use `std::lock_guard` for RAII-style mutex locking and unlocking
4. How to create multiple threads that all access the same shared resource
5. How to pass references to threads using `std::ref`

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex12-multi-thread-mutex` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex12-multi-thread-mutex` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```
   Note: The Makefile includes the `-pthread` flag required for threading.

   참고: Makefile에는 threading에 필요한 `-pthread` flag가 포함되어 있습니다.

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex12.out
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
cd ex12-multi-thread-mutex
make
```

This will compile the example and create an executable named `ex12.out`. When you run it, you'll see that the final counter value is exactly 100,000 (10 threads × 10,000 increments), demonstrating that the mutex successfully prevented race conditions.

## What You Will Learn

**배울 내용**

- How to use `std::mutex` to protect shared resources in multi-threaded code
- How to use `std::lock_guard` for automatic mutex management
- How to pass references to threads using `std::ref`
- How to create and manage multiple threads with `std::vector<std::thread>`
- The importance of synchronization in concurrent programming

- Multi-thread 코드에서 공유 resource를 보호하기 위해 `std::mutex`를 사용하는 방법
- 자동 mutex 관리를 위해 `std::lock_guard`를 사용하는 방법
- `std::ref`를 사용하여 thread에 참조를 전달하는 방법
- `std::vector<std::thread>`로 여러 thread를 생성하고 관리하는 방법
- 동시성 프로그래밍에서 동기화의 중요성

This example provides practical insights into thread synchronization in C++, demonstrating how to safely share and modify data across multiple threads without race conditions.

이 예제는 C++에서 thread 동기화에 대한 실용적인 통찰을 제공하며, race condition 없이 여러 thread에서 data를 안전하게 공유하고 수정하는 방법을 보여줍니다.
