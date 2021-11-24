//
// Created by Gianluca Rosadini on 03/11/21.
//

#include "../header/Boss.h"
#include <utility>

void Boss::fight(Character &character) {
    if (!dying) {
        if (isLegalFight(&character)) {
            attacking = true;
            attackStrategy = std::make_shared<MeleeBossAttack>();
            attackStrategy->fight(character, this);
        } else if (round(character.getPosition().y) == round(getPosition().y)) {
            attacking = true;
            attackStrategy = std::make_shared<RangedBossAttack>();
            attackStrategy->fight(character, this);
        }
        for (auto laser = lasers.begin(); laser != lasers.end();) {
            if (laser->get()->isCollide(&character)) {
                character.receiveDamage(laserDamage);
                laser = lasers.erase(laser);
            } else
                laser++;
        }
    }

}

Boss::Boss(CharacterType type, std::shared_ptr<BossStrategy> attackStrategy, int damage, int laserDamage, int hp,
           int width, float speed, std::shared_ptr<MoveStrategy> moveStrategy, int height) : laserDamage(laserDamage),
                                                                                             Enemy(type, width, height,
                                                                                                   hp, damage, speed,
                                                                                                   std::move(
                                                                                                           moveStrategy)),
                                                                                             attackStrategy(std::move(
                                                                                                     attackStrategy)) {
    attackTimer = 0;
}

void Boss::update(float deltaTime) {
    Entity::update(deltaTime);
    if (attacking)
        attackTimer += deltaTime;
    attacking = false;
    for (auto &laser: lasers) {
        laser->update(deltaTime);
    }
}

float Boss::getAttackTimer() const {
    return attackTimer;
}

void Boss::setAttackTimer(float attackTimer) {
    Boss::attackTimer = attackTimer;
}

const std::list<std::shared_ptr<Bullet>> &Boss::getLasers() const {
    return lasers;
}

void Boss::addLaser(Bullet bullet) {
    lasers.push_back(std::make_shared<Bullet>(bullet));
}

void Boss::moveLaser(const Map &arena) {
    for (auto laser = lasers.begin(); laser != lasers.end();) {
        laser->get()->movement(arena);
        if (!laser->get()->isLife())
            laser = lasers.erase(laser);
        else laser++;
    }
}

const std::shared_ptr<BossStrategy> &Boss::getAttackStrategy() const {
    return attackStrategy;
}
