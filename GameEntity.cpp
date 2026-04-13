#include <string>

#include "GameEntity.h"

GameEntity::GameEntity(std::string name) {
    this->name = name;
}

std::string GameEntity::getName() const {
    return name;
}

GameEntity::~GameEntity() {}
