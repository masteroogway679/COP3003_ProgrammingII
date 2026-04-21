#include "Blackjack.h"
#include <cstdlib>
#include <ctime>

MiniBlackjack::MiniBlackjack() {
    std::srand(std::time(nullptr));
}

int MiniBlackjack::drawCard() {
    return (std::rand() % 10) + 1; // 1–10
}

int MiniBlackjack::calculateScore(const std::vector<int>& hand) const {
    int total = 0;
    for (int card : hand) total += card;
    return total;
}

void MiniBlackjack::startGame(double bet) {
    playerHand.clear();
    dealerHand.clear();
    gameOver = false;
    result = "";
    currentBet = bet;

    playerHand.push_back(drawCard());
    playerHand.push_back(drawCard());

    dealerHand.push_back(drawCard());
}

void MiniBlackjack::hit() {
    if (gameOver) return;

    playerHand.push_back(drawCard());

    if (calculateScore(playerHand) > 21) {
        result = "Bust! You lose.";
        gameOver = true;
    }
}

void MiniBlackjack::stand() {
    if (gameOver) return;

    while (calculateScore(dealerHand) < 17) {
        dealerHand.push_back(drawCard());
    }

    int playerScore = calculateScore(playerHand);
    int dealerScore = calculateScore(dealerHand);

    if (dealerScore > 21 || playerScore > dealerScore) {
        result = "You win!";
    } else if (playerScore < dealerScore) {
        result = "Dealer wins!";
    } else {
        result = "Push (tie)";
    }

    gameOver = true;
}

int MiniBlackjack::getPlayerScore() const {
    return calculateScore(playerHand);
}

int MiniBlackjack::getDealerScore() const {
    return calculateScore(dealerHand);
}

std::string MiniBlackjack::getResult() const {
    return result;
}

bool MiniBlackjack::isGameOver() const {
    return gameOver;
}
