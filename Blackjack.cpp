#include "blackjack.h"
#include <cstdlib>
#include <ctime>

// card values
const char* Suits[4] = { "Star", "Club", "Duce", "Heart" };
const char* Ranks[13] = {
    "A","2","3","4","5","6","7",
    "8","9","10","Jack","Queen","King"
};

CARD::CARD(int Card_Number) {
    Card_Suit = static_cast<SUIT>(Card_Number / 13);
    Card_Rank = static_cast<RANK>((Card_Number % 13) + 1);
}

void CARD::Print_Card() const {
    std::cout << Ranks[static_cast<int>(Card_Rank) - 1]
        << Suits[static_cast<int>(Card_Suit)];
}

// deck 
DECK::DECK() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Reshuffle();
}

void DECK::Reshuffle() {
    Cards_Remaining = 52;
    for (int i = 0; i < 52; i++) {
        Cards_Dealt[i] = false;
    }
}

int DECK::RNG(int n) {
    return std::rand() % n;
}

int DECK::Select_Available_Card(int Card) {
    while (Cards_Dealt[Card]) {
        Card = RNG(52);
    }
    return Card;
}

CARD DECK::Deal_Card() {
    if (Cards_Remaining == 0) {
        Reshuffle();
    }

    int Card_Number = RNG(52);
    Card_Number = Select_Available_Card(Card_Number);

    Cards_Dealt[Card_Number] = true;
    Cards_Remaining--;

    return CARD(Card_Number);
}


BLACKJACK::BLACKJACK() {
    Cards_Received = 0;
    Current_Total = 0;
    Bust = false;
}

void BLACKJACK::Add_Card(const CARD& card) {
    if (Cards_Received < 11) {
        Cards[Cards_Received++] = card;
        Current_Total = Get_Hand_Total();

        if (Current_Total > 21) {
            Bust = true;
        }
    }
}

int BLACKJACK::Get_Hand_Total() {
    int total = 0;
    int aces = 0;

    for (int i = 0; i < Cards_Received; i++) {
        int rank = static_cast<int>(Cards[i].Card_Rank);

        if (rank == 1) {
            aces++;
            total += 11;
        }
        else if (rank >= 10) {
            total += 10;
        }
        else {
            total += rank;
        }
    }

    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}
