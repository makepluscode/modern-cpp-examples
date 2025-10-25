# Publisher-Subscriber Pattern in Modern C++

This example demonstrates the Publisher-Subscriber (Pub-Sub) design pattern implemented in modern C++. The Pub-Sub pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. This pattern promotes loose coupling between components.

이 예제는 modern C++로 구현된 Publisher-Subscriber (Pub-Sub) design pattern을 보여줍니다. Pub-Sub pattern은 객체들 간의 일대다 의존성을 정의하여, 한 객체의 상태가 변경될 때 모든 의존 객체들이 자동으로 알림을 받고 업데이트되도록 합니다. 이 pattern은 component들 간의 느슨한 결합을 촉진합니다.

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

**일반적인 사용 사례**

- Event handling systems
- Message brokers
- User interface updates
- Distributed systems
- Notification services
- Observer pattern implementations

- Event 처리 system
- Message broker
- User interface 업데이트
- Distributed system
- Notification service
- Observer pattern 구현

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex82-pub-sub-pattern` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex82-pub-sub-pattern` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex82.out
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
cd ex82-pub-sub-pattern
make
```

This will compile the example and create an executable named `ex82.out`. When you run it, you'll see the output showing how multiple subscribers receive the same message from the publisher.

## What You Will Learn

**배울 내용**

- How to implement the Publisher-Subscriber design pattern in modern C++
- How to use interfaces (abstract classes) to define contracts
- How to manage dynamic objects using smart pointers
- How to implement one-to-many relationships between objects
- How to achieve loose coupling between components
- The practical applications of the Pub-Sub pattern

- Modern C++에서 Publisher-Subscriber design pattern을 구현하는 방법
- Interface (abstract class)를 사용하여 contract를 정의하는 방법
- Smart pointer를 사용하여 동적 객체를 관리하는 방법
- 객체들 간의 일대다 관계를 구현하는 방법
- Component들 간의 느슨한 결합을 달성하는 방법
- Pub-Sub pattern의 실용적인 응용

This example provides a practical introduction to the Publisher-Subscriber design pattern in C++, demonstrating how it can be used to create flexible and maintainable event-driven systems.

이 예제는 C++의 Publisher-Subscriber design pattern에 대한 실용적인 소개를 제공하며, 유연하고 유지보수 가능한 event-driven system을 생성하는 데 어떻게 사용될 수 있는지 보여줍니다.
