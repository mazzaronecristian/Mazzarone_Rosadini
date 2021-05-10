//
// Created by Gianluca Rosadini on 16/03/21.
//

#include "../header/Bullet.h"

Bullet::~Bullet() = default;

Bullet::Bullet(bool bulletDirection, float speed):bulletDirection(bulletDirection), speed(speed) {
}

void Bullet::movement(){
    if(bulletDirection)
        sprite.move(speed,0);
    else
        sprite.move(-speed,0);
}

