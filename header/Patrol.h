//
// Created by cristian on 13/04/21.
//

#ifndef MAZZARONE_ROSADINI_PATROL_H
#define MAZZARONE_ROSADINI_PATROL_H

#include "MoveStrategy.h"
class Patrol: public MoveStrategy{
public:
    Patrol();

    void movement(float x, float y, sf::Sprite &sprite, sf::Vector2i &source, float speed) override;

};


#endif //MAZZARONE_ROSADINI_PATROL_H
