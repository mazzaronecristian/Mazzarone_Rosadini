//
// Created by Gianluca Rosadini on 16/03/21.
//

#include "../header/Bullet.h"

Bullet::~Bullet() = default;

Bullet::Bullet(int posX, int posY) {

}

int Bullet::getPosX() const {
    return posX;
}

int Bullet::getPosY() const {
    return posY;
}

void Bullet::setPosX(int posX) {
    Bullet::posX = posX;
}

void Bullet::setPosY(int posY) {
    Bullet::posY = posY;
}
