#include <string>
#include <iostream>

#include "Hazard.h"

Whale::Whale(World* game) : Hazard(true, "Moby Dick") {
    this->game = game;
    this->isAwake = false;
}

void Whale::triggerEffect(Player& player) {
    killPlayer();
}

void Whale::killPlayer() {
    std::cout << "You got to close to the whale and it sunk your ship." << std::endl;
    game->setInactive();
}

std::string Whale::getWarning() {
    return "You see a white shape under the water near your boat.";
}

std::string Whale::describe() {
    return "whale";
}

void Whale::onEnter() {
    // DO nothing
}