#include "GameEntity.h"
#include "Player.h"

#if !defined(hazard_h)
#define hazard_h

class Hazard : public GameEntity {
private:
    int isDeadly;
public:
    Hazard(int isDeadly, std::string name);
    virtual void triggerEffect(Player& player) = 0;
    virtual std::string getWarning() = 0;
};

class Siren : public Hazard {
private:
    int flightDistance;
public:
    Siren();
    virtual void triggerEffect(Player& player);
    virtual std::string getWarning();
    void movePlayer(Player& player);
    std::string describe() override;
    void onEnter() override;
};

class Whirlpool : public Hazard {
private:
    World* game;
public:
    Whirlpool(World* game);
    virtual void triggerEffect(Player& player);
    virtual std::string getWarning();
    void endGame();
    std::string describe() override;
    void onEnter() override;
};

class Whale : public Hazard {
private:
    bool isAwake;
    World* game;
public:
    Whale(World* game);
    virtual void triggerEffect(Player& player);
    virtual std::string getWarning();
    void killPlayer();
    std::string describe() override;
    void onEnter() override;
};

#endif // hazard_h