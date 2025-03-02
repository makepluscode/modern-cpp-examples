#include <iostream>

void func(int* ptr) {
    std::cout << "Called func(int*)" << (ptr ? "" : " with null") << "\n";
}

void func(char* ptr) {
    std::cout << "Called func(char*)" << (ptr ? "" : " with null") << "\n";
}

int main() {
    // NULL is problematic due to ambiguity
    func((int*)NULL);    // Explicitly cast to avoid ambiguity
    
    // nullptr also needs explicit casting in this case
    func((int*)nullptr);  // or could use (char*)nullptr to call the other overload

    return 0;
}