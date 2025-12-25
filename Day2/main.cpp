#include <iostream>
using namespace std;

int main() {
    // Allocation on the STACK
    int stackVar = 10;
    
    // Allocation on the HEAP
    int* heapVar = new int(20);

    cout << "Stack Address: " << &stackVar << endl;
    cout << "Heap Address:  " << heapVar << endl;

    // IMPORTANT: Manual cleanup for Heap
    delete heapVar; 

    return 0;
}