//
// Created by Gianluca Rosadini on 03/11/21.
//

#include "../header/MeleeBossAttack.h"

void MeleeBossAttack::fight(Character &hero, Enemy *boss, float &timer) {
    if (timer < .8) return;
    boss->setAnim(8, 0.06, hero.getPosition().x < boss->getPosition().x ? 5 : 4);
    if (boss->getSource().x == 5) {
        boss->setSourceX(boss->getSource().x + 1);
        hero.receiveDamage(boss->getDamage());
        timer = 0;
    }
}
