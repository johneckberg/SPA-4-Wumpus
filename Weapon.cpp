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

/**
 *
 * @return ammo count
 */
int Weapon::getAmmo() const {
    return ammo;
}

/**
 * This function decrements the ammo of weapon
 */
void Weapon::decrementAmmo() {
    if (ammo > 0) {
        ammo--;
    }
}

Harpoon::Harpoon() : Weapon(5, 3) {}

/**
 * This function fires the harpoon weapon
 * @param direction direction of fire
 */
void Harpoon::fire(int direction) {
    // ammo checking is handled by Player::fireWeapon 
    std::cout << "Firing Harpoon in direction " << direction << " with range " << range << std::endl;
    decrementAmmo();
}

/**
 * This function returns the name of the harpoon
 * @return the name of the weapon
 */
std::string Harpoon::getName() const {
    return "Harpoon Gun";
}

Cannon::Cannon() : Weapon(5, 1), splashRadius(3) {}

/**
 * This function fires the cannon weapon
 * @param direction direction of fire
 */
void Cannon::fire(int direction) {
    // ammo checking is handled by Player::fireWeapon 
    std::cout << "Firing Cannon in direction " << direction << " with splash radius " << splashRadius << std::endl;
    decrementAmmo();
}

/**
 * This function returns the name of the cannon
 * @return the name of the weapon
 */
std::string Cannon::getName() const {
    return "Heavy Cannon";
}

/**
 * This function describes the cannon
 * @return a string describing the weapon for pick-up
 */
std::string Weapon::describe() {
    return "You spot a floating crate of heavy naval equipment drifting in the seafoam.";
}
