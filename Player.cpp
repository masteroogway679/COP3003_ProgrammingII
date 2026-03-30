#include "Player.h"

// Constructor
Player::Player(const std::string& name, double initialBalance) : name(name), balance(initialBalance) {}

// Getters
std::string Player::getName() const {
    return name;
}

double Player::getBalance() const {
    return balance;
}

// Deposit
void Player::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

// Withdraw (true if successful)
bool Player::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}