#progma once
#include "Game.h"

class sicBo : public Game {
private:
	int winningMatch, losingMatch, outcome, choice, frequency, dice_number, dice1, dice2, dice3, bet;
public: 
	void play() override;  
	double singleDieBet() const;
	double dieCombinations() const;
	double dieTotals() const;
};
