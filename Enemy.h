//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_ENEMY_H
#define MAZZARONE_ROSADINI_ENEMY_H

#include "Character.h"
#include "FightStrategy.h"
#include "MoveStrategy.h"

class Enemy: public Character {
public:
    Enemy(int hp, int posX, int posY, int damage);
    virtual ~Enemy();

    virtual void fight(FightStrategy fightStrategy);
    virtual void move(MoveStrategy moveStrategy);

protected:
    FightStrategy fightStrategy;
    MoveStrategy moveStrategy;

};


#endif //MAZZARONE_ROSADINI_ENEMY_H
