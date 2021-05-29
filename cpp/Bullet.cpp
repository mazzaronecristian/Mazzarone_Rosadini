//
// Created by Gianluca Rosadini on 16/03/21.
//

#include <iostream>
#include "../header/Bullet.h"

Bullet::~Bullet() = default;

Bullet::Bullet(short int bulletDirection, float speed):bulletDirection(bulletDirection), speed(speed) {
}

void Bullet::movement(){
        sprite.move((float)bulletDirection*speed,0);
}

void Bullet::update(float deltaTime) {
    Entity::update(deltaTime);
    if(source.x==2)
        life=false;
}

bool Bullet::isCollide(Enemy &enemy) {
    sf::FloatRect bulletBox = sprite.getGlobalBounds();
    sf::FloatRect characterBox = enemy.getSprite().getGlobalBounds();
    if(bulletBox.intersects(characterBox)){
        life = false;
        return true;
    }
    return false;
}

bool Bullet::isCollide(std::list<Enemy> &enemies) {
    sf::FloatRect bulletBox = sprite.getGlobalBounds();
    for(auto i=enemies.begin(); i!=enemies.end(); i++){
        sf::FloatRect iBox = i->getSprite().getGlobalBounds();
        if(bulletBox.intersects(iBox)){
            life = false;
            i->setLife(false);
            return true;
        }
    }
    return false;
}

