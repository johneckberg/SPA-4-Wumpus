#include <string>

#include "Hazard.h"

Hazard::Hazard(int isDeadly, std::string name) : GameEntity(name) {
    this->isDeadly = isDeadly;
}