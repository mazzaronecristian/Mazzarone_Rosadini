//
// Created by cristian on 08/09/21.
//

#ifndef MAZZARONE_ROSADINI_MELEEATTACK_H
#define MAZZARONE_ROSADINI_MELEEATTACK_H

#include "AttackStrategy.h"
#include "Barrel.h"
class MeleeAttack : public AttackStrategy {
public:
    void fight(Character *hero, Character &enemy) override;

};


#endif //MAZZARONE_ROSADINI_MELEEATTACK_H
