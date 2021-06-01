//
// Created by cristian on 06/04/21.
//

#ifndef MAZZARONE_ROSADINI_FOLLOW_H
#define MAZZARONE_ROSADINI_FOLLOW_H

#include "MoveStrategy.h"
#include <cmath>

class Follow: public MoveStrategy {
public:
    sf::Vector2f movement(sf::Vector2f direction, sf::Sprite &sprite) override;
};

#endif //MAZZARONE_ROSADINI_FOLLOW_H
