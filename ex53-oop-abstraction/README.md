# Abstraction in Object-Oriented Programming with C++

This example demonstrates abstraction, one of the four fundamental principles of object-oriented programming, using C++. Abstraction involves hiding complex implementation details and showing only the necessary features of an object. This example uses geometric shapes to illustrate how abstract base classes and inheritance can be used to implement abstraction.

## Files

- **ex53.cpp**: This file contains the C++ code that demonstrates abstraction through a `Shape` base class and derived `Circle` and `Rectangle` classes.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates abstraction:

```cpp
#include <iostream>

// Abstract base class for shapes
class Shape {
private:
    std::string color;

public:
    // Constructor with color parameter
    Shape(const std::string& c) : color(c) {}

    // Pure virtual function for calculating area
    virtual double getArea() const = 0;
    
    // Virtual function to display shape information
    virtual void printInfo() const {
        std::cout << "Color: " << color << "\n"
                  << "Area: " << getArea() << "\n";
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor with color and radius
    Circle(const std::string& c, double r) 
        : Shape(c), radius(r) {}

    // Override area calculation for circle
    double getArea() const override {
        return 3.14 * radius * radius;
    }

    // Override info display for circle
    void printInfo() const override {
        std::cout << "Circle Info:\n";
        Shape::printInfo();
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor with color, width and height
    Rectangle(const std::string& c, double w, double h) 
        : Shape(c), width(w), height(h) {}

    // Override area calculation for rectangle
    double getArea() const override {
        return width * height;
    }

    // Override info display for rectangle
    void printInfo() const override {
        std::cout << "Rectangle Info:\n";
        Shape::printInfo();
    }
};
```

This code shows:
1. An abstract base class `Shape` that defines a common interface for all shapes
2. A pure virtual function `getArea()` that must be implemented by derived classes
3. Derived classes `Circle` and `Rectangle` that provide specific implementations
4. How abstraction allows treating different shapes uniformly through their common interface

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex53-oop-abstraction` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex53.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex53-oop-abstraction
make
```

This will compile the example and create an executable named `ex53.out`. When you run it, you'll see the output showing information about different shapes, demonstrating how abstraction allows working with different objects through a common interface.

## What You Will Learn

- The concept of abstraction in object-oriented programming
- How to create abstract base classes with pure virtual functions
- How to implement concrete derived classes
- How to use virtual functions to enable polymorphic behavior
- How abstraction helps in creating flexible and maintainable code
- How to use inheritance to implement "is-a" relationships

This example provides a practical introduction to abstraction in C++, demonstrating how it helps create more modular and extensible code by defining clear interfaces and hiding implementation details. 