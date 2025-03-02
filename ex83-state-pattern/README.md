# State Design Pattern in Modern C++

This example demonstrates the State design pattern implemented in modern C++. The State pattern allows an object to alter its behavior when its internal state changes, appearing as if the object changed its class. This pattern is particularly useful for implementing state machines in an object-oriented way.

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

- State machines
- Workflow systems
- Game character behavior
- UI control states
- Network connection management
- Document editing modes

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex83-state-pattern` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex83.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
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

- How to implement the State design pattern in modern C++
- How to use interfaces (abstract classes) to define state behaviors
- How to manage state transitions in an object-oriented way
- How to use forward declarations to resolve circular dependencies
- How to use smart pointers for memory management
- How to separate state-specific behavior from the context object
- The practical applications of the State pattern

This example provides a practical introduction to the State design pattern in C++, demonstrating how it can be used to create maintainable and flexible state-dependent behavior.
