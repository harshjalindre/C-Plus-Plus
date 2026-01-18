#include <iostream>
#include <vector>
#include <algorithm> // Required for STL algorithms

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // 1. Standard Sort (Ascending)
    std::sort(numbers.begin(), numbers.end());

    // 2. Custom Sort using a Lambda (Descending)
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b; 
    });

    std::cout << "Sorted: ";
    for (int n : numbers) std::cout << n << " ";

    // 3. Find_if with a Lambda
    // Finds the first number greater than 5
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });

    if (it != numbers.end()) {
        std::cout << "\nFirst number > 5: " << *it << std::endl;
    }

    // 4. Count_if
    int evens = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "Count of even numbers: " << evens << std::endl;

    return 0;
}