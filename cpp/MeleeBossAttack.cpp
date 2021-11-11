//
// Created by Gianluca Rosadini on 03/11/21.
//

#include "../header/MeleeBossAttack.h"
#include "../header/Boss.h"

void MeleeBossAttack::fight(Character &hero, Boss *boss) {
    if (boss->getAttackTimer() < .8) return;
    boss->setAnim(8, .06, hero.getPosition().x < boss->getPosition().x ? 5 : 4);
    if (boss->getSource().x == 5) {
        boss->setSourceX(boss->getSource().x + 1);
        hero.receiveDamage(boss->getDamage());
        boss->setAttackTimer(0);
    }
}
