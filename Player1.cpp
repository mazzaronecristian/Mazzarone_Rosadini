//
// Created by cristian on 28/02/21.
//

#include "Player1.h"

Player1::Player1(int hp, int posX, int posY, int damage) : Character(hp, posX, posY, damage) {

}
Player1::~Player1() {

}

void Player1::move(int posX, int posY) {

}

void Player1::fight(Character &enemy) {

}

Weapon* Player1::getWeapon() const {
    return weapon;
}

void Player1::setWeapon(Weapon* weapon) {
    Player1::weapon = weapon;
}

Potion* Player1::getPotion() const {
    return potion;
}

void Player1::setPotion(Potion* potion) {
    Player1::potion = potion;
}

void Player1::usePotion() {
    if(potion->getDescription()=="heal")
        setHp(potion->use(getHp()));
    else
        setDamage(potion->use(getDamage()));
}

bool Player1::isLegalFight(Character &enemy) {
    return false;
}

AttackStrategy *Player1::getAttackStrategy() const {
    return attackStrategy;
}

void Player1::setAttackStrategy(AttackStrategy *attackStrategy) {
    Player1::attackStrategy = attackStrategy;
}

/*Player1::Player1(int hp, int posX, int posY, int damage) : Character(hp, posX, posY, damage) {

}*/

//Player1::Player1(int hp, int posX, int posY, int damage, const Weapon &weapon, const Potion &potion) : Character(hp, posX, posY, damage), weapon(weapon), potion(potion) {}


