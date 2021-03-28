//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(){}

Enemy::~Enemy() {

}

void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}
