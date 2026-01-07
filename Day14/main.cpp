#include <iostream>

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the + operator
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    // Overloading the << operator (must be a friend or external function)
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p1(10, 20);
    Point p2(5, 5);

    Point p3 = p1 + p2; // Clean and intuitive!

    std::cout << "P1: " << p1 << std::endl;
    std::cout << "P2: " << p2 << std::endl;
    std::cout << "P3 (Sum): " << p3 << std::endl;

    return 0;
}