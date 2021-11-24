//
// Created by cristian on 24/11/21.
//
#include "gtest/gtest.h"
#include "../header/Player1.h"
#include "../header/PlayersFactory.h"
#include "../header/Potion.h"
#include "../header/ObjectsFactory.h"

TEST(Potion, superPotion) {
    ObjectsFactory factory;
    PlayersFactory pFactory;
    std::shared_ptr<Potion> p = std::make_shared<Potion>(
            factory.createPotion(PotionType::super, sf::Vector2f(50, 270)));
    Player1 hero = pFactory.createHero(CharacterType::spaceCadet);
    hero.pickPotion(p);
    hero.receiveDamage(50);
    hero.usePotion();
    EXPECT_EQ(120, hero.getHp());
}

TEST(Potion, regularPotion) {
    ObjectsFactory factory;
    PlayersFactory pFactory;
    std::shared_ptr<Potion> p = std::make_shared<Potion>(
            factory.createPotion(PotionType::regular, sf::Vector2f(50, 270)));
    Player1 hero = pFactory.createHero(CharacterType::spaceCadet);
    hero.pickPotion(p);
    hero.receiveDamage(30);
    hero.usePotion();
    EXPECT_EQ(120, hero.getHp());
}

TEST(Potion, maxPotion) {
    ObjectsFactory factory;
    PlayersFactory pFactory;
    std::shared_ptr<Potion> p = std::make_shared<Potion>(factory.createPotion(PotionType::max, sf::Vector2f(50, 270)));
    Player1 hero = pFactory.createHero(CharacterType::spaceCadet);
    hero.pickPotion(p);
    hero.receiveDamage(120);
    hero.usePotion();
    EXPECT_EQ(120, hero.getHp());
}

TEST(Potion, noHeal) {
    ObjectsFactory factory;
    PlayersFactory pFactory;
    std::shared_ptr<Potion> p = std::make_shared<Potion>(
            factory.createPotion(PotionType::super, sf::Vector2f(50, 270)));
    Player1 hero = pFactory.createHero(CharacterType::spaceCadet);
    hero.pickPotion(p);
    hero.usePotion();
    EXPECT_EQ(150, hero.getHp());
}
