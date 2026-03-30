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
    double betAmount;
    int chosenNumber;

    std::cout << "\nRoulette: \n";
    std::cout << "Current Balance: $" << player->getBalance() << "\n";

    std::cout << "Enter bet amount: $";
    std::cin >> betAmount;

    std::cout << "Choose a number (0-36): ";
    std::cin >> chosenNumber;

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
