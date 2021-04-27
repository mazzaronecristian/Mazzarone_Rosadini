//
// Created by cristian on 06/04/21.
//

#include "../header/Follow.h"
sf::Vector2f Follow::movement(float x, float y, sf::Sprite &sprite) {
    //if(abs(y - sprite.getPosition().y) > speed || abs(x - sprite.getPosition().x) > speed) {
        float e = 0.1;
        sf::Vector2f direction;
        direction.x = (x - sprite.getPosition().x ) / std::abs((x - sprite.getPosition().x)+e);
        direction.y = (y - sprite.getPosition().y ) / std::abs((y - sprite.getPosition().y)+e);
//        float directionX = (x - sprite.getPosition().x ) / std::abs((x - sprite.getPosition().x)+e);
//        float directionY = (y - sprite.getPosition().y ) / std::abs((y - sprite.getPosition().y)+e);
        return direction;
//        if (directionX < 0 )
//            return 2;
//        else
//            return 1;
    //}
}
