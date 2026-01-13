#include <iostream>
#include <string>

// The 'T' stands for Type (you can name it anything, but T is standard)
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Works with integers
    std::cout << "Max of 10, 20: " << myMax(10, 20) << std::endl;

    // Works with doubles
    std::cout << "Max of 5.5, 2.2: " << myMax(5.5, 2.2) << std::endl;

    // Works with strings!
    std::string s1 = "Apple", s2 = "Zebra";
    mySwap(s1, s2);
    std::cout << "Swapped Strings: " << s1 << ", " << s2 << std::endl;

    return 0;
}