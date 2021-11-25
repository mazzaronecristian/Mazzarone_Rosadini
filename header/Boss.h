//
// Created by Gianluca Rosadini on 03/11/21.
//

#ifndef MAZZARONE_ROSADINI_BOSS_H
#define MAZZARONE_ROSADINI_BOSS_H

#include "Enemy.h"
#include "BossStrategy.h"
#include "MeleeBossAttack.h"
#include "RangedBossAttack.h"
#include "Bullet.h"

class Boss : public Enemy {
public:
    Boss(CharacterType type, std::shared_ptr<BossStrategy> attackStrategy, int damage = 30, int laserDamage = 50,
         int hp = 1000, int width = 64, float speed = 0.25,
         std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<Follow>(), int height = 64);

    void fight(Character &character) final;

    void update(float deltaTime) override;

    void addLaser(Bullet bullet);

    void moveLaser(const Map &arena);

    float getAttackTimer() const;

    void setAttackTimer(float timer);

    const std::list<std::shared_ptr<Bullet>> &getLasers() const;

private:
    int laserDamage;
    float attackTimer;
    std::shared_ptr<BossStrategy> attackStrategy;
    std::list<std::shared_ptr<Bullet>> lasers;
};


#endif //MAZZARONE_ROSADINI_BOSS_H
