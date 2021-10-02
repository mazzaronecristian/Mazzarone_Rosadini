//
// Created by cristian on 28/02/21.
//

#include "../header/Enemy.h"

#include <utility>

Enemy::Enemy(CharacterType type, std::shared_ptr<MoveStrategy> moveStrategy) : moveStrategy(std::move(moveStrategy)),
                                                                               Character(type, 100, 8, 0.1) {}

void Enemy::movement(sf::Vector2f direction, const Map &map) {
    if (!attacking && !dying) {
        if (abs(direction.y - getPosition().y) > speed || abs(direction.x - getPosition().x) > speed) {
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
    Character::update(deltaTime);
    attacking = false;
}

bool Enemy::isLegalMove(sf::Vector2f direction, Map map) {
    sf::Vector2f futurePos;
    sf::Vector2f dir;
    dir.x = (direction.x - getPosition().x) / std::abs((direction.x - getPosition().x) + 0.07);
    dir.y = (direction.y - getPosition().y) / std::abs((direction.y - getPosition().y) + 0.07);
    futurePos = {getPosition().x + (speed * dir.x), getPosition().y + (speed * dir.y)};
    int i = round(futurePos.x / 32);
    int j = round(futurePos.y / 32);
    sf::Vector2i source = {i, j};
    Tile tile = map.getTile(source);
    if (tile.isWalkable())
        return true;
    //adaptMovement(tile, direction, futurePos);
    return false;
}

void Enemy::adaptMovement(Tile tile, sf::Vector2f direction, sf::Vector2f futurePos) {
    sf::Vector2f tilePosition = tile.getTilePosition();
    if (round(tilePosition.y) != round(Entity::getPosition().y)) {
        setMoveStrategy(std::make_shared<Patrol>());
        sprite.move(direction.x >= Entity::getPosition().x ? speed : -speed, 0);
    }
    if (round(tilePosition.x) != round(Entity::getPosition().x)) {
        setMoveStrategy(std::make_shared<Patrol>());
        sprite.move(0, direction.y >= Entity::getPosition().y ? speed : -speed);
    }
}

void Enemy::setMoveStrategy(const std::shared_ptr<MoveStrategy> &moveStrategy) {
    Enemy::moveStrategy = moveStrategy;
}

void Enemy::setMoveStrategy(sf::Vector2f direction, Map arena) {
    sf::Vector2f dir;
    dir.x = (direction.x - getPosition().x) / std::abs((direction.x - getPosition().x) + 0.07);
    dir.y = (direction.y - getPosition().y) / std::abs((direction.y - getPosition().y) + 0.07);
    sf::Vector2f futurePos = {getPosition().x + (speed * dir.x), getPosition().y + (speed * dir.y)};
    int i = round(futurePos.x / 32);
    int j = round(futurePos.y / 32);
    sf::Vector2i code = {i, j};
    Tile tile = arena.getTile(code);
    if (!tile.isWalkable()) {
        if (fabs(tile.getTilePosition().y - Entity::getPosition().y) < 32)
            moveStrategy = std::make_shared<AdaptHorizontal>();
        if (fabs(tile.getTilePosition().x - Entity::getPosition().x) < 32)
            moveStrategy = std::make_shared<AdaptVertical>();
    }

}

