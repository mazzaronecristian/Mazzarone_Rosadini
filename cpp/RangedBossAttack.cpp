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
        if (hero.getPosition().x < boss->getPosition().x) {
            boss->setAnim(6, 0.1, 9);
            direction = -1;
        } else {
            boss->setAnim(6, 0.1, 8);
            direction = 1;
        }
        if (boss->getSource().x == 4) {
            Bullet bullet = BulletsFactory::createBullet(BulletType::laser, direction,
                                                         sf::Vector2f(boss->getPosition().x,
                                                                      boss->getPosition().y - 16), sf::Vector2i(64, 7));
            boss->addLaser(bullet);
            boss->setAttackTimer(0);
        }
    }
}



