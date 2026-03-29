#progma once
#include "Game.h"

class sicBo : public Game {
private:
	int m_winningMatch = 0, m_losingMatch = 0, m_diceNumber = 0, m_dice1 = 0, m_dice2 = 0, m_dice3 = 0, m_bet = 0;
public:
	void play() override;  
	double singleDieBet() const;
	double dieCombinations() const;
	double dieTotals() const;
};
