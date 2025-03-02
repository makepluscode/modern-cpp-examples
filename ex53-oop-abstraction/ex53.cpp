#include <iostream>

// Abstract base class for shapes
class Shape {
private:
    std::string color;

public:
    // Constructor with color parameter
    Shape(const std::string& c) : color(c) {}

    // Pure virtual function for calculating area
    virtual double getArea() const = 0;
    
    // Virtual function to display shape information
    virtual void printInfo() const {
        std::cout << "Color: " << color << "\n"
                  << "Area: " << getArea() << "\n";
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor with color and radius
    Circle(const std::string& c, double r) 
        : Shape(c), radius(r) {}

    // Override area calculation for circle
    double getArea() const override {
        return 3.14 * radius * radius;
    }

    // Override info display for circle
    void printInfo() const override {
        std::cout << "Circle Info:\n";
        Shape::printInfo();
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor with color, width and height
    Rectangle(const std::string& c, double w, double h) 
        : Shape(c), width(w), height(h) {}

    // Override area calculation for rectangle
    double getArea() const override {
        return width * height;
    }

    // Override info display for rectangle
    void printInfo() const override {
        std::cout << "Rectangle Info:\n";
        Shape::printInfo();
    }
};

int main() {
    // Create instances of shapes
    Circle circle("Red", 5);
    Rectangle rectangle("Blue", 4, 6);

    // Display information for each shape
    circle.printInfo();
    std::cout << "\n";
    rectangle.printInfo();

    return 0;
}