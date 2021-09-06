//
// Created by cristian on 24/06/21.
//

#include "../header/CharacterFactory.h"

CharacterFactory::CharacterFactory() {}

sf::Vector2f CharacterFactory::setPosition(ElementType type) {
    std::srand(time(NULL));
    sf::Vector2f position = {0, 0};
    if (type == ElementType::hero)
        position = sf::Vector2f(100, 100);
    if (type == ElementType::ghoul)
        position = sf::Vector2f(rand() % 450 + 100, rand() % 450 + 100);
    return position;
}