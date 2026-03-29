casino.cpp

// RANDOM NUMBER GENERATOR
int randomInteger() {
	static random_device rd;
	static default_random_engine engine{ rd() };
	static uniform_int_distribution randomInt{ 1, 10 };

	return randomInt(engine);
}
// RANDOM NUMBER GENERATOR FOR THREE INTEGERS
int threeRandomIntegers() {
    int a{ randomIntegers() };
    int b{ randomIntegers() };
    int c{ randomIntegers() };
    cout << format("Slot results: {} {} {}\n", a, b, c);
    if ((a == b) && (a == c)) {
        return 1;
    }
    else {
        return 0;
    }
}
  
// SLOTS GAME
  class Slots : private Player {
public:
    int winningMatch{ 0 };
    int losingMatch{ 0 };

    void play() override {
        int reelOutcome = threeRandomIntegers(); // set reel outcome equal to the threeRandomIntegers function. This will display the slot results and determine 
      // whether to return 1 or 0
        if (reelOutcome == 1) { // player wins if outcome is equal to one
            balance += 10'000.0;
            cout << "You win! $10'000.0  won!\n";
            ++winningMatch;
        }
        else {
            balance -= 1'000.0; // player loses if outcome is less than zero
            cout << "You lose! $1'000 lost!\n";
            ++losingMatch;
        }
    }
};


  
// SIC BO GAME
  class sicBo : protected Player {

  // data members for the Sic Bo game
	int winningMatch{ 0 };
	int losingMatch{ 0 };
	int outcome{ 0 };
	int choice{ 0 };
	int frequency{ 0 };
	int dice_number{ 0 };
	int dice1{ 0 }, dice2{ 0 }, dice3{ 0 }, bet{ 0 };

// void play() will start here as displaying the menu, then providng the user three options. After, switch case will be used to determine which bet to execute. 

  void displayMenu () {
  // dispaly menu for dice game
	cout << "-----Menu-----";
	cout << "Place a bet on: \n";
	cout << "1. Single Die Bet\n";
	cout << "2. Dice Combinations\n";
	cout << "3. Die Total\n";
  }

  // choose options from 1-3, which will be used for 
	cout << "Choose option 1-3: "
		cin >> choice;
   // then depending on options 1-3, switch case will be used to call the game

// this game is choosing a dice number to bet on how often it'll appear (once, twice, or three times).
	void singeDieBet () {
		cout << "Dice number to bet on: ";
		cin >> dice_number; // dice number to bet on must be between 1-6, will ensure it stays in that range by throwing exceptions

		cout << "Will it appear once, twice, or thrice?";
		cin >> frequency; // input is stored in frequency
    // three if-statements are used to determine if each dice is equal to the betted nice number. if so, outcome will be incremented by 1
		if (dice1 == dice_number) {
			++outcome;
		}
		if (dice2 == dice_number) {
			++outcome;
		}
		if (dice == dice_number) {
			++outcome;
		}

		switch (frequency) {  // switch-case for frequency. if frequency is equal to one, then the program will decide if
		case 1:
			if (outcome == 1) {
				balance += 10'000;
			}
			else {
				balance -= 1'000;
			}
		case 2:
			if (outcome == 2) {
				balance += 30'000;
			}
			else {
				balance -= 3'000;
			}
		case 3:
			if (outcome == 3) {
				balance += 100'000;
			}
			else {
				balance -= 10'000;
			}
		}

	}
  // CASE 2
	void dieCombinations() {
		vector <int> combos; // vector to add the two dice numbers to the back
		cout << "Enter a combination of two dice numbers: ";
		cin >> dice1 >> dice2;
		combos.pushback(dice1);
		combos.pushback(dice2);

		vector <int> threeRolls;  // vector to add three dice rolls to 
		threeRolls.pushback(randomEngine);
		threeRolls.pushback(randomEngine);
		threeRolls.pushback(randomEngine);

		if (combos = threeRolls.popback(dice1)) {
			balance += 10'000.0;
		}
		else if (combos = threeRolls.popback(dice3)) {
			balance += 10'000.0;
		}
		else {
			balance -= 1'000.0;
		}
	}
  // CAse 3
	void dieTotal() {
		cout << "Choose a total to bet on: ";
		cin >> bet;
		bet = (randomInteger() + randomInteger() + randomInteger());
		dice1 = randomInteger();
		dice2 = randomInteger();
		dice3 = randomInteger();

		if ((dice1 + dice2 + dice3) == bet) {
			balance += 10'000.0;
		}
		else {
			balance -= 1'000.0;
		}
	}

}

 
