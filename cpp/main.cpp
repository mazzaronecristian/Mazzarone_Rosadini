#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Map.h"
#include "../header/Character.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Follow.h"
#include "../header/Bullet.h"
#include "../header/PlayersFactory.h"
#include "../header/BulletsFactory.h"
#include "../header/LifeBar.h"
#include "../header/UserInterfaceFactory.h"
#include "../header/MapFactory.h"
#include "../header/AdaptHorizontal.h"
#include "../header/AdaptVertical.h"

#include <cmath>
#include <list>
#include <memory>

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int wavwCounter); //generates waves of enemies

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar);

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar);

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          LifeBar &lifeBar);

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero, int &numArena);

int main() {
    bool restart;
    //scelta personaggio
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

    float deltaTimeChoice;
    sf::Clock clockChoice;

    CharacterType heroType;
    while (choice.isOpen()) {
        deltaTimeChoice = clockChoice.restart().asSeconds();
        sf::Event e;
        while (choice.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                return 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            heroType = heroesGif[0]->getType();
            choice.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            heroType = heroesGif[1]->getType();
            choice.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            heroType = heroesGif[2]->getType();
            choice.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
            heroType = heroesGif[3]->getType();
            choice.close();
        }
        choice.clear();
        choice.draw(choiceSprite);
        for (const auto &i: heroesGif) {
            i->update(deltaTimeChoice);
            choice.draw(*i);
        }
        choice.display();
    }
    int numArena = 2;
    do {
        int waveCounter = 0;
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
        UserInterfaceFactory userFactory;
        MapFactory mapFactory;

        std::vector<std::shared_ptr<Player1>> hero;

        hero.push_back(std::make_shared<Player1>(factory.createHero(heroType)));

        LifeBar lifeBar = userFactory.createLifeBar(hero[0].get());

        Map arena = mapFactory.createMap(numArena);

        srand(time(NULL));
        std::list<std::shared_ptr<Enemy>> enemies;
        waveCounter++;
        generateEnemies(enemies, waveCounter);
        sf::Clock clock;
        float deltaTime;
        std::list<std::shared_ptr<Bullet>> bullets;
        BulletsFactory bullFactory;
        //main loop
        while (window.isOpen()) {
            deltaTime = clock.restart().asSeconds();
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    window.close();
                }
                if (e.type == sf::Event::KeyReleased)
                    if (e.key.code == sf::Keyboard::Enter) {
                        if (hero[0]->getType() == CharacterType::spaceCadet && !hero[0]->isDying()) {
                            short int bulletDirection;
                            if (hero[0]->getSource().y % 2 == 0) {
                                hero[0]->setSourceY(4);
                                bulletDirection = 1; //right
                            } else {
                                hero[0]->setSourceY(5);
                                bulletDirection = -1; //left
                            }
                            std::shared_ptr<Bullet> shot = std::make_shared<Bullet>(
                                    bullFactory.createBullet(hero[0]->getPosition(),
                                                             bulletDirection));
                            hero[0]->setAnim(8, 0.06);
                            shot->setAnim(3, 0.3);
                            bullets.push_back(shot);
                        }
                    }
            }

            //check restart conditions
            restart = checkRestart(window, hero, numArena);

            //hero action
            if (!hero[0]->isDying()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    hero[0]->movement(sf::Vector2f(0, -1), arena);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    hero[0]->movement(sf::Vector2f(-1, 0), arena);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    hero[0]->movement(sf::Vector2f(0, 1), arena);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    hero[0]->movement(sf::Vector2f(1, 0), arena);
                if (hero[0]->getType() != CharacterType::spaceCadet)
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                        hero[0]->setIsFighting(true);
            }

            //Enemies movement
            for (auto i = enemies.begin(); i != enemies.end(); i++) {
                if (!i->get()->isFighting()) {
                    if (std::abs(hero[0]->getPosition().x - i->get()->getPosition().x) <= 300
                        && std::abs(hero[0]->getPosition().y - i->get()->getPosition().y) <= 300) {
                        i->get()->setMoveStrategy(std::make_shared<Follow>());
                    } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
                } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
            }

            if (hero[0]->getKillCounter() == 10 && waveCounter < 2) {
                waveCounter++;
                generateEnemies(enemies, waveCounter);
            }

            (hero[0]->getType() == CharacterType::spaceCadet) ?
            update(bullets, hero, enemies, deltaTime, arena, lifeBar) : update(hero, enemies, deltaTime, arena,
                                                                               lifeBar);

            draw(bullets, hero, enemies, window, gameOver, arena, lifeBar);
        }
    } while (restart);
    return 0;
}

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter) {
    PlayersFactory factory;
    std::cout << waveCounter;
    for (int i = 0; i < 1; i++) {
        std::shared_ptr<Enemy> enemy;
        if (waveCounter == 1)
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(rand() % 2 + 4),
                                        sf::Vector2f(
                                                (float) (rand() % 450 + 300),
                                                (float) (rand() % 450 +
                                                         100))));
        else
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(rand() % 2 + 6),
                                        sf::Vector2f(
                                                (float) (rand() % 450 + 300),
                                                (float) (rand() % 450 +
                                                         100))));
        enemies.push_back(enemy);
    }

}

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar) {

    //Bullets update
    for (auto i = bullets.begin(); i != bullets.end();) {
        i->get()->movement();
        i->get()->update(deltaTime);
        auto y = enemies.begin();
        while (y != enemies.end()) {
            if (i->get()->isCollide(**y)) {
                hero[0]->fight(**y);
                break;
            }
            y++;
        }
        if (!i->get()->isLife())
            i = bullets.erase(i);
        else i++;
    }

    update(hero, enemies, deltaTime, arena, lifeBar);
}

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar) {
    //Enemies update
    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->isLegalFight(*hero[0])) {
            i->get()->fight(*hero[0]);
        }
    }

    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->getHp() <= 0)
            i->get()->kill();
    }
    for (auto i = enemies.begin(); i != enemies.end();) {
        if (!i->get()->isLegalMove(hero[0]->getPosition(), arena))
            i->get()->setMoveStrategy(
                    std::make_shared<AdaptHorizontal>());//TODO adattare il movimento del nemico agli ostacoli!!!!
        i->get()->movement(hero[0]->getPosition(), arena);
        i->get()->update(deltaTime);
        if (!(i->get()->isLife())) {
            i = enemies.erase(i);
            hero[0]->increaseKillCounter();
        }
        i++;
    }
    if (hero[0]->isFighting()) {
        if (hero[0]->getSource().y % 2 == 0)
            hero[0]->setAnim(8, 0.04, 4);
        else hero[0]->setAnim(8, 0.04, 5);
        auto y = enemies.begin();
        while (y != enemies.end()) {
            if (hero[0]->isLegalFight(**y)) {
                hero[0]->fight(**y);
                break;
            }
            y++;
        }
    }

    //Heroes update
    if (hero[0]->getHp() <= 0)
        hero[0]->kill();
    if (!hero[0]->isLife()) {
        hero.pop_back();
    } else
        hero[0]->update(deltaTime);
    lifeBar.update();

    if (hero[0]->getKillCounter() == 20)
        arena.openExitTile();
}

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          LifeBar &lifeBar) {
    window.clear();
    window.draw(arena);
    window.draw(*hero[0]);
    for (auto i: enemies) {
        window.draw(*i);
    }
    for (auto i: bullets) {
        window.draw(*i);
    }
    window.draw(lifeBar);
    if (!hero[0]->isLife()) {
        sf::Sprite over(gameOver.getTexture());
        window.draw(over);
    }
    window.display();

}

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero, int &numArena) {

    bool restart = false;
    if (!hero[0]->isLife()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            restart = true;
            window.close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.close();
    } else if (hero[0]->getPosition().x >= 943) {
        restart = true;
        numArena = 2;
        window.close();
    }
    return restart;
}