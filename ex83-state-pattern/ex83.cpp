#include <iostream>
#include <memory>

// Forward declaration
class Device;

// Forward declarations for concrete states
class StandbyState;
class OnState;

// State interface
class PowerState {
public:
    virtual void powerButton(Device& device) = 0;
    virtual ~PowerState() = default;
};

// Device class
class Device {
private:
    std::shared_ptr<PowerState> state;

public:
    Device() {
        state = std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>());
        std::cout << "Device initialized in Standby\n";
    }

    void setState(const std::shared_ptr<PowerState>& newState) {
        state = newState;
    }

    void pressPowerButton() {
        state->powerButton(*this);
    }
};

// Concrete states
class StandbyState : public PowerState {
public:
    void powerButton(Device& device) override;  // 선언만 하고
};

class OnState : public PowerState {
public:
    void powerButton(Device& device) override;  // 선언만 하고
};

// 구현부를 클래스 정의 후로 이동
void StandbyState::powerButton(Device& device) {
    std::cout << "Turning ON\n";
    device.setState(std::static_pointer_cast<PowerState>(std::make_shared<OnState>()));
}

void OnState::powerButton(Device& device) {
    std::cout << "Turning OFF\n";
    device.setState(std::static_pointer_cast<PowerState>(std::make_shared<StandbyState>()));
}

int main() {
    auto device = std::make_unique<Device>();
    
    device->pressPowerButton();  // Standby -> On
    device->pressPowerButton();  // On -> Standby
    device->pressPowerButton();  // Standby -> On

    return 0;
}