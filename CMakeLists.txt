cmake_minimum_required(VERSION 3.10)
project(SPA-4-Wumpus)

set(CMAKE_CXX_STANDARD 20)

add_executable(SPA-4-Wumpus main.cpp Player.cpp Room.cpp Weapon.cpp
        World.cpp
        World.h
        GameEntity.cpp
        GameEntity.h
        Hazard.cpp
        Hazard.h
        Siren.cpp
        Whirlpool.cpp
        Whale.cpp
)