//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

#include <utility>

Enemy::Enemy(std::shared_ptr<MoveStrategy> moveStrategy): moveStrategy(std::move(moveStrategy)), Character(100,2,0.1){}

void Enemy::movement(sf::Vector2f direction) {
    if(abs(direction.y - sprite.getPosition().y) > speed || abs(direction.x - sprite.getPosition().x) > speed) {
        sf::Vector2f dir = moveStrategy->movement(direction,sprite);
        sprite.move(dir.x * speed, dir.y * speed);
        if(dir.x < 0)
            source.y = left;
        else if(dir.x== 0 && dir.y == 0)
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


