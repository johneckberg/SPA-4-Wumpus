//
// Created by eckbergj on 4/9/2026.
//

#ifndef SPA_4_WUMPUS_ROOM_H
#define SPA_4_WUMPUS_ROOM_H

#include <vector>

#include "Weapon.h"

class Room {
private:
    std::vector<Room*> adjacentRooms;
    GameEntity* contents;
    bool startingRoom = false;

public:
    Room();

    void setStartingRoom();
    bool getRoomType();
    void setNeighbor(int direction, Room* room);
    Room* getNeighbor(int direction);

    void addEntity(GameEntity* e);
    void describeRoom();
    GameEntity* getContents();
    bool isOccupied();
    ~Room();
};


#endif //SPA_4_WUMPUS_ROOM_H