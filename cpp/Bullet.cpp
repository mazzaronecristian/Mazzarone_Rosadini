//
// Created by Gianluca Rosadini on 16/03/21.
//

#include "../header/Bullet.h"
#include <cmath>


Bullet::~Bullet() = default;

Bullet::Bullet(short int bulletDirection, sf::Vector2i dimension, float speed)
        : bulletDirection(bulletDirection), speed(speed),
          Entity(dimension) {
}

void Bullet::movement(const Map &arena) {
    if (isLegalMove(arena))
        sprite.move((float) bulletDirection * speed, 0);
    else life = false;
}

void Bullet::update(float deltaTime) {
    Entity::update(deltaTime);
    if (source.x == 2)
        life = false;
}

bool Bullet::isLegalMove(Map arena) {
    sf::Vector2f futurePos = {getPosition().x + (speed * (float) bulletDirection), getPosition().y};
    sf::Vector2i code = {(int) std::round(futurePos.x / 32), (int) std::round(futurePos.y / 32)};
    Tile tile = arena.getTile(code);
    if (!tile.isWalkable())
        return false;
    return true;
}

bool Bullet::isCollide(const Entity *entity) {
    sf::FloatRect bulletBox = sprite.getGlobalBounds();
    sf::FloatRect characterBox = entity->getSprite().getGlobalBounds();
    if (bulletBox.intersects(characterBox)) {
        life = false;
        return true;
    }
    return false;
}
