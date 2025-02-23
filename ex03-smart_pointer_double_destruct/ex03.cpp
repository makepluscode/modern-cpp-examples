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
    auto sharedPtr1 = std::make_shared<MyClass>();
    sharedPtr1->display();

    // Get a raw pointer from the smart pointer
    auto rawPtr = sharedPtr1.get();

    // Manually delete the raw pointer (this is incorrect and dangerous)
    delete rawPtr;

    // When sharedPtr1 goes out of scope, it will try to delete the same memory again
    return 0;
}
