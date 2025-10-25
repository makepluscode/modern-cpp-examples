#include <iostream>

class Counter {
private:
    // Single private member variable
    // 단일 private member 변수
    int count;
    
public:
    // Constructor
    // Constructor
    Counter(int initialValue = 0) : count(initialValue) {
    }

    // Method to increment the value
    // 값을 증가시키는 method
    void increment() {
        count++;
    }

    // Method to decrement the value
    // 값을 감소시키는 method
    void decrement() {
        if (count > 0) {  // Prevent negative values / 음수 값 방지
            count--;
        }
    }

    // Method to read the current value
    // 현재 값을 읽는 method
    int getValue() const {
        return count;
    }
};

int main() {
    // Create a counter object with initial value of 5
    // 초기값 5로 counter 객체 생성
    Counter counter(5);

    std::cout << "Initial value: " << counter.getValue() << "\n";

    // Increment the counter
    // Counter 증가
    counter.increment();
    std::cout << "After increment: " << counter.getValue() << "\n";

    // Decrement the counter
    // Counter 감소
    counter.decrement();
    std::cout << "After decrement: " << counter.getValue() << "\n";

    return 0;
}