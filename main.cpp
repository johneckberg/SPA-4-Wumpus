//
// Created by eckbergj on 3/23/2026.
//
#include <iostream>

int main() {

    std::cout << "Welcome to: Hunting the great whale" << std::endl;
    std::cout << "Your an old pirate hunting a great white whale" << std::endl;
    std::cout << "You've been hunting this whale you're entire life, and today you'll finally catch them" << std::endl;
    std::cout << "Your starting weapon is a harpoon gun which shoots in a straight line" << std::endl;
    std::cout << "While on the sea there are also other weapons available such as the cannon" << std::endl;
    std::cout << "The cannon has less range than the harpoon gun, but has an explosive AOE which can damage multiple tiles!" << std::endl;
    std::cout << "You have five harpoons and five cannonballs, although you can find more on your travels" << std::endl;
    std::cout << "Although you are close to catching this whale, there are still hazards upon the sea you must be weary of" << std::endl;
    std::cout << "One such hazard would be the sea siren, which when you listen upon her song you end up in a random tile!" << std::endl;
    std::cout << "There are also various whirlpools which when entered will spell your untimely doom for you are your crew" << std::endl;
    std::cout << "You are only allowed to move in one of the four cardinal directions, (N)orth, (S)outh, (E)ast, or (W)est" << std::endl;
    std::cout << "There are many clues that can help you find the whale, as well as alert you of any dangers" << std::endl;
    std::cout << "Hearing a faint laugh means theres a siren nearby" << std::endl;
    std::cout << "Seeing disturbed waves means the whale is nearby" << std::endl;
    std::cout << "Feeling a faint force against your boat means a whirlpool is near" << std::endl;

    std::cout << std::endl;

    std::cout << "A sample map is provided below" << std::endl;
    std::cout << "? > . @ ." << std::endl;
    std::cout << "! . > . ." << std::endl;
    std::cout << "> . + @ ." << std::endl;
    std::cout << ". @ . > !" << std::endl;
    std::cout << "# . . > @" << std::endl;

    std::cout << std::endl;

    cout << ". = empty room" << endl;
    cout << "+ = player" << endl;
    cout << "> = ammo" << endl;
    cout << "! = Siren" << endl;
    cout << "@ = Whirlpool" << endl;
    cout << "? = Cannon" << endl;
    cout << "# = The great whale" << endl;

    std::cout << "Actions: (N)orth, (S)outh, (E)ast, (W)est, (F)ire, (H)elp, (Q)uit:" << std::endl;

    return 0;
}