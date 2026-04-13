#include "TreasureChest.h"
#include "Player.h"

#include <ctime>

void TreasureChest::onEnter() {
    int i = 1; //Basically just a dummy function for inheritence purposes
}

TreasureChest::TreasureChest() : GameEntity("Treasure") {
    srand(time(0));
    value = rand() % 50;
    isCollected = false;
}

void TreasureChest::onEnter(Player player) {
    if (!isCollected) {
        player.collectTreasure(value);
        isCollected = true;
    }
}

std::string TreasureChest::getWarning() {
    return "You see something sparkle on the waves.";
}

std::string TreasureChest::describe() {
    return TreasureChest::getWarning();
}