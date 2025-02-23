# Smart Pointer Ownership Example

This example demonstrates the concept of ownership transfer in smart pointers, specifically using `std::unique_ptr`. It highlights the correct way to transfer ownership using move semantics and the error that occurs when attempting to copy a `std::unique_ptr`.

## Files

- **ex4.cpp**: This file contains the C++ code that demonstrates the use of `std::unique_ptr` and how to transfer ownership using `std::move`.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex4-smart_pointer_ownership` directory. Run the following command to compile the code:
   ```bash
   make
   ```

   By default, the code uses `std::move` to transfer ownership. If you want to see the compilation error caused by attempting to copy a `std::unique_ptr`, modify the `Makefile` to define the `IMPLICITLY_DELECTED_COPY_ERROR` macro by adding `-DIMPLICITLY_DELECTED_COPY_ERROR` to the `CXXFLAGS`.

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./smart_pointer_ownership
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## What You Will Learn

- **Ownership Transfer**: Understand how to transfer ownership of a `std::unique_ptr` using `std::move`.
- **Copy Error**: Learn why copying a `std::unique_ptr` results in a compilation error and how to avoid it.
- **Smart Pointer Management**: Gain insights into managing resources with smart pointers in C++.

This example provides a practical demonstration of smart pointer ownership and the importance of move semantics in modern C++.
