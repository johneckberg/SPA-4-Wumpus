#include <string>
#include <random>
#include <ctime>

#include "Hazard.h"

Siren::Siren() : Hazard(false, "siren") { 
    srand(time(0));
    this->flightDistance = rand() % 3 + 3; // Get a random number between 2 and 5
}

void Siren::triggerEffect(Player& player) {
    movePlayer(player);
}

void Siren::movePlayer(Player& player) {
    for (int i = 0; i < flightDistance; i++) {
        player.moveRoom(rand() % 4); //move player in random direction (0-3)
    }
}

std::string Siren::getWarning() {
    return "You hear an enticing song floating across the waves.";
}

std::string Siren::describe() {
    return "siren";
}

void Siren::onEnter() {
    // DO nothing
}