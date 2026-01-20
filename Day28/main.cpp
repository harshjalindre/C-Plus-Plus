#include <iostream>
#include <fstream> // Required for file operations
#include <string>

int main() {
    std::string fileName = "day28_log.txt";

    // 1. Writing to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << "Day 28: I have mastered File I/O in C++!" << std::endl;
        outFile << "Writing to the disk is easier than I thought." << std::endl;
        outFile.close(); // Explicitly closing, though RAII would do it
        std::cout << "Data written successfully." << std::endl;
    } else {
        std::cerr << "Error: Could not create file!" << std::endl;
    }

    // 2. Reading from a file
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        std::cout << "\nReading from file contents:" << std::endl;
        while (std::getline(inFile, line)) {
            std::cout << ">> " << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error: Could not open file for reading!" << std::endl;
    }

    return 0;
}