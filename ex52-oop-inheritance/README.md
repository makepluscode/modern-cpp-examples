# Inheritance and Polymorphism in Object-Oriented Programming with C++

This example demonstrates inheritance and polymorphism, two fundamental concepts in object-oriented programming, using C++. Inheritance allows a class to inherit attributes and methods from another class, while polymorphism enables objects of different classes to be treated as objects of a common base class.

이 예제는 C++를 사용하여 객체 지향 프로그래밍의 두 가지 기본 개념인 inheritance(상속)와 polymorphism(다형성)을 보여줍니다. Inheritance는 class가 다른 class로부터 attribute와 method를 상속받을 수 있게 하며, polymorphism은 서로 다른 class의 객체들을 공통 base class의 객체로 취급할 수 있게 합니다.

## Files

- **ex52.cpp**: This file contains the C++ code that demonstrates inheritance and polymorphism through an `Animal` base class and derived `Dog` and `Cat` classes.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates inheritance and polymorphism:

```cpp
#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    virtual ~Animal() = default;  // Virtual destructor, (virtual ~Animal() { })
    virtual void makeSound() = 0;  // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Using smart pointers
    auto dog = std::make_unique<Dog>();
    auto cat = std::make_unique<Cat>();
    
    dog->makeSound();  // Output: Woof!
    cat->makeSound();  // Output: Meow!

    return 0;
}
```

This code shows:
1. An abstract base class `Animal` with a pure virtual function `makeSound()`
2. Two derived classes `Dog` and `Cat` that inherit from `Animal` and override the `makeSound()` function
3. The use of `virtual` and `override` keywords to enable polymorphism
4. Smart pointers (`std::unique_ptr`) to manage memory automatically
5. Calling the overridden methods to demonstrate polymorphic behavior

## How to Compile and Run

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex52-oop-inheritance` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex52-oop-inheritance` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex52.out
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
cd ex52-oop-inheritance
make
```

This will compile the example and create an executable named `ex52.out`. When you run it, you'll see the output showing different sounds made by the dog and cat objects, demonstrating polymorphic behavior.

## What You Will Learn

**배울 내용**

- The concept of inheritance in object-oriented programming
- How to create abstract base classes with pure virtual functions
- How to implement derived classes that override base class methods
- The importance of virtual destructors in polymorphic class hierarchies
- How to use the `override` keyword to ensure correct method overriding
- How to use smart pointers to manage polymorphic objects
- The basics of runtime polymorphism in C++

- 객체 지향 프로그래밍의 inheritance 개념
- Pure virtual function을 가진 abstract base class를 생성하는 방법
- Base class method를 override하는 derived class를 구현하는 방법
- Polymorphic class hierarchy에서 virtual destructor의 중요성
- 올바른 method overriding을 보장하기 위한 `override` keyword 사용법
- Polymorphic 객체를 관리하기 위한 smart pointer 사용법
- C++의 runtime polymorphism 기초

This example provides a practical introduction to inheritance and polymorphism in C++, demonstrating how these concepts enable code reuse and flexibility in object-oriented design.

이 예제는 C++의 inheritance와 polymorphism에 대한 실용적인 소개를 제공하며, 이러한 개념들이 어떻게 객체 지향 설계에서 코드 재사용과 유연성을 가능하게 하는지 보여줍니다.