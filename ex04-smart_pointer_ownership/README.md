# Smart Pointer Ownership Transfer in C++

This example demonstrates ownership transfer with smart pointers in C++, specifically focusing on `std::unique_ptr`. Since `std::unique_ptr` implements exclusive ownership semantics, it cannot be copied, but its ownership can be transferred using `std::move()`. This example illustrates the proper way to transfer ownership of resources managed by smart pointers.

## Files

- **ex04.cpp**: This file contains the C++ code that demonstrates ownership transfer with smart pointers and shows what happens when you try to copy a `std::unique_ptr`.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates ownership transfer with smart pointers:

```cpp
// Create a unique_ptr
auto ptr1(new MyClass());
ptr1->display();

#ifdef IMPLICITLY_DELECTED_COPY_ERROR
    // This would cause a compilation error because unique_ptr cannot be copied
    auto ptr2(ptr1);
#else
    // Transfer ownership from ptr1 to ptr2 using std::move
    auto ptr2 = std::move(ptr1);
#endif

// ptr2 now owns the object, ptr1 is null
ptr2->display();
```

This code shows:
1. How to create a `std::unique_ptr` using direct initialization
2. Why copying a `std::unique_ptr` is not allowed (commented out to prevent compilation errors)
3. How to properly transfer ownership using `std::move()`

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex04-smart_pointer_ownership` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex04.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

4. **Test with Error**: If you want to see the compilation error when trying to copy a `std::unique_ptr`, you can compile with:
   ```bash
   make CXXFLAGS="-std=c++14 -Wall -DIMPLICITLY_DELECTED_COPY_ERROR"
   ```
   This will define the preprocessor macro that enables the code that attempts to copy a `std::unique_ptr`.

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex04-smart_pointer_ownership
make
```

This will compile the example and create an executable named `ex04.out`. When you run it, you'll see the output demonstrating how ownership is transferred from one smart pointer to another.

## What You Will Learn

- The exclusive ownership semantics of `std::unique_ptr`.
- Why `std::unique_ptr` cannot be copied.
- How to transfer ownership using `std::move()`.
- The behavior of smart pointers after ownership transfer.

This example provides practical insights into the ownership model of smart pointers in modern C++, demonstrating how to safely transfer resources without causing memory leaks or double deletions.
