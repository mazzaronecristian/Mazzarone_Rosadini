//
// Created by cristian on 06/09/21.
//

#include "../header/UserInterfaceFactory.h"

LifeBar UserInterfaceFactory::createLifeBar(Character *character) {
    LifeBar lifeBar(character);
    lifeBar.load(setBitMap(UserInterfaceType::lifeBar), sf::Vector2f(10, 680));
    return lifeBar;
}

std::string UserInterfaceFactory::setBitMap(UserInterfaceType type) {
    std::string result;
    if (type == UserInterfaceType::lifeBar)
        result = "./tileSets/userInterface/lifeBar.png";
    return result;
}