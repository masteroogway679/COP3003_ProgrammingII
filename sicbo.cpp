#include <random>
#include "sicBo.h"
using namespace std;

// get random integer
int SicBo::randomInteger() {
    static random_device rd;
    static default_random_engine engine{ rd() };
    static uniform_int_distribution randomInt{ 1, 6 };
    return randomInt(engine);
}

int SicBo::getNumber() {
    return randomInteger();
}

vector <int> SicBo::getDice() {
    vector <int> diceResults;
    for (int i = 0; i < 3; i++) {
        diceResults.push_back(randomInteger());
    }

    return diceResults;
}

int SicBo::evaulate(const vector <int>& diceResults, int diceNumber) {
    // count matches
    int winCount = 0;
    for (int i : diceResults) {
        if (i == diceNumber) {
            ++winCount;
        }
    }
    return winCount;
}

std::string SicBo::applyResult(double amount, int winCount) {
    if (winCount == 1) {
        player->deposit(amount * 2.0);
        return "You win\n";
    }
    else if (winCount == 2) {
        player->deposit(amount * 3.0);
        return "You win\n";
    }
    else if (winCount == 3) {
        player->deposit(amount * 5.0);
        return "You win\n";
    }
    else {
        return "You lose\n";
    }
}
