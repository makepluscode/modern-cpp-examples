# Encapsulation in Object-Oriented Programming with C++

This example demonstrates the principle of encapsulation in object-oriented programming using C++. Encapsulation is one of the four fundamental OOP concepts and involves bundling data and methods that operate on that data within a single unit (class) and restricting direct access to some of the object's components.

## Files

- **ex51.cpp**: This file contains the C++ code that demonstrates encapsulation through a simple `Counter` class.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates encapsulation:

```cpp
#include <iostream>

class Counter {
private:
    // Single private member variable
    int count;
    
public:
    // Constructor
    Counter(int initialValue = 0) : count(initialValue) {
    }
    
    // Method to increment the value
    void increment() {
        count++;
    }
    
    // Method to decrement the value
    void decrement() {
        if (count > 0) {  // Prevent negative values
            count--;
        }
    }
    
    // Method to read the current value
    int getValue() const {
        return count;
    }
};

int main() {
    Counter counter(5);
    
    std::cout << "Initial value: " << counter.getValue() << "\n";
    
    counter.increment();
    std::cout << "After increment: " << counter.getValue() << "\n";
    
    counter.decrement();
    std::cout << "After decrement: " << counter.getValue() << "\n";
    
    return 0;
}
```

This code shows:
1. A `Counter` class that encapsulates a single integer value
2. Private data member (`count`) that cannot be accessed directly from outside the class
3. Public methods that provide controlled access to the private data
4. Data validation in the `decrement()` method to ensure the counter never becomes negative

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex51-oop-encapsulation` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex51.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex51-oop-encapsulation
make
```

This will compile the example and create an executable named `ex51.out`. When you run it, you'll see the output showing the counter's value after various operations, demonstrating how encapsulation allows controlled access to the object's state.

## What You Will Learn

- The concept of encapsulation in object-oriented programming
- How to implement encapsulation in C++ using access specifiers (private, public)
- How to create a class with private data members and public methods
- How to use constructors to initialize objects
- How to implement data validation to maintain object invariants
- The benefits of encapsulation for code maintainability and robustness

This example provides a practical introduction to encapsulation in C++, demonstrating how it helps create more maintainable and robust code by hiding implementation details and providing controlled access to an object's state.