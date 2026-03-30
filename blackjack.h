#pragma once

#include <iostream>

// card values
extern const char* Suits[4];
extern const char* Ranks[13];

// all the cards
enum class SUIT { Spades, Clubs, Diamonds, Hearts };

enum class RANK {
    Ace = 1, Two, Three, Four, Five, Six,
    Seven, Eight, Nine, Ten, Jack, Queen, King
};

// card process
class CARD {
public:
    SUIT Card_Suit{};
    RANK Card_Rank{};

    CARD() = default;
    CARD(int Card_Number);

    void Print_Card() const;
};

// deck class
class DECK {
public:
    int Cards_Remaining{};
    bool Cards_Dealt[52]{};

    DECK();

    void Reshuffle();
    CARD Deal_Card();

private:
    int RNG(int n);
    int Select_Available_Card(int Card);
};

class BLACKJACK {
public:
    int Cards_Received{};
    int Current_Total{};
    bool Bust{};
    CARD Cards[11]{};

    BLACKJACK();

    int Get_Hand_Total();
    void Add_Card(const CARD& card);
};
