#include "Game.h"

class Roulette : public Game {
private:
    int winningNumber;

    int spinWheel();

public:
    Roulette(Player* p);

    void play() override;
};

