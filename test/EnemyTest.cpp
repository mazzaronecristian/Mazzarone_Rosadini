//
// Created by cristian on 06/09/21.
//
#include "gtest/gtest.h"
#include "../header/Enemy.h"
#include "../header/Player1.h"
#include "../header/Follow.h"

TEST(Enemy, TestFightLeft) {
    Enemy e;
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    e.load("./tileSets/ghoul.png", sf::Vector2f(101, 100));
    e.fight(p);
    int x = e.getSource().y;
    EXPECT_EQ(5, x);
}

TEST(Enemy, TestFightRight) {
    Enemy e;
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    e.load("./tileSets/ghoul.png", sf::Vector2f(99, 100));
    e.fight(p);
    int x = e.getSource().y;
    EXPECT_EQ(4, x);
}