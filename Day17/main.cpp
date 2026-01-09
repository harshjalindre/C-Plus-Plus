#include <iostream>
#include <vector>

class Animal {
public:
    // Virtual destructor is CRITICAL when using polymorphism
    virtual ~Animal() {}

    virtual void makeSound() const {
        std::cout << "*Generic Animal Noise*" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // A list of Animal pointers, but containing Dogs and Cats
    std::vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());

    for (Animal* animal : zoo) {
        // Polymorphism: The right sound is made at RUNTIME
        animal->makeSound();
    }

    // Cleanup
    for (Animal* a : zoo) delete a;
    
    return 0;
}