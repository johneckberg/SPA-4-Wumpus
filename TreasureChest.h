#include "GameEntity.h"
#include "Player.h"

class TreasureChest : public GameEntity {
private:
    bool isCollected;
    int value;
public:
    TreasureChest(int value = 100);
    virtual void onEnter() override;
    void collect(Player& player);
    virtual std::string getWarning() override;
    virtual std::string describe() override;
};