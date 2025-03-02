# Weak Pointers and Circular References in C++

This example demonstrates the use of `std::weak_ptr` to break circular references that would otherwise cause memory leaks when using `std::shared_ptr`. Circular references occur when two or more objects hold shared pointers to each other, creating a reference cycle that prevents the objects from being deleted even when they are no longer accessible from the rest of the program.

## Files

- **ex05.cpp**: This file contains the C++ code that demonstrates how to use `std::weak_ptr` to prevent memory leaks caused by circular references.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates breaking circular references with weak pointers:

```cpp
class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Use weak_ptr to prevent circular reference

    Node() {
        std::cout << "Node Constructor" << std::endl;
    }
    ~Node() {
        std::cout << "Node Destructor" << std::endl;
    }
};

int main() {
    // Create two nodes
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    // Create a circular reference
    node1->next = node2;
    node2->prev = node1;  // Use weak_ptr to avoid circular reference

    // At this point, node1 and node2 can be properly destroyed
    return 0;
}
```

This code shows:
1. How to create a doubly-linked list structure with `Node` objects
2. How using `std::shared_ptr` for both directions would create a circular reference
3. How using `std::weak_ptr` for one direction breaks the circular reference
4. How the objects are properly destroyed when the program ends

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

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex05-smart_pointer_weak_ptr
make
```

This will compile the example and create an executable named `ex05.out`. When you run it, you'll see the output showing that both Node objects are properly constructed and destroyed, demonstrating that the circular reference has been broken.

## What You Will Learn

- What circular references are and why they cause memory leaks.
- How to use `std::weak_ptr` to break circular references.
- The relationship between `std::shared_ptr` and `std::weak_ptr`.
- How to implement data structures like doubly-linked lists safely with smart pointers.

This example provides practical insights into solving a common memory management problem in C++ using modern smart pointer techniques, demonstrating how `std::weak_ptr` complements `std::shared_ptr` to create more robust code.
