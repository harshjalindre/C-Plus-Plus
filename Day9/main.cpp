#include <iostream>
#include "config.h"
#include "config.h" // Including it twice on purpose!

int main() {
    // If you didn't have Header Guards, this would fail to compile
    std::cout << "Project Version: " << VERSION << std::endl;
    return 0;
}