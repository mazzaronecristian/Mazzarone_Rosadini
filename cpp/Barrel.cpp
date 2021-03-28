//
// Created by cristian on 02/03/21.
//

#include "../header/Barrel.h"

Barrel::Barrel(int hp, Potion potion) : hp(hp), potion(potion) {}

Barrel::~Barrel() {

}

void Barrel::receiveDamage(int damage) {
    Barrel::hp -= damage;
}

