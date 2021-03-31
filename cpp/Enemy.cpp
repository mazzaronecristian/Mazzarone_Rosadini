//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

Enemy::Enemy(): Character(2,2,0.1){}


void Enemy::movement(Player1 hero) {
    if(abs(hero.getSprite().getPosition().y - this->getSprite().getPosition().y) > speed ||
       abs(hero.getSprite().getPosition().x - this->getSprite().getPosition().x) > speed){

        if(hero.getSprite().getPosition().y > this->getSprite().getPosition().y){
            if(this->getSource().y == stay)
                this->setSourceY(right);
            this->Entity::movement(0,speed);
            this->doAnimation();
        }
        if(hero.getSprite().getPosition().y < this->getSprite().getPosition().y){
            if(this->getSource().y == stay)
                this->setSourceY(right);
            this->Entity::movement(0,-speed);
            this->doAnimation();
        }
        if(hero.getSprite().getPosition().x > this->getSprite().getPosition().x){
            this->setSourceY(right);
            this->Entity::movement(speed, 0);
            this->doAnimation();
        }
        if(hero.getSprite().getPosition().x < this->getSprite().getPosition().x){
            this->setSourceY(left);
            this->Entity::movement(-speed, 0);
            this->doAnimation();
        }
    }
}

void Enemy::fight(Character *hero) {
    this->fightStrategy.fight(hero, this->getDamage());
}
