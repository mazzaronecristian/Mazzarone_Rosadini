//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_ENEMY_H
#define MAZZARONE_ROSADINI_ENEMY_H


#include "Character.h"
#include "Patrol.h"
#include "AdaptHorizontal.h"
#include "AdaptVertical.h"
#include "Follow.h"
#include <memory>


class Enemy : public Character {
public:

    explicit Enemy(CharacterType type, int width = 32, int height = 32, int hp = 100, int damage = 8, float speed = 0.1,
                   std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<Patrol>());

    void update(float deltaTime) override;

    void movement(sf::Vector2f direction, const Map &map) override;

    bool isLegalMove(sf::Vector2f position, const Map &map) override;

    void fight(Character &character) override;

    void setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrat);

    void setMoveStrategy(sf::Vector2f position, const Map &arena);

private:
    std::shared_ptr<MoveStrategy> moveStrategy;
};

#endif //MAZZARONE_ROSADINI_ENEMY_H
