#include <iostream>
#include <string>

class BankAccount {
private:
    // Hidden data (Encapsulation)
    std::string owner;
    double balance;

public:
    // Constructor to initialize data
    BankAccount(std::string name, double initialBalance) {
        owner = name;
        balance = initialBalance;
    }

    // Public method to modify private data safely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        }
    }

    void display() {
        std::cout << "Account: " << owner << " | Balance: $" << balance << std::endl;
    }
};

int main() {
    BankAccount myAccount("Harsh", 1000.0);

    myAccount.deposit(500.0);
    myAccount.display();

    // myAccount.balance = 1000000; // ERROR: balance is private!
    
    return 0;
}