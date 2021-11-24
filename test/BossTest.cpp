//
// Created by cristian on 24/11/21.
//

#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/PlayersFactory.h"
#include "../header/Boss.h"
#include "../header/MapFactory.h"

///THE BOSS'S MOVEMENT TEST ARE THE SAME AS THE ENEMY'S (EnemyTest)

TEST(Boss, MeleeAttack) {
    PlayersFactory factory;
    Boss b = factory.createBoss(CharacterType::cyclops);
    Player1 p(CharacterType::spaceCadet);
    p.load("./tileSets/characters/spaceCadet.png", sf::Vector2f(700, 270));
    b.setAttackTimer(1);
    while (b.getSource().x < 6) {
        b.fight(p);
        b.setSourceX(b.getSource().x + 1);
    }
    EXPECT_EQ(90, p.getHp());
}

TEST(Boss, LaserAttack) {
    PlayersFactory factory;
    Boss b = factory.createBoss(CharacterType::cyclops);
    Player1 p = factory.createHero(CharacterType::spaceCadet);
    b.setAttackTimer(1);
    while (b.getSource().x < 6) {
        b.fight(p);
        b.setSourceX(b.getSource().x + 1);
    }
    auto x = b.getLasers().begin();
    auto y = b.getLasers().end();
    int i = 0;
    while (x != y) {
        i++;
        x++;
    }
    EXPECT_EQ(1, i);
}

TEST(Boss, noLaserAttack) {
    PlayersFactory factory;
    Boss b = factory.createBoss(CharacterType::cyclops);
    Player1 p(CharacterType::spaceCadet);
    p.load("./tileSets/characters/spaceCadet.png", sf::Vector2f(50, 570));
    b.setAttackTimer(1);
    while (b.getSource().x < 6) {
        b.fight(p);
        b.setSourceX(b.getSource().x + 1);
    }
    auto x = b.getLasers().begin();
    auto y = b.getLasers().end();
    int i = 0;
    while (x != y) {
        i++;
        x++;
    }
    EXPECT_EQ(0, i);
}

TEST(Boss, noMeleeAttack) {
    PlayersFactory factory;
    Boss b = factory.createBoss(CharacterType::cyclops);
    Player1 p(CharacterType::spaceCadet);
    b.setAttackTimer(1);
    while (b.getSource().x < 6) {
        b.fight(p);
        b.setSourceX(b.getSource().x + 1);
    }
    EXPECT_EQ(120, p.getHp());
}
