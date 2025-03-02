#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    virtual ~Animal() = default;  // Virtual destructor, (virtual ~Animal() { })
    virtual void makeSound() = 0;  // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Using smart pointers
    auto dog = std::make_unique<Dog>();
    auto cat = std::make_unique<Cat>();
    
    dog->makeSound();  // Output: Woof!
    cat->makeSound();  // Output: Meow!

    return 0;
}