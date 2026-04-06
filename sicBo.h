#pragma once
#include "Game.h"

class SicBo : public Game {
private:
    int winningMatch, losingMatch, outcome, choice, frequency, dice_number, dice1, dice2, dice3, bet, randomInteger();
public:
    SicBo(Player* p) : Game(p) {}

    void play() override;
    double singleDieBet() const;
    double dieCombinations() const;
    double dieTotals() const;


};
