#include <iostream>
#include <memory>

// Forward declaration for Device class
// Device class에 대한 forward declaration
class Device;

// Forward declarations for concrete state classes
// 구체적인 state class들에 대한 forward declaration
class StandbyState;
class OnState;

// State interface (abstract class)
// State interface (추상 class)
class PowerState {
public:
    // Pure virtual function for handling power button press
    // Power button 누름을 처리하는 순수 가상 함수
    virtual void powerButton(Device& device) = 0;
    virtual ~PowerState() = default;
};

// Device class that manages its state
// 상태를 관리하는 Device class
class Device {
private:
    // Current state of the device
    // Device의 현재 상태
    std::shared_ptr<PowerState> state;

public:
    // Constructor initializes device in Standby state
    // Constructor는 device를 Standby 상태로 초기화
    Device() {
        state = std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>());
        std::cout << "Device initialized in Standby\n";
    }

    // Method to change the device state
    // Device 상태를 변경하는 method
    void setState(const std::shared_ptr<PowerState>& newState) {
        state = newState;
    }

    // Method to handle power button press
    // Power button 누름을 처리하는 method
    void pressPowerButton() {
        state->powerButton(*this);
    }
};

// Concrete state: Standby
// 구체적인 state: Standby
class StandbyState : public PowerState {
public:
    // Declaration only - implementation below
    // 선언만 - 구현은 아래에
    void powerButton(Device& device) override;
};

// Concrete state: On
// 구체적인 state: On
class OnState : public PowerState {
public:
    // Declaration only - implementation below
    // 선언만 - 구현은 아래에
    void powerButton(Device& device) override;
};

// Implementation of StandbyState::powerButton
// StandbyState::powerButton의 구현
void StandbyState::powerButton(Device& device) {
    std::cout << "Turning ON\n";
    // Transition to On state
    // On 상태로 전환
    device.setState(std::static_pointer_cast<PowerState>(std::make_shared<OnState>()));
}

// Implementation of OnState::powerButton
// OnState::powerButton의 구현
void OnState::powerButton(Device& device) {
    std::cout << "Turning OFF\n";
    // Transition to Standby state
    // Standby 상태로 전환
    device.setState(std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>()));
}

int main() {
    // Create a device instance
    // Device instance 생성
    auto device = std::make_shared<Device>();

    // Press power button multiple times to see state transitions
    // State transition을 보기 위해 power button을 여러 번 누름
    device->pressPowerButton();  // Standby -> On
    device->pressPowerButton();  // On -> Standby
    device->pressPowerButton();  // Standby -> On

    return 0;
}