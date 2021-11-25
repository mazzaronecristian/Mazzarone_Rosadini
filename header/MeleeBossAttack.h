//
// Created by Gianluca Rosadini on 03/11/21.
//

#ifndef MAZZARONE_ROSADINI_MELEEBOSSATTACK_H
#define MAZZARONE_ROSADINI_MELEEBOSSATTACK_H

#include "BossStrategy.h"

class MeleeBossAttack : public BossStrategy {
public:
    void fight(Character &hero, Boss *boss) override;
};

#endif //MAZZARONE_ROSADINI_MELEEBOSSATTACK_H
