#include <iostream>
#include <memory>
#include <string>

class Notification {
public:
    virtual void notify() const = 0;
    virtual ~Notification() = default;
};

class WindowsEmailNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Windows: Sending Email Notification" << std::endl;
    }
};

class WindowsSMSNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Windows: Sending SMS Notification" << std::endl;
    }
};

class WindowsPushNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Windows: Sending Push Notification" << std::endl;
    }
};

class MacOSEmailNotification: public Notification {
public:
    void notify() const override {
        std::cout << "MacOS: Sending Email Notification" << std::endl;
    }
};

class MacOSSMSNotification: public Notification {
public:
    void notify() const override {
        std::cout << "MacOS: Sending SMS Notification" << std::endl;
    }
};

class MacOSPushNotification: public Notification {
public:
    void notify() const override {
        std::cout << "MacOS: Sending Push Notification" << std::endl;
    }
};

class LinuxEmailNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Linux: Sending Email Notification" << std::endl;
    }
};

class LinuxSMSNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Linux: Sending SMS Notification" << std::endl;
    }
};

class LinuxPushNotification: public Notification {
public:
    void notify() const override {
        std::cout << "Linux: Sending Push Notification" << std::endl;
    }
};

class NotificationFactory {
public:
    virtual std::unique_ptr<Notification> createNotification(const std::string& type) const = 0;
    virtual ~NotificationFactory() = default;
};

class WindowsNotificationFactory: public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification(const std::string& type) const override {
        std::unique_ptr<Notification> ptr = nullptr;
        if (type == "email") ptr = std::make_unique<WindowsEmailNotification>();
        else if (type == "sms") ptr = std::make_unique<WindowsSMSNotification>();
        else if (type == "push") ptr = std::make_unique<WindowsPushNotification>();
        return ptr;
    }
};

class MacOSNotificationFactory: public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification(const std::string& type) const override {
        std::unique_ptr<Notification> ptr = nullptr;
        if (type == "email") ptr = std::make_unique<MacOSEmailNotification>();
        else if (type == "sms") ptr = std::make_unique<MacOSSMSNotification>();
        else if (type == "push") ptr = std::make_unique<MacOSPushNotification>();
        return ptr;
    }
};

class LinuxNotificationFactory: public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification(const std::string& type) const override {
        std::unique_ptr<Notification> ptr = nullptr;
        if (type == "email") ptr = std::make_unique<LinuxEmailNotification>();
        else if (type == "sms") ptr = std::make_unique<LinuxSMSNotification>();
        else if (type == "push") ptr = std::make_unique<LinuxPushNotification>();
        return ptr;
    }
};

int main() {
    std::string platform, type;
    std::unique_ptr<NotificationFactory> factory = nullptr;

    std::cout << "Enter platform (windows/mac/linux): ";
    std::cin >> platform;

    if (platform == "windows") {
        factory = std::make_unique<WindowsNotificationFactory>();
    }
    else if (platform == "mac") {
        factory = std::make_unique<MacOSNotificationFactory>();
    }
    else if (platform == "linux") {
        factory = std::make_unique<LinuxNotificationFactory>();
    }

    while (!factory) {
        std::cout << "Invalid platform name! Try again!" << std::endl;
        std::cout << "Enter platform (windows/mac/linux): ";
        std::cin >> platform;

        if (platform == "windows") {
            factory = std::make_unique<WindowsNotificationFactory>();
        }
        else if (platform == "mac") {
            factory = std::make_unique<MacOSNotificationFactory>();
        }
        else if (platform == "linux") {
            factory = std::make_unique<LinuxNotificationFactory>();
        }
    }

    std::cout << "Enter notification type (email/sms/push): ";
    std::cin >> type;

    auto notification = factory->createNotification(type);

    while (!notification) {
        std::cout << "Invalid notification type name! Try again! " << std::endl;
        std::cout << "Enter notification type (email/sms/push): ";
        std::cin >> type;
        notification = factory->createNotification(type);
    }

    notification->notify();

    return 0;
}
