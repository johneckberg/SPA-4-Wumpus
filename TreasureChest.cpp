#include "TreasureChest.h"
#include "Player.h"

#include <ctime>

void TreasureChest::onEnter() {
    int i = 1; //Basically just a dummy function for inheritence purposes
}

TreasureChest::TreasureChest(int val) : GameEntity("Treasure") {
    srand(time(0));
    value = val == 100 ? (rand() % 50 + 10) : val;
    isCollected = false;
}

void TreasureChest::collect(Player& player) {
    if (!isCollected) {
        // Assume player has collectTreasure or similar. If not, it will fail to compile.
        player.collectTreasure(value);
        isCollected = true;
    }
}

std::string TreasureChest::getWarning() {
    return "You see something sparkle on the waves.";
}

std::string TreasureChest::describe() {
    // used for the debug map
    return "chest";
}