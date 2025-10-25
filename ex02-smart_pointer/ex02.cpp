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
    // Create a unique_ptr - exclusive ownership
    // unique_ptr 생성 - 독점적 ownership
    auto uniquePtr = std::make_unique<MyClass>();
    uniquePtr->display();

    // Create a shared_ptr - shared ownership with reference counting
    // shared_ptr 생성 - reference counting을 통한 공유 ownership
    auto sharedPtr1 = std::make_shared<MyClass>();
    {
        // Create another shared_ptr pointing to the same object
        // 동일한 객체를 가리키는 또 다른 shared_ptr 생성
        auto sharedPtr2 = sharedPtr1;
        std::cout << "Shared pointer count: " << sharedPtr1.use_count() << std::endl;
    }
    // sharedPtr2 is destroyed here, reference count decreases
    // sharedPtr2가 여기서 파괴되고 reference count가 감소
    std::cout << "Shared pointer count after block: " << sharedPtr1.use_count() << std::endl;

    return 0;
}
