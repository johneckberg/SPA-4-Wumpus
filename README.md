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

Once the build is complete, you can find the executable named `SPA-4-Wumpus` inside the `build` directory.

## Debug Mode

If you want to view the entire map and see where all the entities and hazards are located, you can enter Debug Mode while playing the game. 

When prompted for an action during your **first** turn (e.g., North, South, East, West, Fire, etc.), simply input `M` (or `m`). 
This will toggle the debug map on or off, displaying a 5x5 grid of the ocean and revealing the location of your ship, weapons, hazards, and the Great Whale!

## Changes from Original Design

### Shifted Game Orchestration in World: 
The biggest change is the expansion of the World class. In the original design, 
World was just a data container holding the rooms and an activity boolean. 
However, to actually make a turn-based game loop function, World had to become a controller. 
Methods like resolveState() and resolveFire() were introduced so World could manage interactions.
### Room Contents Simplification: 
The initial UML specified that each Room would hold a list (vector<GameEntity*>) of contents. 
In the implemented architecture, this was simplified to a single GameEntity* contents pointer per room.
I'm not sure why we thought the list was a good idea in hindsight.
### Proper Reference Sharing via Pointers: 
The original design relied on value types for associations (e.g., Player holding the actual Room object, and Hazards holding a World object). 
The implemented architecture moved these to pointers (Room* currentRoom, World* game). 
This allows all entities to reference the exact same map and central game state, which is necessary 
for hazards to end the game.