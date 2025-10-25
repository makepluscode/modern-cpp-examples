#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }
    void display() {
        std::cout << "Displaying MyClass" << std::endl;
    }
};

int main() {
    // Create a smart pointer
    // Smart pointer 생성
    auto sharedPtr1 = std::make_shared<MyClass>();
    sharedPtr1->display();

    // Get a raw pointer from the smart pointer
    // Smart pointer로부터 raw pointer 얻기
    auto rawPtr = sharedPtr1.get();

    // WARNING: Manually deleting the raw pointer is INCORRECT and DANGEROUS
    // 경고: Raw pointer를 수동으로 delete하는 것은 잘못되었고 위험합니다
    delete rawPtr;

    // When sharedPtr1 goes out of scope, it will try to delete the same memory again
    // This causes double destruction and undefined behavior
    // sharedPtr1이 scope를 벗어나면 동일한 메모리를 다시 delete하려고 시도합니다
    // 이는 double destruction과 undefined behavior를 일으킵니다
    return 0;
}
