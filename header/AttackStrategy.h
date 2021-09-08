//
// Created by cristian on 28/05/21.
//

#ifndef MAZZARONE_ROSADINI_ATTACKSTRATEGY_H
#define MAZZARONE_ROSADINI_ATTACKSTRATEGY_H

#include "Character.h"

class AttackStrategy {
public:
    virtual ~AttackStrategy() = default;

    virtual void fight(Character *hero, Character &enemy) = 0;
};


#endif //MAZZARONE_ROSADINI_ATTACKSTRATEGY_H
