#include <iostream>

class Notification {
    public:
    virtual void notify() const = 0;
};

class SMSNotification: public Notification {
    void notify() const override {
        std:: cout << "Sending SMS Notification" << std::endl; 
    }
};

class EmailNotification: public Notification {
    void notify() const override {
        std:: cout << "Sending Email Notification" << std::endl; 
    }
};

class PushNotification: public Notification {
    void notify() const override {
        std:: cout << "Sending Push Notification" << std::endl; 
    }
};

class NotificationFactory {
    public:
    static Notification* createNotification(const std::string& type) {
        Notification* ptr = nullptr;

        if (type == "sms") {
            ptr = new SMSNotification;
        }
        else if (type == "email") {
            ptr = new EmailNotification;
        }
        else if (type == "push") {
            ptr = new PushNotification;
        }

        return ptr;
    }
};


int main() {
    std::string type;
    std::cout << "Enter notification type (email/sms/push): ";
    std::cin >> type;
    Notification* ptr = NotificationFactory::createNotification(type);
    ptr->notify();
    delete ptr;

    return 0;
}