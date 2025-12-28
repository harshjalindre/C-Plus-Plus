#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // Pointer: I can point to 'a', then change to 'b'
    int* ptr = &a;
    std::cout << "Pointer points to: " << *ptr << std::endl;
    ptr = &b; 
    std::cout << "Pointer now points to: " << *ptr << std::endl;

    // Reference: I'm just a nickname for 'a'
    int& ref = a;
    std::cout << "Reference value: " << ref << std::endl;
    
    // Changing ref changes 'a' itself!
    ref = 100;
    std::cout << "Value of 'a' after ref change: " << a << std::endl;

    return 0;
}