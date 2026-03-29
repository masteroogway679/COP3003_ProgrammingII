 // slots class derived from Player class

class Slots : public Game {
private:
	int m_winningMatch{ 0 }, m_losingMatch{ 0 }, m_reelOutcome{ 0 };
public:
	void play() override;
	double spinReel const();  
};

 
