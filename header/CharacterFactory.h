//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTERFACTORY_H
#define MAZZARONE_ROSADINI_CHARACTERFACTORY_H

#include <memory>
#include "Player1.h"
#include "Enemy.h"
#include "RangedAttack.h"
#include "MeleeAttack.h"
#include "Patrol.h"

#include <random>

class CharacterFactory {
public:
    CharacterFactory();

    virtual Player1 createHero(CharacterType type) = 0;

    virtual Enemy createEnemy(CharacterType type, sf::Vector2f position, Map arena) = 0;

protected:
    std::string setBitMap(CharacterType type);

};


#endif //MAZZARONE_ROSADINI_CHARACTERFACTORY_H
