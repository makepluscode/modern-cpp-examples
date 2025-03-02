# Smart Pointer Double Destruction in C++

This example demonstrates a common pitfall when using smart pointers in C++: double destruction. When you manually delete a raw pointer obtained from a smart pointer, it leads to undefined behavior as the smart pointer will attempt to delete the same memory again when it goes out of scope. This example serves as a warning about improper usage of smart pointers and raw pointers together.

## Files

- **ex03.cpp**: This file contains the C++ code that demonstrates the double destruction problem when mixing smart pointers with manual memory management.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates the double destruction problem:

```cpp
// Create a smart pointer
auto sharedPtr1 = std::make_shared<MyClass>();
sharedPtr1->display();

// Get a raw pointer from the smart pointer
auto rawPtr = sharedPtr1.get();

// Manually delete the raw pointer (this is incorrect and dangerous)
delete rawPtr;

// When sharedPtr1 goes out of scope, it will try to delete the same memory again
```

This code shows an anti-pattern that should be avoided. The program will likely crash or exhibit undefined behavior because:
1. The raw pointer is manually deleted
2. The smart pointer will attempt to delete the same memory when it goes out of scope

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex03-smart_pointer_double_destruct` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex03.out
   ```
   Note: This program may crash or exhibit undefined behavior by design.

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex03-smart_pointer_double_destruct
make
```

This will compile the example and create an executable named `ex03.out`. When you run it, you'll likely see the program crash or exhibit undefined behavior, demonstrating the dangers of double destruction.

## What You Will Learn

- The dangers of mixing smart pointers with manual memory management.
- Why you should never manually delete a raw pointer obtained from a smart pointer.
- How double destruction leads to undefined behavior.
- Best practices for using smart pointers safely.

This example serves as a cautionary tale about the proper use of smart pointers in modern C++, highlighting a common mistake that can lead to serious memory corruption issues.
