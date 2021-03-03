//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_HAMMER_H
#define MAZZARONE_ROSADINI_HAMMER_H

#include "Weapon.h"

class Hammer: public Weapon {
public:
    void attack() override;

    Hammer();
};


#endif //MAZZARONE_ROSADINI_HAMMER_H
