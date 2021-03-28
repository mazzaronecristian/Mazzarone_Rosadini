//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_MOVESTRATEGY_H
#define MAZZARONE_ROSADINI_MOVESTRATEGY_H
#include "Character.h"

class MoveStrategy {
public:
    virtual void move(Character *hero, int *enemyX, int *enemyY);
};


#endif //MAZZARONE_ROSADINI_MOVESTRATEGY_H
