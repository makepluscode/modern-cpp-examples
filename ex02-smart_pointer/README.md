# Smart Pointers in Modern C++

This example demonstrates how to use smart pointers in C++. Smart pointers help manage memory automatically and prevent memory leaks.

## Files

- **ex2.cpp**: This file contains the C++ code that demonstrates the use of `std::unique_ptr` and `std::shared_ptr` to manage object lifetimes.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `02-smart_pointer` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./smart_pointer_example
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## What You Will Learn

- How to use `std::unique_ptr` for exclusive ownership of resources.
- How to use `std::shared_ptr` for shared ownership and reference counting.
- Basic usage of a Makefile to compile and clean a C++ project.

This example provides an introduction to smart pointers, which are a key feature in modern C++ for safe and efficient memory management.
