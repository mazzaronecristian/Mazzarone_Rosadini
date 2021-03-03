//
// Created by cristian on 28/02/21.
//

#include "Player1.h"
Player1::~Player1() {

}

void Player1::move(int posX, int posY) {

}

void Player1::fight(Character) {

}

bool Player1::isLegalFight(Character) {
    return false;
}

Player1::Player1(int hp, int posX, int posY, int damage) : Character(hp, posX, posY, damage) {

}

const Weapon &Player1::getWeapon() const {
    return weapon;
}

void Player1::setWeapon(const Weapon &weapon) {
    Player1::weapon = weapon;
}

const Potion &Player1::getPotion() const {
    return potion;
}

void Player1::setPotion(const Potion &potion) {
    Player1::potion = potion;
}

/*Player1::Player1(int hp, int posX, int posY, int damage) : Character(hp, posX, posY, damage) {

}*/

//Player1::Player1(int hp, int posX, int posY, int damage, const Weapon &weapon, const Potion &potion) : Character(hp, posX, posY, damage), weapon(weapon), potion(potion) {}


