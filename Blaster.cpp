//
// Created by cristian on 28/02/21.
//

#include "Blaster.h"

Blaster::Blaster(int ammo) : ammo(ammo) {}

int Blaster::attack() {
    Weapon::attack();
}

