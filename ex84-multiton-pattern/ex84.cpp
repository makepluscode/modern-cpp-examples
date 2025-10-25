#include <iostream>
#include <map>
#include <memory>

// Multiton class definition - GPIO pin controller
// Multiton 클래스 정의 - GPIO 핀 컨트롤러
class GpioPin {
public:
    // Static method to get instance by pin number
    // 핀 번호로 인스턴스를 얻기 위한 정적 메서드
    static GpioPin& getInstance(int pinNumber) {
        // Thread-safe initialization using static local variable (C++11 feature)
        // 정적 지역 변수를 사용한 스레드 안전 초기화 (C++11 기능)
        static std::map<int, std::unique_ptr<GpioPin>> instances;

        // If instance for this pin doesn't exist, create it
        // 이 핀에 대한 인스턴스가 없으면 생성
        if (instances.find(pinNumber) == instances.end()) {
            // Use unique_ptr to manage the instance
            // unique_ptr로 인스턴스 관리
            instances[pinNumber] = std::unique_ptr<GpioPin>(new GpioPin(pinNumber));
        }

        return *instances[pinNumber];
    }

    // Delete copy constructor to prevent copying
    // 복사를 방지하기 위해 복사 생성자 삭제
    GpioPin(const GpioPin&) = delete;

    // Delete copy assignment operator to prevent copying
    // 복사를 방지하기 위해 복사 대입 연산자 삭제
    GpioPin& operator=(const GpioPin&) = delete;

    // Delete move constructor to prevent moving
    // 이동을 방지하기 위해 이동 생성자 삭제
    GpioPin(GpioPin&&) = delete;

    // Delete move assignment operator to prevent moving
    // 이동을 방지하기 위해 이동 대입 연산자 삭제
    GpioPin& operator=(GpioPin&&) = delete;

    // Method to set pin high
    // 핀을 HIGH로 설정하는 메서드
    void setHigh() {
        state = true;
        std::cout << "[GPIO" << pin << "] Set to HIGH" << std::endl;
    }

    // Method to set pin low
    // 핀을 LOW로 설정하는 메서드
    void setLow() {
        state = false;
        std::cout << "[GPIO" << pin << "] Set to LOW" << std::endl;
    }

    // Method to get pin state
    // 핀 상태를 얻는 메서드
    bool getState() const {
        return state;
    }

    // Destructor (must be public for unique_ptr)
    // 소멸자 (unique_ptr를 위해 public이어야 함)
    ~GpioPin() {
        std::cout << "GPIO pin " << pin << " released" << std::endl;
    }

private:
    int pin;
    bool state;

    // Private constructor to prevent direct instantiation
    // 직접 인스턴스화를 방지하기 위한 private 생성자
    explicit GpioPin(int pinNumber) : pin(pinNumber), state(false) {
        std::cout << "GPIO pin " << pin << " initialized" << std::endl;
    }

    // Friend declaration to allow unique_ptr to access private constructor
    // unique_ptr가 private 생성자에 접근할 수 있도록 friend 선언
    friend std::unique_ptr<GpioPin>::deleter_type;
};

int main() {
    // Get instances for different GPIO pins
    // 다른 GPIO 핀에 대한 인스턴스 얻기
    GpioPin& led = GpioPin::getInstance(13);      // LED on pin 13
    GpioPin& motor = GpioPin::getInstance(5);     // Motor on pin 5
    GpioPin& sensor = GpioPin::getInstance(7);    // Sensor on pin 7

    // Control the GPIO pins
    // GPIO 핀 제어
    led.setHigh();      // Turn on LED
    motor.setHigh();    // Start motor
    sensor.setLow();    // Disable sensor

    std::cout << "\n";

    // Get the same instance again (should not create a new one)
    // 같은 인스턴스를 다시 얻기 (새로 생성되지 않아야 함)
    GpioPin& led_again = GpioPin::getInstance(13);
    led_again.setLow(); // Turn off LED

    // Verify both references point to the same object
    // 두 참조가 같은 객체를 가리키는지 확인
    std::cout << "\nAddress of led:       " << &led << std::endl;
    std::cout << "Address of led_again: " << &led_again << std::endl;
    std::cout << "Are they the same? " << (&led == &led_again ? "Yes" : "No") << std::endl;
    std::cout << "LED state: " << (led.getState() ? "HIGH" : "LOW") << std::endl;

    return 0;
}
