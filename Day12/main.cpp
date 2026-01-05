#include <iostream>

class Resource {
private:
    int* data;
public:
    // Constructor: Acquiring resource
    Resource() {
        data = new int[100]; 
        std::cout << "Resource acquired (Heap memory allocated)." << std::endl;
    }

    // Destructor: Releasing resource
    ~Resource() {
        delete[] data;
        std::cout << "Resource released (Heap memory freed automatically)." << std::endl;
    }
};

void createScope() {
    Resource myRes; // Constructor called here
    std::cout << "Inside the function scope..." << std::endl;
} // Destructor called here AUTOMATICALLY

int main() {
    std::cout << "Starting main..." << std::endl;
    createScope();
    std::cout << "Back in main. Memory is already clean." << std::endl;
    return 0;
}