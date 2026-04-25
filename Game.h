#include "Player.h"

class Game {
protected:
    Player* player;

template <typename T>
bool isBetween(T value, T min, T max) const {
    return value >= min && value <= max;
}


public:
    // Constructor
    Game(Player* p);

    // derived classes will implement their own play functions!
    virtual void play() = 0;
    // virtual functions need destructors
    virtual ~Game();
};
