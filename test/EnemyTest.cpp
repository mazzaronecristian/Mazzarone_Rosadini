//
// Created by cristian on 06/09/21.
//
#include "gtest/gtest.h"
#include "../header/Enemy.h"
#include "../header/Player1.h"
#include "../header/Follow.h"

TEST(Enemy, TestMoveDown) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    Enemy e(CharacterType::ghoul, std::make_shared<Follow>());
    e.load("./tileSets/ghoul.png", sf::Vector2f(100, 50));
    e.movement(p.getPosition(), arena);
    EXPECT_EQ(100, e.getPosition().x);
    EXPECT_NEAR(50.1, e.getPosition().y, 0.001);
}

TEST(Enemy, TestMoveUp) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    Enemy e(CharacterType::ghoul, std::make_shared<Follow>());
    e.load("./tileSets/ghoul.png", sf::Vector2f(100, 150));
    e.movement(p.getPosition(), arena);
    EXPECT_EQ(100, e.getPosition().x);
    EXPECT_NEAR(149.9, e.getPosition().y, 0.001);
}

TEST(Enemy, TestMoveRight) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    Enemy e(CharacterType::ghoul, std::make_shared<Follow>());
    e.load("./tileSets/ghoul.png", sf::Vector2f(50, 100));
    e.movement(p.getPosition(), arena);
    EXPECT_NEAR(50.1, e.getPosition().x, 0.001);
    EXPECT_EQ(100, e.getPosition().y);
}

TEST(Enemy, TestMoveLeft) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    Enemy e(CharacterType::ghoul, std::make_shared<Follow>());
    e.load("./tileSets/ghoul.png", sf::Vector2f(150, 100));
    e.movement(p.getPosition(), arena);
    EXPECT_NEAR(149.9, e.getPosition().x, 0.001);
    EXPECT_EQ(100, e.getPosition().y);
}

TEST(Enemy, TestFightLeft) {
    Enemy e(CharacterType::ghoul);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    e.load("./tileSets/ghoul.png", sf::Vector2f(101, 100));
    e.fight(p);
    int x = e.getSource().y;
    EXPECT_EQ(5, x);
}

TEST(Enemy, TestFightRight) {
    Enemy e(CharacterType::ghoul);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    e.load("./tileSets/ghoul.png", sf::Vector2f(99, 100));
    e.fight(p);
    int x = e.getSource().y;
    EXPECT_EQ(4, x);
}

TEST(Enemy, TestEnemyStay) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Enemy e(CharacterType::ghoul);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    e.load("./tileSets/ghoul.png", sf::Vector2f(100, 100));
    e.movement(p.getPosition(), arena);
    EXPECT_EQ(100, e.getPosition().x);
    EXPECT_EQ(100, e.getPosition().y);
}