//
// Created by maltesr on 4/11/2026.
//

#ifndef SPA_4_WUMPUS_WORLD_H
#define SPA_4_WUMPUS_WORLD_H
#include "Room.h"


class World {
private:
    bool isGameActive = false;
    bool isDebugMode = false;
    std::vector<Room*> rooms;


public:
    World();
    void setInactive();
    bool isActive();
    ~World();
    void fillRooms();
    Room* getStartingRoom();
    void toggleDebug();
    bool getDebug() const;
    void printMap(Room* currentRoom);
    void resolveState(class Player& player);
    void printWarnings(Room* currentRoom);
    void resolveFire(int dir, Weapon* weapon, Room* currentRoom);
    void resolveCannonSplash(Room* target, Room* currentRoom);
};


#endif //SPA_4_WUMPUS_WORLD_H