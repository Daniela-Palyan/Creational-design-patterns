#include <iostream>

class Logger {
    private:
    static Logger* instance; 
    Logger() {}

    public:

    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;


    static Logger* get_Instance() {
        if (!instance) {
            instance = new Logger;
        }
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }

};

Logger* Logger::instance = nullptr;


int main() {
    Logger* l1 = Logger::get_Instance();
    l1->log("Making first logger...");
    Logger* l2 = Logger::get_Instance();
    l2->log("Making second one....");
    l2->log("Comparing them...");
    if (l1 == l2) l1 -> log("Loggers are the same!");
    else l1 -> log("Loggers are different!");

    return 0;
}