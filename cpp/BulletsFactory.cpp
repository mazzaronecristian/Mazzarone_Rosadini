//
// Created by cristian on 24/06/21.
//

#include "../header/BulletsFactory.h"

Bullet BulletsFactory::createBullet(sf::Vector2f position, short int direction) {
    Bullet *result = new Bullet(direction);
    position.y += 16;
    position.x += (40 * (float) direction);
    result->load("./tileSets/bullet.png", position);
    return *result;
}
