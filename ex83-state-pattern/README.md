# State Design Pattern in Modern C++

This example demonstrates the State design pattern implemented in modern C++. The State pattern allows an object to alter its behavior when its internal state changes, appearing as if the object changed its class. This pattern is particularly useful for implementing state machines in an object-oriented way.

이 예제는 modern C++로 구현된 State design pattern을 보여줍니다. State pattern은 객체의 내부 상태가 변경될 때 객체의 동작을 변경할 수 있게 하여, 마치 객체의 class가 변경된 것처럼 보이게 합니다. 이 pattern은 객체 지향 방식으로 state machine을 구현하는 데 특히 유용합니다.

## Files

- **ex83.cpp**: This file contains the C++ code that demonstrates a simple implementation of the State pattern using a device with power states.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates the State pattern implementation:

```cpp
#include <iostream>
#include <memory>

// Forward declaration
class Device;

// State interface
class PowerState {
public:
    virtual void powerButton(Device& device) = 0;
    virtual ~PowerState() = default;
};

// Device class
class Device {
private:
    std::shared_ptr<PowerState> state;

public:
    Device() {
        state = std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>());
        std::cout << "Device initialized in Standby\n";
    }

    void setState(const std::shared_ptr<PowerState>& newState) {
        state = newState;
    }

    void pressPowerButton() {
        state->powerButton(*this);
    }
};

// Concrete states
class StandbyState : public PowerState {
public:
    void powerButton(Device& device) override {
        std::cout << "Turning ON\n";
        device.setState(std::static_pointer_cast<PowerState>(std::make_shared<OnState>()));
    }
};

class OnState : public PowerState {
public:
    void powerButton(Device& device) override {
        std::cout << "Turning OFF\n";
        device.setState(std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>()));
    }
};
```

This code shows:
1. A `PowerState` interface that defines the behavior for different states
2. A `Device` class that maintains a reference to its current state
3. Concrete state classes (`StandbyState` and `OnState`) that implement specific behaviors
4. How the device's behavior changes based on its current state
5. The use of `std::shared_ptr` for memory management of state objects

## Common Use Cases

**일반적인 사용 사례**

- State machines
- Workflow systems
- Game character behavior
- UI control states
- Network connection management
- Document editing modes

- State machine
- Workflow system
- Game character 동작
- UI control 상태
- Network connection 관리
- Document 편집 mode

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex83-state-pattern` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex83-state-pattern` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex83.out
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
cd ex83-state-pattern
make
```

This will compile the example and create an executable named `ex83.out`. When you run it, you'll see the output showing how the device transitions between different states when the power button is pressed.

## What You Will Learn

**배울 내용**

- How to implement the State design pattern in modern C++
- How to use interfaces (abstract classes) to define state behaviors
- How to manage state transitions in an object-oriented way
- How to use forward declarations to resolve circular dependencies
- How to use smart pointers for memory management
- How to separate state-specific behavior from the context object
- The practical applications of the State pattern

- Modern C++에서 State design pattern을 구현하는 방법
- Interface (abstract class)를 사용하여 state 동작을 정의하는 방법
- 객체 지향 방식으로 state transition을 관리하는 방법
- Forward declaration을 사용하여 순환 의존성을 해결하는 방법
- Memory 관리를 위해 smart pointer를 사용하는 방법
- Context 객체에서 state별 동작을 분리하는 방법
- State pattern의 실용적인 응용

This example provides a practical introduction to the State design pattern in C++, demonstrating how it can be used to create maintainable and flexible state-dependent behavior.

이 예제는 C++의 State design pattern에 대한 실용적인 소개를 제공하며, 유지보수 가능하고 유연한 상태 의존적 동작을 생성하는 데 어떻게 사용될 수 있는지 보여줍니다.
