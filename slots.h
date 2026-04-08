#pragma once

#include "Game.h"

class Slots : public Game {
private:
    int randomInteger();

public:
    Slots(Player* p) : Game(p) {}

    void play() override;
};
