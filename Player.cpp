//
// Created by eckbergj on 4/9/2026.
//

#include "Player.h"

#include <iostream>
#include <vector>

Player::Player(Room* startRoom, World* w) : currentRoom(startRoom), world(w), activeWeaponIndex(0) {
    // start player with harpoon
    inventory.push_back(new Harpoon());
    activeWeapon = inventory[0];
}

Player::~Player() {
    for (Weapon* w : inventory) {
        delete w;
    }
}

void Player::moveRoom(int direction) {
    if (currentRoom == nullptr) return;
    
    // attempt to get the neighbor room and move
    Room* nextRoom = currentRoom->getNeighbor(direction);


    //MAYBE: use this as a way to check what to do in the room
    //we already have the room so we can easily get the contents of the room
    //then just check what the contents are, and based on that do the correct action
    //like whirlpools end the game, sirens teleport you, etc etc
    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        std::cout << "you moved to a new unchartered area." << std::endl;
    } else {
        std::cout << "the sea is too rough that way. you cannot go there." << std::endl;
    }
    
    std::cout << "moving direction: " << direction << std::endl;
}

void Player::swapWeapon() {
    if (inventory.empty()) return;

    if (inventory.size() < 2) {
        std::cout << "you only have one weapon" << std::endl;
        return;
    }

    activeWeaponIndex = (activeWeaponIndex + 1) % (int)inventory.size();
    activeWeapon = inventory[activeWeaponIndex];

    std::cout << "you readied your new weapon" << std::endl;
}

Room* Player::getCurrentRoom() {
    return currentRoom;
}

void Player::addWeapon(Weapon* w) {
    inventory.push_back(w);
}

Weapon* Player::getActiveWeapon() {
    return activeWeapon;
}

Weapon* Player::fireWeapon(int direction) {
    // safety check ensuring a weapon is actually equipped
    if (activeWeapon == nullptr) {
        // I don't think this should ever happen but it might be nice to handle?
        std::cout << "you have no weapon equipped" << std::endl;
        return nullptr;
    }

    // since we want to integrate with a World resolveFire method we check ammo here
    // only return a valid Weapon pointer if the weapon is actually capable of firing
    // if ammo > 0, we fire and pass the weapon back to main loop to be given to world.resolveFire()
    if (activeWeapon->getAmmo() > 0) {
        activeWeapon->fire(direction);
        return activeWeapon;
    } else {

        //return nullptr so world resolve doesn't trigger
        std::cout << "out of ammo" << std::endl;
        return nullptr;
    }
}