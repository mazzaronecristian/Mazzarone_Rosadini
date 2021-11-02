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
#include "MeleeAttack.h"
#include "Character.h"
#include "Potion.h"
#include "Subject.h"

class Player1 : public Character, public Subject {
public:
    explicit Player1(CharacterType type,
                     std::shared_ptr<AttackStrategy> attackStrategy = std::make_shared<RangedAttack>(),
                     int killCounter = 0, int width = 32, int height = 32);

    Player1(CharacterType type, int hp, int damage, float speed = 0.7,
            std::shared_ptr<AttackStrategy> attackStrategy = std::make_shared<MeleeAttack>(),
            int killCounter = 0, int width = 32, int height = 32);

    void update(float deltaTime) override;

    virtual ~Player1();

    void movement(sf::Vector2f direction, const Map &map) override;

    bool isLegalMove(sf::Vector2f direction, const Map &map) override;

    void fight(Character &character) override;

    int getKillCounter() const;

    const std::shared_ptr<AttackStrategy> &getAttackStrategy() const;

    void increaseKillCounter();

    bool pickPotion(const std::shared_ptr<Potion> &potion);

    //Subject methods
    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    //TODO RESOLVE POTION
    void usePotion();

    //setter
    //void setPotion(Potion potion);

    //getter

    const std::shared_ptr<Potion> &getPotion() const;

private:
    std::shared_ptr<Potion> potion = nullptr;
    std::shared_ptr<AttackStrategy> attackStrategy;
    int killCounter;
    Observer *observer = nullptr;

};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
