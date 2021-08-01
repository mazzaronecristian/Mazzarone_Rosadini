//
// Created by cristian on 24/06/21.
//

#include "../header/BulletsFactory.h"

std::shared_ptr<Bullet> BulletsFactory::createBullet(EntityType type, sf::Vector2f position, short int direction) {
    std::shared_ptr<Bullet> result(new Bullet(direction));
    position.y += 16;
    position.x += (16 * (float) direction);
    result->load(setBitMap(type), position);
    return result;
}
