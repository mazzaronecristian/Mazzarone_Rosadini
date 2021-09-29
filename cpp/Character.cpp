//
// Created by cristian on 28/02/21.
//

#include "../header/Character.h"

Character::Character(CharacterType type, int hp, int damage, float speed, bool isAttacking, bool isDying) : hp(hp),
                                                                                                            damage(damage),
                                                                                                            speed(speed),
                                                                                                            attacking(
                                                                                                                    isAttacking),
                                                                                                            dying(isDying),
                                                                                                            type(type) {}

//getter
int Character::getHp() const {
    return hp;
}

int Character::getDamage() const {
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
    if (type == CharacterType::spaceCadet)
        attacking = false;
}

void Character::kill() {
    attacking = false;
    dying = true;
    setAnim(8, 0.15, die);
    if (source.x == 7)
        life = false;
}

void Character::fight(Character &character) {
    attacking = true;
}

bool Character::isLegalFight(const Character &character) {
    sf::FloatRect box = character.getSprite().getGlobalBounds();
    sf::FloatRect thisBox = sprite.getGlobalBounds();
    if (thisBox.intersects(box))
        return true;
    return false;
}

bool Character::isFighting() const {
    return attacking;
}

void Character::setIsFighting(bool isAttacking) {
    Character::attacking = isAttacking;
}


CharacterType Character::getType() const {
    return type;
}

bool Character::isDying() const {
    return dying;
}
