#include <iostream>
#include <string>

// Define the template
template <typename T>
class Box {
private:
    T contents;
public:
    Box(T item) : contents(item) {}

    void setContents(T item) { contents = item; }
    T getContents() const { return contents; }

    void display() const {
        std::cout << "Box contains: " << contents << std::endl;
    }
};

int main() {
    // A box for integers
    Box<int> intBox(123);
    intBox.display();

    // A box for strings
    Box<std::string> nameBox("C++ Templates");
    nameBox.display();

    // A box for doubles
    Box<double> priceBox(19.99);
    priceBox.display();

    return 0;
}