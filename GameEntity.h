//
// Created by maltesr on 4/11/2026.
//

#ifndef SPA_4_WUMPUS_GAMEENTITY_H
#define SPA_4_WUMPUS_GAMEENTITY_H
#include <string>

//Exist purely to define what is a game entity for room class
class GameEntity {
public:
    virtual ~GameEntity() = 0;
    virtual std::string describe() = 0;
};


#endif //SPA_4_WUMPUS_GAMEENTITY_H