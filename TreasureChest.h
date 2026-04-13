#include "GameEntity.h"
#include "Player.h"

class TreasureChest : private GameEntity {
private:
    bool isCollected;
    int value;
public:
    void onEnter(Player player);
    virtual std::string getWarning();
    virtual std::string describe();
};