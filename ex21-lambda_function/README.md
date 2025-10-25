# Lambda Functions in Modern C++

This example demonstrates the basic usage of lambda functions in modern C++. Lambda functions, introduced in C++11, provide a concise way to define anonymous function objects inline. They are particularly useful for short, one-off functions that are passed to algorithms or used locally within a function.

이 예제는 Modern C++에서 lambda 함수의 기본 사용법을 보여줍니다. C++11에서 도입된 lambda 함수는 익명 함수 객체를 인라인으로 간결하게 정의할 수 있는 방법을 제공합니다. 알고리즘에 전달되거나 함수 내부에서 지역적으로 사용되는 짧은 일회성 함수에 특히 유용합니다.

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

## 컴파일 및 실행 방법

1. **코드 컴파일**: 터미널을 열고 `ex21-lambda_function` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **실행 파일 실행**: 컴파일 후 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex21.out
   ```

3. **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
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

## 배우게 될 내용

- C++에서 기본 lambda 함수를 정의하는 방법
- Lambda 표현식의 문법
- Lambda 함수를 변수에 저장하는 방법
- Lambda 함수를 호출하는 방법

이 예제는 Modern C++의 lambda 함수에 대한 간단한 소개를 제공하며, 더 간결하고 읽기 쉬운 코드를 작성하는 데 어떻게 사용될 수 있는지 보여줍니다. Lambda 함수는 C++에서 함수형 프로그래밍 기법을 가능하게 하는 강력한 기능이며, Standard Library의 알고리즘 및 컨테이너와 함께 널리 사용됩니다.
