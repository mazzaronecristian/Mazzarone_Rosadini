//
// Created by cristian on 29/09/21.
//

#ifndef MAZZARONE_ROSADINI_ADAPTHORIZONTAL_H
#define MAZZARONE_ROSADINI_ADAPTHORIZONTAL_H

#include "MoveStrategy.h"

class AdaptHorizontal : public MoveStrategy {
public:
    sf::Vector2f movement(sf::Vector2f direction, sf::Sprite &sprite) override;
};


#endif //MAZZARONE_ROSADINI_ADAPTHORIZONTAL_H
