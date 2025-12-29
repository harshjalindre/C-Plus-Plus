#include <iostream>
#include <vector>
#include <string>

// 1. Pass by Value (The Expensive Way)
// Copies the entire vector. If vector has 1M elements, it copies 1M elements.
void processByValue(std::vector<int> vec) {
    std::cout << "Processing copy of size: " << vec.size() << std::endl;
}

// 2. Pass by Reference (The Efficiency Way)
// No copy is made. 'const' prevents accidental modification.
void processByConstRef(const std::vector<int>& vec) {
    std::cout << "Processing original of size: " << vec.size() << std::endl;
}

// 3. Pass by Pointer (The Optional Way)
// Useful if the data might not exist (nullptr).
void processByPointer(std::vector<int>* vecPtr) {
    if (vecPtr) {
        std::cout << "Pointer accessed vector of size: " << vecPtr->size() << std::endl;
    } else {
        std::cout << "No data provided (nullptr)." << std::endl;
    }
}

int main() {
    // Creating a large dataset: 1 million integers
    std::vector<int> largeData(1000000, 100);
    // Call 1: Creating a redundant copy (High memory overhead)
    processByValue(largeData);

    // Call 2: The "Golden Rule" (Zero-copy, high performance)
    processByConstRef(largeData);

    // Call 3: Using a pointer for optionality
    processByPointer(&largeData);
    processByPointer(nullptr);

    return 0;
}