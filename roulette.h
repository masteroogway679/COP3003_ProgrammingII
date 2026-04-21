#include "Roulette.h"
#include <cstdlib>
#include <ctime>

void Roulette::play() {

}

Roulette::Roulette(Player* p) : Game(p), winningNumber(0) {
    std::srand(std::time(nullptr));
}

int Roulette::spinWheel() {
    int winningNumber = std::rand() % 37;   // 0 to 36
    return winningNumber;
}

std::string Roulette::applyResult(double amount, int chosenNumber) {
    if (chosenNumber == winningNumber) {
        player -> deposit(amount * 35.0);
        return "You win!";
    }

    else {
        return "You lose!";
    }
}



