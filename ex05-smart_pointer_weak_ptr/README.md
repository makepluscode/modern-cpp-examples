# Weak Pointers and Circular References in C++

This example demonstrates the use of `std::weak_ptr` to break circular references that would otherwise cause memory leaks when using `std::shared_ptr`. Circular references occur when two or more objects hold shared pointers to each other, creating a reference cycle that prevents the objects from being deleted even when they are no longer accessible from the rest of the program.

이 예제는 `std::shared_ptr`을 사용할 때 memory leak을 일으킬 수 있는 순환 참조(circular reference)를 끊기 위해 `std::weak_ptr`을 사용하는 방법을 보여줍니다. 순환 참조는 두 개 이상의 객체가 서로에 대한 shared pointer를 보유할 때 발생하며, 프로그램의 나머지 부분에서 더 이상 접근할 수 없는 경우에도 객체가 삭제되는 것을 방지하는 reference cycle을 생성합니다.

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

**컴파일 및 실행 방법**

1. **Compile the Code**: Open a terminal and navigate to the `ex05-smart_pointer_weak_ptr` directory. Run the following command to compile the code:

   **코드 컴파일**: terminal을 열고 `ex05-smart_pointer_weak_ptr` 디렉토리로 이동합니다. 다음 명령어를 실행하여 코드를 컴파일합니다:
   ```bash
   make
   ```

2. **Run the Executable**: After compiling, run the executable with the following command:

   **실행 파일 실행**: 컴파일 후, 다음 명령어로 실행 파일을 실행합니다:
   ```bash
   ./ex05.out
   ```

3. **Clean Up**: To remove the compiled executable, use the following command:

   **정리**: 컴파일된 실행 파일을 제거하려면 다음 명령어를 사용합니다:
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

**배울 내용**

- What circular references are and why they cause memory leaks.
- How to use `std::weak_ptr` to break circular references.
- The relationship between `std::shared_ptr` and `std::weak_ptr`.
- How to implement data structures like doubly-linked lists safely with smart pointers.

- 순환 참조가 무엇이며 왜 memory leak을 발생시키는지
- 순환 참조를 끊기 위해 `std::weak_ptr`을 사용하는 방법
- `std::shared_ptr`과 `std::weak_ptr`의 관계
- Smart pointer를 사용하여 이중 연결 리스트와 같은 data structure를 안전하게 구현하는 방법

This example provides practical insights into solving a common memory management problem in C++ using modern smart pointer techniques, demonstrating how `std::weak_ptr` complements `std::shared_ptr` to create more robust code.

이 예제는 modern smart pointer 기법을 사용하여 C++의 일반적인 메모리 관리 문제를 해결하는 실용적인 통찰을 제공하며, `std::weak_ptr`이 어떻게 `std::shared_ptr`을 보완하여 더 견고한 코드를 만드는지 보여줍니다.
