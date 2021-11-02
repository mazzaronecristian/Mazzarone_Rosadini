//
// Created by cristian on 02/03/21.
//

#include "../header/Barrel.h"

Barrel::Barrel(PotionType type, int hp) : hp(hp), Entity(sf::Vector2i(32, 32)) {
    potion = new Potion(type);
}

Barrel::~Barrel() {

}

void Barrel::receiveDamage(int damage) {
    Barrel::hp -= damage;
}

void Barrel::update(float deltaTime) {
    Entity::update(deltaTime);
    if (source == sf::Vector2i(7, 1))
        life = false;
}

Potion &Barrel::kill() {
    source.y = 1;
    setAnim(8, 0.06);
    return *potion;
}

