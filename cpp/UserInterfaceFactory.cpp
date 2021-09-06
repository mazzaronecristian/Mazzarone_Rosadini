//
// Created by cristian on 06/09/21.
//

#include "../header/UserInterfaceFactory.h"

LifeBar UserInterfaceFactory::createLifeBar(Character *character) {
    LifeBar lifeBar(character);
    lifeBar.load(setBitMap(ElementType::lifeBar), sf::Vector2f(10, 680));
    return lifeBar;
}

std::string UserInterfaceFactory::setBitMap(ElementType type) {
    std::string result;
    if (type == ElementType::lifeBar)
        result = "./tileSets/userInterface/lifeBar.png";
    return result;
}

UserInterfaceFactory::UserInterfaceFactory() {}
