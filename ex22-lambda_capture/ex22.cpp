#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector with some numbers
    // 숫자들로 vector 초기화
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Define a threshold value that we want to capture in lambda
    // Lambda에서 capture할 threshold 값 정의
    int threshold = 3;

    std::cout << "Numbers greater than " << threshold << ":\n";

    // Lambda function with capture
    // [threshold]: captures 'threshold' by value
    // (int n): parameter list, takes each number from vector
    // Capture를 사용하는 lambda 함수
    // [threshold]: 'threshold'를 값으로 capture
    // (int n): parameter 리스트, vector의 각 숫자를 받음
    auto check_threshold = [threshold](int n) {
        if (n > threshold) {
            std::cout << n << " is greater than " << threshold << std::endl;
        }
    };

    // Use for_each algorithm with our lambda function
    // This will apply the lambda to each element in the vector
    // Lambda 함수와 함께 for_each 알고리즘 사용
    // Vector의 각 요소에 lambda를 적용
    std::for_each(numbers.begin(), numbers.end(), check_threshold);

    return 0;
}