#include "GameEntity.h"
#include "Player.h"

class TreasureChest : public GameEntity {
private:
    bool isCollected;
    int value;
public:
    TreasureChest();
    virtual void onEnter();
    void onEnter(Player player);
    virtual std::string getWarning();
    virtual std::string describe();
};