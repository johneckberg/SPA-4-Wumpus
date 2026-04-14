#include "TreasureChest.h"
#include "Player.h"

#include <ctime>

void TreasureChest::onEnter() {
    int i = 1; //Basically just a dummy function for inheritance purposes
}

TreasureChest::TreasureChest(int val) : GameEntity("Treasure") {
    srand(time(0));
    value = val == 100 ? (rand() % 50 + 10) : val;
    isCollected = false;
}

void TreasureChest::collect(Player& player) {
    // check if collected, then call players method
    if (!isCollected) {
        player.collectTreasure(value);
        isCollected = true;
    }
}

std::string TreasureChest::getWarning() {
    return "You see something sparkle on the waves.";
}

std::string TreasureChest::describe() {
    // used for the debug map
    return "A wooden chest bobs gently on the waves, its rusted lock broken open.";
}