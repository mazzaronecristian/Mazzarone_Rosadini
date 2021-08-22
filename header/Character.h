//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H


#include "Entity.h"
#include "../header/Map.h"
#include "../header/Tile.h"

class Character : public Entity {
public:
    explicit Character(int hp = 100, int damage = 50, float speed = 0.3, bool isAttacking = false,
                       bool isDying = false);

    void setIsFighting(bool isAttacking);

    virtual void movement(sf::Vector2f direction, const Map &map) = 0;

    void update(float deltaTime) override;

    virtual void kill();

    virtual void fight(Character &character) = 0;

    bool isLegalMove(Character &character);

    bool isLegalMove(sf::Vector2f direction, Map map);

    bool isLegalFight(const Character &character);

    void receiveDamage(int damage);

    //getter
    int getHp() const;

    int getDamage() const;

    float getSpeed() const;

    //setter
    void setHp(int hp);

    bool isFighting() const;

    void setDamage(int damage);

    void setSpeed(float speed);

protected:
    bool isAttacking, isDying;
    int hp, damage;
    float speed;
    enum action {
        stayR = 0, stayL = 1, right = 2, left = 3, attackR = 4, attackL = 5, stay = 6, die = 7
    };
};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
