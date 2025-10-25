# Singleton Pattern in Modern C++

This example demonstrates the Singleton design pattern implemented in modern C++. The Singleton pattern ensures a class has only one instance and provides a global point of access to it. This pattern is useful when exactly one object is needed to coordinate actions across the system.

이 예제는 modern C++로 구현된 Singleton design pattern을 보여줍니다. Singleton pattern은 class가 단 하나의 instance만 가지도록 보장하고 그것에 대한 전역 접근 지점을 제공합니다. 이 pattern은 시스템 전체에서 작업을 조율하기 위해 정확히 하나의 객체가 필요할 때 유용합니다.

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

**일반적인 사용 사례**

- Hardware interface management (UART, GPIO)
- Resource managers
- Configuration managers
- Logger systems
- Database connections

- Hardware interface 관리 (UART, GPIO)
- Resource manager
- Configuration manager
- Logger system
- Database connection

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex81-singleton-pattern` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex81-singleton-pattern` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex81.out
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
cd ex81-singleton-pattern
make
```

This will compile the example and create an executable named `ex81.out`. When you run it, you'll see the output showing that both instances have the same memory address, confirming that only one instance of the Singleton class exists.

## What You Will Learn

**배울 내용**

- How to implement the Singleton design pattern in modern C++
- How to use static local variables for thread-safe initialization (C++11 feature)
- How to use `std::shared_ptr` for memory management
- How to prevent direct instantiation using private constructors
- The practical applications of the Singleton pattern

- Modern C++에서 Singleton design pattern을 구현하는 방법
- Thread-safe 초기화를 위해 static local 변수를 사용하는 방법 (C++11 기능)
- Memory 관리를 위해 `std::shared_ptr`을 사용하는 방법
- Private constructor를 사용하여 직접 instantiation을 방지하는 방법
- Singleton pattern의 실용적인 응용

This example provides a practical introduction to the Singleton design pattern in C++, demonstrating how it can be used to ensure a class has only one instance throughout the application's lifecycle.

이 예제는 C++의 Singleton design pattern에 대한 실용적인 소개를 제공하며, application의 생명주기 동안 class가 단 하나의 instance만 가지도록 보장하는 데 어떻게 사용될 수 있는지 보여줍니다.
