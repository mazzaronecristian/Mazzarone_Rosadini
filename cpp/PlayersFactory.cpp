//
// Created by cristian on 24/06/21.
//

#include "../header/PlayersFactory.h"


Enemy PlayersFactory::createEnemy(CharacterType type, sf::Vector2f position, Map arena) {
    auto *result = new Enemy(type);
    sf::Vector2i code = {(int) std::round(position.x / 32), (int) std::round(position.y / 32)};
    Tile tile = arena.getTile(code);
    if (tile.isWalkable())
        result->load(setBitMap(type), position);
    return *result;
}

Player1 PlayersFactory::createHero(CharacterType type) {
    Player1 *result;
    if (type == CharacterType::spaceCadet)
        result = new Player1(type);
    else
        result = new Player1(type, 150, 60);
    result->load(setBitMap(type), sf::Vector2f(50, 270));
    return *result;
}

Enemy PlayersFactory::createBoss(CharacterType type) {
    auto *result = new Enemy(type);
    result->load(setBitMap(type), sf::Vector2f(700, 270), 64, 64);
    return *result;
}
