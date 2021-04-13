//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(MoveStrategy *moveStrategy): moveStrategy(moveStrategy), Character(2,2,0.1){}

void Enemy::movement(float x, float y) {
    delete moveStrategy;
    moveStrategy->movement(x, y, sprite, source, speed);
    doAnimation();
}

void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}

MoveStrategy *Enemy::getMoveStrategy() const {
    return moveStrategy;
}

void Enemy::setMoveStrategy(MoveStrategy *moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}

