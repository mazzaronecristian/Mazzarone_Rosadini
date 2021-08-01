//
// Created by cristian on 06/04/21.
//

#include "../header/Follow.h"

sf::Vector2f Follow::movement(sf::Vector2f direction, sf::Sprite &sprite) {
    float e = 0.1;
    sf::Vector2f dir;
    dir.x = (direction.x - sprite.getPosition().x) / std::abs((direction.x - sprite.getPosition().x) + e);
    dir.y = (direction.y - sprite.getPosition().y) / std::abs((direction.y - sprite.getPosition().y) + e);
    return dir;
}
