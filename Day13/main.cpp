#include <iostream>

class MyData {
public:
    int* val;

    MyData(int v) {
        val = new int(v);
    }

    // 1. Copy Constructor (Deep Copy)
    MyData(const MyData& other) {
        val = new int(*other.val); // Allocate new memory
        std::cout << "Deep Copy Performed!" << std::endl;
    }

    // 2. Destructor
    ~MyData() {
        delete val;
        std::cout << "Memory Freed!" << std::endl;
    }
};

int main() {
    MyData obj1(100);
    MyData obj2 = obj1; // Calls Copy Constructor

    *obj2.val = 200; // Changing obj2 won't affect obj1

    std::cout << "Obj1: " << *obj1.val << " | Obj2: " << *obj2.val << std::endl;

    return 0; // Both objects deleted safely!
}