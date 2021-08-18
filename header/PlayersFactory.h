//
// Created by cristian on 24/06/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYERSFACTORY_H
#define MAZZARONE_ROSADINI_PLAYERSFACTORY_H

#include "CharacterFactory.h"

class PlayersFactory : public CharacterFactory {
public:
    std::shared_ptr<Enemy> createEnemy(EntityType type, sf::Vector2f position) override;

    std::unique_ptr<Player1> createHero(EntityType type) override;

    PlayersFactory();
};


#endif //MAZZARONE_ROSADINI_PLAYERSFACTORY_H
