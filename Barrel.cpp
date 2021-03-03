//
// Created by cristian on 02/03/21.
//

#include "Barrel.h"

Barrel::Barrel(int hp, const Potion &potion) : hp(hp), potion(potion) {}

Barrel::~Barrel() {

}

void Barrel::receiveDamage(int damage) {
    Barrel::hp -= damage;
}

