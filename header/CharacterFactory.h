//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTERFACTORY_H
#define MAZZARONE_ROSADINI_CHARACTERFACTORY_H

#include "Player1.h"
#include "Enemy.h"
#include "RangedAttack.h"
#include "MeleeAttack.h"
#include "Patrol.h"
#include "Boss.h"

class CharacterFactory {
public:
    CharacterFactory();

    virtual Player1 createHero(CharacterType type) = 0;

    virtual Enemy createEnemy(CharacterType type, sf::Vector2f position, Map arena) = 0;

    virtual Boss createBoss(CharacterType type) = 0;

protected:
    static std::string setBitMap(CharacterType type);

};


#endif //MAZZARONE_ROSADINI_CHARACTERFACTORY_H
