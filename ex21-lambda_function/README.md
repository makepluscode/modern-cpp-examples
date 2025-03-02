# Lambda Functions in Modern C++

This example demonstrates the basic usage of lambda functions in modern C++. Lambda functions, introduced in C++11, provide a concise way to define anonymous function objects inline. They are particularly useful for short, one-off functions that are passed to algorithms or used locally within a function.

## Files

- **ex21.cpp**: This file contains the C++ code that demonstrates how to define and use a simple lambda function.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates a basic lambda function:

```cpp
#include <iostream>

int main() {
    // Define a simple lambda function
    auto greet = []() {
        std::cout << "Hello, World!" << std::endl;
    };

    greet(); // Call the lambda function

    return 0;
}
```

This code shows:
1. How to define a lambda function using the `[]` syntax
2. How to store a lambda function in a variable using `auto`
3. How to call a lambda function like a regular function

The lambda syntax `[](){}` consists of:
- Capture clause `[]`: Specifies which variables from the surrounding scope are accessible inside the lambda
- Parameter list `()`: Similar to regular function parameters
- Function body `{}`: Contains the code to be executed

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex21-lambda_function` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex21.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex21-lambda_function
make
```

This will compile the example and create an executable named `ex21.out`. When you run it, you'll see the output "Hello, World!" demonstrating the execution of the lambda function.

## What You Will Learn

- How to define a basic lambda function in C++
- The syntax of lambda expressions
- How to store lambda functions in variables
- How to call lambda functions

This example provides a simple introduction to lambda functions in modern C++, demonstrating how they can be used to write more concise and readable code. Lambda functions are a powerful feature that enable functional programming techniques in C++ and are widely used in conjunction with algorithms and containers from the Standard Library.
