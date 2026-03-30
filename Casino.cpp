#include "Casino.h"
#include <iostream>
#include <fstream>

Casino::Casino(const std::string& playerName, double startingBalance) : player(playerName, startingBalance), running(true) {
    loadBalance();
}

void Casino::displayTitle() const {
    std::cout << "Casino Simulator: \n";
    std::cout << "Player: " << player.getName() << "\n";
    std::cout << "Balance: $" << player.getBalance() << "\n\n";
}

void Casino::displayMenu() const {
    std::cout << "1. Blackjack\n";
    std::cout << "2. Roulette\n";
    std::cout << "3. SicBo\n";
    std::cout << "4. Slots\n";
    std::cout << "5. Save Game\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

void Casino::saveBalance() {
    std::ofstream outFile("save.txt");

    if (outFile.is_open()) {
        outFile << player.getBalance();
        outFile.close();
    }
}

void Casino::loadBalance() {
    std::ifstream inFile("save.txt");

    double savedBalance;

    if (inFile.is_open()) {
        inFile >> savedBalance;
        inFile.close();
    }
}

void Casino::run() {
    int choice;

    while (running) {
        displayTitle();
        displayMenu();

        std::cin >> choice;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input, try again!\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Blackjack coming soon...\n\n";
            break;

            case 2:
                std::cout << "Roulette coming soon...\n\n";
            break;

            case 3:
                std::cout << "Baccarat coming soon...\n\n";
            break;

            case 4:
                  std::cout << "SicBo coming soon...\n\n";

            case 5:
                saveBalance();
            std::cout << "Game saved.\n\n";
            break;

            case 6:
                saveBalance();
            std::cout << "Thanks for playing!\n";
            running = false;
            break;

            default:
                std::cout << "Invalid menu option.\n\n";
        }
    }
}
