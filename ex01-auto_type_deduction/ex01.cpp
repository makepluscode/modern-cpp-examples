#include <iostream>
#include <vector>
#include <string>

int main() {
    // Declare an integer variable using auto
    // auto를 사용하여 정수형 변수 선언
    auto integer = 42;
    std::cout << "Integer: " << integer << std::endl;

    // Declare a floating-point variable using auto
    // auto를 사용하여 실수형 변수 선언
    auto floating_point = 3.14;
    std::cout << "Floating Point: " << floating_point << std::endl;

    // Declare a string variable using auto
    // auto를 사용하여 문자열 변수 선언
    auto text = std::string("Hello, World!");
    std::cout << "Text: " << text << std::endl;

    // Declare and initialize a vector using auto
    // auto를 사용하여 vector 선언 및 초기화
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};
    std::cout << "Vector: ";
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
} 