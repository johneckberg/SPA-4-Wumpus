//
// Created by eckbergj on 4/9/2026.
//

#include "Room.h"

#include <iostream>

#include "Player.h"

void Room::addEntity(GameEntity* e) {
    if (!isOccupied()) {
        contents = e;
    } else {
        //not sure if need to throw error
        //shouldnt be able to put something in an occupied room
    }
}

void Room::describeRoom() {
    if (isOccupied()) {
        //the item will have its description
        //so the hazards class will have its own description
        //im not sure if its better to use this method
        //or to just get the contents from getContents
        //then from there call the contents getDescription itself
        std::cout << contents -> describe() << std::endl;
    }
}

GameEntity* Room::getContents() {
    return contents;
}

void Room::clearContents() {
    contents = nullptr;
}

bool Room::isOccupied() {
    if (contents == nullptr) {
        return false;
    } else {
        return true;
    }
}

Room::~Room() {
    delete contents;
}

Room *Room::getNeighbor(int direction) {
    if (direction < 4 && direction >= 0) {
        return adjacentRooms[direction];
    }
    return nullptr;
}

Room::Room() : contents(nullptr), adjacentRooms(4, nullptr), startingRoom(false){

}

void Room::setNeighbor(int direction, Room *room) {
    if (direction < 4 && direction >= 0) {
        adjacentRooms[direction] = room;
    }
}

void Room::setStartingRoom() {
    startingRoom = true;
}

bool Room::getRoomType() {
    return startingRoom;
}
