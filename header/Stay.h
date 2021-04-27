//
// Created by Gianluca Rosadini on 17/04/21.
//

#ifndef MAZZARONE_ROSADINI_STAY_H
#define MAZZARONE_ROSADINI_STAY_H

#include "MoveStrategy.h"

class Stay: public MoveStrategy{
    sf::Vector2f movement(float x, float y, sf::Sprite &sprite) override;
};


#endif //MAZZARONE_ROSADINI_STAY_H
