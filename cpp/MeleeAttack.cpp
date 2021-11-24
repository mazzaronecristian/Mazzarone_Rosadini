//
// Created by cristian on 08/09/21
//

#include "../header/MeleeAttack.h"

void MeleeAttack::fight(Character *hero, Character &enemy) {
    enemy.receiveDamage(hero->getDamage() + 10);
}
