#include <iostream>
#include <vector>
#include <string>

int main() {
    // 1. Declaration and Initialization
    std::vector<std::string> shoppingList = {"Milk", "Eggs", "Bread"};

    // 2. Dynamic growth
    shoppingList.push_back("Coffee");
    shoppingList.push_back("C++ Books");

    std::cout << "Items in list: " << shoppingList.size() << std::endl;

    // 3. Modern way to iterate (Range-based for loop)
    std::cout << "\nUsing Range-based loop:" << std::endl;
    for (const std::string& item : shoppingList) {
        std::cout << "- " << item << std::endl;
    }

    // 4. The "Under the hood" way: Manual Iterators
    std::cout << "\nUsing Manual Iterators:" << std::endl;
    std::vector<std::string>::iterator it;
    for (it = shoppingList.begin(); it != shoppingList.end(); ++it) {
        std::cout << "Address: " << &(*it) << " | Value: " << *it << std::endl;
    }

    return 0;
}