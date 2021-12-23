//
// Created by cristian on 02/03/21.
//

#include "../header/Barrel.h"

Barrel::Barrel(PotionType type) : potion(std::make_shared<Potion>(Potion(type))), Entity(sf::Vector2i(32, 32)) {
}

void Barrel::update(float deltaTime) {
    Entity::update(deltaTime);
    if (source == sf::Vector2i(7, 1))
        life = false;
}

bool Barrel::kill(PotionType &type) {
    if (source.y != 1) {
        source.y = 1;
        setAnim(8, 0.06);
        type = potion->getType();
        return true;
    }
    return false;
}


