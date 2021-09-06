//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYERSFACTORY_H
#define MAZZARONE_ROSADINI_PLAYERSFACTORY_H

#include "CharacterFactory.h"

class PlayersFactory : public CharacterFactory {
public:
    Enemy createEnemy(ElementType type, sf::Vector2f position) override;

    Player1 createHero(ElementType type) override;

    PlayersFactory();
};


#endif //MAZZARONE_ROSADINI_PLAYERSFACTORY_H
