#include "GameEntity.h"

class TreasureChest : private GameEntity {
private:
    bool isCollected;
    int value;
};