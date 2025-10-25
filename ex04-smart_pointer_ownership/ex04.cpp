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
    // Create a unique_ptr with exclusive ownership
    // 독점적 ownership을 가진 unique_ptr 생성
    auto ptr1(new MyClass());
    ptr1->display();

#ifdef IMPLICITLY_DELECTED_COPY_ERROR
    // This would cause a compilation error: unique_ptr cannot be copied
    // 이것은 컴파일 에러를 발생시킵니다: unique_ptr은 복사할 수 없습니다
    auto ptr2(ptr1);
#else
    // Transfer ownership from ptr1 to ptr2 using std::move
    // std::move를 사용하여 ptr1에서 ptr2로 ownership 전송
    auto ptr2 = std::move(ptr1);
#endif

    // ptr2 now owns the object, ptr1 is null
    // 이제 ptr2가 객체를 소유하고, ptr1은 null입니다
    ptr2->display();

    return 0;
}