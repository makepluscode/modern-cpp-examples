#include <iostream>

int main() {
    // 간단한 람다 함수 정의 및 호출
    auto greet = []() {
        std::cout << "Hello, World!" << std::endl;
    };

    greet(); // 람다 함수 호출

    return 0;
}
