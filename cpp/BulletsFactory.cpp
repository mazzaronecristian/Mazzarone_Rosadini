//
// Created by cristian on 24/06/21.
//

#include "../header/BulletsFactory.h"

Bullet
BulletsFactory::createBullet(BulletType type, short int direction, sf::Vector2f position, sf::Vector2i dimension) {
    auto *result = new Bullet(direction, dimension);
    position.y += 16;
    position.x += (40 * (float) direction);
    result->load(setBitmap(type), position);
    return *result;
}

std::string BulletsFactory::setBitmap(BulletType type) {
    if (type == BulletType::laser)
        return "./tileSets/bullets/laser.png";
    else return "./tileSets/bullets/bullet.png";
}
