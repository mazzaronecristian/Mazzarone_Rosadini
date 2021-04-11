//
// Created by cristian on 06/04/21.
//

#include "../header/Follow.h"

void Follow::movement(float x, float y, sf::Sprite& sprite, sf::Vector2i& source, float speed) {
    if(abs(y - sprite.getPosition().y) > speed || abs(x - sprite.getPosition().x) > speed) {
        float directionX = (x - sprite.getPosition().x) / std::abs(x - sprite.getPosition().x);
        float directionY = (y- sprite.getPosition().y)/std::abs(y- sprite.getPosition().y);
        sprite.move(directionX*speed, directionY*speed);
        if(directionX == -1)
            source.y = 2;
        else
            source.y = 1;
    }
}
