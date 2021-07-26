//
// Created by cristian on 26/07/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"

class Player1Suite: public ::testing::Test{
protected:
    virtual void setUp(){
        p.setPosition(sf::Vector2f(10,10));
    }
    Player1 p;
};

TEST_F(Player1Suite, TestMoveDown){
    p.movement(sf::Vector2f(0,1));
    EXPECT_EQ(sf::Vector2f(10,10.3) , p.getPosition());
}