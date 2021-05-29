//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

#include <utility>

Enemy::Enemy(std::shared_ptr<MoveStrategy> moveStrategy): moveStrategy(std::move(moveStrategy)), Character(100,2,0.1){}

void Enemy::movement(float x, float y) {
    if(abs(y - sprite.getPosition().y) > speed || abs(x - sprite.getPosition().x) > speed) {
        sf::Vector2f direction = moveStrategy->movement(x, y, sprite);
        sprite.move(direction.x * speed, direction.y * speed);
        if(direction.x < 0)
            source.y = left;
        else if(direction.x== 0 && direction.y == 0)
            source.y = stayR;
        else source.y = right;
    }
    else
        source.y = stayL;
}

void Enemy::setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}

void Enemy::kill() {
    Character::kill();
}

Enemy::Enemy() {

}

void Enemy::fight(Character &character) {

}


