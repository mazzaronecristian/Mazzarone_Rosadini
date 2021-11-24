//
// Created by cristian on 27/07/21.
//

#include "gtest/gtest.h"
#include "../header/Bullet.h"
#include "../header/Patrol.h"
#include "../header/Enemy.h"
#include "../header/PlayersFactory.h"
#include "../header/BulletsFactory.h"

//test colpo a segno
TEST(Bullet, bulletCollision) {
    auto *e = new Enemy(CharacterType::ghoul);
    e->load("./tileSets/characters/ghoul.png", sf::Vector2f(10, 10));
    Bullet b = BulletsFactory::createBullet(BulletType::bullet, 1, sf::Vector2f(10, 10), sf::Vector2i(32, 3));
    bool c = b.isCollide(e);
    EXPECT_EQ(true, c);
}