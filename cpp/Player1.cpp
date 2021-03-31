//
// Created by cristian on 28/02/21.
//

#include "../header/Player1.h"

Player1::Player1() {}

Player1::~Player1() {}


void Player1::moveUp() {
    if(this->getSource().y == stay)
        this->setSourceY(right);
    this->movement(0, -speed);

    this->doAnimation();
}

void Player1::moveDown() {
    if(this->getSource().y == stay)
        this->setSourceY(right);
    this->movement(0, speed);

    this->doAnimation();
}

void Player1::moveLeft() {
    this->setSourceY(left);
    this->movement(-speed, 0);

    this->doAnimation();
}

void Player1::moveRight() {
    this->setSourceY(right);
    this->movement(speed, 0);

    this->doAnimation();
}
void Player1::fight(Character &enemy) {

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

bool Player1::isLegalFight(Character &enemy) {
    return false;
}

/*AttackStrategy *Player1::getAttackStrategy() const {
    return attackStrategy;
}

void Player1::setAttackStrategy(AttackStrategy *attackStrategy) {
    Player1::attackStrategy = attackStrategy;
}
*/

