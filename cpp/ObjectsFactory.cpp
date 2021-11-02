//
// Created by cristian on 02/11/21.
//

#include "../header/ObjectsFactory.h"

ObjectsFactory::ObjectsFactory() {

}


Barrel ObjectsFactory::createBarrel(sf::Vector2f position) {
    auto *barrel = new Barrel(PotionType::regular);
    barrel->load("./tileSets/objects/barrel.png", position);
    return *barrel;
}

Potion ObjectsFactory::createPotion(Potion &potion, sf::Vector2f position) {
    potion.load(setBitmap(potion.getType()), position);
    return potion;
}

std::string ObjectsFactory::setBitmap(PotionType type) {
    if (type == PotionType::regular)
        return "./tileSets/objects/potion.png";
    if (type == PotionType::super)
        return "./tileSets/objects/potion.png";
    if (type == PotionType::max)
        return "./tileSets/objects/potion.png";
}

