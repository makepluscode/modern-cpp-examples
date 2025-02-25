#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Subscriber interface
class Subscriber {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Subscriber() = default;
};

// Publisher class
class Publisher {
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers;

public:
    void subscribe(const std::shared_ptr<Subscriber>& sub) {
        subscribers.push_back(sub);
    }

    void notify(const std::string& message) {
        for (const auto& sub : subscribers) {
            sub->update(message);
        }
    }
};

// Concrete subscriber
class ConcreteSubscriber : public Subscriber {
private:
    std::string name;

public:
    explicit ConcreteSubscriber(std::string n) : name(std::move(n)) {}

    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

int main() {
    auto publisher = std::make_shared<Publisher>();
    
    auto sub1 = std::make_shared<ConcreteSubscriber>("Subscriber 1");
    auto sub2 = std::make_shared<ConcreteSubscriber>("Subscriber 2");

    publisher->subscribe(sub1);
    publisher->subscribe(sub2);

    publisher->notify("Hello, Subscribers!");

    return 0;
}
