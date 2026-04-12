#include "GameEntity.h"
#include "Player.h"

#if !defined(hazard_h)
#define hazard_h

class Hazard : private GameEntity {
private:
    int isDeadly;
public:
    Hazard(int isDeadly, std::string name);
    virtual void triggerEffect(Player player) = 0;
    virtual std::string getWarning() = 0;
};

class Siren : private Hazard {
private:
    int flightDistance;
public:
    Siren();
    virtual void triggerEffect(Player player);
    virtual std::string getWarning();
    void movePlayer(Player player);
};

class Whirlpool : private Hazard {
private:
    World game;
public:
    Whirlpool(World game);
    virtual void triggerEffect(Player player);
    virtual std::string getWarning();
    void endGame();
};

class Whale : private Hazard {
private:
    bool isAwake;
    World game;
public:
    Whale(World game);
    virtual void triggerEffect(Player player);
    virtual std::string getWarning();
    void killPlayer();
};

#endif // hazard_h