# Lambda Capture in Modern C++

This example demonstrates how to use lambda captures in C++. Lambda captures allow lambda functions to access variables from the surrounding scope. This is a powerful feature that makes lambdas more flexible and useful in a variety of contexts, particularly when working with algorithms from the Standard Library.

이 예제는 C++에서 lambda capture를 사용하는 방법을 보여줍니다. Lambda capture는 lambda 함수가 주변 범위의 변수에 접근할 수 있도록 합니다. 이것은 lambda를 더 유연하고 유용하게 만드는 강력한 기능이며, 특히 Standard Library의 알고리즘과 함께 작업할 때 유용합니다.

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

## 컴파일 및 실행 방법

1. **코드 컴파일**: 터미널을 열고 `ex22-lambda_capture` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **실행 파일 실행**: 컴파일 후 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex22.out
   ```

3. **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
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

## 배우게 될 내용

- Lambda 함수에서 주변 범위의 변수를 capture하는 방법
- 값에 의한 capture와 참조에 의한 capture의 차이점 (이 예제는 값에 의한 capture 사용)
- `std::for_each`와 같은 표준 알고리즘에서 lambda 함수를 사용하는 방법
- Lambda capture가 lambda를 더 강력하고 유연하게 만드는 방법

이 예제는 C++의 lambda capture에 대한 실용적인 통찰을 제공하며, lambda가 주변 컨텍스트의 변수에 접근하고 사용할 수 있게 하여 다양한 프로그래밍 작업에서 더 다용도로 사용될 수 있음을 보여줍니다.
