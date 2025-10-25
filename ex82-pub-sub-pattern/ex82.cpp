#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Subscriber interface (abstract class)
// Subscriber interface (추상 class)
class Subscriber {
public:
    // Pure virtual function for receiving updates
    // 업데이트를 받기 위한 순수 가상 함수
    virtual void update(const std::string& message) = 0;
    virtual ~Subscriber() = default;
};

// Publisher class that manages subscribers
// Subscriber들을 관리하는 Publisher class
class Publisher {
private:
    // List of subscribers using smart pointers
    // Smart pointer를 사용한 subscriber 목록
    std::vector<std::shared_ptr<Subscriber>> subscribers;

public:
    // Subscribe a new subscriber
    // 새로운 subscriber 등록
    void subscribe(const std::shared_ptr<Subscriber>& sub) {
        subscribers.push_back(sub);
    }

    // Notify all subscribers with a message
    // 모든 subscriber에게 메시지로 알림
    void notify(const std::string& message) {
        for (const auto& sub : subscribers) {
            sub->update(message);
        }
    }
};

// Concrete implementation of Subscriber
// Subscriber의 구체적 구현
class ConcreteSubscriber : public Subscriber {
private:
    std::string name;

public:
    // Constructor with name initialization
    // 이름 초기화를 하는 constructor
    explicit ConcreteSubscriber(std::string n) : name(std::move(n)) {}

    // Override the update method to handle notifications
    // 알림을 처리하기 위해 update method override
    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

int main() {
    // Create a publisher
    // Publisher 생성
    auto publisher = std::make_shared<Publisher>();

    // Create subscribers
    // Subscriber 생성
    auto sub1 = std::make_shared<ConcreteSubscriber>("Subscriber 1");
    auto sub2 = std::make_shared<ConcreteSubscriber>("Subscriber 2");

    // Subscribe to the publisher
    // Publisher에 등록
    publisher->subscribe(sub1);
    publisher->subscribe(sub2);

    // Publish a message to all subscribers
    // 모든 subscriber에게 메시지 발행
    publisher->notify("Hello, Subscribers!");

    return 0;
}
