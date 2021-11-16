//
// Created by cristian on 28/02/21.
//

#include "../header/Player1.h"

#include <utility>

Player1::Player1(CharacterType type, std::shared_ptr<AttackStrategy> attackStrategy, int killCounter, int width,
                 int height) : attackStrategy(
        std::move(attackStrategy)), killCounter(killCounter), Character(type, width, height) {
}

Player1::Player1(CharacterType type, int hp, int damage, float speed, std::shared_ptr<AttackStrategy> attackStrategy,
                 int killCounter, int width, int height)
        : attackStrategy(
        std::move(attackStrategy)), killCounter(killCounter), Character(type, width, height, hp, damage, speed) {
}

Player1::~Player1() = default;

void Player1::movement(sf::Vector2f direction, const Map &map) {
    if (!dying && !attacking) {
        if (direction.x == 0) {
            if (source.y == stayR)
                source.y = right;
            else
                source.y = left;
        } else {
            if (direction.x == 1)
                source.y = right;
            else
                source.y = left;
        }
        setAnim(8, 0.06);
        if (isLegalMove(direction, map))
            sprite.move(direction.x * speed, direction.y * speed);
    }
}

void Player1::fight(Character &character) {
    if (!dying)
        attackStrategy->fight(this, character);
}

void Player1::update(float deltaTime) {
    Entity::update(deltaTime);
    if (attacking && source.x >= 7)
        attacking = false;
}

int Player1::getKillCounter() const {
    return killCounter;
}

void Player1::increaseKillCounter() {
    killCounter++;
}

bool Player1::isLegalMove(sf::Vector2f direction, const Map &arena) {
    return isLegalDirection(direction, arena);

}

//Subject methods
void Player1::subscribe(Observer *o) {
    observer = o;
}

void Player1::unsubscribe(Observer *o) {
    observer = nullptr;
}

void Player1::notify(int numArena) {
    observer->update(numArena);
}

void Player1::usePotion() {
    if (potion != nullptr) {
        hp = Player1::potion->use(hp);
        if (hp > 150)
            hp = 150;
        potion = nullptr;
    }
}

bool Player1::pickPotion(const std::shared_ptr<Potion> &potion) {
    sf::FloatRect bulletBox = sprite.getGlobalBounds();
    sf::FloatRect characterBox = potion->getSprite().getGlobalBounds();
    if (bulletBox.intersects(characterBox) && Player1::potion == nullptr) {
        Player1::potion = potion;
        return true;
    }
    return false;
}
