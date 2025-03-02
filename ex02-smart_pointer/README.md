# Smart Pointers in Modern C++

Modern C++ introduced smart pointers as part of the C++11 standard to help manage dynamic memory allocation and prevent memory leaks. Smart pointers are wrapper classes that manage the lifetime of dynamically allocated objects through RAII (Resource Acquisition Is Initialization) principles. The three main types of smart pointers in C++ are `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, each serving different ownership semantics and memory management needs.

## Files

- **ex02.cpp**: This file contains the C++ code that demonstrates the use of `std::unique_ptr` and `std::shared_ptr` to manage object lifetimes.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates various uses of smart pointers:

```cpp
// Unique pointer example
auto uniquePtr = std::make_unique<MyClass>();
uniquePtr->display();
// uniquePtr has exclusive ownership of the MyClass object
// When uniquePtr goes out of scope, the object is automatically deleted

// Shared pointer example
auto sharedPtr1 = std::make_shared<MyClass>();
{
    auto sharedPtr2 = sharedPtr1;
    std::cout << "Shared pointer count: " << sharedPtr1.use_count() << std::endl;
    // Both sharedPtr1 and sharedPtr2 share ownership of the same object
    // The reference count is 2
}
std::cout << "Shared pointer count after block: " << sharedPtr1.use_count() << std::endl;
// After the inner block, sharedPtr2 is destroyed, reducing the reference count to 1
// The object is deleted only when the last shared_ptr (sharedPtr1) goes out of scope
```

Each example shows how smart pointers automatically manage memory, eliminating the need for manual memory management with `new` and `delete`.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex02-smart_pointer` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex02.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex02-smart_pointer
make
```

This will compile the example and create an executable named `ex02.out`. When you run it, you'll see the output demonstrating how smart pointers manage object lifetimes and how reference counting works with shared pointers.

## What You Will Learn

- How to use `std::unique_ptr` for exclusive ownership of resources.
- How to use `std::shared_ptr` for shared ownership and reference counting.
- How smart pointers automatically manage memory and prevent memory leaks.
- How to create smart pointers using factory functions like `std::make_unique` and `std::make_shared`.

This example is a practical introduction to smart pointers in modern C++, demonstrating how they can make your code safer by eliminating common memory management errors.
