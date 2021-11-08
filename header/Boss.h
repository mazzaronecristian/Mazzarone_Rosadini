//
// Created by Gianluca Rosadini on 03/11/21.
//

#ifndef MAZZARONE_ROSADINI_BOSS_H
#define MAZZARONE_ROSADINI_BOSS_H

#include "Enemy.h"
#include "BossStrategy.h"
#include "MeleeBossAttack.h"

class Boss : public Enemy {
public:
    Boss(CharacterType type, std::shared_ptr<BossStrategy> attackStrategy, int width = 64, int height = 64,
         int hp = 450,
         int damage = 30, float speed = 0.25, std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<Follow>());

    void fight(Character &character) final;

private:
    std::shared_ptr<BossStrategy> attackStrategy;
};


#endif //MAZZARONE_ROSADINI_BOSS_H
