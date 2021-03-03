//
Axe::Axe() {}
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_AXE_H
#define MAZZARONE_ROSADINI_AXE_H

#include "Weapon.h"

class Axe: public Weapon {
public:
    Axe();

    void attack() override;

};


#endif //MAZZARONE_ROSADINI_AXE_H
