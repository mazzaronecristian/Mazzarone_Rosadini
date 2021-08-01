//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_MOVESTRATEGY_H
#define MAZZARONE_ROSADINI_MOVESTRATEGY_H

#include "Character.h"

class MoveStrategy {
public:
    virtual ~MoveStrategy() = default;

    virtual sf::Vector2f movement(sf::Vector2f direction, sf::Sprite &sprite) = 0;
};


#endif //MAZZARONE_ROSADINI_MOVESTRATEGY_H
