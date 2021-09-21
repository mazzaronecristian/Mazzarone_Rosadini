//
// Created by cristian on 24/06/21.
//

#include "../header/PlayersFactory.h"


Enemy PlayersFactory::createEnemy(CharacterType type, sf::Vector2f position) {
    Enemy *result = new Enemy(type);
    result->load(setBitMap(type), position);
    return *result;
}

Player1 PlayersFactory::createHero(CharacterType type) {
    Player1 *result;
    if (type == CharacterType::spaceCadet)
        result = new Player1(type, std::make_shared<RangedAttack>());
    else
        result = new Player1(type, 150, 60, std::make_shared<MeleeAttack>());
    result->load(setBitMap(type), sf::Vector2f(50, 270));
    return *result;
}
