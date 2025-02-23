# Weak Pointer Example

This example demonstrates the use of `std::weak_ptr` to prevent circular references in a linked structure. By using `std::weak_ptr`, we can avoid memory leaks that occur when `std::shared_ptr` objects form a cycle.

## Files

- **ex05.cpp**: This file contains the C++ code that demonstrates how to use `std::weak_ptr` to break circular references between `std::shared_ptr` objects.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex05-smart_pointer_weak_ptr` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex05.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## What You Will Learn

- **Circular References**: Understand how circular references can lead to memory leaks when using `std::shared_ptr`.
- **Using `std::weak_ptr`**: Learn how `std::weak_ptr` can be used to break cycles and prevent memory leaks by not contributing to the reference count.
- **Smart Pointer Management**: Gain insights into managing resources with smart pointers in C++.

This example provides a practical demonstration of how to use `std::weak_ptr` to manage memory effectively in complex data structures.
