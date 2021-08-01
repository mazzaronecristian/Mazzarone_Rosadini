//
// Created by cristian on 27/07/21.
//

#include "gtest/gtest.h"
#include "../header/Bullet.h"
#include "../header/Patrol.h"

TEST(Bullet, collision) {
    Enemy e(std::make_shared<Patrol>());
    e.load("./tileSets/ghoul.png", sf::Vector2f(10, 10));
    Bullet b(1);
    b.load("./tileSets/bullet.png", sf::Vector2f(10, 10));
    bool c = b.isCollide(e);
    EXPECT_EQ(true, c);
}