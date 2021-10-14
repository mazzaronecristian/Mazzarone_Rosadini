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

#include <cmath>
#include <list>
#include <memory>

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter,
                     Map arena); //generates waves of enemies

void generateBoss(std::vector<std::shared_ptr<Enemy>> &boss);


void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar);

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar);

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          LifeBar &lifeBar, const std::vector<std::shared_ptr<Enemy>> &boss);

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero, short int &numArena);


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
    Gif heroGif3 = choiceFactory.createGif(CharacterType::dwarf, sf::Vector2f(200, 380));
    Gif heroGif4 = choiceFactory.createGif(CharacterType::gladiator, sf::Vector2f(500, 380));
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
    short int numArena = 2;
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
        UserInterfaceFactory userFactory;
        MapFactory mapFactory;

        std::vector<std::shared_ptr<Player1>> hero;

        hero.push_back(std::make_shared<Player1>(factory.createHero(heroType)));

        LifeBar lifeBar = userFactory.createLifeBar(hero[0].get());

        Map arena = mapFactory.createMap(numArena);

        srand(time(NULL));

        //enemies
        std::list<std::shared_ptr<Enemy>> enemies;
        waveCounter++;
        generateEnemies(enemies, waveCounter, arena);

        //boss
        std::vector<std::shared_ptr<Enemy>> boss;
        if (numArena == 2)
            generateBoss(boss);
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
            for (auto &enemy: enemies) {
                if (std::abs(hero[0]->getPosition().x - enemy->getPosition().x) <= 300
                    && std::abs(hero[0]->getPosition().y - enemy->getPosition().y) <= 300) {
                    enemy->setMoveStrategy(std::make_shared<Follow>());
                } else enemy->setMoveStrategy(std::make_shared<Patrol>());
            }

            if (hero[0]->getKillCounter() == 10 && waveCounter < 2) {
                waveCounter++;
                generateEnemies(enemies, waveCounter, arena);
            }

            (hero[0]->getType() == CharacterType::spaceCadet) ?
            update(bullets, hero, enemies, boss, deltaTime, arena, lifeBar) : update(hero, enemies, boss, deltaTime,
                                                                                     arena,
                                                                                     lifeBar);

            draw(bullets, hero, enemies, window, gameOver, arena, lifeBar, boss);
        }
    } while (restart);
    return 0;
}

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter, Map arena) {
    PlayersFactory factory;
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Enemy> enemy;
        bool legalPosition = false;
        sf::Vector2f position;
        while (!legalPosition) {
            position = {(float) (rand() % 450 + 300), (float) (rand() % 450 + 100)};
            sf::Vector2i source = {(int) round(position.x / 32), (int) round(position.y / 32)};
            Tile tile = arena.getTile(source);
            if (tile.isWalkable())
                legalPosition = true;
        }
        if (waveCounter == 1)
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(rand() % 2 + 4),
                                        position, arena));
        else
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(rand() % 2 + 6),
                                        sf::Vector2f(
                                                (float) (rand() % 450 + 300),
                                                (float) (rand() % 450 +
                                                         100)), arena));
        enemies.push_back(enemy);
    }

}

void generateBoss(std::vector<std::shared_ptr<Enemy>> &boss) {
    PlayersFactory factory;
    std::shared_ptr<Enemy> enemy;
    enemy = std::make_shared<Enemy>(factory.createBoss(CharacterType::cyclops));
    boss.push_back(enemy);
    boss[0]->setMoveStrategy(std::make_shared<Follow>());
}

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar) {

    //Bullets update
    for (auto i = bullets.begin(); i != bullets.end();) {
        i->get()->movement(arena);
        i->get()->update(deltaTime);
        auto y = enemies.begin();
        while (y != enemies.end()) {
            if (i->get()->isCollide(**y)) {
                hero[0]->fight(**y);
                break;
            }
            y++;
        }
        if (i->get()->isCollide(*boss[0]))
            hero[0]->fight(*boss[0]);

        if (!i->get()->isLife())
            i = bullets.erase(i);
        else i++;
    }

    update(hero, enemies, boss, deltaTime, arena, lifeBar);
}

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar) {
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
        //enemySelectionStrategy(enemies, hero, arena);
        if (!i->get()->isLegalMove(hero[0]->getPosition(), arena))
            i->get()->setMoveStrategy(hero[0]->getPosition(), arena);
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
        hero[0]->isLegalFight(*boss[0]);
    }

    if (boss[0]->isLegalMove(hero[0]->getPosition(), arena))
        boss[0]->setMoveStrategy(hero[0]->getPosition(), arena);
    boss[0]->movement(hero[0]->getPosition(), arena);
    boss[0]->update(deltaTime);

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
          LifeBar &lifeBar, const std::vector<std::shared_ptr<Enemy>> &boss) {
    window.clear();
    window.draw(arena);
    window.draw(*hero[0]);
    for (const auto &i: enemies) {
        window.draw(*i);
    }
    for (const auto &i: bullets) {
        window.draw(*i);
    }
    window.draw(lifeBar);
    if (!hero[0]->isLife()) {
        sf::Sprite over(gameOver.getTexture());
        window.draw(over);
    }
    window.draw(*boss[0]);
    window.display();
}

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero, short int &numArena) {

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