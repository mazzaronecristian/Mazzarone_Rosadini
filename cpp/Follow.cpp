//
// Created by cristian on 06/04/21.
//

#include "../header/Follow.h"
sf::Vector2f Follow::movement(float x, float y, sf::Sprite &sprite) {
        float e = 0.1;
        sf::Vector2f direction;
        direction.x = (x - sprite.getPosition().x ) / std::abs((x - sprite.getPosition().x)+e);
        direction.y = (y - sprite.getPosition().y ) / std::abs((y - sprite.getPosition().y)+e);
        return direction;
}
