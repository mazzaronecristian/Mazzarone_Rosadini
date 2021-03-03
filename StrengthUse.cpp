//
// Created by cristian on 02/03/21.
//

#include "StrengthUse.h"

void StrengthUse::use() {
    UseStrategy::use();
    Character::setDamage(Character::getDamage()+2);
}
