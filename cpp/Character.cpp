//
// Created by cristian on 28/02/21.
//

#include "../header/Character.h"

Character::Character(int hp, int damage, float speed): hp(hp), damage(damage), speed(speed){}

//getter
int Character::getHp() const{
    return hp;
}

int Character::getDamage() const{
    return damage;
}

//setter
void Character::setHp(int hp) {
    Character::hp = hp;
}

void Character::setDamage(int damage) {
    Character::damage = damage;
}

void Character::receiveDamage(int damage) {
    Character::hp -= damage;
}
