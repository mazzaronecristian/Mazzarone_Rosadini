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

