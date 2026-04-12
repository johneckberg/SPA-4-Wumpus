//
// Created by eckbergj on 4/9/2026.
//

#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int startAmmo, int startRange) : GameEntity("Weapon"), ammo(startAmmo), range(startRange) {}

Weapon::~Weapon() {}

std::string Weapon::getWarning() {
    return "";
}

void Weapon::onEnter() {
    // DO nothing
}

int Weapon::getAmmo() const {
    return ammo;
}

void Weapon::decrementAmmo() {
    if (ammo > 0) {
        ammo--;
    }
}

Harpoon::Harpoon() : Weapon(5, 3) {}

void Harpoon::fire(int direction) {
    // ammo checking is handled by Player::fireWeapon 
    std::cout << "Firing Harpoon in direction " << direction << " with range " << range << std::endl;
    decrementAmmo();
}

std::string Harpoon::getName() const {
    return "Harpoon Gun";
}

Cannon::Cannon() : Weapon(5, 1), splashRadius(3) {}

void Cannon::fire(int direction) {
    // ammo checking is handled by Player::fireWeapon 
    std::cout << "Firing Cannon in direction " << direction << " with splash radius " << splashRadius << std::endl;
    decrementAmmo();
}

std::string Cannon::getName() const {
    return "Heavy Cannon";
}

std::string Weapon::describe() {
    return "There's something floating in the water here!";
}
