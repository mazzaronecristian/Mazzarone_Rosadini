//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYER1_H
#define MAZZARONE_ROSADINI_PLAYER1_H


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <memory>

#include "AttackStrategy.h"
#include "Character.h"
#include "Potion.h"

class Player1 : public Character{
public:
   // Player1(int hp = 10, int posX = 10, int posY = 10, int damage = 2, const Weapon &weapon, const Potion &potion);
   Player1(const std::shared_ptr<AttackStrategy>&  attackStrategy);

    virtual ~Player1();

    void movement(sf::Vector2f direction) override;

    void fight(Character &character) override;
    bool isLegalFight(Character &enemy);
    //TODO RESOLVE POTION
    //void usePotion();

    //setter
    //void setPotion(Potion potion);

    //getter
    //Potion getPotion() const;

private:
    //Potion potion;
    std::shared_ptr<AttackStrategy> attacksStrategy;

};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
