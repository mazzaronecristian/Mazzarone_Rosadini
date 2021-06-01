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

void Character::update(float deltaTime) {
    Entity::update(deltaTime);
    if(hp==0)
        life = false;
}

void Character::kill() {
    source = {4,6};
}

void Character::fight(Character &character) {

}

bool Character::isLegalMove(Character &character) {
    sf::FloatRect box = sprite.getGlobalBounds();
    sf::FloatRect extBox = character.getSprite().getGlobalBounds();
    if(box.intersects(extBox))
        return false;
    return true;
}

