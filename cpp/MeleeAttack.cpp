//
// Created by cristian on 08/09/21
//

#include "../header/MeleeAttack.h"

void MeleeAttack::fight(Character *hero, Character &enemy) {
    if (hero->getSource().x == 5) {
        hero->setSourceX(hero->getSource().x + 1);
        enemy.receiveDamage(hero->getDamage());
    }
    if (hero->getSource().x >= 7)
        hero[0].setIsFighting(false);
}
