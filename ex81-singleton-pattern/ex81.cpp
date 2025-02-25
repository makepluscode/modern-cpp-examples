#include <iostream>
#include <memory>

class Singleton {
public:
    static std::shared_ptr<Singleton> getInstance() {
        static std::shared_ptr<Singleton> instance(new Singleton());
        return instance;
    }

    void printMessage(const std::string& message) const {
        std::cout << message << std::endl;
    }

private:
    Singleton() {
        std::cout << "Constructor called" << std::endl;
    }
};

int main() {
    auto instance1 = Singleton::getInstance();
    auto instance2 = Singleton::getInstance();

    instance1->printMessage("Testing singleton...");

    std::cout << "Address of instance1: " << instance1.get() << std::endl;
    std::cout << "Address of instance2: " << instance2.get() << std::endl;

    return 0;
}
