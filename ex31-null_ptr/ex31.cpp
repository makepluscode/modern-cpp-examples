#include <iostream>

// Overloaded function that accepts int pointer
// int pointer를 받는 오버로드된 함수
void func(int* ptr) {
    std::cout << "Called func(int*)" << (ptr ? "" : " with null") << "\n";
}

// Overloaded function that accepts char pointer
// char pointer를 받는 오버로드된 함수
void func(char* ptr) {
    std::cout << "Called func(char*)" << (ptr ? "" : " with null") << "\n";
}

int main() {
    // NULL is problematic due to ambiguity
    // Explicitly cast to avoid ambiguity
    // NULL은 모호성 때문에 문제가 됨
    // 모호성을 피하기 위해 명시적으로 캐스팅
    func((int*)NULL);

    // nullptr also needs explicit casting in this case
    // or could use (char*)nullptr to call the other overload
    // 이 경우 nullptr도 명시적 캐스팅이 필요함
    // 또는 (char*)nullptr을 사용하여 다른 오버로드 호출 가능
    func((int*)nullptr);

    return 0;
}