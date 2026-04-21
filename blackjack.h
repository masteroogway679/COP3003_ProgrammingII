#pragma once
#include <vector>
#include <string>

class MiniBlackjack {
public:
    MiniBlackjack();

    void startGame(double bet);
    void hit();
    void stand();

    int getPlayerScore() const;
    int getDealerScore() const;

    std::string getResult() const;
    bool isGameOver() const;

private:
    std::vector<int> playerHand;
    std::vector<int> dealerHand;

    int drawCard();
    int calculateScore(const std::vector<int>& hand) const;

    double currentBet;
    std::string result;
    bool gameOver;
};
