#include "Roulette.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Roulette::Roulette(Player* p) : Game(p), winningNumber(0) {
    std::srand(std::time(nullptr));
}

int Roulette::spinWheel() {
    return std::rand() % 37;   // 0 to 36
}

void Roulette::play() {

        if (player->getBalance() <= 0) {
            std::cout << "You have no money left to bet.\n\n";
            return;
        }

    double betAmount;
    int chosenNumber;

    std::cout << "\nRoulette: \n";
    std::cout << "Current Balance: $" << player->getBalance() << "\n";

    std::cout << "Enter bet amount: $";
    std::cin >> betAmount;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input.\n\n";
        return;
    }

    if (betAmount <= 0 || betAmount > player->getBalance()) {
        std::cout << "Invalid bet amount.\n\n";
        return;
    }

    std::cout << "Choose a number (0-36): ";
    std::cin >> chosenNumber;

    if (chosenNumber < 0 || chosenNumber > 36) {
        std::cout << "Invalid number. Choose 0 through 36.\n\n";
        return;
    }

    player->withdraw(betAmount);

    winningNumber = spinWheel();

    std::cout << "The wheel spins...\n";
    std::cout << "Winning number: " << winningNumber << "\n";

    if (chosenNumber == winningNumber) {
        double winnings = betAmount * 35;
        player->deposit(winnings + betAmount);

        std::cout << "You win $" << winnings << "!\n";
    }
    else {
        std::cout << "You lose.\n";
    }

    std::cout << "New Balance: $" << player->getBalance() << "\n\n";
}
