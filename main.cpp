//
// Created by eckbergj on 3/23/2026.
//
#include <iostream>
#include <string>
#include "Player.h"
#include "Weapon.h"
#include "World.h"

void printStart() {
    std::cout << "Welcome to: Hunting the great whale!\n" << std::endl;
    std::cout << "You're an old pirate hunting a great white whale." << std::endl;
    std::cout << "You've been hunting this whale your entire life, and today you'll finally catch them.\n" << std::endl;
    std::cout << "Your starting weapon is a harpoon gun which shoots in a straight line." << std::endl;
    std::cout << "While on the sea there are also other weapons available such as the cannon." << std::endl;
    std::cout << "The cannon has less range than the harpoon gun, but has an explosive impact which can damage multiple tiles!" << std::endl;
    std::cout << "You have five harpoons and five cannonballs, although you can find more on your travels.\n" << std::endl;
    std::cout << "Although you are close to catching this whale, there are still hazards upon the sea you must be weary of." << std::endl;
    std::cout << "One such hazard would be the sea siren, which when you listen upon her song you end up in a random tile!" << std::endl;
    std::cout << "There are also various whirlpools which when entered will spell your untimely doom for you and your crew.\n" << std::endl;
    std::cout << "There are many clues that can help you find the whale, as well as alert you of any dangers:" << std::endl;
    std::cout << "- Hearing a faint laugh means there's a siren nearby." << std::endl;
    std::cout << "- Seeing disturbed waves means the whale is nearby." << std::endl;
    std::cout << "- Feeling a faint force against your boat means a whirlpool is near." << std::endl;
}

void printHelp() {
    std::cout << "INSTRUCTIONS" << std::endl;
    std::cout << "Harpoon Gun: Shoots in a straight line (Long range)." << std::endl;
    std::cout << "Cannon: Shorter range, but deals explosive AOE damage!" << std::endl;
    std::cout << "Hazards: Sirens (teleport you) and Whirlpools (instant death)." << std::endl;
    std::cout << "Clues: Faint laugh = Siren, Waves = Whale, Faint force = Whirlpool." << std::endl;

    std::cout << "\n    Map Legend    " << std::endl;
    std::cout << ". = Sea room | + = Your Ship | > = Ammo Cache" << std::endl;
    std::cout << "! = Siren    | @ = Whirlpool  | ? = Cannon" << std::endl;
    std::cout << "# = The Great Whale" << std::endl;
}

int main() {
    World world;
    Player player = Player(world.getStartingRoom(), &world); // eventually pass world.getStartRoom() and &world

    printStart();
    printHelp(); 

    char choice;
    while (world.isActive()) { // change to world.isActive() when world is implemented
        std::cout << "\nActions: (N)orth, (S)outh, (E)ast, (W)est, (F)ire, (C)hange Weapon, (H)elp, (Q)uit:" << std::endl;
        std::cin >> choice;
        choice = std::toupper(choice);

        if (choice == 'Q') {
            std::cout << "Abandoning ship... Goodbye!" << std::endl;
            break;
        }

        switch (choice) {
            case 'N': player.moveRoom(0); break;
            case 'S': player.moveRoom(1); break;
            case 'E': player.moveRoom(2); break;
            case 'W': player.moveRoom(3); break;
            case 'F': {
                int dir;
                std::cout << "Fire in Direction (0=N, 1=S, 2=E, 3=W): ";
                std::cin >> dir;

                // using pointers to propagate fire back to world
                // Weapon* firedWeapon = player.fireWeapon(dir);
                // if (firedWeapon) {
                //      world.resolveFire(dir, firedWeapon);
                // }
                break;
            }
            case 'C':
                player.swapWeapon();
                if (player.getActiveWeapon()) {
                    std::cout << "Switched to: " << player.getActiveWeapon()->getName() << "**" << std::endl;
                }
                else {
                    std::cout << "No weapons in inventory" << std::endl;
                }
                break;

            case 'H':
                printHelp();
                break;

            default:
                std::cout << "Invalid action! Press (H) for help" << std::endl;
                //clear input buffer to prevent extra chars from being read
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
        }

        // world.resolveState(player);
    }

    return 0;
}