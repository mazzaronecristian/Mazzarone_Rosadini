//
// Created by cristian on 28/05/21.
//

#include "../header/RangedAttack.h"

void RangedAttack::fight(Character *hero, Character &enemy) {
    enemy.receiveDamage(hero->getDamage() - 5);
}
