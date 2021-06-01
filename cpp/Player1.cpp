//
// Created by cristian on 28/02/21.
//

#include "../header/Player1.h"

#include <utility>

Player1::Player1(const std::shared_ptr<AttackStrategy>&  attackStrategy): attacksStrategy(std::move(attackStrategy)) {

}
Player1::~Player1() {}

void Player1::movement(sf::Vector2f direction) {
    if(direction.x==0){
        if(source.y == stayR)
            source.y = right;
        else
            source.y = left;
    }
    else{
        if(direction.x==1)
            source.y = right;
        else
            source.y = left;
    }
    sprite.move(direction.x*speed, direction.y*speed);
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

void Player1::fight(Character &character) {
    attacksStrategy->fight(character, damage);
}



/*AttackStrategy *Player1::getAttackStrategy() const {
    return attackStrategy;
}

void Player1::setAttackStrategy(AttackStrategy *attackStrategy) {
    Player1::attackStrategy = attackStrategy;
}
*/

