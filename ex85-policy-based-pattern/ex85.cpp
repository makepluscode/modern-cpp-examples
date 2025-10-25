#include <iostream>
#include <chrono>
#include <thread>

// X86 Platform Time Policy
// X86 플랫폼 시간 정책
// Uses std::chrono for time measurement (standard C++ library)
// 시간 측정을 위해 std::chrono 사용 (표준 C++ 라이브러리)
struct X86TimePolicy {
    // Initialize time system (not needed for x86)
    // 시간 시스템 초기화 (x86에서는 불필요)
    static void init() {
        std::cout << "[X86] Time system initialized (using std::chrono)" << std::endl;
    }

    // Get current time in milliseconds
    // 현재 시간을 밀리초 단위로 얻기
    static uint32_t getMilliseconds() {
        using namespace std::chrono;
        auto now = steady_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count();
        return static_cast<uint32_t>(ms);
    }

    // Delay for specified milliseconds
    // 지정된 밀리초 동안 지연
    static void delay(uint32_t ms) {
        std::cout << "[X86] Delaying " << ms << "ms using std::this_thread::sleep_for" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
};

// Embedded Platform Time Policy
// 임베디드 플랫폼 시간 정책
// Simulates hardware timer (SysTick) for embedded systems
// 임베디드 시스템을 위한 하드웨어 타이머(SysTick) 시뮬레이션
struct EmbeddedTimePolicy {
    // Simulated SysTick counter (in real hardware, this is updated by interrupt)
    // 시뮬레이션된 SysTick 카운터 (실제 하드웨어에서는 인터럽트로 업데이트됨)
    static uint32_t systick_counter;

    // Initialize SysTick timer (simulated)
    // SysTick 타이머 초기화 (시뮬레이션)
    static void init() {
        std::cout << "[Embedded] SysTick timer initialized" << std::endl;
        std::cout << "[Embedded] Timer configured for 1ms tick" << std::endl;
        systick_counter = 0;
    }

    // Get current time in milliseconds from SysTick counter
    // SysTick 카운터에서 현재 시간을 밀리초 단위로 얻기
    static uint32_t getMilliseconds() {
        // In real embedded system: return systick_counter;
        // 실제 임베디드 시스템: return systick_counter;
        // For simulation, we use chrono but pretend it's a hardware register
        // 시뮬레이션을 위해 chrono를 사용하지만 하드웨어 레지스터인 척함
        using namespace std::chrono;
        auto now = steady_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count();
        return static_cast<uint32_t>(ms);
    }

    // Delay using busy-wait loop (typical for embedded systems)
    // 바쁜 대기 루프를 사용한 지연 (임베디드 시스템에 전형적)
    static void delay(uint32_t ms) {
        std::cout << "[Embedded] Delaying " << ms << "ms using busy-wait loop" << std::endl;
        uint32_t start = getMilliseconds();
        // Busy-wait loop (polling)
        // 바쁜 대기 루프 (폴링)
        while (getMilliseconds() - start < ms) {
            // In real hardware: __NOP() or WFI() instruction
            // 실제 하드웨어: __NOP() 또는 WFI() 명령어
        }
    }
};

// Initialize static member
// 정적 멤버 초기화
uint32_t EmbeddedTimePolicy::systick_counter = 0;

// System Timer class template with Policy-Based Design
// Policy-Based Design을 사용하는 시스템 타이머 클래스 템플릿
template<typename TimePolicy>
class SystemTimer {
public:
    // Initialize the timer system
    // 타이머 시스템 초기화
    static void initialize() {
        TimePolicy::init();
    }

    // Get current time in milliseconds
    // 현재 시간을 밀리초 단위로 얻기
    static uint32_t millis() {
        return TimePolicy::getMilliseconds();
    }

    // Delay for specified milliseconds
    // 지정된 밀리초 동안 지연
    static void delayMs(uint32_t ms) {
        TimePolicy::delay(ms);
    }

    // Measure elapsed time for a task
    // 작업의 경과 시간 측정
    static uint32_t measureElapsed(void (*task)()) {
        uint32_t start = millis();
        task();
        uint32_t end = millis();
        return end - start;
    }
};

// Application code that works on both platforms
// 두 플랫폼 모두에서 작동하는 애플리케이션 코드

// Simulate LED blink (platform independent)
// LED 깜빡임 시뮬레이션 (플랫폼 독립적)
template<typename TimePolicy>
void blinkLED() {
    std::cout << "\n>>> LED ON" << std::endl;
    SystemTimer<TimePolicy>::delayMs(500);

    std::cout << ">>> LED OFF" << std::endl;
    SystemTimer<TimePolicy>::delayMs(500);
}

// Simulate sensor reading with timeout (platform independent)
// 타임아웃을 사용한 센서 읽기 시뮬레이션 (플랫폼 독립적)
template<typename TimePolicy>
void readSensorWithTimeout() {
    std::cout << "\n>>> Reading sensor..." << std::endl;
    uint32_t start = SystemTimer<TimePolicy>::millis();

    // Simulate sensor reading
    // 센서 읽기 시뮬레이션
    SystemTimer<TimePolicy>::delayMs(100);

    uint32_t elapsed = SystemTimer<TimePolicy>::millis() - start;
    std::cout << ">>> Sensor read completed in " << elapsed << "ms" << std::endl;
}

// Task for performance measurement
// 성능 측정용 작업
void sampleTask() {
    volatile int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Policy-Based Design: Timing System" << std::endl;
    std::cout << "========================================\n" << std::endl;

    // Example 1: Using X86 Time Policy (development environment)
    // 예제 1: X86 시간 정책 사용 (개발 환경)
    std::cout << "*** Example 1: X86 Platform (Development) ***\n" << std::endl;

    SystemTimer<X86TimePolicy>::initialize();

    std::cout << "\nCurrent time: " << SystemTimer<X86TimePolicy>::millis() << "ms" << std::endl;

    blinkLED<X86TimePolicy>();
    readSensorWithTimeout<X86TimePolicy>();

    uint32_t taskTime = SystemTimer<X86TimePolicy>::measureElapsed(sampleTask);
    std::cout << "\n>>> Task execution time: " << taskTime << "ms" << std::endl;

    std::cout << "\n========================================\n" << std::endl;

    // Example 2: Using Embedded Time Policy (production environment)
    // 예제 2: 임베디드 시간 정책 사용 (제품 환경)
    std::cout << "*** Example 2: Embedded Platform (Production) ***\n" << std::endl;

    SystemTimer<EmbeddedTimePolicy>::initialize();

    std::cout << "\nCurrent time: " << SystemTimer<EmbeddedTimePolicy>::millis() << "ms" << std::endl;

    blinkLED<EmbeddedTimePolicy>();
    readSensorWithTimeout<EmbeddedTimePolicy>();

    taskTime = SystemTimer<EmbeddedTimePolicy>::measureElapsed(sampleTask);
    std::cout << "\n>>> Task execution time: " << taskTime << "ms" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "Platform-independent application code!" << std::endl;
    std::cout << "Same logic runs on X86 and Embedded" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
