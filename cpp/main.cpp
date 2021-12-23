#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Utility.h"

#include <list>
#include <memory>

int main() {
    //Start Window
    sf::RenderWindow start(sf::VideoMode(960, 495), "Rage Arena");
    sf::Texture startBackground;
    startBackground.loadFromFile("./tileSets/userInterface/presentation.png");
    sf::Sprite startSprite(startBackground);
    while (start.isOpen()) {
        sf::Event e{};
        while (start.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                return 0;
            else if (e.type == sf::Event::KeyPressed)
                start.close();
        }
        start.clear();
        start.draw(startSprite);
        start.display();
    }
    bool restart = false, finish = false;
    short int numArena = 1;

    //Hero choice
    sf::RenderWindow choice(sf::VideoMode(960, 740), "Choose your hero");
    sf::Texture choiceBackground;
    choiceBackground.loadFromFile("./tileSets/userInterface/choiceBackground.png");
    sf::Sprite choiceSprite(choiceBackground);
    choiceSprite.setPosition(0, 0);
    std::vector<std::shared_ptr<Gif>> heroesGif;
    Gif heroGif1 = UserInterfaceFactory::createGif(CharacterType::spaceCadet, sf::Vector2f(200, 130));
    Gif heroGif2 = UserInterfaceFactory::createGif(CharacterType::adventurer, sf::Vector2f(500, 130));
    Gif heroGif3 = UserInterfaceFactory::createGif(CharacterType::dwarf, sf::Vector2f(200, 380));
    Gif heroGif4 = UserInterfaceFactory::createGif(CharacterType::gladiator, sf::Vector2f(500, 380));
    heroesGif.push_back(std::make_shared<Gif>(heroGif1));
    heroesGif.push_back(std::make_shared<Gif>(heroGif2));
    heroesGif.push_back(std::make_shared<Gif>(heroGif3));
    heroesGif.push_back(std::make_shared<Gif>(heroGif4));
    sf::Clock clockChoice;
    CharacterType heroType;

    while (choice.isOpen()) {
        float deltaTimeChoice = clockChoice.restart().asSeconds();
        sf::Event e{};
        while (choice.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    return 0;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Num1) {
                        heroType = heroesGif[0]->getType();
                        choice.close();
                    }
                    if (e.key.code == sf::Keyboard::Num2) {
                        heroType = heroesGif[1]->getType();
                        choice.close();
                    }
                    if (e.key.code == sf::Keyboard::Num3) {
                        heroType = heroesGif[2]->getType();
                        choice.close();
                    }
                    if (e.key.code == sf::Keyboard::Num4) {
                        heroType = heroesGif[3]->getType();
                        choice.close();
                    }
                    break;
                default:
                    break;
            }
        }

        choice.clear();
        choice.draw(choiceSprite);
        for (const auto &i: heroesGif) {
            i->update(deltaTimeChoice);
            choice.draw(*i);
        }
        choice.display();
    }

    int hpHero = 120;

    //Objects initialization
    do {
        short int waveCounter = 0;
        sf::RenderWindow window(sf::VideoMode(960, 740), "GAME");
        sf::RenderTexture gameOver;
        if (!gameOver.create(960, 740))
            return -1;
        gameOver.clear(sf::Color(0, 0, 0, 80));
        sf::Texture t;
        t.loadFromFile("./tileSets/userInterface/gameOver.png");
        sf::Sprite s(t);
        s.setPosition(250, 80);
        gameOver.draw(s);
        gameOver.display();

        PlayersFactory factory;

        std::vector<std::shared_ptr<Player1>> hero;
        hero.push_back(std::make_shared<Player1>(factory.createHero(heroType)));

        std::list<std::shared_ptr<LifeBar>> lifeBars;

        LifeBar lifeBar = UserInterfaceFactory::createLifeBar(hero[0].get(), sf::Vector2f(10, 680), LifeBarType::hero);

        lifeBars.push_back(std::make_shared<LifeBar>(lifeBar));

        Map arena = MapFactory::createMap(numArena, *hero[0]);

        if (numArena == 2)
            hero[0]->setHp(hpHero);
        //enemies
        std::list<std::shared_ptr<Enemy>> enemies;
        waveCounter++;
        generateEnemies(enemies, waveCounter, arena);

        //boss
        std::list<std::shared_ptr<Boss>> boss;

        sf::Clock clock;
        std::list<std::shared_ptr<Bullet>> bullets;

        //Barrels
        std::list<std::shared_ptr<Barrel>> barrels;
        generateBarrels(barrels, arena);
        std::list<std::shared_ptr<Potion>> potions;

        //main loop
        while (window.isOpen()) {
            float deltaTime = clock.restart().asSeconds();
            sf::Event e{};
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    window.close();
                }
                if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Enter) {
                    hero[0]->setAttacking(true);
                    //Bullets creation
                    if (hero[0]->getType() == CharacterType::spaceCadet) {
                        short int bulletDirection;
                        hero[0]->setSourceY(4 + (hero[0]->getSource().y % 2));
                        bulletDirection = (hero[0]->getSource().y % 2 == 0) ? 1 : -1;
                        std::shared_ptr<Bullet> shot = std::make_shared<Bullet>(
                                BulletsFactory::createBullet(BulletType::bullet,
                                                             bulletDirection, hero[0]->getPosition(),
                                                             sf::Vector2i(32, 3)));
                        hero[0]->setAnim(8, 0.06);
                        shot->setAnim(3, 0.3);
                        bullets.push_back(shot);
                    } else {
                        if (hero[0]->getSource().y % 2 == 0)
                            hero[0]->setAnim(8, 0.04, 4);
                        else hero[0]->setAnim(8, 0.04, 5);
                        auto enemy = enemies.begin();
                        bool attacked = false;
                        while (!attacked &&
                               enemy != enemies.end()) {
                            if (hero[0]->isLegalFight(&(**enemy))) {
                                hero[0]->fight(**enemy);
                                attacked = true;
                            } else enemy++;
                        }
                        auto bos = boss.begin();
                        attacked = false;
                        while (!attacked && bos != boss.end()) {
                            if (hero[0]->isLegalFight(&(**bos))) {
                                hero[0]->fight(**bos);
                                attacked = true;
                            } else bos++;
                        }
                        for (auto &barrel: barrels)
                            if (hero[0]->isLegalFight(&(*barrel)))
                                newPotion(potions, *barrel);
                    }
                }
            }

            heroAction(hero, arena, potions);
            enemiesMovement(hero, enemies);
            if (hero[0]->getKillCounter() == 10 && waveCounter < 2) {
                waveCounter++;
                generateEnemies(enemies, waveCounter, arena);
            }
            if (waveCounter == 2 && numArena == 2) {
                waveCounter++;
                generateBoss(boss, lifeBars);
            }

            update(bullets, hero, enemies, boss, deltaTime, arena, lifeBars, barrels, potions, numArena);

            draw(bullets, hero, enemies, window, gameOver, arena, lifeBars, boss, barrels, potions);

            //check restart conditions
            restart = checkRestart(window, hero, boss, numArena, finish);
            hpHero = hero[0]->getHp();
        }
    } while (restart);

    //"YOU WON" window
    if (finish) {
        sf::RenderWindow end(sf::VideoMode(960, 740), "YOU WON!!!");
        sf::Texture endBackground;
        endBackground.loadFromFile("./tileSets/userInterface/end.png");
        sf::Sprite endSprite(endBackground);

        while (end.isOpen()) {
            sf::Event e{};
            while (end.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    end.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                end.close();
            end.clear();
            end.draw(endSprite);
            end.display();
        }
    }

    return 0;
}
