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
#include "RangedAttack.h"
#include "Character.h"
#include "Potion.h"

class Player1 : public Character {
public:
    Player1(CharacterType type, std::shared_ptr<AttackStrategy> attackStrategy);

    Player1(CharacterType type, int hp, int damage, std::shared_ptr<AttackStrategy> attackStrategy);


    void update(float deltaTime) override;

    virtual ~Player1();

    void movement(sf::Vector2f direction, const Map &map) override;

    void fight(Character &character) override;

    //TODO RESOLVE POTION
    //void usePotion();

    //setter
    //void setPotion(Potion potion);

    //getter
    //Potion getPotion() const;

private:
    //Potion potion;
    std::shared_ptr<AttackStrategy> attackStrategy;

};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
