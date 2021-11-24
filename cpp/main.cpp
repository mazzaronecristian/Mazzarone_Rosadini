#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Map.h"
#include "../header/Player1.h"
#include "../header/Follow.h"
#include "../header/Bullet.h"
#include "../header/PlayersFactory.h"
#include "../header/BulletsFactory.h"
#include "../header/LifeBar.h"
#include "../header/UserInterfaceFactory.h"
#include "../header/MapFactory.h"
#include "../header/ObjectsFactory.h"


#include <cmath>
#include <list>
#include <memory>

void generateBarrels(std::list<std::shared_ptr<Barrel>> &barrels, const Map &arena);

void newPotion(std::list<std::shared_ptr<Potion>> &potions, Barrel &barrel);

sf::Vector2f rightPosition(Map arena);

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter,
                     const Map &arena); //generates waves of enemies

void generateBoss(std::list<std::shared_ptr<Boss>> &boss, std::list<std::shared_ptr<LifeBar>> &lifeBar);


void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Boss>> &boss, float deltaTime,
            Map &arena, std::list<std::shared_ptr<LifeBar>> &lifeBars, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions, int numArena);

void update(std::vector<std::shared_ptr<Player1>> hero, std::list<std::shared_ptr<Enemy>> &enemies,
            std::list<std::shared_ptr<Boss>> &boss, float deltaTime, Map &arena,
            std::list<std::shared_ptr<LifeBar>> &lifeBars, std::list<std::shared_ptr<Barrel>> &barrels, int numArena);

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          const std::list<std::shared_ptr<LifeBar>> &lifeBars, const std::list<std::shared_ptr<Boss>> &boss,
          const std::list<std::shared_ptr<Barrel>> &barrels, const std::list<std::shared_ptr<Potion>> &potions);

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero,
                  const std::list<std::shared_ptr<Boss>> &boss, short int &numArena, bool &finish);


int main() {
    bool restart = false, finish = false;
    short int numArena = 1;

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
    int hpHero = 120;
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

        std::list<std::shared_ptr<LifeBar>> lifeBars;

        LifeBar lifeBar = userFactory.createLifeBar(hero[0].get(), sf::Vector2f(10, 680), LifeBarType::hero);

        lifeBars.push_back(std::make_shared<LifeBar>(lifeBar));

        Map arena = mapFactory.createMap(numArena, *hero[0]);

        if (numArena == 2)
            hero[0]->setHp(hpHero);
        //enemies
        std::list<std::shared_ptr<Enemy>> enemies;
        waveCounter++;
        generateEnemies(enemies, waveCounter, arena);

        //boss
        std::list<std::shared_ptr<Boss>> boss;

        sf::Clock clock;
        float deltaTime;
        std::list<std::shared_ptr<Bullet>> bullets;

        //Barrels
        std::list<std::shared_ptr<Barrel>> barrels;
        generateBarrels(barrels, arena);
        std::list<std::shared_ptr<Potion>> potions;

        //main loop
        while (window.isOpen()) {
            deltaTime = clock.restart().asSeconds();
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    window.close();
                }
                if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Enter) {
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


            //hero actions
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
            if (waveCounter == 2 && numArena == 2) {
                waveCounter++;
                generateBoss(boss, lifeBars);
            }

            (hero[0]->getType() == CharacterType::spaceCadet) ?
            update(bullets, hero, enemies, boss, deltaTime, arena, lifeBars, barrels, potions, numArena) : update(hero,
                                                                                                                  enemies,
                                                                                                                  boss,
                                                                                                                  deltaTime,
                                                                                                                  arena,
                                                                                                                  lifeBars,
                                                                                                                  barrels,
                                                                                                                  numArena);

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                end.close();
            end.clear();
            end.draw(endSprite);
            end.display();
        }
    }

    return 0;
}

void generateBarrels(std::list<std::shared_ptr<Barrel>> &barrels, const Map &arena) {
    ObjectsFactory barrelFactory;
    PotionType T[3] = {PotionType::regular, PotionType::super, PotionType::max};
    for (int i = 0; i < 3; i++) {
        sf::Vector2f position = rightPosition(arena);
        std::shared_ptr<Barrel> barrel = (std::make_shared<Barrel>(
                barrelFactory.createBarrel(T[random() % 3], position)));
        barrels.push_back(barrel);
    }

}

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter, const Map &arena) {
    PlayersFactory factory;
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Enemy> enemy;
        sf::Vector2f position = rightPosition(arena);
        if (waveCounter == 1)
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(random() % 2 + 4),
                                        position, arena));
        else
            enemy = std::make_shared<Enemy>(
                    factory.createEnemy(static_cast<CharacterType>(random() % 2 + 6),
                                        sf::Vector2f(
                                                (float) (random() % 450 + 300),
                                                (float) (random() % 450 +
                                                         100)), arena));
        enemies.push_back(enemy);
    }
}

void newPotion(std::list<std::shared_ptr<Potion>> &potions, Barrel &barrel) {
    PotionType type;
    if (barrel.kill(type)) {
        ObjectsFactory factory;
        std::shared_ptr<Potion> potion;
        potion = std::make_shared<Potion>(factory.createPotion(type, barrel.getPosition()));
        potions.push_back(potion);
    }
}

sf::Vector2f rightPosition(Map arena) {
    bool legalPosition = false;
    sf::Vector2f position;
    while (!legalPosition) {
        position = {(float) (random() % 450 + 300), (float) (random() % 450 + 100)};
        sf::Vector2i source = {(int) round(position.x / 32), (int) round(position.y / 32)};
        Tile tile = arena.getTile(source);
        if (tile.isWalkable())
            legalPosition = true;
    }
    return position;
}

void generateBoss(std::list<std::shared_ptr<Boss>> &boss, std::list<std::shared_ptr<LifeBar>> &lifeBars) {
    PlayersFactory factory;
    UserInterfaceFactory userFactory;
    std::shared_ptr<Boss> b;
    b = std::make_shared<Boss>(factory.createBoss(CharacterType::cyclops));
    boss.push_back(b);
    for (auto &bos: boss) {
        bos->setMoveStrategy(std::make_shared<Follow>());
        std::shared_ptr<LifeBar> lifeBar = std::make_shared<LifeBar>(
                userFactory.createLifeBar(bos.get(), sf::Vector2f(600, 680), LifeBarType::cyclops));
        lifeBars.push_back(lifeBar);
    }
}


void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Boss>> &boss, float deltaTime,
            Map &arena, std::list<std::shared_ptr<LifeBar>> &lifeBars, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions, int numArena) {

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
        for (auto &bos: boss) {
            if (bullet->get()->isCollide(&*bos))
                hero[0]->fight(*bos);
        }
        if (!bullet->get()->isLife())
            bullet = bullets.erase(bullet);
        else bullet++;
    }

    update(hero, enemies, boss, deltaTime, arena, lifeBars, barrels, numArena);
}

void update(std::vector<std::shared_ptr<Player1>> hero, std::list<std::shared_ptr<Enemy>> &enemies,
            std::list<std::shared_ptr<Boss>> &boss, float deltaTime, Map &arena,
            std::list<std::shared_ptr<LifeBar>> &lifeBars, std::list<std::shared_ptr<Barrel>> &barrels, int numArena) {
    //Enemies update
    for (auto &enemy: enemies) {
        if (enemy->isLegalFight(&*hero[0])) {
            enemy->fight(*hero[0]);
        }
    }
    for (auto &enemy: enemies) {
        if (enemy->getHp() <= 0)
            enemy->kill();
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
    //boss update
    for (auto &bos: boss) {
        bos->fight(*hero[0]);
        bos->moveLaser(arena);
        if (!bos->isLegalMove(hero[0]->getPosition(), arena))
            bos->setMoveStrategy(hero[0]->getPosition(), arena);
        bos->movement(hero[0]->getPosition(), arena);
        bos->setMoveStrategy(std::make_shared<Follow>());
        bos->update(deltaTime);
        if (bos->getHp() <= 0)
            bos->kill();
    }

    //Hero update
    if (hero[0]->getHp() <= 0)
        hero[0]->kill();
    if (!hero[0]->isLife())
        hero.pop_back();
    else hero[0]->update(deltaTime);

    for (auto barrel = barrels.begin(); barrel != barrels.end();) {
        barrel->get()->update(deltaTime);
        !barrel->get()->isLife() ? (barrel = barrels.erase(barrel)) : barrel++;
    }
    for (auto &lifeBar: lifeBars)
        lifeBar->update();
    arena.update(numArena);
}

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          const std::list<std::shared_ptr<LifeBar>> &lifeBars, const std::list<std::shared_ptr<Boss>> &boss,
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
    for (const auto &i: lifeBars) {
        window.draw(*i);
    }
    if (!hero[0]->isLife()) {
        sf::Sprite over(gameOver.getTexture());
        window.draw(over);
    }
    for (const auto &bos: boss) {
        window.draw(*bos);
        for (const auto &laser: bos->getLasers())
            window.draw(*laser);
    }
    window.display();
}

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero,
                  const std::list<std::shared_ptr<Boss>> &boss, short int &numArena, bool &finish) {
    bool restart = false;
    if (!hero[0]->isLife()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            restart = true;
            numArena = 1;
            window.close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.close();
    } else if (hero[0]->getPosition().x >= 943) {
        restart = true;
        numArena = 2;
        window.close();
    }
    for (const auto &bos: boss) {
        finish = !bos->isLife();
    }
    if (finish)
        window.close();
    return restart;
}