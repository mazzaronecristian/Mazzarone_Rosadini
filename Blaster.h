//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_BLASTER_H
#define MAZZARONE_ROSADINI_BLASTER_H

#include "Weapon.h"
class Blaster: public Weapon {
public:
    int attack() override;

    Blaster(int ammo);

private:
    int ammo;
};


#endif //MAZZARONE_ROSADINI_BLASTER_H
