//
// Created by cristian on 02/11/21.
//

#ifndef MAZZARONE_ROSADINI_OBJECTSFACTORY_H
#define MAZZARONE_ROSADINI_OBJECTSFACTORY_H

#include "Potion.h"
#include "Barrel.h"

class ObjectsFactory {
public:
    ObjectsFactory();

    static Potion createPotion(PotionType type, sf::Vector2f position);

    static Barrel createBarrel(PotionType type, sf::Vector2f position);

private:
    static std::string setBitmap(PotionType);
};

#endif //MAZZARONE_ROSADINI_OBJECTSFACTORY_H