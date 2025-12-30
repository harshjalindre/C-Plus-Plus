#include <iostream>

int main() {
    int x = 5;
    int y = 10;

    // 1. Pointer to Constant Data
    const int* ptr1 = &x; 
    // *ptr1 = 7; // ERROR: Cannot change the data
    ptr1 = &y;    // OK: Can change the address

    // 2. Constant Pointer
    int* const ptr2 = &x;
    *ptr2 = 7;    // OK: Can change the data
    // ptr2 = &y; // ERROR: Cannot change the address

    // 3. Compile-time constant (Modern C++)
    constexpr int max_limit = 100; // Resolved during compilation
    
    std::cout << "ptr1 value: " << *ptr1 << "\nptr2 value: " << *ptr2 << std::endl;

    return 0;
}