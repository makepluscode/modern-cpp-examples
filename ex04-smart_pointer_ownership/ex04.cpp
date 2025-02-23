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
    auto ptr1(new MyClass());
    ptr1->display();

#ifdef IMPLICITLY_DELECTED_COPY_ERROR
    auto ptr2(ptr1);
#else
    auto ptr2 = std::move(ptr1);
#endif

    ptr2->display();

    return 0;
}