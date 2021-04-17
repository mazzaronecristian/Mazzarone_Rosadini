//
// Created by cristian on 13/04/21.
//

#include "../header/Patrol.h"

Patrol::Patrol() {}

int Patrol::movement(float x, float y, sf::Sprite &sprite, float speed) {

    float e = 0.1;
    int positionY = (int) (abs(sprite.getPosition().y - 500) / abs((sprite.getPosition().y - 500) + e));
    sprite.move(0 * speed, positionY * speed);
    return 1;

}
