//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_ENEMY_H
#define MAZZARONE_ROSADINI_ENEMY_H

#include "Character.h"
#include "FightStrategy.h"
#include "MoveStrategy.h"
#include "Player1.h"
#include "Follow.h"
#include <math.h>
#include <memory.h>

class Enemy: public Character {
public:
    explicit Enemy(MoveStrategy *moveStrategy = nullptr);

    void movement(float x, float y);

    MoveStrategy *getMoveStrategy() const;

    void setMoveStrategy(MoveStrategy *moveStrategy);

    virtual void fight(Character *hero);

private:
    FightStrategy fightStrategy;
    MoveStrategy *moveStrategy;
};

#endif //MAZZARONE_ROSADINI_ENEMY_H
