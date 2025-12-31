#include <iostream>

// Struct with potential padding
struct DatabaseEntry {
    char id;      // 1 byte
    // 3 bytes of padding likely added here by compiler
    int value;    // 4 bytes
    char grade;   // 1 byte
    // 3 bytes of padding likely added here at the end
};

union DataPacket {
    int intVal;
    float floatVal;
};

int main() {
    DatabaseEntry entry;
    DataPacket packet;

    std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    
    // You might expect 1+4+1 = 6, but it will likely be 12!
    std::cout << "Actual size of DatabaseEntry: " << sizeof(entry) << " bytes" << std::endl;

    packet.intVal = 65; 
    std::cout << "Union as Int: " << packet.intVal << std::endl;
    // Changing the same memory location!
    std::cout << "Union as Float: " << packet.floatVal << std::endl;

    return 0;
}