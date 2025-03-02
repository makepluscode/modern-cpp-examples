# Publisher-Subscriber Pattern in Modern C++

This example demonstrates the Publisher-Subscriber (Pub-Sub) design pattern implemented in modern C++. The Pub-Sub pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. This pattern promotes loose coupling between components.

## Files

- **ex82.cpp**: This file contains the C++ code that demonstrates a simple implementation of the Publisher-Subscriber pattern.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates a Publisher-Subscriber implementation:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Subscriber interface
class Subscriber {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Subscriber() = default;
};

// Publisher class
class Publisher {
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers;

public:
    void subscribe(const std::shared_ptr<Subscriber>& sub) {
        subscribers.push_back(sub);
    }

    void notify(const std::string& message) {
        for (const auto& sub : subscribers) {
            sub->update(message);
        }
    }
};

// Concrete subscriber
class ConcreteSubscriber : public Subscriber {
private:
    std::string name;

public:
    explicit ConcreteSubscriber(std::string n) : name(std::move(n)) {}

    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};
```

This code shows:
1. A `Subscriber` interface with a virtual `update()` method
2. A `Publisher` class that maintains a list of subscribers and notifies them of changes
3. A `ConcreteSubscriber` class that implements the `Subscriber` interface
4. The use of `std::shared_ptr` for memory management of subscribers

## Common Use Cases

- Event handling systems
- Message brokers
- User interface updates
- Distributed systems
- Notification services
- Observer pattern implementations

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex82-pub-sub-pattern` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex82.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex82-pub-sub-pattern
make
```

This will compile the example and create an executable named `ex82.out`. When you run it, you'll see the output showing how multiple subscribers receive the same message from the publisher.

## What You Will Learn

- How to implement the Publisher-Subscriber design pattern in modern C++
- How to use interfaces (abstract classes) to define contracts
- How to manage dynamic objects using smart pointers
- How to implement one-to-many relationships between objects
- How to achieve loose coupling between components
- The practical applications of the Pub-Sub pattern

This example provides a practical introduction to the Publisher-Subscriber design pattern in C++, demonstrating how it can be used to create flexible and maintainable event-driven systems.
