//
// Created by cristian on 29/09/21.
//

#include "../header/AdaptHorizontal.h"

sf::Vector2f AdaptHorizontal::movement(sf::Vector2f direction, sf::Sprite &sprite) {
    sf::Vector2f dir;
    dir = {static_cast<float>(direction.x <= sprite.getPosition().x ? -1 : 1), 0};
    return dir;
}
