//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

#include <utility>

Enemy::Enemy(std::shared_ptr<MoveStrategy> moveStrategy): moveStrategy(std::move(moveStrategy)), Character(100,1,0.1){}

void Enemy::movement(sf::Vector2f direction) {
    if(life && !isAttacking && !isDying){
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
}
void Enemy::setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}
Enemy::Enemy(){

}
void Enemy::fight(Character &character) {
    Character::fight(character);
    if(hp>0){
        if(source.y %2 == 0)
            source.y = attackR;
        else source.y = attackL;
        if(source.x==5){
            source.x++;
            character.receiveDamage(damage);
        }
    }
}
void Enemy::kill() {
    Character::kill();
}


