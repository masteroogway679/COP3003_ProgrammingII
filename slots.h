#ifndef SLOTS_H
#define SLOTS_H

#pragma once
#include "Game.h"
#include <vector>

class Slots : public Game {
private:
    int randomInteger();

public:
    Slots(Player* p) : Game(p) {}

    // NEW: spin function
    std::vector<int> spin();

    // NEW: evaluate result
    int evaluate(const std::vector<int>& slotNum);

    // NEW: apply result to player
    std::string applyResult(double amount, int winCount);

    void play() override;
};

#endif // SLOTS_H
