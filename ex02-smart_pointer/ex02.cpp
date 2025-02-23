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
    auto uniquePtr = std::make_unique<MyClass>();
    uniquePtr->display();

    auto sharedPtr1 = std::make_shared<MyClass>();
    {
        auto sharedPtr2 = sharedPtr1;
        std::cout << "Shared pointer count: " << sharedPtr1.use_count() << std::endl;
    }
    std::cout << "Shared pointer count after block: " << sharedPtr1.use_count() << std::endl;

    return 0;
}
