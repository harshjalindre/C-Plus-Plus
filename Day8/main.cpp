#include <iostream>

// Creating a custom namespace
namespace ProjectA {
    void log() {
        std::cout << "Logging from Project A" << std::endl;
    }
}

namespace ProjectB {
    void log() {
        std::cout << "Logging from Project B" << std::endl;
    }
}

int x = 50; // Global scope

int main() {
    int x = 10; // Local scope (Shadows the global x)

    std::cout << "Local x: " << x << std::endl;
    std::cout << "Global x: " << ::x << std::endl; // Accessing global using ::

    ProjectA::log();
    ProjectB::log();

    {
        int blockVar = 5;
        std::cout << "Inside block: " << blockVar << std::endl;
    }
    // std::cout << blockVar; // ERROR: blockVar is dead here!

    return 0;
}