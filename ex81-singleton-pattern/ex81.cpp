#include <iostream>

// Singleton class definition
// Singleton class 정의
class Singleton {
public:
    // Static method to get the single instance (returns reference)
    // 단일 instance를 얻기 위한 static method (참조 반환)
    static Singleton& getInstance() {
        // Thread-safe initialization using static local variable (C++11 feature)
        // Static local 변수를 사용한 thread-safe 초기화 (C++11 기능)
        // The C++11 standard guarantees thread-safe initialization of static local variables
        // C++11 표준은 static local 변수의 thread-safe 초기화를 보장함
        static Singleton instance;
        return instance;
    }

    // Delete copy constructor to prevent copying
    // 복사를 방지하기 위해 복사 생성자 삭제
    Singleton(const Singleton&) = delete;

    // Delete copy assignment operator to prevent copying
    // 복사를 방지하기 위해 복사 대입 연산자 삭제
    Singleton& operator=(const Singleton&) = delete;

    // Delete move constructor to prevent moving
    // 이동을 방지하기 위해 이동 생성자 삭제
    Singleton(Singleton&&) = delete;

    // Delete move assignment operator to prevent moving
    // 이동을 방지하기 위해 이동 대입 연산자 삭제
    Singleton& operator=(Singleton&&) = delete;

    // Method to print a message
    // 메시지를 출력하는 method
    void printMessage(const std::string& message) const {
        std::cout << message << std::endl;
    }

private:
    // Private constructor to prevent direct instantiation
    // 직접 instantiation을 방지하기 위한 private constructor
    Singleton() {
        std::cout << "Constructor called" << std::endl;
    }

    // Destructor (private or default is fine for singletons)
    // 소멸자 (singleton의 경우 private 또는 default 모두 가능)
    ~Singleton() = default;
};

int main() {
    // Get the first instance reference
    // 첫 번째 instance 참조 얻기
    Singleton& instance1 = Singleton::getInstance();

    // Get the second instance reference (will be the same as instance1)
    // 두 번째 instance 참조 얻기 (instance1과 동일함)
    Singleton& instance2 = Singleton::getInstance();

    // Use the singleton instance
    // Singleton instance 사용
    instance1.printMessage("Testing singleton...");

    // Verify both instances refer to the same object
    // 두 instance가 같은 객체를 참조하는지 확인
    std::cout << "Address of instance1: " << &instance1 << std::endl;
    std::cout << "Address of instance2: " << &instance2 << std::endl;

    return 0;
}
