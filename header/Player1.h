//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYER1_H
#define MAZZARONE_ROSADINI_PLAYER1_H

#include "Character.h"
#include "Potion.h"
#include "AttackStrategy.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Player1 : public Character{
public:
   // Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2, const Weapon &weapon, const Potion &potion);
   Player1();

    virtual ~Player1();

    virtual void fight(Character &enemy);
    bool isLegalFight(Character &enemy);
    //TODO RESOLVE POTION
    //void usePotion();

    //setter
    //void setAttackStrategy(AttackStrategy *attackStrategy);
    //void setPotion(Potion potion);

    //getter
    //TODO RESOLVE ATTACKSTRATEGY
    //AttackStrategy *getAttackStrategy() const;
    //Potion getPotion() const;

private:
    //Potion potion;
    //AttackStrategy* attackStrategy;

};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
