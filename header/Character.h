//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Entity.h"

class Character: public Entity {
public:
    explicit Character(int hp = 10, int damage = 5, float speed = 0.3);

    virtual void movement(float x, float y) = 0;

    bool isLegalMove(sf::FloatRect bBox);

    void receiveDamage(int damage);

    //getter
    int getHp() const;

    int getDamage() const;

    float getSpeed() const;

    //setter
    void setHp(int hp);

    void setDamage(int damage);

    void setSpeed(float speed);

protected:
    int hp, damage;
    float speed;
    enum action{stay, right, left, attack, die};

};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
