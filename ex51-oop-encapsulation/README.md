# Encapsulation in Object-Oriented Programming with C++

This example demonstrates the principle of encapsulation in object-oriented programming using C++. Encapsulation is one of the four fundamental OOP concepts and involves bundling data and methods that operate on that data within a single unit (class) and restricting direct access to some of the object's components.

이 예제는 C++를 사용하여 객체 지향 프로그래밍의 encapsulation(캡슐화) 원리를 보여줍니다. Encapsulation은 네 가지 기본 OOP 개념 중 하나로, 데이터와 그 데이터를 조작하는 method를 단일 unit(class) 내에 묶고 객체의 일부 component에 대한 직접 접근을 제한하는 것을 포함합니다.

## Files

- **ex51.cpp**: This file contains the C++ code that demonstrates encapsulation through a simple `Counter` class.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates encapsulation:

```cpp
#include <iostream>

class Counter {
private:
    // Single private member variable
    int count;
    
public:
    // Constructor
    Counter(int initialValue = 0) : count(initialValue) {
    }
    
    // Method to increment the value
    void increment() {
        count++;
    }
    
    // Method to decrement the value
    void decrement() {
        if (count > 0) {  // Prevent negative values
            count--;
        }
    }
    
    // Method to read the current value
    int getValue() const {
        return count;
    }
};

int main() {
    Counter counter(5);
    
    std::cout << "Initial value: " << counter.getValue() << "\n";
    
    counter.increment();
    std::cout << "After increment: " << counter.getValue() << "\n";
    
    counter.decrement();
    std::cout << "After decrement: " << counter.getValue() << "\n";
    
    return 0;
}
```

This code shows:
1. A `Counter` class that encapsulates a single integer value
2. Private data member (`count`) that cannot be accessed directly from outside the class
3. Public methods that provide controlled access to the private data
4. Data validation in the `decrement()` method to ensure the counter never becomes negative

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex51-oop-encapsulation` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex51-oop-encapsulation` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex51.out
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
cd ex51-oop-encapsulation
make
```

This will compile the example and create an executable named `ex51.out`. When you run it, you'll see the output showing the counter's value after various operations, demonstrating how encapsulation allows controlled access to the object's state.

## What You Will Learn

**배울 내용**

- The concept of encapsulation in object-oriented programming
- How to implement encapsulation in C++ using access specifiers (private, public)
- How to create a class with private data members and public methods
- How to use constructors to initialize objects
- How to implement data validation to maintain object invariants
- The benefits of encapsulation for code maintainability and robustness

- 객체 지향 프로그래밍의 encapsulation 개념
- Access specifier(private, public)를 사용하여 C++에서 encapsulation을 구현하는 방법
- Private data member와 public method를 가진 class를 생성하는 방법
- Constructor를 사용하여 객체를 초기화하는 방법
- 객체 불변성을 유지하기 위한 데이터 유효성 검증 구현 방법
- 코드 유지보수성과 견고성을 위한 encapsulation의 이점

This example provides a practical introduction to encapsulation in C++, demonstrating how it helps create more maintainable and robust code by hiding implementation details and providing controlled access to an object's state.

이 예제는 C++의 encapsulation에 대한 실용적인 소개를 제공하며, 구현 세부사항을 숨기고 객체 상태에 대한 제어된 접근을 제공함으로써 더 유지보수하기 쉽고 견고한 코드를 만드는 방법을 보여줍니다.