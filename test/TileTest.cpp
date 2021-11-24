//
// Created by cristian on 26/07/21.
//
#include "gtest/gtest.h"
#include "../header/Tile.h"

TEST(Tile, dimension) {
    Tile t(1, 2, true, sf::Vector2f(0, 0));
    sf::Texture texture;
    t.load(texture);
    EXPECT_EQ(32, t.getSprite().getTextureRect().left);
    EXPECT_EQ(64, t.getSprite().getTextureRect().top);
    EXPECT_EQ(32, t.getSprite().getTextureRect().height);
    EXPECT_EQ(32, t.getSprite().getTextureRect().width);
}