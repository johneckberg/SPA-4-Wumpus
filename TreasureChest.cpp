#include "TreasureChest.h"
#include "Player.h"

void TreasureChest::onEnter(Player player) {
    if (!isCollected) {
        player.collectTreasure(value);
    }
    isCollected = true;
}

std::string TreasureChest::getWarning() {
    return "You see something sparkle on the waves."
}

std::string TreasureChest::describe() {
    return TreasureChest::getWarning();
}