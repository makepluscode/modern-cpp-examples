#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Define a lambda function for thread 1
    // Thread 1을 위한 lambda function 정의
    auto say_hello = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Hello from thread 1!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for 100ms
                                                                          // 100ms 대기
        }
    };

    // Define a lambda function for thread 2
    // Thread 2를 위한 lambda function 정의
    auto say_goodbye = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Goodbye from thread 2!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for 100ms
                                                                          // 100ms 대기
        }
    };

    std::thread t1(say_hello);   // Create and execute first thread
                                 // 첫 번째 thread 생성 및 실행
    std::thread t2(say_goodbye); // Create and execute second thread
                                 // 두 번째 thread 생성 및 실행

    t1.join(); // Main thread waits for t1 to finish
               // Main thread가 t1 thread 종료를 대기
    t2.join(); // Main thread waits for t2 to finish
               // Main thread가 t2 thread 종료를 대기

    return 0;
}