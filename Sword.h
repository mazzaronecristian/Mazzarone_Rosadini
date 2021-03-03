//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_SWORD_H
#define MAZZARONE_ROSADINI_SWORD_H

#include "Weapon.h"

class Sword: public Weapon {
public:
    void attack() override;

    Sword();
};


#endif //MAZZARONE_ROSADINI_SWORD_H
