//
// Created by cristian on 26/07/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"

TEST(Player1, TestMoveDown) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    p.movement(sf::Vector2f(0, 1), arena);
    EXPECT_EQ(100, p.getPosition().x);
    EXPECT_FLOAT_EQ(100.3, p.getPosition().y);
}

TEST(Player1, TestMoveUp) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    p.movement(sf::Vector2f(0, -1), arena);
    EXPECT_EQ(100, p.getPosition().x);
    EXPECT_FLOAT_EQ(99.7, p.getPosition().y);
}

TEST(Player1, TestMoveRight) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    p.movement(sf::Vector2f(1, 0), arena);
    EXPECT_FLOAT_EQ(100.3, p.getPosition().x);
    EXPECT_EQ(100, p.getPosition().y);
}

TEST(Player1, TestMoveLeft) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::spaceCadet, std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    p.movement(sf::Vector2f(-1, 0), arena);
    EXPECT_FLOAT_EQ(99.7, p.getPosition().x);
    EXPECT_EQ(100, p.getPosition().y);
}

TEST(Player1, TestMeleeAttack) {
    std::ifstream matrix("./matrix.txt");
    Map arena;
    arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix);
    Player1 p(CharacterType::ghoul, std::make_shared<RangedAttack>());
    p.load("./tileSets/ghoul.png", sf::Vector2f(100, 100));
    Enemy e(CharacterType::ghoul);
    e.load("./tileSets/ghoul.png", sf::Vector2f(116, 100));
    while (p.getSource().x <= 7) {
        p.fight(e);
    }
    EXPECT_EQ(50, e.getHp());
}