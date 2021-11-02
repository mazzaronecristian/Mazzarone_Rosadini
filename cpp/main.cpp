#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Map.h"
#include "../header/Character.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Follow.h"
#include "../header/Bullet.h"
#include "../header/Barrel.h"
#include "../header/PlayersFactory.h"
#include "../header/BulletsFactory.h"
#include "../header/LifeBar.h"
#include "../header/UserInterfaceFactory.h"
#include "../header/MapFactory.h"
#include "../header/ObjectsFactory.h"

#include <cmath>
#include <list>
#include <memory>

void newPotion(std::list<std::shared_ptr<Potion>> &potions, Barrel &barrel);

sf::Vector2f rightPosition(Map arena);

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter,
                     Map arena); //generates waves of enemies

void generateBoss(std::vector<std::shared_ptr<Enemy>> &boss);


void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions);

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions);

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          LifeBar &lifeBar, const std::vector<std::shared_ptr<Enemy>> &boss,
          const std::list<std::shared_ptr<Barrel>> &barrels, const std::list<std::shared_ptr<Potion>> &potions);

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

        Map arena = mapFactory.createMap(numArena, *hero[0]);

        srand(time(NULL));

        //enemies
        std::list<std::shared_ptr<Enemy>> enemies;
        waveCounter++;
        generateEnemies(enemies, waveCounter, arena);

        std::vector<std::shared_ptr<Enemy>> boss;
        if (numArena == 2)
            generateBoss(boss);
        sf::Clock clock;
        float deltaTime;
        std::list<std::shared_ptr<Bullet>> bullets;
        BulletsFactory bullFactory;

        //Barrels
        std::list<std::shared_ptr<Barrel>> barrels;
        ObjectsFactory barrelFactory;
        for (int i = 0; i < 3; i++) {
            sf::Vector2f position = rightPosition(arena);
            std::shared_ptr<Barrel> barrel = (std::make_shared<Barrel>(barrelFactory.createBarrel(position)));
            barrels.push_back(barrel);
        }

        std::list<std::shared_ptr<Potion>> potions;

        //main loop
        while (window.isOpen()) {
            deltaTime = clock.restart().asSeconds();
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    window.close();
                }
                if (e.type == sf::Event::KeyReleased) {
                    if (e.key.code == sf::Keyboard::Enter && hero[0]->getType() == CharacterType::spaceCadet) {
                        short int bulletDirection;
                        hero[0]->setSourceY(4 + (hero[0]->getSource().y % 2));
                        bulletDirection = (hero[0]->getSource().y % 2 == 0) ? 1 : -1;
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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    for (auto i = potions.begin(); i != potions.end();)
                        hero[0]->pickPotion(*i) ? (i = potions.erase(i)) : i++;
                    hero[0]->usePotion();
                }
                if (hero[0]->getType() != CharacterType::spaceCadet)
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (hero[0]->getSource().y % 2 == 0)
                            hero[0]->setAnim(8, 0.04, 4);
                        else hero[0]->setAnim(8, 0.04, 5);
                        auto enemy = enemies.begin();
                        while (enemy != enemies.end()) {
                            if (hero[0]->isLegalFight(&(**enemy))) {
                                hero[0]->fight(**enemy);
                                break;
                            }
                            enemy++;
                        }
                        auto barrel = barrels.begin();
                        while (barrel != barrels.end()) {
                            if (hero[0]->isLegalFight(&(**barrel))) {
                                newPotion(potions, **barrel);
                            }
                            barrel++;
                        }
                    }
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
            update(bullets, hero, enemies, boss, deltaTime, arena, lifeBar, barrels, potions) : update(hero, enemies,
                                                                                                       boss, deltaTime,
                                                                                                       arena,
                                                                                                       lifeBar, barrels,
                                                                                                       potions);

            draw(bullets, hero, enemies, window, gameOver, arena, lifeBar, boss, barrels, potions);
        }
    } while (restart);
    return 0;
}

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter, Map arena) {
    PlayersFactory factory;
    for (int i = 0; i < 1; i++) {
        std::shared_ptr<Enemy> enemy;
        sf::Vector2f position = rightPosition(arena);
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

void newPotion(std::list<std::shared_ptr<Potion>> &potions, Barrel &barrel) {
    std::shared_ptr<Potion> potion;
    ObjectsFactory factory;
    potion = std::make_shared<Potion>(factory.createPotion(barrel.kill(), barrel.getPosition()));
    potions.push_back(potion);
}

sf::Vector2f rightPosition(Map arena) {
    bool legalPosition = false;
    sf::Vector2f position;
    while (!legalPosition) {
        position = {(float) (rand() % 450 + 300), (float) (rand() % 450 + 100)};
        sf::Vector2i source = {(int) round(position.x / 32), (int) round(position.y / 32)};
        Tile tile = arena.getTile(source);
        if (tile.isWalkable())
            legalPosition = true;
    }
    return position;
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
            Map &arena, LifeBar &lifeBar, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions) {

    //Bullets update
    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
        bullet->get()->movement(arena);
        bullet->get()->update(deltaTime);
        auto enemy = enemies.begin();
        while (enemy != enemies.end()) {
            if (bullet->get()->isCollide(&(**enemy))) {
                hero[0]->fight(**enemy);
                break;
            }
            enemy++;
        }
        auto barrel = barrels.begin();
        while (barrel != barrels.end()) {
            if (bullet->get()->isCollide(&(**barrel))) {
                newPotion(potions, **barrel);
                break;
            }
            barrel++;
        }
        if (bullet->get()->isCollide(&*boss[0]))
            hero[0]->fight(*boss[0]);
        if (!bullet->get()->isLife())
            bullet = bullets.erase(bullet);
        else bullet++;
    }

    update(hero, enemies, boss, deltaTime, arena, lifeBar, barrels, potions);
}

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::vector<std::shared_ptr<Enemy>> boss, float deltaTime,
            Map &arena, LifeBar &lifeBar, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions) {
    //Enemies update
    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->isLegalFight(&*hero[0])) {
            i->get()->fight(*hero[0]);
        }
    }
    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->getHp() <= 0)
            i->get()->kill();
    }
    for (auto i = enemies.begin(); i != enemies.end();) {
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
    for (auto i = barrels.begin(); i != barrels.end();) {
        i->get()->update(deltaTime);
        !i->get()->isLife() ? (i = barrels.erase(i)) : i++;
    }
    lifeBar.update();
    arena.update();
}

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          LifeBar &lifeBar, const std::vector<std::shared_ptr<Enemy>> &boss,
          const std::list<std::shared_ptr<Barrel>> &barrels, const std::list<std::shared_ptr<Potion>> &potions) {
    window.clear();
    window.draw(arena);
    window.draw(*hero[0]);
    for (const auto &i: enemies) {
        window.draw(*i);
    }
    for (const auto &i: bullets) {
        window.draw(*i);
    }
    for (const auto &i: barrels) {
        window.draw(*i);
    }
    for (const auto &i: potions) {
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