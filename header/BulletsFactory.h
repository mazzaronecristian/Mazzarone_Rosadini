//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_BULLETSFACTORY_H
#define MAZZARONE_ROSADINI_BULLETSFACTORY_H

#include "Bullet.h"
#include "Character.h"

enum class BulletType {
    bullet, laser
};

class BulletsFactory {
public:
    static Bullet createBullet(BulletType type, short int direction, sf::Vector2f position, sf::Vector2i dimension);

    static std::string setBitmap(BulletType type);
};


#endif //MAZZARONE_ROSADINI_BULLETSFACTORY_H
