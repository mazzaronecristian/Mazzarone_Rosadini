//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_ENEMY_H
#define MAZZARONE_ROSADINI_ENEMY_H

#include "Character.h"
#include "FightStrategy.h"
#include "MoveStrategy.h"
#include "Player1.h"
#include <math.h>

class Enemy: public Character {
public:
    Enemy();
    void movement(float x, float y);


    virtual void fight(Character *hero);

protected:
    FightStrategy fightStrategy;
    MoveStrategy moveStrategy;

};

#endif //MAZZARONE_ROSADINI_ENEMY_H
