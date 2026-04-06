#pragma once
#include "Game.h"

class SicBo : public Game {
private:
    int diceNumber, winCount, randomInteger();
public:
    SicBo(Player* p) : Game(p) {}
    void play() override;
};
