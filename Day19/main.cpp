#include <iostream>

class PoweredDevice {
public:
    PoweredDevice(int power) {
        std::cout << "PoweredDevice initialized with " << power << "W" << std::endl;
    }
};

// Use 'virtual' here to solve the diamond problem
class Scanner : virtual public PoweredDevice {
public:
    Scanner(int power) : PoweredDevice(power) {}
};

// Use 'virtual' here as well
class Printer : virtual public PoweredDevice {
public:
    Printer(int power) : PoweredDevice(power) {}
};

// Copier inherits from both
class Copier : public Scanner, public Printer {
public:
    Copier(int power) : PoweredDevice(power), Scanner(power), Printer(power) {
        std::cout << "Copier ready!" << std::endl;
    }
};

int main() {
    Copier myCopier(500);
    return 0;
}