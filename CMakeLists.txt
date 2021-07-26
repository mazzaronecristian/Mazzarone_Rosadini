cmake_minimum_required(VERSION 3.13)
project(Mazzarone_Rosadini)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/Users/gianlucarosadini/SFML/include")
set(SFML_LIBRARY_DIR "/Users/gianlucarosadini/SFML/lib")
set(SFML_DIR "/Users/gianlucarosadini/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Mazzarone_Rosadini cpp/main.cpp cpp/Character.cpp header/Character.h cpp/Player1.cpp header/Player1.h cpp/Enemy.cpp header/Enemy.h cpp/MoveStrategy.cpp header/MoveStrategy.h cpp/FightStrategy.cpp header/FightStrategy.h cpp/Map.cpp header/Map.h cpp/Tile.cpp header/Tile.h cpp/Potion.cpp header/Potion.h cpp/UseStrategy.cpp header/UseStrategy.h cpp/HealUse.cpp header/HealUse.h cpp/StrengthUse.cpp header/StrengthUse.h cpp/Barrel.cpp header/Barrel.h cpp/TrapBarrel.cpp header/TrapBarrel.h cpp/Bullet.cpp header/Bullet.h cpp/Entity.cpp header/Entity.h cpp/Follow.cpp header/Follow.h cpp/Patrol.cpp header/Patrol.h cpp/Stay.cpp header/Stay.h cpp/Animation.cpp header/Animation.h cpp/AttackStrategy.cpp header/AttackStrategy.h cpp/RangedAttack.cpp header/RangedAttack.h cpp/EntityFactory.cpp header/EntityFactory.h cpp/CharacterFactory.cpp header/CharacterFactory.h cpp/PlayersFactory.cpp header/PlayersFactory.h cpp/BulletsFactory.cpp header/BulletsFactory.h)
target_link_libraries (Mazzarone_Rosadini sfml-graphics sfml-window sfml-system)

add_subdirectory(test)
set(SOURCE_FILES cpp/Character.cpp header/Character.h cpp/Player1.cpp header/Player1.h cpp/Enemy.cpp header/Enemy.h cpp/MoveStrategy.cpp header/MoveStrategy.h cpp/FightStrategy.cpp header/FightStrategy.h cpp/Map.cpp header/Map.h cpp/Tile.cpp header/Tile.h cpp/Potion.cpp header/Potion.h cpp/UseStrategy.cpp header/UseStrategy.h cpp/HealUse.cpp header/HealUse.h cpp/StrengthUse.cpp header/StrengthUse.h cpp/Barrel.cpp header/Barrel.h cpp/TrapBarrel.cpp header/TrapBarrel.h cpp/Bullet.cpp header/Bullet.h cpp/Entity.cpp header/Entity.h cpp/Follow.cpp header/Follow.h cpp/Patrol.cpp header/Patrol.h cpp/Stay.cpp header/Stay.h cpp/Animation.cpp header/Animation.h cpp/AttackStrategy.cpp header/AttackStrategy.h cpp/RangedAttack.cpp header/RangedAttack.h cpp/EntityFactory.cpp header/EntityFactory.h cpp/CharacterFactory.cpp header/CharacterFactory.h cpp/PlayersFactory.cpp header/PlayersFactory.h cpp/BulletsFactory.cpp header/BulletsFactory.h test/runAllTests.cpp)
add_executable(unit_testing cpp/main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(unit_testing core)