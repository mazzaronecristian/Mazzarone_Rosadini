//
// Created by Gianluca Rosadini on 11/11/21.
//

#include "../header/RangedBossAttack.h"
#include "../header/Boss.h"
#include "../header/BulletsFactory.h"

void RangedBossAttack::fight(Character &hero, Boss *boss) {
    if (boss->getAttackTimer() < .8) return;
    int numLaser = 0;
    for (auto i = boss->getLasers().begin(); i != boss->getLasers().end(); i++)
        numLaser++;
    if (numLaser < 3) {
        short int direction;
        if (boss->getSource().y % 2 == 0) {
            boss->setAnim(6, 0.1, 8);
            direction = 1;
        } else {
            boss->setAnim(6, 0.1, 9);
            direction = -1;
        }
        BulletsFactory factory;
        Bullet bullet = factory.createBullet(boss->getPosition(), direction);
        boss->addLaser(bullet);
    }
    if (boss->getSource().x == 5)
        boss->setAttackTimer(0);
}



