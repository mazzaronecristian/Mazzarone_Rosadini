//
// Created by cristian on 24/11/21.
//

#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/PlayersFactory.h"
#include "../header/LifeBar.h"
#include "../header/UserInterfaceFactory.h"


TEST(LifeBar, weakDamage) {
    PlayersFactory pFactory;
    UserInterfaceFactory userFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    LifeBar l = userFactory.createLifeBar(&p, sf::Vector2f(10, 680), LifeBarType::hero);
    p.receiveDamage(10);
    l.update();
    EXPECT_EQ(0, l.getSource().y);
}

TEST(LifeBar, damageTest) {
    PlayersFactory pFactory;
    UserInterfaceFactory userFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    LifeBar l = userFactory.createLifeBar(&p, sf::Vector2f(10, 680), LifeBarType::hero);
    p.receiveDamage(25);
    l.update();
    EXPECT_EQ(1, l.getSource().y);
}

TEST(LifeBar, fullDamage) {
    PlayersFactory pFactory;
    UserInterfaceFactory userFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    LifeBar l = userFactory.createLifeBar(&p, sf::Vector2f(10, 680), LifeBarType::hero);
    p.receiveDamage(p.getHp());
    l.update();
    EXPECT_EQ(5, l.getSource().y);
}

TEST(LifeBar, healTest) {
    PlayersFactory pFactory;
    UserInterfaceFactory userFactory;
    Player1 p = pFactory.createHero(CharacterType::spaceCadet);
    LifeBar l = userFactory.createLifeBar(&p, sf::Vector2f(10, 680), LifeBarType::hero);
    p.receiveDamage(p.getHp());
    l.update();

    p.setHp(50);
    l.update();
    EXPECT_EQ(2, l.getSource().y);
}