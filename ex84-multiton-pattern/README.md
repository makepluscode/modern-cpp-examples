# Multiton Pattern in Modern C++

This example demonstrates the Multiton design pattern implemented in modern C++. The Multiton pattern is an extension of the Singleton pattern that manages a map of named instances, ensuring only one instance exists per key. This pattern is particularly useful in embedded systems and hardware interface management where multiple independent resources need to be controlled.

이 예제는 modern C++로 구현된 Multiton design pattern을 보여줍니다. Multiton pattern은 Singleton pattern의 확장으로, 이름이 지정된 instance들의 map을 관리하여 key마다 하나의 instance만 존재하도록 보장합니다. 이 pattern은 여러 독립적인 resource를 제어해야 하는 embedded system과 hardware interface 관리에 특히 유용합니다.

## Files

- **ex84.cpp**: This file contains the C++ code that demonstrates a thread-safe implementation of the Multiton pattern for GPIO pin control using `std::map` and `std::unique_ptr`.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates a Multiton implementation for GPIO pins:

```cpp
#include <iostream>
#include <map>
#include <memory>

class GpioPin {
public:
    static GpioPin& getInstance(int pinNumber) {
        static std::map<int, std::unique_ptr<GpioPin>> instances;

        if (instances.find(pinNumber) == instances.end()) {
            instances[pinNumber] = std::unique_ptr<GpioPin>(new GpioPin(pinNumber));
        }

        return *instances[pinNumber];
    }

    void setHigh() {
        state = true;
        std::cout << "[GPIO" << pin << "] Set to HIGH" << std::endl;
    }

    void setLow() {
        state = false;
        std::cout << "[GPIO" << pin << "] Set to LOW" << std::endl;
    }

private:
    int pin;
    bool state;

    explicit GpioPin(int pinNumber) : pin(pinNumber), state(false) {
        std::cout << "GPIO pin " << pin << " initialized" << std::endl;
    }
};

int main() {
    GpioPin& led = GpioPin::getInstance(13);
    GpioPin& motor = GpioPin::getInstance(5);

    led.setHigh();
    motor.setHigh();

    return 0;
}
```

This code shows:
1. A Multiton class with a private constructor to prevent direct instantiation
2. A static `getInstance()` method that takes a key (pin number) and returns the corresponding instance
3. The use of `std::map` to store multiple instances indexed by key
4. The use of `std::unique_ptr` for automatic memory management
5. How multiple calls with the same key return the same instance

이 코드는 다음을 보여줍니다:
1. 직접 instantiation을 방지하기 위한 private constructor를 가진 Multiton class
2. Key (pin 번호)를 받아 해당 instance를 반환하는 static `getInstance()` method
3. Key로 indexing된 여러 instance를 저장하기 위한 `std::map` 사용
4. 자동 memory 관리를 위한 `std::unique_ptr` 사용
5. 같은 key로 여러 번 호출하면 같은 instance가 반환되는 방식

## Difference from Singleton

**Singleton vs Multiton**

The Singleton pattern maintains exactly one instance globally, while the Multiton pattern maintains one instance per key.

Singleton pattern은 전역적으로 정확히 하나의 instance를 유지하는 반면, Multiton pattern은 key마다 하나의 instance를 유지합니다.

**Singleton Example:**
```cpp
Singleton& instance = Singleton::getInstance();  // Only one instance
```

**Multiton Example:**
```cpp
GpioPin& pin13 = GpioPin::getInstance(13);  // Instance for pin 13
GpioPin& pin5 = GpioPin::getInstance(5);    // Instance for pin 5
GpioPin& pin7 = GpioPin::getInstance(7);    // Instance for pin 7
```

## Common Use Cases

**일반적인 사용 사례**

- GPIO pin controllers in embedded systems
- Hardware peripheral interfaces (UART, SPI, I2C ports)
- Database connection pools with multiple databases
- Cache managers with multiple cache regions
- Network socket managers with port numbers
- Resource pools indexed by identifier

- Embedded system의 GPIO pin controller
- Hardware 주변장치 interface (UART, SPI, I2C port)
- 여러 database를 가진 database connection pool
- 여러 cache 영역을 가진 cache manager
- Port 번호를 가진 network socket manager
- 식별자로 indexing된 resource pool

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex84-multiton-pattern` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex84-multiton-pattern` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex84.out
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
cd ex84-multiton-pattern
make
./ex84.out
```

This will compile the example and create an executable named `ex84.out`. When you run it, you'll see the output showing that:
- Three separate GPIO pin instances are created (pins 13, 5, and 7)
- Each pin maintains its own state independently
- Requesting the same pin number twice returns the same instance (same memory address)

## What You Will Learn

**배울 내용**

- How to implement the Multiton design pattern in modern C++
- How to use `std::map` to manage multiple instances indexed by key
- How to use `std::unique_ptr` for automatic memory management
- How to prevent copying and moving using deleted copy/move constructors
- The difference between Singleton and Multiton patterns
- Practical applications in embedded systems and hardware control

- Modern C++에서 Multiton design pattern을 구현하는 방법
- Key로 indexing된 여러 instance를 관리하기 위해 `std::map`을 사용하는 방법
- 자동 memory 관리를 위해 `std::unique_ptr`을 사용하는 방법
- 삭제된 copy/move constructor를 사용하여 복사와 이동을 방지하는 방법
- Singleton과 Multiton pattern의 차이점
- Embedded system과 hardware 제어에서의 실용적인 응용

## Key Advantages

**주요 장점**

The Multiton pattern provides several benefits for hardware resource management:
- Prevents hardware conflicts by ensuring only one instance per resource
- Maintains state consistency across the application
- Resource-efficient with lazy initialization
- Type-safe with compile-time key validation

Multiton pattern은 hardware resource 관리에 여러 이점을 제공합니다:
- Resource마다 하나의 instance만 보장하여 hardware 충돌 방지
- Application 전체에서 상태 일관성 유지
- Lazy initialization으로 resource 효율적
- Compile-time key 검증으로 type-safe

This example provides a practical introduction to the Multiton design pattern in C++, demonstrating how it can be used to manage multiple named instances of a class, particularly useful for hardware interface management in embedded systems.

이 예제는 C++의 Multiton design pattern에 대한 실용적인 소개를 제공하며, 특히 embedded system의 hardware interface 관리에 유용한 class의 여러 이름이 지정된 instance를 관리하는 데 어떻게 사용될 수 있는지 보여줍니다.
