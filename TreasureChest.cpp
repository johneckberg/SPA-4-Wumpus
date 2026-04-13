#include "TreasureChest.h"
#include "Player.h"

TreasureChest::TreasureChest(int val) : GameEntity("Treasure Chest"), isCollected(false), value(val) {
}

void TreasureChest::onEnter() {
    // empty, since the interface requires no arguments
}

void TreasureChest::collect(Player& player) {
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