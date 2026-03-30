#include "Player.h"

class Game {
protected:
    Player* player;

public:
    // Constructor
    Game(Player* p);

    // derived classes will implement their own play functions!
    virtual void play() = 0;
};
