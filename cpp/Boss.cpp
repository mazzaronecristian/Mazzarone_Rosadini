//
// Created by Gianluca Rosadini on 03/11/21.
//

#include "../header/Boss.h"

#include <utility>

void Boss::fight(Character &character) {
    if (isLegalFight(&character)) {
        attacking = true;
        attackStrategy = std::make_shared<MeleeBossAttack>();
        attackStrategy->fight(character, this, attackTimer);
    }
}

Boss::Boss(CharacterType type, std::shared_ptr<BossStrategy> attackStrategy, int width, int height, int hp, int damage,
           float speed,
           std::shared_ptr<MoveStrategy> moveStrategy) : Enemy(type, width, height, hp, damage, speed,
                                                               std::move(moveStrategy)),
                                                         attackStrategy(std::move(attackStrategy)) {
    attackTimer = 0;
}

void Boss::update(float deltaTime) {
    Entity::update(deltaTime);
    if (attacking)
        attackTimer += deltaTime;
    attacking = false;
}
