# Basic Thread Usage in Modern C++

This example demonstrates the fundamental usage of threads in modern C++ using the `std::thread` class introduced in C++11. Multithreading allows programs to perform multiple operations concurrently, improving performance and responsiveness in many applications. This example shows how to create, execute, and synchronize basic threads.

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

1. **Compile the Code**: Open a terminal and navigate to the `ex11-basic-thread` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex11.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
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

- How to create and start threads using `std::thread`
- How to define thread functions using lambda expressions
- How to synchronize threads using `join()`
- How to use `std::this_thread::sleep_for` to pause thread execution
- Basic concepts of concurrent programming in C++

This example provides a practical introduction to multithreading in modern C++, demonstrating how to create and manage concurrent operations in your programs.
