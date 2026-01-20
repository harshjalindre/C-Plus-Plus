#include <iostream>
#include <string>
#include <memory>

// --- SINGLETON PATTERN ---
// Ensures only ONE instance of the settings exists
class Configuration {
private:
    Configuration() { std::cout << "Settings Loaded Once.\n"; }
public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }
    void showVersion() { std::cout << "App Version 1.0\n"; }
};

// --- FACTORY PATTERN ---
// Creates different types of 'Notifications' dynamically
class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() {}
};

class Email : public Notification {
    void send() override { std::cout << "Sending Email...\n"; }
};

class SMS : public Notification {
    void send() override { std::cout << "Sending SMS...\n"; }
};

class NotificationFactory {
public:
    static std::unique_ptr<Notification> create(int choice) {
        if (choice == 1) return std::make_unique<Email>();
        return std::make_unique<SMS>();
    }
};

int main() {
    // Singleton access
    Configuration::getInstance().showVersion();

    // Factory creation
    auto myNotify = NotificationFactory::create(1);
    myNotify->send();

    return 0;
}