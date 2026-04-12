#include "Blackjack.h"
#include <cstdlib>
#include <ctime>

// card values
const char* Suits[4] = { "Diamond", "Club", "Spade", "Heart" };
const char* Ranks[13] = {
    "A","2","3","4","5","6","7",
    "8","9","10","Jack","Queen","King"
};

CARD::CARD(int Card_Number) {
    Card_Suit = static_cast<SUIT>(Card_Number / 13);
    Card_Rank = static_cast<RANK>((Card_Number % 13) + 1);
}

void CARD::Print_Card() const {
    std::cout << Ranks[static_cast<int>(Card_Rank) - 1] << " (" << Suits[static_cast<int>(Card_Suit)] << ")";
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


Hand::Hand() {
    Cards_Received = 0;
    Current_Total = 0;
    Bust = false;
}

void Hand::Add_Card(const CARD& card) {
    if (Cards_Received < 11) {
        Cards[Cards_Received++] = card;
        Current_Total = Get_Hand_Total();

        if (Current_Total > 21) {
            Bust = true;
        }
    }
}

int Hand::Get_Hand_Total() {
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
// actual game implementation
void Blackjack::play() {
    double betAmount{0.0};
    char choice{};

    std::cout << "Current balance: $" << player->getBalance() << "\n";
    std::cout << "Enter bet amount: ";
    std::cin >> betAmount;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input.\n\n";
        return;
    }

    if (betAmount <= 0 || betAmount > player->getBalance()) {
        std::cout << "Invalid bet amount.\n\n";
        return;
    }

    if (!player->withdraw(betAmount)) {
        std::cout << "Unable to place bet.\n\n";
        return;
    }

    playerHand = Hand();
    dealerHand = Hand();

    playerHand.Add_Card(deck.Deal_Card());
    dealerHand.Add_Card(deck.Deal_Card());
    playerHand.Add_Card(deck.Deal_Card());
    dealerHand.Add_Card(deck.Deal_Card());

    std::cout << "\nDealer's hand: ";
    std::cout << "[Hidden], ";
    dealerHand.Cards[1].Print_Card();
    std::cout << "\n";

    std::cout << "Your hand: ";
    for (int i = 0; i < playerHand.Cards_Received; i++) {
        playerHand.Cards[i].Print_Card();
        if (i < playerHand.Cards_Received - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\nYour total: " << playerHand.Get_Hand_Total() << "\n";

    while (!playerHand.Bust) {
        std::cout << "Hit or stand? (h/s): ";
        std::cin >> choice;

        if (choice == 'h' || choice == 'H') {
            playerHand.Add_Card(deck.Deal_Card());

            std::cout << "Your hand: ";
            for (int i = 0; i < playerHand.Cards_Received; i++) {
                playerHand.Cards[i].Print_Card();
                if (i < playerHand.Cards_Received - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "\nYour total: " << playerHand.Get_Hand_Total() << "\n";
        }
        else if (choice == 's' || choice == 'S') {
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    if (playerHand.Bust) {
        std::cout << "You busted. Dealer wins.\n";
        std::cout << "New balance: $" << player->getBalance() << "\n\n";
        return;
    }

    while (dealerHand.Get_Hand_Total() < 17) {
        dealerHand.Add_Card(deck.Deal_Card());
    }

    std::cout << "\nDealer's final hand: ";
    for (int i = 0; i < dealerHand.Cards_Received; i++) {
        dealerHand.Cards[i].Print_Card();
        if (i < dealerHand.Cards_Received - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\nDealer total: " << dealerHand.Get_Hand_Total() << "\n";

    std::cout << "Your final hand: ";
    for (int i = 0; i < playerHand.Cards_Received; i++) {
        playerHand.Cards[i].Print_Card();
        if (i < playerHand.Cards_Received - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\nYour total: " << playerHand.Get_Hand_Total() << "\n";

    int playerTotal = playerHand.Get_Hand_Total();
    int dealerTotal = dealerHand.Get_Hand_Total();

    if (dealerHand.Bust || playerTotal > dealerTotal) {
        player->deposit(betAmount * 2);
        std::cout << "You win!\n";
    }
    else if (playerTotal == dealerTotal) {
        player->deposit(betAmount);
        std::cout << "Push. Your bet is returned.\n";
    }
    else {
        std::cout << "Dealer wins.\n";
    }

    std::cout << "New balance: $" << player->getBalance() << "\n\n";
}
