#include <random>
#include <vector>
#include "Slots.h"
#include "Player.h"
using namespace std;

void Slots::play() {

}

// enum to represent 4 symbols
enum {
    Cherry, Lemon, Bell, Seven
};

// function to get random numbers from 0-3
// these represent the vector subscripts
int Slots::randomInteger() {
    static random_device rd;
    static default_random_engine engine{ rd() };
    static uniform_int_distribution randomInt{ 0, 3 };
    return randomInt(engine);
}

// 🎰 Generate spin
vector<int> Slots::spin() {
    vector<int> slotNum;
    for (int i = 0; i < 3; i++) {
        slotNum.push_back(randomInteger());
    }
    return slotNum;
}

int Slots::evaluate(const vector<int>& slotNum) {
    int winCount = 0;
    // increment winCount if both symbols match
    if (slotNum[0] == slotNum[1]) { ++winCount; }
    if (slotNum[0] == slotNum[2]) { ++winCount; }
    if (slotNum[1] == slotNum[2]) { ++winCount; }

    // to combat 3 matches
    if (winCount > 2) { winCount = 2; }
    return winCount;
}

std::string Slots::applyResult(double amount, int winCount)  {
    if (winCount == 1) {
        player->deposit(amount * 2.0);
        return "You win\n";
    }
    else if (winCount == 2) {
        player->deposit(amount * 5.0);
        return "You win\n";
    }
    else {
        player->withdraw(amount);
        return "You lose\n";
    }
}
