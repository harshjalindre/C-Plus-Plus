#include <iostream>
#include <map>
#include <string>
#include <set>

int main() {
    // 1. std::map (Sorted by name)
    std::map<std::string, int> scores;
    scores["Rohit"] = 1500;
    scores["Viraj"] = 9000;
    scores["MS"] = 2300;

    // Searching for a key
    std::string searchName = "Rohit";
    if (scores.find(searchName) != scores.end()) {
        std::cout << searchName << "'s Score: " << scores[searchName] << std::endl;
    }

    // 2. std::set (Only keeps unique values)
    std::set<int> uniqueIDs;
    uniqueIDs.insert(101);
    uniqueIDs.insert(102);
    uniqueIDs.insert(101); // This will be ignored!

    std::cout << "Unique IDs count: " << uniqueIDs.size() << std::endl;

    // 3. Iterating through a map
    std::cout << "\nFull Scoreboard:" << std::endl;
    for (const auto& [name, score] : scores) { // Modern C++17 Structured Binding
        std::cout << name << ": " << score << std::endl;
    }

    return 0;
}