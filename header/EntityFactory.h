//
// Created by cristian on 23/06/21.
//

#ifndef MAZZARONE_ROSADINI_ENTITYFACTORY_H
#define MAZZARONE_ROSADINI_ENTITYFACTORY_H

#include "memory"
#include "Entity.h"
#include "Player1.h"
#include "Enemy.h"
#include "RangedAttack.h"
#include "Patrol.h"

enum class EntityType {hero, ghoul, bullet};

class EntityFactory {
public:
    EntityFactory();
    //virtual std::unique_ptr<Entity> createEntity(EntityType);
    std::string setBitMap(EntityType type);
};



#endif //MAZZARONE_ROSADINI_ENTITYFACTORY_H
