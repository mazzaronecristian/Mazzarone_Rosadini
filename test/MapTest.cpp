//
// Created by cristian on 24/11/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Bullet.h"
#include "../header/MapFactory.h"
#include "../header/PlayersFactory.h"

TEST(Map, openExitTile) {
    MapFactory mFactory;
    PlayersFactory pFactory;
    short int numarena = 1;
    Player1 p(CharacterType::spaceCadet);
    p.load("./tileSets/characters/spaceCadet.png", sf::Vector2f(943, 270));
    p.setKillCounter(20);
    Map arena = mFactory.createMap(numarena, p);
    arena.update(numarena);
    EXPECT_EQ(8, arena.getTile(299).getCodeX());
    EXPECT_EQ(5, arena.getTile(299).getCodeY());
}
