//
// Created by cristian on 06/04/21.
//

#ifndef MAZZARONE_ROSADINI_FOLLOW_H
#define MAZZARONE_ROSADINI_FOLLOW_H

#include "MoveStrategy.h"
#include <cmath>

class Follow: public MoveStrategy {
public:
    void movement(float x, float y, sf::Sprite& sprite, sf::Vector2i& source, float speed) override;
};


#endif //MAZZARONE_ROSADINI_FOLLOW_H
