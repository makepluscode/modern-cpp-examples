# Lambda Capture in Modern C++

This example demonstrates how to use lambda captures in C++. Lambda captures allow lambda functions to access variables from the surrounding scope. This is a powerful feature that makes lambdas more flexible and useful in a variety of contexts, particularly when working with algorithms from the Standard Library.

## Files

- **ex22.cpp**: This file contains the C++ code that demonstrates how to use lambda captures to access variables from the surrounding scope.
- **Makefile**: This file is used to compile the C++ code. It contains instructions for building the executable using `g++`.

## How to use

The example code demonstrates lambda captures:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector with some numbers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Define a threshold value that we want to capture in lambda
    int threshold = 3;

    std::cout << "Numbers greater than " << threshold << ":\n";

    // Lambda function with capture
    // [threshold]: captures 'threshold' by value
    // (int n): parameter list, takes each number from vector
    auto check_threshold = [threshold](int n) {
        if (n > threshold) {
            std::cout << n << " is greater than " << threshold << std::endl;
        }
    };

    // Use for_each algorithm with our lambda function
    // This will apply the lambda to each element in the vector
    std::for_each(numbers.begin(), numbers.end(), check_threshold);

    return 0;
}
```

This code shows:
1. How to define a lambda function that captures a variable from the surrounding scope
2. How to use the captured variable inside the lambda function
3. How to use the lambda function with the `std::for_each` algorithm

The capture clause `[threshold]` specifies that the lambda function captures the `threshold` variable by value, making it accessible inside the lambda body.

## How to Compile and Run

1. **Compile the Code**: Open a terminal and navigate to the `ex22-lambda_capture` directory. Run the following command to compile the code:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:
   ```bash
   ./ex22.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:
   ```bash
   make clean
   ```

## Test

To test this example, you can follow these steps:

```bash
git clone https://github.com/makepluscode/modern-cpp-examples.git
cd ex22-lambda_capture
make
```

This will compile the example and create an executable named `ex22.out`. When you run it, you'll see the output listing the numbers from the vector that are greater than the threshold value, demonstrating how the lambda function uses the captured variable.

## What You Will Learn

- How to capture variables from the surrounding scope in lambda functions
- The difference between capturing by value and by reference (this example uses capture by value)
- How to use lambda functions with standard algorithms like `std::for_each`
- How lambda captures make lambdas more powerful and flexible

This example provides practical insights into lambda captures in C++, demonstrating how they enable lambdas to access and use variables from their surrounding context, making them more versatile for a wide range of programming tasks.
