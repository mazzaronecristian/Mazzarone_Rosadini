//
// Created by Gianluca Rosadini on 03/11/21.
//

#ifndef MAZZARONE_ROSADINI_BOSSSTRATEGY_H
#define MAZZARONE_ROSADINI_BOSSSTRATEGY_H

#include "Enemy.h"
#include "Player1.h"

class BossStrategy {
public:
    virtual void fight(Character &hero, Enemy *boss) = 0;
};


#endif //MAZZARONE_ROSADINI_BOSSSTRATEGY_H
