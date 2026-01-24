#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

// Template Class for versatile data storage
template <typename T>
class Resource {
public:
    std::string name;
    T* data;

    Resource(std::string n, T val) : name(n), data(new T(val)) {}

    // Move Constructor: Efficiency is key for Day 30!
    Resource(Resource&& other) noexcept : name(std::move(other.name)), data(other.data) {
        other.data = nullptr;
        std::cout << "[System] Resource '" << name << "' moved into Vault.\n";
    }

    ~Resource() { delete data; }
    
    // Disable copying to enforce modern standards
    Resource(const Resource&) = delete;
};

int main() {
    std::vector<Resource<std::string>> vault;

    // 1. Add a resource using Move Semantics
    Resource<std::string> note("Secret", "C++ is Powerful");
    vault.push_back(std::move(note));

    // 2. Save Vault State to File
    std::ofstream outFile("vault.txt");
    for(const auto& res : vault) {
        outFile << res.name << ": " << *(res.data) << "\n";
    }
    outFile.close();

    std::cout << "\nVault Status: Saved and Optimized. Mission Accomplished.\n";
    return 0;
}