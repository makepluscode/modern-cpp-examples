# Smart Pointer Double Destruct Example

This example demonstrates a common mistake when using smart pointers: manually deleting a raw pointer obtained from a smart pointer, leading to a double free error.

## Files

- **ex3.cpp**: This file contains the C++ code that demonstrates the incorrect use of a raw pointer with a `std::shared_ptr`, resulting in a double free error.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `03-smart_pointer_double_destruct` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./double_destruct_example
   ```

   Note: Running this program will likely result in a crash or an abort signal due to the double free error.

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## What You Will Learn

- The dangers of manually deleting a raw pointer obtained from a smart pointer.
- How a double free error can occur when a smart pointer tries to delete memory that has already been freed.
- The importance of letting smart pointers manage memory automatically to avoid such errors.

This example serves as a cautionary tale about the misuse of smart pointers and highlights the importance of proper memory management in C++.
