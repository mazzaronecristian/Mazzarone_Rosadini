//
// Created by cristian on 02/03/21.
//

#include "HealUse.h"
#include "Character.h"
void HealUse::use() {
    UseStrategy::use();
    Character::setHp(Character::getHp()+2);
}
