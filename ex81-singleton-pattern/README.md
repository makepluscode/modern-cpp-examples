# Singleton Pattern in Modern C++

This example demonstrates the Singleton design pattern implemented in modern C++. The Singleton pattern ensures a class has only one instance and provides a global point of access to it. This pattern is useful when exactly one object is needed to coordinate actions across the system.

## Files

- **ex81.cpp**: This file contains the C++ code that demonstrates a thread-safe implementation of the Singleton pattern using `std::shared_ptr`.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates a Singleton implementation:

```cpp
#include <iostream>
#include <memory>

class Singleton {
public:
    static std::shared_ptr<Singleton> getInstance() {
        static std::shared_ptr<Singleton> instance(new Singleton());
        return instance;
    }

    void printMessage(const std::string& message) const {
        std::cout << message << std::endl;
    }

private:
    Singleton() {
        std::cout << "Constructor called" << std::endl;
    }
};

int main() {
    auto instance1 = Singleton::getInstance();
    auto instance2 = Singleton::getInstance();

    instance1->printMessage("Testing singleton...");

    std::cout << "Address of instance1: " << instance1.get() << std::endl;
    std::cout << "Address of instance2: " << instance2.get() << std::endl;

    return 0;
}
```

This code shows:
1. A Singleton class with a private constructor to prevent direct instantiation
2. A static `getInstance()` method that returns the single instance
3. The use of `std::shared_ptr` for automatic memory management
4. How multiple calls to `getInstance()` return the same instance

## Common Use Cases

- Hardware interface management (UART, GPIO)
- Resource managers
- Configuration managers
- Logger systems
- Database connections

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex81-singleton-pattern` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex81.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex81-singleton-pattern
make
```

This will compile the example and create an executable named `ex81.out`. When you run it, you'll see the output showing that both instances have the same memory address, confirming that only one instance of the Singleton class exists.

## What You Will Learn

- How to implement the Singleton design pattern in modern C++
- How to use static local variables for thread-safe initialization (C++11 feature)
- How to use `std::shared_ptr` for memory management
- How to prevent direct instantiation using private constructors
- The practical applications of the Singleton pattern

This example provides a practical introduction to the Singleton design pattern in C++, demonstrating how it can be used to ensure a class has only one instance throughout the application's lifecycle.
