#include <iostream>
#include <stdexcept> // For standard exceptions

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Math Error: Attempted to divide by zero!");
    }
    return a / b;
}

int main() {
    double x = 10, y = 0;

    try {
        std::cout << "Attempting division..." << std::endl;
        double result = divide(x, y);
        std::cout << "Result: " << result << std::endl;
    } 
    catch (const std::runtime_error& e) {
        // Catching a specific error
        std::cerr << "Caught an error: " << e.what() << std::endl;
    } 
    catch (...) {
        // The "Catch-All" block
        std::cerr << "An unknown error occurred." << std::endl;
    }

    std::cout << "Program continues to run safely..." << std::endl;
    return 0;
}