//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_MOVESTRATEGY_H
#define MAZZARONE_ROSADINI_MOVESTRATEGY_H
#include "Character.h"

class MoveStrategy {
public:
    virtual ~MoveStrategy();

    virtual int movement(float x, float y, sf::Sprite& sprite, float speed) = 0;
};


#endif //MAZZARONE_ROSADINI_MOVESTRATEGY_H
