#include <iostream>
#include <string>
#include <string_view>

void printName(std::string_view name) {
    std::cout << "Hello, " << name << std::endl;
}

int main() {
    // Traditional Array
    int ages[3] = {20, 25, 30};

    // Modern String vs View
    std::string s = "Harsh"; 
    std::string_view sv = s; // No copy made!

    printName(sv);
    printName("Fast Constant String"); // Efficient!

    return 0;
}