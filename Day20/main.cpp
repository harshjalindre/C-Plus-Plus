#include <iostream>
#include <vector>
#include <memory>

// Day 18 Concept: Abstract Base Class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
};

// Day 16 Concept: Inheritance
class Circle final : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159265358979323846;

public:
    explicit Circle(double r) : radius(r) {}

    double getArea() const override {
        return PI * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a Circle ⭕\n";
    }
};

class Rectangle final : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing a Rectangle 🟦\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.emplace_back(std::make_unique<Circle>(5.0));
    shapes.emplace_back(std::make_unique<Rectangle>(4.0, 6.0));

    std::cout << "--- Rendering Shapes ---\n";

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->getArea() << "\n\n";
    }

    return 0;
}
