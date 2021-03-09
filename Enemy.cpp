//
// Created by cristian on 28/02/21.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int posX, int posY, int damage) : Character(hp, posX, posY, damage) {}

Enemy::~Enemy() {

}

void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}

void Enemy::move(MoveStrategy moveStrategy) {

}
