//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTERFACTORY_H
#define MAZZARONE_ROSADINI_CHARACTERFACTORY_H

#include <memory>
#include "Character.h"
#include "Player1.h"
#include "Enemy.h"
#include "RangedAttack.h"
#include "Patrol.h"
#include "EntityFactory.h"

#include <random>

enum class CharacterType {
    player1, enemy
};

class CharacterFactory : public EntityFactory {
public:
    CharacterFactory();

    virtual Player1 createHero(ElementType type) = 0;

    virtual Enemy createEnemy(ElementType type, sf::Vector2f position) = 0;

    sf::Vector2f setPosition(ElementType type);

};


#endif //MAZZARONE_ROSADINI_CHARACTERFACTORY_H
