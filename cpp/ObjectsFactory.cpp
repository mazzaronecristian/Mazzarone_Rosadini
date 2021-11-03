//
// Created by cristian on 02/11/21.
//

#include "../header/ObjectsFactory.h"

ObjectsFactory::ObjectsFactory() {
}

Barrel ObjectsFactory::createBarrel(PotionType type, sf::Vector2f position) {
    auto *barrel = new Barrel(type);
    barrel->load("./tileSets/objects/barrel.png", position);
    return *barrel;
}

Potion ObjectsFactory::createPotion(PotionType type, sf::Vector2f position) {
    Potion *potion = new Potion(type);
    potion->load(setBitmap(type), position);
    return *potion;
}

std::string ObjectsFactory::setBitmap(PotionType type) {
    if (type == PotionType::regular)
        return "./tileSets/objects/potionRegular.png";
    if (type == PotionType::super)
        return "./tileSets/objects/potionSuper.png";
    if (type == PotionType::max)
        return "./tileSets/objects/potionMax.png";
    return "./tileSets/objects/potionRegular.png";
}
