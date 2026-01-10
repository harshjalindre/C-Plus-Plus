#include <iostream>

// Abstract Base Class (The Interface)
class SmartDevice {
public:
    virtual ~SmartDevice() {}

    // Pure Virtual Function
    virtual void turnOn() = 0; 

    void identify() {
        std::cout << "I am a smart device." << std::endl;
    }
};

class Light : public SmartDevice {
public:
    void turnOn() override {
        std::cout << "Light: Adjusting brightness to 100%..." << std::endl;
    }
};

class Fan : public SmartDevice {
public:
    void turnOn() override {
        std::cout << "Fan: Spinning up to medium speed..." << std::endl;
    }
};

int main() {
    // SmartDevice generic; // ERROR: Cannot instantiate abstract class
    
    SmartDevice* myLamp = new Light();
    SmartDevice* myFan = new Fan();

    myLamp->turnOn();
    myFan->turnOn();

    delete myLamp;
    delete myFan;

    return 0;
}