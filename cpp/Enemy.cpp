//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(): Character(2,2,0.1){}

void Enemy::movement(float x, float y) {
    if(abs(y - sprite.getPosition().y) > speed ||
       abs(x - sprite.getPosition().x) > speed) {
        float directionX = (x - sprite.getPosition().x) / std::abs(x - sprite.getPosition().x);
        float directionY = (y- sprite.getPosition().y)/std::abs(y- sprite.getPosition().y);
        sprite.move(directionX*speed, directionY*speed);
    }
    else{
        source.y = attack;
        this->doAnimation();
    }
}

void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}
