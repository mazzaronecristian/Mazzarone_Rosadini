//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

#include <cmath>

Enemy::Enemy(CharacterType type, int width, int height, int hp, int damage, float speed,
             std::shared_ptr<MoveStrategy> moveStrategy) :
        moveStrategy(std::move(moveStrategy)),
        Character(type, width, height, hp, speed, damage) {
}

void Enemy::movement(sf::Vector2f direction, const Map &map) {
    if (!attacking && !dying) {
        if (std::abs(direction.y - getPosition().y) > speed || std::abs(direction.x - getPosition().x) > speed) {
            sf::Vector2f dir;
            dir = moveStrategy->movement(direction, sprite);
            sprite.move(dir.x * speed, dir.y * speed);
            if (dir.x < 0)
                source.y = left;
            else if (dir.x == 0 && dir.y == 0)
                source.y = stayR;
            else source.y = right;
        }
        setAnim(8, 0.06);
    }
}

void Enemy::fight(Character &character) {
    Character::fight(character);
    if (hp > 0) {
        if (character.getPosition().x < Entity::getPosition().x)
            setAnim(8, 0.06, attackL);
        else setAnim(8, 0.06, attackR);
        if (source.x == 5) {
            source.x++;
            character.receiveDamage(damage);
        }
    }
}

void Enemy::update(float deltaTime) {
    Entity::update(deltaTime);
    attacking = false;
}

bool Enemy::isLegalMove(sf::Vector2f position, const Map &arena) {
    sf::Vector2f direction;
    direction.x = (float) round((position.x - getPosition().x) / std::abs((position.x - getPosition().x) + 0.07));
    direction.y = (float) round((position.y - getPosition().y) / std::abs((position.y - getPosition().y) + 0.07));
    return isLegalDirection(direction, arena);
}

void Enemy::setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrat) {
    Enemy::moveStrategy = moveStrat;
}

void Enemy::setMoveStrategy(sf::Vector2f position, const Map &arena) {
    sf::Vector2f direction;
    direction.x = (float) round((position.x - getPosition().x) / std::abs((position.x - getPosition().x) + 0.07));
    direction.y = (float) round((position.y - getPosition().y) / std::abs((position.y - getPosition().y) + 0.07));
    if (!isLegalDirection(direction, arena)) {
        if (isLegalDirection({0, direction.y}, arena)) {
            moveStrategy = std::make_shared<AdaptVertical>();
        } else if (isLegalDirection({direction.x, 0}, arena)) {
            moveStrategy = std::make_shared<AdaptHorizontal>();
        }
    }
}
