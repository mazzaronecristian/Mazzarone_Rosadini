//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYER1_H
#define MAZZARONE_ROSADINI_PLAYER1_H

#include "Character.h"
#include "Weapon.h"
#include "Potion.h"
class Player1 : public Character{
public:
    explicit Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2);
   // Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2, const Weapon &weapon, const Potion &potion);

    virtual ~Player1();

    void move(int posX, int posY);
    void fight(Character);
    bool isLegalFight(Character);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);

    const Potion &getPotion() const;

    void setPotion(const Potion &potion);

private:
    Weapon weapon;
    Potion potion;
};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
