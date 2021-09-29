//
// Created by cristian on 29/09/21.
//

#include "../header/AdaptVertical.h"

sf::Vector2f AdaptVertical::movement(sf::Vector2f direction, sf::Sprite &sprite) {
    sf::Vector2f dir;
    dir = {0, static_cast<float>(direction.y <= sprite.getPosition().y ? -1 : 1)};
    return dir;
}
