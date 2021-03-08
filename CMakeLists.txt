cmake_minimum_required(VERSION 3.13)
project(Mazzarone_Rosadini)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Mazzarone_Rosadini main.cpp Character.cpp Character.h Player1.cpp Player1.h Weapon.cpp Weapon.h Hammer.cpp Hammer.h Sword.cpp Sword.h Axe.cpp Axe.h Blaster.cpp Blaster.h ActionStrategy.cpp ActionStrategy.h FemaleWarrior.cpp FemaleWarrior.h Dwarf.cpp Dwarf.h SpaceCadet.cpp SpaceCadet.h Gladiator.cpp Gladiator.h Enemy.cpp Enemy.h MoveStrategy.cpp MoveStrategy.h FightStrategy.cpp FightStrategy.h Map.cpp Map.h Tile.cpp Tile.h Potion.cpp Potion.h UseStrategy.cpp UseStrategy.h HealUse.cpp HealUse.h StrengthUse.cpp StrengthUse.h Barrel.cpp Barrel.h TrapBarrel.cpp TrapBarrel.h AttackStrategy.cpp AttackStrategy.h RangedAttack.cpp RangedAttack.h meleeAttack.cpp meleeAttack.h)
target_link_libraries (Mazzarone_Rosadini sfml-graphics sfml-window sfml-system)