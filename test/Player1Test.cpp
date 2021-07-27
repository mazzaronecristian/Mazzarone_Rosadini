//
// Created by cristian on 26/07/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"

TEST(Player1, TestMoveDown){
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(10,10));
    p.movement(sf::Vector2f(0,1));
    EXPECT_EQ(10 , p.getPosition().x);
    EXPECT_FLOAT_EQ(10.3 , p.getPosition().y);
}
TEST(Player1, TestMoveUp){
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(10,10));
    p.movement(sf::Vector2f(0,-1));
    EXPECT_EQ(10 , p.getPosition().x);
    EXPECT_FLOAT_EQ(9.7 , p.getPosition().y);
}
TEST(Player1, TestMoveRight){
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(10,10));
    p.movement(sf::Vector2f(1,0));
    EXPECT_FLOAT_EQ(10.3 , p.getPosition().x);
    EXPECT_EQ(10 , p.getPosition().y);
}
TEST(Player1, TestMoveLeft){
    Player1 p(std::make_shared<RangedAttack>());
    p.load("./tileSets/spaceCadet.png", sf::Vector2f(10,10));
    p.movement(sf::Vector2f(-1,0));
    EXPECT_FLOAT_EQ(9.7 , p.getPosition().x);
    EXPECT_EQ(10 , p.getPosition().y);
}