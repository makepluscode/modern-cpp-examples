# Inheritance and Polymorphism in Object-Oriented Programming with C++

This example demonstrates inheritance and polymorphism, two fundamental concepts in object-oriented programming, using C++. Inheritance allows a class to inherit attributes and methods from another class, while polymorphism enables objects of different classes to be treated as objects of a common base class.

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

1. **Compile the Code**: Open a terminal and navigate to the `ex52-oop-inheritance` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex52.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
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

- The concept of inheritance in object-oriented programming
- How to create abstract base classes with pure virtual functions
- How to implement derived classes that override base class methods
- The importance of virtual destructors in polymorphic class hierarchies
- How to use the `override` keyword to ensure correct method overriding
- How to use smart pointers to manage polymorphic objects
- The basics of runtime polymorphism in C++

This example provides a practical introduction to inheritance and polymorphism in C++, demonstrating how these concepts enable code reuse and flexibility in object-oriented design.