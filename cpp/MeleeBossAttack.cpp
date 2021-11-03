//
// Created by Gianluca Rosadini on 03/11/21.
//

#include "../header/MeleeBossAttack.h"

void MeleeBossAttack::fight(Character &hero, Enemy *boss) {
    if (hero.getPosition().x < boss->getPosition().x)
        boss->setAnim(8, 0.06, 5);
    else boss->setAnim(8, 0.06, 4);
    if (boss->getSource().x == 5) {
        boss->setSourceX(boss->getSource().x + 1);
        hero.receiveDamage(boss->getDamage());
    }
}
