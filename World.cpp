//
// Created by maltesr on 4/11/2026.
//

#include "World.h"
#include "Hazard.h"
#include "TreasureChest.h"
#include "GameEntity.h"

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

/**
 * This function prints the current map of the world for debugging purposes
 * @param currentRoom room the player is currently in
 */
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
                // whale
                } else if (desc.find("whale") != std::string::npos) {
                    std::cout << "# ";
                // treasure chest/ammo
                } else if (desc.find("chest") != std::string::npos) {
                    std::cout << "> ";
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

/**
 * This function dynamically fills all the rooms at game start
 */
void World::fillRooms() {

    //randomly fills the rooms with items
    //or makes it so the rooms are empty

    srand(time(0));

    bool whaleSpawned = false;

    for (Room* r : rooms) {

        //check if it is the starting room
        //if not, then potentially fill it with stuff
        if (!r -> getRoomType()) {
            int chance = rand() % 100;

            if (chance < 20) {
                //add hazard or treasure chest (?) 20%
                int hazardType = rand() % 4;

                // force only one whale to be spawned
                if (hazardType == 2 && whaleSpawned) {
                    hazardType = rand() % 3; // if whale already spawned, make it a siren or whirlpool instead? idk
                }

                if (hazardType == 0) {
                    r->addEntity(new Siren());
                } else if (hazardType == 1) {
                    r->addEntity(new Whirlpool(this));
                } else if (hazardType == 2) {
                    r->addEntity(new TreasureChest());
                }else {
                    r->addEntity(new Whale(this));
                    whaleSpawned = true;
                }
            } else if (chance < 40) {
                //20%
                r -> addEntity(new Cannon); //add cannon to room tile
            }
            //60% it will be empty
        }
    }

    // fallback in case the 20% chance roll and the 1/3 inner roll NEVER triggered a whale
    if (!whaleSpawned) {
        // just find the first empty room and put the whale there
        for (Room* r: rooms) {
            if (!r->getRoomType() && !r->isOccupied()) {
                r->addEntity(new Whale(this));
                break;
            }
        }
    }
}

/**
 * This function prints the warnings for the room the player is currently in, along with warnings
 * for the adjecent rooms
 * @param currentRoom The room the player is currently in
 */
void World::printWarnings(Room* currentRoom) {
    for (int i = 0; i < 4; i++) {
        Room* neighbor = currentRoom->getNeighbor(i);
        if (neighbor != nullptr && neighbor->isOccupied()) {
            GameEntity* entity = neighbor->getContents();
            if (entity != nullptr) {
                std::string warning = entity->getWarning();
                if (!warning.empty()) {
                    std::cout << warning << std::endl;
                }
            }
        }
    }
}

/**
 * This function handles the main logic after the user/player makes an action
 * it checks if the player has hit a hazard or found a weapon/treasure
 * @param player the player object
 */
void World::resolveState(Player& player) {
    if (!isGameActive) {
        return;
    }

    Room* currentRoom = player.getCurrentRoom();
    
    // print warnings for adjacent rooms
    printWarnings(currentRoom);

    // now describe current room
    currentRoom->describeRoom();

    // check if player moved onto a hazard/entity
    // use dynamic cast to check runtime type (not sure if theres a better way to do this?)
    if (currentRoom->isOccupied()) {
        GameEntity* e = currentRoom->getContents();
        Hazard* hazard = dynamic_cast<Hazard*>(e); // see if its a hazard
        TreasureChest* chest = dynamic_cast<TreasureChest*>(e); // check for treasure chest

        if (hazard) {
            hazard->triggerEffect(player);
        } else if (chest) {
            chest->collect(player);
        } else {
            // it might be a weapon
            Weapon* w = dynamic_cast<Weapon*>(e);
            if (w) {
                player.addWeapon(w);
                currentRoom->clearContents();
                std::cout << "You picked up a " << w->getName() << "!" << std::endl;
            }
        }
    }
}

/**
 * This function returns a pointer to the room the player starts in
 * @return a pointer to the starting room object
 */
Room* World::getStartingRoom() {
    srand(time(NULL));
    int room = rand() % 25;

    rooms[room] -> setStartingRoom();

    return rooms[room];

}

/**
 * This function handles the game logic required when the player/user fires their weapon
 * @param dir Direction of fire
 * @param weapon Weapon that was fired
 * @param currentRoom room the user is firing from
 */
void World::resolveFire(int dir, Weapon* weapon, Room* currentRoom) {
    if (!weapon || !currentRoom) return;

    std::cout << "You fired your " << weapon->getName() << "!" << std::endl;
    Room* target = currentRoom->getNeighbor(dir);
    
    if (!target) {
        std::cout << "Your shot missed and hit the edge of the world." << std::endl;
        return;
    }

    bool hitSomething = false;
    if (target->isOccupied()) {
        GameEntity* targetEntity = target->getContents();
        if (targetEntity) {
            std::cout << "You hit: " << targetEntity->getName() << "!" << std::endl;
            if (targetEntity->describe().find("whale") != std::string::npos) {
                std::cout << "You defeated the Great Whale! You win!" << std::endl;
                isGameActive = false;
            }
            delete targetEntity;
            target->clearContents();
            hitSomething = true;
        }
    } 
    
    if (!hitSomething) {
        std::cout << "Your shot splashed harmlessly into the water." << std::endl;
    }

    // check if the weapon fired was a Cannon to apply splash damage
    Cannon* cannon = dynamic_cast<Cannon*>(weapon);
    if (cannon) {
        resolveCannonSplash(target, currentRoom);
    }
}

/**
 * Resolves splash damage when a cannon is fired
 * @param target the primary room that was hit
 * @param currentRoom the room the player fired from (to prevent self-damage)
 */
void World::resolveCannonSplash(Room* target, Room* currentRoom) {
    if (!target) return;
    
    std::cout << "The cannonball explodes, damaging adjacent tiles!" << std::endl;
    for (int i = 0; i < 4; i++) {
        Room* splashTarget = target->getNeighbor(i);
        
        // protect the players room from taking splash damage
        if (splashTarget && splashTarget != currentRoom && splashTarget->isOccupied()) {
            GameEntity* splashEntity = splashTarget->getContents();
            if (splashEntity) {
                std::cout << "Splash damage caught: " << splashEntity->getName() << "!" << std::endl;
                if (splashEntity->describe().find("whale") != std::string::npos) {
                    std::cout << "You defeated the Great Whale with splash damage! You win!" << std::endl;
                    isGameActive = false;
                }
                delete splashEntity;
                splashTarget->clearContents();
            }
        }
    }
}
