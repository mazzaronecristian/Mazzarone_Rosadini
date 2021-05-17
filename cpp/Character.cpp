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

float Character::getSpeed() const {
    return speed;
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

void Character::setSpeed(float speed) {
    Character::speed = speed;
}

bool Character::isLegalMove(sf::FloatRect bBox) {
    //if(sprite.getGlobalBounds().intersects(bBox))
        //return false;
    return true;
}

//bool Character::isLegalMove() {
//    if(sprite.getPosition().y < 32 || sprite.getPosition().y > 560)
//        return false;
//    if(sprite.getPosition().x < 16 || sprite.getPosition().x > 905)
//        return false;
//    return true;
//}

