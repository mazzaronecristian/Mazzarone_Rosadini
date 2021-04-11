//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_MOVESTRATEGY_H
#define MAZZARONE_ROSADINI_MOVESTRATEGY_H
#include "Character.h"

class MoveStrategy {
public:
    virtual ~MoveStrategy();

    virtual void movement(float x, float y, sf::Sprite& sprite, sf::Vector2i& source, float speed) = 0;
};


#endif //MAZZARONE_ROSADINI_MOVESTRATEGY_H
