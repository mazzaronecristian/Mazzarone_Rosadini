//
// Created by cristian on 29/09/21.
//

#ifndef MAZZARONE_ROSADINI_ADAPTVERTICAL_H
#define MAZZARONE_ROSADINI_ADAPTVERTICAL_H

#include "MoveStrategy.h"

class AdaptVertical : public MoveStrategy {
public:
    sf::Vector2f movement(sf::Vector2f direction, sf::Sprite &sprite) override;
};


#endif //MAZZARONE_ROSADINI_ADAPTVERTICAL_H
