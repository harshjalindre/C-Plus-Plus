#include <iostream>
#include <memory> // Required for smart pointers

class Gizmo {
public:
    Gizmo() { std::cout << "Gizmo Created!" << std::endl; }
    ~Gizmo() { std::cout << "Gizmo Destroyed Automatically!" << std::endl; }
    void doWork() { std::cout << "Gizmo is working..." << std::endl; }
};

int main() {
    std::cout << "--- Unique Pointer Scope ---" << std::endl;
    {
        // 1. Create a unique pointer
        std::unique_ptr<Gizmo> myGizmo = std::make_unique<Gizmo>();
        myGizmo->doWork();
        
        // No copy allowed: 
        // std::unique_ptr<Gizmo> copyGizmo = myGizmo; // ERROR!
    } // myGizmo goes out of scope here -> Destructor called!

    std::cout << "\n--- Shared Pointer Scope ---" << std::endl;
    std::shared_ptr<Gizmo> shared1 = std::make_shared<Gizmo>();
    {
        std::shared_ptr<Gizmo> shared2 = shared1; // Copying is OK!
        std::cout << "Reference count: " << shared1.use_count() << std::endl;
    } // shared2 dies, but shared1 is still alive
    
    std::cout << "Reference count after inner scope: " << shared1.use_count() << std::endl;

    return 0;
} // shared1 dies here -> Gizmo destroyed!