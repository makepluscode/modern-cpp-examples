#include <iostream>
#include <thread>
#include <chrono>

int main() {
    auto say_hello = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Hello from thread 1!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 100ms 대기
        }
    };

    auto say_goodbye = []() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Goodbye from thread 2!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 100ms 대기
        }
    };

    std::thread t1(say_hello);   // 첫 번째 스레드 생성 및 실행
    std::thread t2(say_goodbye); // 두 번째 스레드 생성 및 실행

    t1.join(); // 메인 스레드가 t1 스레드 종료를 대기
    t2.join(); // 메인 스레드가 t2 스레드 종료를 대기

    return 0;
}