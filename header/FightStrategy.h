//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_FIGHTSTRATEGY_H
#define MAZZARONE_ROSADINI_FIGHTSTRATEGY_H

#include "Character.h"

class FightStrategy {
public:
    virtual void fight(Character *hero, int damage);
};


#endif //MAZZARONE_ROSADINI_FIGHTSTRATEGY_H
