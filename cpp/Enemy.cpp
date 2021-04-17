//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(std::shared_ptr<MoveStrategy> moveStrategy): moveStrategy(moveStrategy), Character(2,2,0.1){}

void Enemy::movement(float x, float y) {
    source.y = moveStrategy->movement(x, y, sprite, speed);
    doAnimation();
}

void Enemy::setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}


