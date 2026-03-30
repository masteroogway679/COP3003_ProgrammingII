#include <string>

class Player {
private:
    std::string name;
    double balance;

public:
    // Constructor
    Player(const std::string& name, double initialBalance);

    // Getters
    std::string getName() const;
    double getBalance() const;

    // Balance operations
    void deposit(double amount);
    bool withdraw(double amount);
};
