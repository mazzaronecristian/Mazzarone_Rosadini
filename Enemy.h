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
    explicit Enemy(int hp=5, int posX=5, int posY=5, int damage=5);
    virtual ~Enemy();

    virtual void fight(Character *hero);
    virtual void move(Character *hero);

protected:
    FightStrategy fightStrategy;
    MoveStrategy moveStrategy;

};


#endif //MAZZARONE_ROSADINI_ENEMY_H
