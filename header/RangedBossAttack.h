//
// Created by Gianluca Rosadini on 11/11/21.
//

#ifndef MAZZARONE_ROSADINI_RANGEDBOSSATTACK_H
#define MAZZARONE_ROSADINI_RANGEDBOSSATTACK_H

#include "BossStrategy.h"


class RangedBossAttack : public BossStrategy {
public:
    void fight(Character &hero, Boss *boss) override;
};

#endif //MAZZARONE_ROSADINI_RANGEDBOSSATTACK_H
