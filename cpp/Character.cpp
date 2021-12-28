//
// Created by cristian on 28/02/21.
//

#include "../header/Character.h"
#include <cmath>


Character::Character(CharacterType type, int width, int height, int hp, float speed, int damage, bool isAttacking,
                     bool isDying) : hp(hp), damage(damage), speed(speed), attacking(isAttacking), dying(isDying),
                                     type(type),
                                     Entity(sf::Vector2i(width, height)) {}

//getter
int Character::getHp() const {
    return hp;
}

int Character::getDamage() const {
    return damage;
}

//setter
void Character::setHp(int hitpoints) {
    Character::hp = hitpoints;
}

void Character::receiveDamage(int dmg) {
    Character::hp -= dmg;
}

void Character::kill() {
    attacking = false;
    dying = true;
    setAnim(8, 0.15, die);
    if (source.x == 7)
        life = false;
}

void Character::fight(Character &character) {
    attacking = true;
}

CharacterType Character::getType() const {
    return type;
}

bool Character::isDying() const {
    return dying;
}

bool Character::isLegalDirection(sf::Vector2f direction, Map arena) {
    sf::Vector2f futurePos = {getPosition().x + (speed * direction.x), getPosition().y + (speed * direction.y)};
    sf::Vector2i code = {(int) std::round(futurePos.x / 32), (int) std::round(futurePos.y / 32)};
    Tile tile = arena.getTile(code);
    if (!tile.isWalkable())
        return false;
    return true;
}

bool Character::isLegalFight(const Entity *entity) {
    sf::FloatRect box = entity->getSprite().getGlobalBounds();
    sf::FloatRect thisBox = sprite.getGlobalBounds();
    if (thisBox.intersects(box))
        return true;
    return false;
}

void Character::setAttacking(bool attack) {
    attacking = attack;
}

//Character::Character(Character *character): Character(character->getType(), 32,32, character->getHp(), character->getSpeed(), character->getDamage()) {}

float Character::getSpeed() const {
    return speed;
}

void Character::setSpeed(float speed) {
    Character::speed = speed;
}
