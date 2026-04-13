#include "Hazard.h"

Whirlpool::Whirlpool(World* game) : Hazard(true, "Whirlpool") {
    this->game = game;
}

void Whirlpool::triggerEffect(Player& player) {
    endGame();
}

std::string Whirlpool::getWarning() {
    return "You hear the sound of rushing water near your boat...";
}

void Whirlpool::endGame() {
    game->setInactive();
}

std::string Whirlpool::describe() {
    return "whirlpool";
}

void Whirlpool::onEnter() {
    // DO nothing
}