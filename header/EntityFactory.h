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
#include "ElementFactory.h"

class EntityFactory : public ElementFactory {
public:
    EntityFactory();

    std::string setBitMap(ElementType type) override;
};


#endif //MAZZARONE_ROSADINI_ENTITYFACTORY_H
