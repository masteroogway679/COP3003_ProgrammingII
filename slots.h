 
// slots class derived from Game class
#pragma once
#include "Game.h"

class Slots : public Game {
private:
int winCount, randomInteger2();
public:
	void play() override;
};

 
