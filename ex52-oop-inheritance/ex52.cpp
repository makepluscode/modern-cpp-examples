#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    // Virtual destructor
    // Virtual destructor
    virtual ~Animal() = default;  // (virtual ~Animal() { })

    // Pure virtual function
    // Pure virtual function
    virtual void makeSound() = 0;
};

// Dog class inherits from Animal
// Dog class는 Animal로부터 상속
class Dog : public Animal {
public:
    // Override the makeSound method
    // makeSound method를 override
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

// Cat class inherits from Animal
// Cat class는 Animal로부터 상속
class Cat : public Animal {
public:
    // Override the makeSound method
    // makeSound method를 override
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Using smart pointers to create Animal objects
    // Smart pointer를 사용하여 Animal 객체 생성
    auto dog = std::make_unique<Dog>();
    auto cat = std::make_unique<Cat>();

    // Call makeSound method - demonstrates polymorphism
    // makeSound method 호출 - polymorphism 시연
    dog->makeSound();  // Output: Woof!
    cat->makeSound();  // Output: Meow!

    return 0;
}