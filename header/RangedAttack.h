//
// Created by cristian on 28/05/21.
//

#ifndef MAZZARONE_ROSADINI_RANGEDATTACK_H
#define MAZZARONE_ROSADINI_RANGEDATTACK_H

#include "AttackStrategy.h"

class RangedAttack : public AttackStrategy {
public:
    void fight(Character &character, int damage) override;
};


#endif //MAZZARONE_ROSADINI_RANGEDATTACK_H
