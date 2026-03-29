#include <random>
#include <format>
#include <vector>
using namespace std; 

#include <random>
#include <format>
#include <vector>
using namespace std; 

void Slots::play() override {
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
