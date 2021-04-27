//
// Created by cristian on 28/02/21.
//

#include "../header/FightStrategy.h"

void FightStrategy::fight(Character *hero, int damage) {
    hero->setHp(hero->getHp()-damage);
}
