#include <string>
#include "Player.h"

class Casino {
private:
    Player player;
    bool running;

    void saveBalance();
    void loadBalance();

public:
    Casino(const std::string& playerName, double startingBalance);

    void displayTitle() const;
    void displayMenu() const;
    void run();
};
