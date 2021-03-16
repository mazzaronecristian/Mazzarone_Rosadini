//
// Created by cristian on 28/02/21.
//

#include "Character.h"

Character::Character(int hp, int posX, int posY, int damage) : hp(hp), posX(posX), posY(posY), damage(damage) {}

int Character::getHp() const{
    return hp;
}

int Character::getPosX() const{
    return posX;
}

int Character::getPosY() const{
    return posY;
}

int Character::getDamage() const{
    return damage;
}

void Character::setHp(int hp) {
    Character::hp = hp;
}

void Character::setPosX(int posX) {
    Character::posX = posX;
}

void Character::setPosY(int posY) {
    Character::posY = posY;
}

void Character::setDamage(int damage) {
    Character::damage = damage;
}

void Character::receiveDamage(int damage) {
    Character::hp -= damage;
}
