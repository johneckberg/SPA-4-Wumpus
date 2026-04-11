#include <string>

#if !defined(game_entity_h)
#define game_entity_h

class GameEntity {
private:
    std::string name;
public:
    GameEntity(std::string name);
    virtual std::string getWarning() = 0;
    virtual void onEnter() = 0;
};

#endif // game_entity_h