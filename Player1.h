//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYER1_H
#define MAZZARONE_ROSADINI_PLAYER1_H

#include "Character.h"
#include "Weapon.h"
#include "Potion.h"
#include "AttackStrategy.h"

class Player1 : public Character{
public:
    explicit Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2);
   // Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2, const Weapon &weapon, const Potion &potion);

    virtual ~Player1();

    void move(int posX, int posY);
    virtual void fight(Character &enemy);
    bool isLegalFight(Character &enemy);
    void usePotion();

    //setter
    void setAttackStrategy(AttackStrategy *attackStrategy);
    void setWeapon(Weapon* weapon);
    void setPotion(Potion* potion);

    //getter
    AttackStrategy *getAttackStrategy() const;
    Potion* getPotion() const;
    Weapon* getWeapon() const;

private:
    Weapon* weapon;
    Potion* potion;
    AttackStrategy* attackStrategy;

};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
