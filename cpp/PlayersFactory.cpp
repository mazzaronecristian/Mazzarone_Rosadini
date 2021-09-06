//
// Created by cristian on 24/06/21.
//

#include "../header/PlayersFactory.h"

PlayersFactory::PlayersFactory() {}

Enemy PlayersFactory::createEnemy(ElementType type, sf::Vector2f position) {
    Enemy *result = new Enemy;
    result->load(setBitMap(type), position);
    return *result;
}

Player1 PlayersFactory::createHero(ElementType type) {
    Player1 *result = new Player1(std::make_shared<RangedAttack>());
    result->load(setBitMap(type), setPosition(type));
    return *result;
}
