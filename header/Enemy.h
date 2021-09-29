//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_ENEMY_H
#define MAZZARONE_ROSADINI_ENEMY_H

#include "Character.h"
#include "FightStrategy.h"
#include "Patrol.h"
#include <math.h>
#include <memory.h>
#include <memory>

class Enemy : public Character {
public:

    explicit Enemy(CharacterType type, std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<Patrol>());

    void update(float deltaTime) override;

    void movement(sf::Vector2f direction, const Map &map) override;

    void adaptMovement(Tile tile, sf::Vector2f direction, sf::Vector2f vector2);

    bool isLegalMove(sf::Vector2f direction, Map map) override;

    void fight(Character &character) override;

    void setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrategy);

private:
    std::shared_ptr<MoveStrategy> moveStrategy;
};

#endif //MAZZARONE_ROSADINI_ENEMY_H
