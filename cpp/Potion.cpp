//
// Created by cristian on 02/03/21.
//

#include "../header/Potion.h"


Potion::Potion(PotionType type) : type(type), Entity(sf::Vector2i(32, 32)) {}

Potion::~Potion() = default;

int Potion::use(int result) {
    int increment = static_cast<int>(type);
    result += increment;
    return result;
}

PotionType Potion::getType() const {
    return type;
}