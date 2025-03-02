#include <iostream>

class Counter {
private:
    // Single private member variable
    int count;
    
public:
    // Constructor
    Counter(int initialValue = 0) : count(initialValue) {
    }
    
    // Method to increment the value
    void increment() {
        count++;
    }
    
    // Method to decrement the value
    void decrement() {
        if (count > 0) {  // Prevent negative values
            count--;
        }
    }
    
    // Method to read the current value
    int getValue() const {
        return count;
    }
};

int main() {
    Counter counter(5);
    
    std::cout << "Initial value: " << counter.getValue() << "\n";
    
    counter.increment();
    std::cout << "After increment: " << counter.getValue() << "\n";
    
    counter.decrement();
    std::cout << "After decrement: " << counter.getValue() << "\n";
    
    return 0;
}