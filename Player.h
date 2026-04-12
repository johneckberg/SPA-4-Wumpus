//
// Created by eckbergj on 4/9/2026.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include "Weapon.h"
#include <vector>
#include "World.h"

class Player {
public:
    Player(Room* startRoom, World* w = nullptr);
    ~Player();

    void moveRoom(int direction); // 0=n, 1=s, 2=e, 3=w
    void swapWeapon();
    Weapon* fireWeapon(int direction);
    Room* getCurrentRoom();
    void addWeapon(Weapon* w);
    Weapon* getActiveWeapon();

private:
    Room* currentRoom;
    World* world;
    std::vector<Weapon*> inventory;
    Weapon* activeWeapon;
    int activeWeaponIndex;
};

#endif