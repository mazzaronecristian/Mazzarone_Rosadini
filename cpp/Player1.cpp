//
// Created by cristian on 28/02/21.
//

#include "../header/Player1.h"

#include <utility>

Player1::Player1(CharacterType type, std::shared_ptr<AttackStrategy> attackStrategy) : attackStrategy(
        std::move(attackStrategy)), Character(type) {
}

Player1::Player1(CharacterType type, int hp, int damage, std::shared_ptr<AttackStrategy> attackStrategy)
        : attackStrategy(
        std::move(attackStrategy)), Character(type, hp, damage) {
}

Player1::~Player1() {}

void Player1::movement(sf::Vector2f direction, const Map &map) {
    if (!dying && !attacking) {
        if (direction.x == 0) {
            if (source.y == stayR)
                source.y = right;
            else
                source.y = left;
        } else {
            if (direction.x == 1)
                source.y = right;
            else
                source.y = left;
        }
        setAnim(8, 0.06);
        if (isLegalMove(direction, map)) {
            sprite.move(direction.x * speed, direction.y * speed);
        }
    }
}

/*Potion Player1::getPotion() const {
    return potion;
}

void Player1::setPotion(Potion potion) {
    Player1::potion = potion;
}

void Player1::usePotion() {
    if(potion.getDescription()=="heal")
        setHp(potion.use(getHp()));
    else
        setDamage(potion.use(getDamage()));
}*/

void Player1::fight(Character &character) {
    if (!dying)
        attackStrategy->fight(this, character);
}

void Player1::update(float deltaTime) {
    Character::update(deltaTime);
    if (attacking && source.x >= 7)
        attacking = false;
}


/*AttackStrategy *Player1::getAttackStrategy() const {
    return attackStrategy;
}

void Player1::setAttackStrategy(AttackStrategy *attackStrategy) {
    Player1::attackStrategy = attackStrategy;
}
*/

