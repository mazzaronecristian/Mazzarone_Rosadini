cmake_minimum_required(VERSION 3.5)
project(Mazzarone_Rosadini)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_subdirectory(test)

set(SOURCE_FILES cpp/Character.cpp header/Character.h cpp/Player1.cpp header/Player1.h cpp/Enemy.cpp
        header/Enemy.h cpp/MoveStrategy.cpp header/MoveStrategy.h cpp/FightStrategy.cpp header/FightStrategy.h
        cpp/Map.cpp header/Map.h cpp/Tile.cpp header/Tile.h cpp/Potion.cpp header/Potion.h cpp/UseStrategy.cpp
        header/UseStrategy.h cpp/HealUse.cpp header/HealUse.h cpp/StrengthUse.cpp header/StrengthUse.h cpp/Barrel.cpp
        header/Barrel.h cpp/TrapBarrel.cpp header/TrapBarrel.h cpp/Bullet.cpp header/Bullet.h cpp/Entity.cpp header/Entity.h
        cpp/Follow.cpp header/Follow.h cpp/Patrol.cpp header/Patrol.h cpp/Animation.cpp header/Animation.h cpp/AttackStrategy.cpp
        header/AttackStrategy.h cpp/RangedAttack.cpp header/RangedAttack.h cpp/CharacterFactory.cpp
        header/CharacterFactory.h cpp/PlayersFactory.cpp header/PlayersFactory.h cpp/BulletsFactory.cpp header/BulletsFactory.h cpp/UserInterface.cpp header/UserInterface.h cpp/Elements.cpp header/Elements.h cpp/LifeBar.cpp header/LifeBar.h cpp/UserInterfaceFactory.cpp header/UserInterfaceFactory.h cpp/MeleeAttack.cpp header/MeleeAttack.h)

add_executable(Mazzarone_Rosadini cpp/main.cpp ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})

target_link_libraries(Mazzarone_Rosadini sfml-graphics sfml-window sfml-system)