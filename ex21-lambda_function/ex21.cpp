#include <iostream>

int main() {
    // Define and call a simple lambda function
    // 간단한 lambda 함수 정의 및 호출
    auto greet = []() {
        std::cout << "Hello, World!" << std::endl;
    };

    // Call the lambda function
    // lambda 함수 호출
    greet();

    return 0;
}
