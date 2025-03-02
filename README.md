# Modern C++ Examples

This repository contains a collection of examples demonstrating modern C++ features, object-oriented programming concepts, and design patterns. Each example is designed to be simple, self-contained, and educational, making it ideal for learning and reference purposes.

## Overview

The examples are organized into several categories:

### Modern C++ Features (ex01-ex3X)
- **ex01-auto_type_deduction**: Demonstrates type deduction with the `auto` keyword
- **ex02-smart_pointer**: Shows basic usage of `std::unique_ptr` and `std::shared_ptr`
- **ex03-smart_pointer_double_destruct**: Illustrates a common pitfall with smart pointers
- **ex04-smart_pointer_ownership**: Demonstrates ownership transfer with `std::unique_ptr`
- **ex05-smart_pointer_weak_ptr**: Shows how to break circular references with `std::weak_ptr`
- **ex21-lambda_function**: Introduces lambda functions in C++
- **ex22-lambda_capture**: Demonstrates capturing variables in lambda functions
- **ex31-null_ptr**: Explains the difference between `NULL` and `nullptr`

### Concurrency (ex11-ex1X)
- **ex11-basic-thread**: Demonstrates basic thread creation and synchronization
- **ex12-multi-thread-mutex**: Shows how to use mutexes to protect shared resources

### Object-Oriented Programming (ex51-ex5X)
- **ex51-oop-encapsulation**: Demonstrates encapsulation in OOP
- **ex52-oop-inheritance**: Shows inheritance and polymorphism
- **ex53-oop-abstraction**: Illustrates abstraction with abstract base classes

### Design Patterns (ex81-ex8X)
- **ex81-singleton-pattern**: Implements the Singleton pattern
- **ex82-pub-sub-pattern**: Demonstrates the Publisher-Subscriber pattern
- **ex83-state-pattern**: Shows the State pattern implementation

## Getting Started

### Prerequisites
- A C++11 (or later) compatible compiler (GCC, Clang, MSVC)
- Make build system

### How to Build and Run

Each example has its own directory with a Makefile. To build and run an example:

```bash
# Clone the repository
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd modern-cpp-examples

# Navigate to an example directory
cd ex01-auto_type_deduction

# Build the example
make

# Run the example
./ex01.out

# Clean up
make clean
```

## Learning Path

If you're new to modern C++, we recommend following this learning path:

1. Start with basic modern C++ features (ex01, ex31)
2. Learn about smart pointers and memory management (ex02-ex05)
3. Explore functional programming with lambdas (ex21-ex22)
4. Study object-oriented programming concepts (ex51-ex53)
5. Dive into concurrency (ex11-ex12)
6. Finish with design patterns (ex81-ex83)

Each example includes detailed comments and a README file explaining the concepts and how the code works.

## Contributing

Contributions are welcome! If you'd like to add more examples or improve existing ones, please feel free to submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- These examples are inspired by modern C++ best practices and common design patterns
- Thanks to all contributors who have helped improve these examples
