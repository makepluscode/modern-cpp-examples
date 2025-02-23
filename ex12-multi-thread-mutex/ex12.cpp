#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void increment(int& counter, std::mutex& mtx) {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // 뮤텍스를 사용하여 동기화
        ++counter; // 안전하게 counter 증가
    }
}

int main() {
    int counter = 0; // 공유 자원
    std::mutex mtx;  // 뮤텍스 객체

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment, std::ref(counter), std::ref(mtx)); // 여러 스레드 생성
    }

    for (auto& t : threads) {
        t.join(); // 모든 스레드가 종료될 때까지 대기
    }

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}