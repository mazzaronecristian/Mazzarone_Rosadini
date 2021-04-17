//
// Created by Gianluca Rosadini on 17/04/21.
//

#ifndef MAZZARONE_ROSADINI_STAY_H
#define MAZZARONE_ROSADINI_STAY_H

#include "MoveStrategy.h"

class Stay: public MoveStrategy{
    int movement(float x, float y, sf::Sprite &sprite, float speed) override;
};


#endif //MAZZARONE_ROSADINI_STAY_H
