//
// Created by maltesr on 4/11/2026.
//

#include "World.h"
#include "Hazard.h"

#include <ctime>
#include <iostream>

World::World() {
    isGameActive = true;
    rooms.reserve(25);

    for (int i = 0; i < 25; i ++) {
        rooms.push_back(new Room());
    }

    //0 = north, 1 = east, 2 = south, 3 = west

    for (int i = 0; i < 25; i++) {

        //North rooms
        //above 5 since 0 to 4 is the top row, so there is no north
        //we do i-5 since subtracting 5 gets us the room north of the current room
        if (i >= 5) {
            rooms[i] -> setNeighbor(0, rooms[i-5]);
        }

        //East rooms
        //we do i%5 !=4 to check if we're on the right edge
        //if we're on the right edge, there is no east room
        //i+1 to move right one, which is east
        if (i % 5 != 4) {
            rooms[i] -> setNeighbor(1, rooms[i+1]);
        }

        //South Rooms
        //less than 20, since bottom row has no south
        //add 5, since adding 5 will go to next row, which is south
        if (i < 20) {
            rooms[i] -> setNeighbor(2, rooms[i+5]);
        }

        //West rooms
        //i%5 != to check if we're on the left edge
        //if we're on the left edge no west rooms
        //i-1 to go left once, which is west
        if (i % 5 != 0) {
            rooms[i] -> setNeighbor(3, rooms[i-1]);
        }
    }

    fillRooms();

}

bool World::isActive() {
    return isGameActive;
}

void World::setInactive() {
    isGameActive = false;
}

bool World::getDebug() const {
    return isDebugMode;
}

void World::toggleDebug() {
    isDebugMode = !isDebugMode;
}

void World::printMap(Room* currentRoom) {
    //only print if debug mode is active
    if (!isDebugMode) return;
    
    std::cout << "\nDEBUG MAP" << std::endl;
    //loop through all 25 rooms to print the grid
    for (int i = 0; i < 25; i++) {
        Room* r = rooms[i];
        //check if this is the room the player is in
        if (r == currentRoom) {
            std::cout << "+ ";
        } else if (r->isOccupied()) {
            //if the room has something, find out what symbol to print based on description
            GameEntity* e = r->getContents();
            if (e != nullptr) {
                std::string desc = e->describe();
                // weapons or cannons
                if (desc.find("floating") != std::string::npos) {
                    std::cout << "? ";
                // sirens
                } else if (desc.find("siren") != std::string::npos) {
                    std::cout << "! ";
                // whirlpools
                } else if (desc.find("whirlpool") != std::string::npos) {
                    std::cout << "@ ";
                // ammo caches
                } else if (desc.find("ammo") != std::string::npos) {
                    std::cout << "> ";
                // whale
                } else if (desc.find("whale") != std::string::npos) {
                    std::cout << "# ";
                //fallback just in case THIS INDICATES ERROR
                } else {
                    std::cout << "X "; 
                }
            }
        } else {
            // empty room
            std::cout << ". ";
        }

        // print a new line every 5 rooms to make the 5x5 grid
        if (i % 5 == 4) {
            std::cout << std::endl;
        }
    }
}

World::~World() {
    for (Room* r : rooms) {
        delete r;
    }
}

void World::fillRooms() {

    //randomly fills the rooms with items
    //or makes it so the rooms are empty

    srand(time(NULL));

    for (Room* r : rooms) {

        //check if it is the starting room
        //if not, then potentially fill it with stuff
        if (!r -> getRoomType()) {
            int chance = rand() % 100;

            if (chance < 20) {
                //add hazard (?) 20%
                int hazardType = rand() % 3;
                if (hazardType == 0) {
                    r->addEntity(new Siren());
                } else if (hazardType == 1) {
                    r->addEntity(new Whirlpool(this));
                } else {
                    r->addEntity(new Whale(this));
                }
            } else if (chance < 40) {
                //20%
                r -> addEntity(new Cannon); //add cannon to room tile
            }
            //60% it will be empty
        }
    }
}

Room *World::getStartingRoom() {
    srand(time(NULL));
    int room = rand() % 25;

    rooms[room] -> setStartingRoom();

    return rooms[room];

}
