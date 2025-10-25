#include <iostream>

// Abstract base class for shapes
// 도형을 위한 abstract base class
class Shape {
private:
    std::string color;

public:
    // Constructor with color parameter
    // 색상 parameter를 가진 constructor
    Shape(const std::string& c) : color(c) {}

    // Pure virtual function for calculating area
    // 면적 계산을 위한 pure virtual function
    virtual double getArea() const = 0;

    // Virtual function to display shape information
    // 도형 정보를 표시하는 virtual function
    virtual void printInfo() const {
        std::cout << "Color: " << color << "\n"
                  << "Area: " << getArea() << "\n";
    }

    // Virtual destructor
    // Virtual destructor
    virtual ~Shape() = default;
};

// Circle class derived from Shape
// Shape로부터 derived된 Circle class
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor with color and radius
    // 색상과 반지름을 가진 constructor
    Circle(const std::string& c, double r)
        : Shape(c), radius(r) {}

    // Override area calculation for circle
    // Circle의 면적 계산을 override
    double getArea() const override {
        return 3.14 * radius * radius;
    }

    // Override info display for circle
    // Circle의 정보 표시를 override
    void printInfo() const override {
        std::cout << "Circle Info:\n";
        Shape::printInfo();
    }
};

// Rectangle class derived from Shape
// Shape로부터 derived된 Rectangle class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor with color, width and height
    // 색상, 너비, 높이를 가진 constructor
    Rectangle(const std::string& c, double w, double h)
        : Shape(c), width(w), height(h) {}

    // Override area calculation for rectangle
    // Rectangle의 면적 계산을 override
    double getArea() const override {
        return width * height;
    }

    // Override info display for rectangle
    // Rectangle의 정보 표시를 override
    void printInfo() const override {
        std::cout << "Rectangle Info:\n";
        Shape::printInfo();
    }
};

int main() {
    // Create instances of shapes
    // 도형 객체 생성
    Circle circle("Red", 5);
    Rectangle rectangle("Blue", 4, 6);

    // Display information for each shape
    // 각 도형의 정보 표시
    circle.printInfo();
    std::cout << "\n";
    rectangle.printInfo();

    return 0;
}