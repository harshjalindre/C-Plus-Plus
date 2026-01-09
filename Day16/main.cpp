#include <iostream>
#include <string>

// Base Class
class Entity {
protected:
    std::string name;
public:
    Entity(std::string n) : name(n) {}
    
    void announce() {
        std::cout << "I am an entity named " << name << std::endl;
    }
};

// Derived Class
class Player : public Entity {
private:
    int level;
public:
    // Calling the Parent Constructor specifically
    Player(std::string n, int l) : Entity(n), level(l) {}

    void showStats() {
        // We can access 'name' because it's PROTECTED, not private
        std::cout << "Player: " << name << " | Level: " << level << std::endl;
    }
};

int main() {
    Player p1("Slayer_99", 15);
    
    p1.announce();  // Inherited method
    p1.showStats(); // Child specific method

    return 0;
}