//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(MoveStrategy *moveStrategy): moveStrategy(moveStrategy), Character(2,2,0.1){}

void Enemy::movement(float x, float y) {
    moveStrategy->movement(x, y, sprite, source, speed);
    delete moveStrategy;
    doAnimation();
}

MoveStrategy *Enemy::getMoveStrategy() const {
    return moveStrategy;
}

void Enemy::setMoveStrategy(MoveStrategy *moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}


void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}

