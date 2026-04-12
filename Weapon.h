//
// Created by eckbergj on 4/9/2026.
//

#ifndef SPA_4_WUMPUS_WEAPON_H
#define SPA_4_WUMPUS_WEAPON_H

#include <string>

#include "GameEntity.h"

class Weapon : public GameEntity {
protected:
    int ammo;
    int range;
public:
    Weapon(int startAmmo, int startRange);
    virtual ~Weapon();
    virtual void fire(int direction) = 0;
    int getAmmo() const;
    void decrementAmmo();
    virtual std::string getName() const = 0;

    std::string describe() override;
    std::string getWarning() override;
    void onEnter() override;

};

class Harpoon : public Weapon {
public:
    Harpoon();
    void fire(int direction) override;
    std::string getName() const override;
};

class Cannon : public Weapon {
public:
    Cannon();
    void fire(int direction) override;
    std::string getName() const override;
private:
    int splashRadius;
};

#endif //SPA_4_WUMPUS_WEAPON_H