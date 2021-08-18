//
// Created by cristian on 24/06/21.
//

#include "../header/PlayersFactory.h"

PlayersFactory::PlayersFactory() {}

std::shared_ptr<Enemy> PlayersFactory::createEnemy(EntityType type, sf::Vector2f position) {
    std::shared_ptr<Enemy> result(new Enemy(std::make_shared<Patrol>()));
    result->load(setBitMap(type), position);
    return result;
}

std::unique_ptr<Player1> PlayersFactory::createHero(EntityType type) {
    std::unique_ptr<Player1> result(new Player1(std::make_shared<RangedAttack>()));
    result->load(setBitMap(type), setPosition(type));
    return result;
}
