#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void increment(int& counter, std::mutex& mtx) {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Synchronize using mutex
                                                // mutex를 사용하여 동기화
        ++counter; // Safely increment counter
                   // 안전하게 counter 증가
    }
}

int main() {
    int counter = 0; // Shared resource
                     // 공유 resource
    std::mutex mtx;  // Mutex object
                     // Mutex 객체

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment, std::ref(counter), std::ref(mtx)); // Create multiple threads
                                                                            // 여러 thread 생성
    }

    for (auto& t : threads) {
        t.join(); // Wait for all threads to finish
                  // 모든 thread가 종료될 때까지 대기
    }

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}