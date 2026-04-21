#ifndef SICBO_H
#define SICBO_H

#pragma once
#include "Game.h"
#include <vector>

class SicBo : public Game {
private:
    int diceNumber, winCount, randomInteger();
public:
    int getNumber();
    std::vector<int> getDice();
    int evaulate(const std::vector <int>& diceResults, int diceNumber);
    std::string applyResult(double amount, int winCount);

    SicBo(Player* p) : Game(p) {}
    void play() override;
};

#endif // SICBO_H
