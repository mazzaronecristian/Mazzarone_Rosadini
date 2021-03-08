//
// Created by cristian on 08/03/21.
//

#ifndef MAZZARONE_ROSADINI_MELEEATTACK_H
#define MAZZARONE_ROSADINI_MELEEATTACK_H

#include "AttackStrategy.h"

class meleeAttack: public AttackStrategy {
    void attack(Character &enemy, Character &hero) override;

};


#endif //MAZZARONE_ROSADINI_MELEEATTACK_H
