//
// Created by cristian on 28/02/21.
//

#include "../header/Player1.h"

Player1::Player1() {}

Player1::~Player1() {}

void Player1::movement(float x, float y) {
    if(x==0){
        if(source.y == stay)
            source.y = right;
    }
    else{
        if(x==1)
            source.y = right;
        else
            source.y = left;
    }
    sprite.move(x*speed, y*speed);
    doAnimation();
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

