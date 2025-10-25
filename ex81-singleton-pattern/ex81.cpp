#include <iostream>
#include <memory>

// Singleton class definition
// Singleton class 정의
class Singleton {
public:
    // Static method to get the single instance
    // 단일 instance를 얻기 위한 static method
    static std::shared_ptr<Singleton> getInstance() {
        // Thread-safe initialization using static local variable (C++11 feature)
        // Static local 변수를 사용한 thread-safe 초기화 (C++11 기능)
        static std::shared_ptr<Singleton> instance(new Singleton());
        return instance;
    }

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
};

int main() {
    // Get the first instance
    // 첫 번째 instance 얻기
    auto instance1 = Singleton::getInstance();

    // Get the second instance (will be the same as instance1)
    // 두 번째 instance 얻기 (instance1과 동일함)
    auto instance2 = Singleton::getInstance();

    // Use the singleton instance
    // Singleton instance 사용
    instance1->printMessage("Testing singleton...");

    // Verify both instances point to the same object
    // 두 instance가 같은 객체를 가리키는지 확인
    std::cout << "Address of instance1: " << instance1.get() << std::endl;
    std::cout << "Address of instance2: " << instance2.get() << std::endl;

    return 0;
}
