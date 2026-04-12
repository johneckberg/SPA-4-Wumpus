//
// Created by maltesr on 4/11/2026.
//

#include "World.h"

#include <ctime>

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

//only done when quitting
void World::setInactive() {
    isGameActive = false;
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
            } else if (chance < 40) {
                //20%
                r -> addEntity(new Cannon); //add harpoon to room tile
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
