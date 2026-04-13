# SPA 4: Hunt The Wumpus

## Game Description
You are an old pirate hunting a great white whale. You have been hunting this whale your
whole life, and today you’ll finally catch them. Your starting weapon is a harpoon gun that
shoots a straight line. You can also find cannons on the sea. The cannon has less range
than the harpoon gun, but has an AOE that can damage multiple tiles. You start with 5
harpoons, although you can find more on your travels. Although you are
close to catching this whale there are still hazards upon the sea you must be wary of. One
such hazard would be the sea siren, which when you listen upon her song you end up in a
random tile! There are also various whirlpools which when entered will spell your untimely
doom for you are your crew.

## Building the Project

This project was built using **C++20** and uses **CMake** as its build system. 

To compile the executable, follow these steps in your terminal:

1. Open a terminal and navigate to the project's root directory.
2. Create a new build directory and navigate into it:
   ```
   mkdir build
   cd build
   ```
3. Run CMake to generate the build files:
   ```
   cmake ..
   ```
4. Compile the executable:
   ```
   cmake --build .
   ```
Alternatively, you can use the build and run buttons at the top of your CLion IDE to build and exectute the program using the same CMakeLists.txt

Once the build is complete, you can find the executable named `SPA-4-Wumpus` (or `SPA-4-Wumpus.exe` on Windows) inside the `build` directory.

## Debug Mode

If you want to view the entire map and see where all the entities and hazards are located, you can enter Debug Mode while playing the game. 

When prompted for an action during your **first** turn (e.g., North, South, East, West, Fire, etc.), simply input `M` (or `m`). 
This will toggle the debug map on or off, displaying a 5x5 grid of the ocean and revealing the location of your ship, weapons, hazards, and the Great Whale!
