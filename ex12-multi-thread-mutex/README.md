# Multi-Threading with Mutex in C++

This example demonstrates how to use mutexes in C++ to protect shared resources in a multi-threaded environment. When multiple threads access and modify shared data concurrently, race conditions can occur, leading to unpredictable results. Mutexes (mutual exclusion objects) provide a synchronization mechanism to ensure that only one thread can access the shared resource at a time.

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

1. **Compile the Code**: Open a terminal and navigate to the `ex12-multi-thread-mutex` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex12.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
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

- How to use `std::mutex` to protect shared resources in multi-threaded code
- How to use `std::lock_guard` for automatic mutex management
- How to pass references to threads using `std::ref`
- How to create and manage multiple threads with `std::vector<std::thread>`
- The importance of synchronization in concurrent programming

This example provides practical insights into thread synchronization in C++, demonstrating how to safely share and modify data across multiple threads without race conditions.
