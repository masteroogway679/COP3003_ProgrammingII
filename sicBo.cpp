#include format
#include <stdexcept>
#include <random>
#include "sicBo.h"
using namespace std;

	// void play() will start here as displaying the menu, then providng the user three options. After, switch case will be used to determine which bet to execute. 

	void sicBo::play() override {
		// display menu for dice game
		cout << "-----Menu-----";
		cout << "Place a bet on: \n";
		cout << "1. Single Die Bet\n";
		cout << "2. Dice Combinations\n";
		cout << "3. Die Total\n";

		cout << "Choose option 1-3: "
		cin >> choice;

		switch (choice) {
		case 1:
			singleDieBet(balance);
		case 2:
			dieCombinations(balance);
		case 3:
			dieTotals(balance);
		case 4: 
			cout << "Invalid choice.\n";
			break;
		}	 
	}

	 

 // this game is choosing a dice number to bet on how often it'll appear (once, twice, or three times).
	double sicBo::singleDieBet(&balance) {
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

		switch (frequency) {  // switch-case for frequency. if frequency is equal to one, then the program will decide if the incremented outcome is equal 
			// to the frequency value
		case 1:
			if (outcome == frequency) {
				balance += 10'000;
			}
			else {
				balance -= 1'000;
			}
		case 2:
			if (outcome == frequency) {
				balance += 30'000;
			}
			else {
				balance -= 3'000;
			}
		case 3:
			if (outcome == frequency) {
				balance += 100'000;
			}
			else {
				balance -= 10'000;
			}
		}

	}
	// CASE 2
	double sicBo::dieCombinations(&balance) {
		vector <int> combos; // vector to add the two dice numbers to the back
		cout << "Enter a combination of two dice numbers: ";
		cin >> dice1 >> dice2;
		combos.push_back(dice1);
		combos.push_back(dice2);

		vector <int> threeRolls;  // vector to add three dice rolls to 
		threeRolls.push_back(randomEngine);
		threeRolls.push_back(randomEngine);
		threeRolls.push_back(randomEngine);

		if (combos = threeRolls.pop_back(dice1)) {
			balance += 10'000.0;
		}
		else if (combos = threeRolls.pop_back(dice3)) {
			balance += 10'000.0;
		}
		else {
			balance -= 1'000.0;
		}
	}
	// CASE 3
	double sicBo::dieTotal(&balance) {
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


