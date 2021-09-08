//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_BULLETSFACTORY_H
#define MAZZARONE_ROSADINI_BULLETSFACTORY_H

#include "Bullet.h"
#include "Character.h"

class BulletsFactory {
public:
    Bullet createBullet(sf::Vector2f position, short int direction);
};


#endif //MAZZARONE_ROSADINI_BULLETSFACTORY_H
