#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    static int player_count; // Declaration

public:
    Player(std::string n) : name(n) {
        player_count++; // Every time a player is born, count goes up
    }

    ~Player() {
        player_count--; // Every time a player is destroyed, count goes down
    }

    // Static method: can be called using Player::get_count()
    static int get_count() {
        return player_count;
    }

    // Giving a non-member function VIP access
    friend void cheat_score(Player& p);
};

// Definition and Initialization of static member (Required!)
int Player::player_count = 0;

void cheat_score(Player& p) {
    // This function is NOT in the class, but can see private data because of 'friend'
    std::cout << "Accessing private data of " << p.name << " via friendship!" << std::endl;
}

int main() {
    std::cout << "Starting players: " << Player::get_count() << std::endl;

    Player* p1 = new Player("Hero");
    Player p2("Sidekick");

    std::cout << "Active players: " << Player::get_count() << std::endl;

    cheat_score(p2);

    delete p1;
    std::cout << "Players after one leaves: " << Player::get_count() << std::endl;

    return 0;
}