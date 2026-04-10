//
// Created by eckbergj on 4/9/2026.
//

#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int startAmmo, int startRange) : ammo(startAmmo), range(startRange) {}

Weapon::~Weapon() {}

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
    if (ammo > 0) {
        std::cout << "Firing Harpoon in direction " << direction << " with range " << range << "!" << std::endl;
        decrementAmmo();
    } else {
        std::cout << "Out of Harpoons!" << std::endl;
    }
}

std::string Harpoon::getName() const {
    return "Harpoon Gun";
}

Cannon::Cannon() : Weapon(5, 1), splashRadius(1) {}

void Cannon::fire(int direction) {
    if (ammo > 0) {
        std::cout << "Firing Cannon in direction " << direction << " with splash radius " << splashRadius << "!" << std::endl;
        decrementAmmo();
    } else {
        std::cout << "Out of Cannonballs!" << std::endl;
    }
}

std::string Cannon::getName() const {
    return "Heavy Cannon";
}
