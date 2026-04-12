//
// Created by maltesr on 4/11/2026.
//

#ifndef SPA_4_WUMPUS_WORLD_H
#define SPA_4_WUMPUS_WORLD_H
#include "Room.h"


class World {
private:
    bool isGameActive = false;
    std::vector<Room*> rooms;


public:
    World();
    void setInactive();
    bool isActive();
    ~World();
    void fillRooms();
    Room* getStartingRoom();
};


#endif //SPA_4_WUMPUS_WORLD_H