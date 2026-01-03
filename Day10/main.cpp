#include <iostream>
#include <string>

// Global Namespace
namespace Inspector {
    int globalVar = 100; // Lives in Global/Data Segment
}

void printAddress(const std::string& label, const void* address) {
    std::cout << label << ": \t" << address << std::endl;
}

int main() {
    // 1. Stack Allocation
    int stackVar = 10;

    // 2. Heap Allocation
    int* heapVar = new int(20);

    // 3. String Literal (usually in Data/Text segment)
    const char* stringLiteral = "Hello Memory";

    std::cout << "--- C++ Memory Address Inspector ---" << std::endl;
    
    printAddress("Global Address", &Inspector::globalVar);
    printAddress("Stack Address ", &stackVar);
    printAddress("Heap Address  ", heapVar);
    printAddress("String Literal", (void*)stringLiteral);

    // Cleanup
    delete heapVar;

    return 0;
}