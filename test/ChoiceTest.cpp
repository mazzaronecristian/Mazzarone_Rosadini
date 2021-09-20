//
// Created by Gianluca Rosadini on 20/09/21.
//

#include "gtest/gtest.h"
#include "../header/Gif.h"
#include "../header/UserInterfaceFactory.h"
#include "../header/Player1.h"
#include "../header/PlayersFactory.h"

TEST(Gif, spaceCadet) {
    sf::RenderWindow choice(sf::VideoMode(960, 740), "Choose your hero");
    sf::Texture choiceBackground;
    UserInterfaceFactory choiceFactory;
    choiceBackground.loadFromFile("./tileSets/userInterface/choiceBackground.png");
    sf::Sprite choiceSprite(choiceBackground);
    choiceSprite.setPosition(0, 0);
    std::vector<std::shared_ptr<Gif>> heroesGif;
    Gif heroGif1 = choiceFactory.createGif(CharacterType::spaceCadet, sf::Vector2f(200, 130));
    Gif heroGif2 = choiceFactory.createGif(CharacterType::adventurer, sf::Vector2f(500, 130));
    Gif heroGif3 = choiceFactory.createGif(CharacterType::dwarf, sf::Vector2f(200, 360));
    Gif heroGif4 = choiceFactory.createGif(CharacterType::gladiator, sf::Vector2f(500, 360));
    heroesGif.push_back(std::make_shared<Gif>(heroGif1));
    heroesGif.push_back(std::make_shared<Gif>(heroGif2));
    heroesGif.push_back(std::make_shared<Gif>(heroGif3));
    heroesGif.push_back(std::make_shared<Gif>(heroGif4));
    CharacterType hero = heroesGif[0]->getType();
    EXPECT_EQ(CharacterType::spaceCadet, hero);
}

TEST(Gif, adventurer) {
    sf::RenderWindow choice(sf::VideoMode(960, 740), "Choose your hero");
    sf::Texture choiceBackground;
    UserInterfaceFactory choiceFactory;
    choiceBackground.loadFromFile("./tileSets/userInterface/choiceBackground.png");
    sf::Sprite choiceSprite(choiceBackground);
    choiceSprite.setPosition(0, 0);
    std::vector<std::shared_ptr<Gif>> heroesGif;
    Gif heroGif1 = choiceFactory.createGif(CharacterType::spaceCadet, sf::Vector2f(200, 130));
    Gif heroGif2 = choiceFactory.createGif(CharacterType::adventurer, sf::Vector2f(500, 130));
    Gif heroGif3 = choiceFactory.createGif(CharacterType::dwarf, sf::Vector2f(200, 360));
    Gif heroGif4 = choiceFactory.createGif(CharacterType::gladiator, sf::Vector2f(500, 360));
    heroesGif.push_back(std::make_shared<Gif>(heroGif1));
    heroesGif.push_back(std::make_shared<Gif>(heroGif2));
    heroesGif.push_back(std::make_shared<Gif>(heroGif3));
    heroesGif.push_back(std::make_shared<Gif>(heroGif4));
    CharacterType hero = heroesGif[1]->getType();
    EXPECT_EQ(CharacterType::adventurer, hero);
}

TEST(Gif, dwarf) {
    sf::RenderWindow choice(sf::VideoMode(960, 740), "Choose your hero");
    sf::Texture choiceBackground;
    UserInterfaceFactory choiceFactory;
    choiceBackground.loadFromFile("./tileSets/userInterface/choiceBackground.png");
    sf::Sprite choiceSprite(choiceBackground);
    choiceSprite.setPosition(0, 0);
    std::vector<std::shared_ptr<Gif>> heroesGif;
    Gif heroGif1 = choiceFactory.createGif(CharacterType::spaceCadet, sf::Vector2f(200, 130));
    Gif heroGif2 = choiceFactory.createGif(CharacterType::adventurer, sf::Vector2f(500, 130));
    Gif heroGif3 = choiceFactory.createGif(CharacterType::dwarf, sf::Vector2f(200, 360));
    Gif heroGif4 = choiceFactory.createGif(CharacterType::gladiator, sf::Vector2f(500, 360));
    heroesGif.push_back(std::make_shared<Gif>(heroGif1));
    heroesGif.push_back(std::make_shared<Gif>(heroGif2));
    heroesGif.push_back(std::make_shared<Gif>(heroGif3));
    heroesGif.push_back(std::make_shared<Gif>(heroGif4));
    CharacterType hero = heroesGif[2]->getType();
    EXPECT_EQ(CharacterType::dwarf, hero);
}

TEST(Gif, gladiator) {
    sf::RenderWindow choice(sf::VideoMode(960, 740), "Choose your hero");
    sf::Texture choiceBackground;
    UserInterfaceFactory choiceFactory;
    choiceBackground.loadFromFile("./tileSets/userInterface/choiceBackground.png");
    sf::Sprite choiceSprite(choiceBackground);
    choiceSprite.setPosition(0, 0);
    std::vector<std::shared_ptr<Gif>> heroesGif;
    Gif heroGif1 = choiceFactory.createGif(CharacterType::spaceCadet, sf::Vector2f(200, 130));
    Gif heroGif2 = choiceFactory.createGif(CharacterType::adventurer, sf::Vector2f(500, 130));
    Gif heroGif3 = choiceFactory.createGif(CharacterType::dwarf, sf::Vector2f(200, 360));
    Gif heroGif4 = choiceFactory.createGif(CharacterType::gladiator, sf::Vector2f(500, 360));
    heroesGif.push_back(std::make_shared<Gif>(heroGif1));
    heroesGif.push_back(std::make_shared<Gif>(heroGif2));
    heroesGif.push_back(std::make_shared<Gif>(heroGif3));
    heroesGif.push_back(std::make_shared<Gif>(heroGif4));
    CharacterType hero = heroesGif[3]->getType();
    EXPECT_EQ(CharacterType::gladiator, hero);
}




