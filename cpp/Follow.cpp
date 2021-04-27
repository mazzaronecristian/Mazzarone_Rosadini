//
// Created by cristian on 06/04/21.
//

#include "../header/Follow.h"

int Follow::movement(float x, float y, sf::Sprite& sprite, float speed) {
    if(abs(y - sprite.getPosition().y) > speed || abs(x - sprite.getPosition().x) > speed) {
        float e = 0.1;
        float directionX = (x - sprite.getPosition().x ) / std::abs((x - sprite.getPosition().x)+e);
        float directionY = (y - sprite.getPosition().y ) / std::abs((y - sprite.getPosition().y)+e);
        sprite.move(directionX * speed, directionY * speed);
        if (directionX < 0 )
            return 2;
        else
            return 1;
    }
    return 0;
}
