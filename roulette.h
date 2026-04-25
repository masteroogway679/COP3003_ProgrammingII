#include "Roulette.h"
#include <cstdlib>
#include <ctime>


void Roulette::play() {

}


int Roulette::spinWheel() {
    winningNumber = std::rand() % 37;   // 0 to 36
    return winningNumber;
}

std::string Roulette::applyResult(double amount, int chosenNumber, int winningNumber) {
    if (chosenNumber == winningNumber) {
        player -> deposit(amount * 35.0);
        return "You win!";
    }

    else {
        return "You lose!";
    }


}




 


