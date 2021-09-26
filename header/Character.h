//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H


#include "Entity.h"
#include "Map.h"
#include "Tile.h"

enum class CharacterType {
    spaceCadetq, adventurer, dwarf, gladiator, ghoul, brain, cobra, miniGolem
};

class Character : public Entity {
public:
    explicit Character(CharacterType type, int hp = 120, int damage = 40, float speed = 0.3, bool isAttacking = false,
                       bool isDying = false);


    virtual void movement(sf::Vector2f direction, const Map &map) = 0;

    CharacterType getType() const;

    void update(float deltaTime) override;

    void kill();

    virtual void fight(Character &character) = 0;

    bool isLegalMove(Character &character);

    bool isLegalMove(sf::Vector2f direction, Map map);

    bool isLegalFight(const Character &character);

    void receiveDamage(int damage);



    //getter

    bool isDying() const;

    int getHp() const;

    int getDamage() const;

    float getSpeed() const;

    bool isFighting() const;

    //setter
    void setHp(int hp);

    void setIsFighting(bool isAttacking);

    void setDamage(int damage);

    void setSpeed(float speed);

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
