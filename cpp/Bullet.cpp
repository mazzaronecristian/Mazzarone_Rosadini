//
// Created by Gianluca Rosadini on 16/03/21.
//

#include "../header/Bullet.h"

Bullet::~Bullet() = default;

Bullet::Bullet(short int bulletDirection, float speed):bulletDirection(bulletDirection), speed(speed), Entity(32,3){
    }

void Bullet::movement(){
        sprite.move((float)bulletDirection*speed,0);
}

void Bullet::update(float deltaTime) {
    Entity::update(deltaTime);
    if(source.x==2)
        life=false;
}

bool Bullet::isCollide(const Enemy &enemy) {
    sf::FloatRect bulletBox = sprite.getGlobalBounds();
    sf::FloatRect characterBox = enemy.getSprite().getGlobalBounds();
    if(bulletBox.intersects(characterBox)){
        life = false;
        return true;
    }
    return false;
}