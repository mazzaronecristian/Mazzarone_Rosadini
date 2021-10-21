//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H


#include "Entity.h"
#include "Map.h"
#include "Tile.h"

enum class CharacterType {
    spaceCadet, adventurer, dwarf, gladiator, ghoul, brain, cobra, miniGolem, cyclops
};

class Character : public Entity {
public:
    Character(CharacterType type, int width, int height, int hp = 120, int damage = 40, float speed = 0.5,
              bool isAttacking = false,
              bool isDying = false);

    virtual void movement(sf::Vector2f direction, const Map &map) = 0;

    CharacterType getType() const;

    void update(float deltaTime) override;

    void kill();

    virtual void fight(Character &character) = 0;

    virtual bool isLegalMove(sf::Vector2f direction, const Map &map) = 0;

    bool isLegalDirection(sf::Vector2f direction, Map map);

    bool isLegalFight(const Character &character);

    void receiveDamage(int damage);

    //getter

    bool isDying() const;

    int getHp() const;

    int getDamage() const;


    //setter
    void setHp(int hp);

    void setIsFighting(bool isAttacking);

protected:
    bool attacking, dying;
    int hp, damage;
    float speed;
    enum action {
        stayR = 0, stayL = 1, right = 2, left = 3, attackR = 4, attackL = 5, stay = 6, die = 7
    };
    CharacterType type;
};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
