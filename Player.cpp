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
    // Room* nextRoom = currentRoom->getNeighbor(direction);
    //
    // if (nextRoom != nullptr) {
    //     currentRoom = nextRoom;
    //     std::cout << "you moved to a new unchartered area." << std::endl;
    // } else {
    //     std::cout << "the sea is too rough that way. you cannot go there." << std::endl;
    // }
    
    std::cout << "moving direction: " << direction << std::endl;
}

void Player::swapWeapon() {
    if (inventory.empty()) return;

    if (inventory.size() < 2) {
        std::cout << "you only have one weapon!" << std::endl;
        return;
    }

    activeWeaponIndex = (activeWeaponIndex + 1) % (int)inventory.size();
    activeWeapon = inventory[activeWeaponIndex];

    std::cout << "you readied your new weapon!" << std::endl;
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
    if (activeWeapon == nullptr) {
        std::cout << "you have no weapon equipped!" << std::endl;
        return nullptr;
    }

    if (activeWeapon->getAmmo() > 0) {
        activeWeapon->fire(direction);
        return activeWeapon;
    } else {
        std::cout << "out of ammo!" << std::endl;
        return nullptr;
    }
}