//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_PLAYER1_H
#define MAZZARONE_ROSADINI_PLAYER1_H

#include <memory>

#include "AttackStrategy.h"
#include "RangedAttack.h"
#include "MeleeAttack.h"
#include "Character.h"
#include "Potion.h"
#include "Subject.h"

class Player1 : public Character, public Subject {
public:
    Player1(CharacterType type, std::shared_ptr<AttackStrategy> attackStrategy,
            int hp, float speed, int damage = 40, int killCounter = 0, int width = 32, int height = 32);

    void update(float deltaTime) override;

    ~Player1() override;

    void movement(sf::Vector2f direction, const Map &map) override;

    bool isLegalMove(sf::Vector2f direction, const Map &map) override;

    void fight(Character &character) override;

    int getKillCounter() const;

    void increaseKillCounter();

    void setKillCounter(int value);

    bool pickPotion(const std::shared_ptr<Potion> &pot);

    //Subject methods
    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify(int numArena) override;

    void usePotion();

private:
    std::shared_ptr<Potion> potion = nullptr;
    std::shared_ptr<AttackStrategy> attackStrategy;
    int killCounter;
    Observer *observer = nullptr;
};


#endif //MAZZARONE_ROSADINI_PLAYER1_H
