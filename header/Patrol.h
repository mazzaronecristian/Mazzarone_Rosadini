//
// Created by cristian on 13/04/21.
//

#ifndef MAZZARONE_ROSADINI_PATROL_H
#define MAZZARONE_ROSADINI_PATROL_H

#include "MoveStrategy.h"

class Patrol : public MoveStrategy {
public:
    Patrol();
    sf::Vector2f movement(sf::Vector2f direction, sf::Sprite &sprite) override;
};

#endif //MAZZARONE_ROSADINI_PATROL_H
