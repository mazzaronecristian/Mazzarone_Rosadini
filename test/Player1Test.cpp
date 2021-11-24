//
// Created by cristian on 26/07/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Bullet.h"
#include "../header/BulletsFactory.h"
#include "../header/MapFactory.h"
#include "../header/PlayersFactory.h"


TEST(Player1, TestMoveDown) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    Map arena = mFactory.createMap(1, p);
    p.movement(sf::Vector2f(0, 1), arena);
    EXPECT_EQ(50, p.getPosition().x);
    EXPECT_FLOAT_EQ(270.5, p.getPosition().y);
}

TEST(Player1, TestMoveUp) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    Map arena = mFactory.createMap(1, p);
    p.movement(sf::Vector2f(0, -1), arena);
    EXPECT_EQ(50, p.getPosition().x);
    EXPECT_FLOAT_EQ(269.5, p.getPosition().y);
}

TEST(Player1, TestMoveRight) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    Map arena = mFactory.createMap(1, p);
    p.movement(sf::Vector2f(1, 0), arena);
    EXPECT_FLOAT_EQ(50.5, p.getPosition().x);
    EXPECT_EQ(270, p.getPosition().y);
}

TEST(Player1, TestMoveLeft) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    Map arena = mFactory.createMap(1, p);
    p.movement(sf::Vector2f(-1, 0), arena);
    EXPECT_FLOAT_EQ(49.5, p.getPosition().x);
    EXPECT_EQ(270, p.getPosition().y);
}

TEST(Player1, TestMeleeAttack) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::adventurer);
    Map arena = mFactory.createMap(1, p);
    Enemy e = pFactory.createEnemy(CharacterType::ghoul, sf::Vector2f(66, 270), arena);
    p.fight(e);
    EXPECT_EQ(50, e.getHp());
}

//Test colpo a vuoto
TEST(Player1, TestRangedAttack) {
    PlayersFactory pFactory;
    MapFactory mFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    Map arena = mFactory.createMap(1, p);
    Enemy *e;
    e = new Enemy(pFactory.createEnemy(CharacterType::ghoul, sf::Vector2f(60, 270), arena));
    Bullet bullet = BulletsFactory::createBullet(BulletType::bullet, 1, p.getPosition(), sf::Vector2i(32, 3));
    bullet.movement(arena);
    bool c = bullet.isCollide(e);
    EXPECT_EQ(false, c);
}