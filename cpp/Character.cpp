//
// Created by cristian on 28/02/21.
//

#include "../header/Character.h"

Character::Character(int hp, int damage, float speed, bool isAttacking, bool isDying): hp(hp), damage(damage), speed(speed), isAttacking(isAttacking), isDying(isDying){}

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
//    if(hp<=0){
//        life = false;
//    }
    isAttacking = false;
}

void Character::kill() {
    isDying = true;
    source.y = die;
    setAnim(6,0.08);
    if(source.x == 5)
       life = false;
}

void Character::fight(Character &character) {
    isAttacking = true;
}

bool Character::isLegalMove(Character &character) {
    sf::FloatRect box = sprite.getGlobalBounds();
    sf::FloatRect extBox = character.getSprite().getGlobalBounds();
    if(box.intersects(extBox))
        return false;
    return true;
}

bool Character::isLegalFight(const Character &character) {
    sf::FloatRect box = character.getSprite().getGlobalBounds();
    sf::FloatRect thisBox = sprite.getGlobalBounds();
    if(thisBox.intersects(box))
        return true;
    return false;
}

bool Character::isFighting() const {
    return isAttacking;
}

void Character::setIsFighting(bool isAttacking) {
    Character::isAttacking = isAttacking;
}
