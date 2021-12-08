//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H


#include "Entity.h"
#include "Map.h"

enum class CharacterType {
    spaceCadet, adventurer, dwarf, gladiator, ghoul, brain, cobra, miniGolem, cyclops
};

class Character : public Entity {
public:
    Character(CharacterType type, int width, int height, int hp, float speed, int damage,
              bool isAttacking = false,
              bool isDying = false);

    virtual void movement(sf::Vector2f direction, const Map &map) = 0;

    CharacterType getType() const;

    void kill();

    virtual void fight(Character &character) = 0;

    virtual bool isLegalMove(sf::Vector2f direction, const Map &map) = 0;

    bool isLegalDirection(sf::Vector2f direction, Map map);

    bool isLegalFight(const Entity *entity);

    void setAttacking(bool attack);

    void receiveDamage(int dmg);

    //getter
    bool isDying() const;

    int getHp() const;

    int getDamage() const;

    //setter
    void setHp(int hitpoints);

protected:
    bool attacking, dying;
    int hp, damage;
    float speed;
    enum action {
        stayR = 0, stayL = 1, right = 2, left = 3, attackR = 4, attackL = 5, die = 7
    };
    CharacterType type;
};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
