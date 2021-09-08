#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Map.h"
#include "../header/Character.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Follow.h"
#include "../header/Patrol.h"
#include "../header/Bullet.h"
#include "../header/RangedAttack.h"
#include "../header/PlayersFactory.h"
#include "../header/BulletsFactory.h"
#include "../header/LifeBar.h"
#include "../header/UserInterfaceFactory.h"

#include <cmath>
#include <list>
#include <memory>

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar);

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar);

int main() {
    bool restart;
    do {
        sf::RenderWindow window(sf::VideoMode(960, 740), "GAME");
        sf::RenderTexture gameOver;
        if (!gameOver.create(960, 740))
            return -1;
        gameOver.clear(sf::Color(0, 0, 0, 80));
        sf::Texture t;
        t.loadFromFile("./tileSets/userInterface/gameOver.png");
        sf::Sprite s(t);
        s.setPosition(250, 140);
        gameOver.draw(s);
        gameOver.display();

        PlayersFactory factory;
        UserInterfaceFactory userFactory;
        std::ifstream m_matrix("./matrix.txt");
        Map arena;
        if (!arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), m_matrix))
            return -1;
        m_matrix.close();
        std::vector<std::shared_ptr<Player1>> hero;

        hero.push_back(std::make_shared<Player1>(factory.createHero(CharacterType::ghoul)));

        LifeBar lifeBar = userFactory.createLifeBar(hero[0].get());

        srand(time(NULL));
        std::list<std::shared_ptr<Enemy>> enemies;
        for (int i = 0; i < 10; i++) {
            std::shared_ptr<Enemy> ghoul = std::make_shared<Enemy>(factory.createEnemy(CharacterType::ghoul,
                                                                                       sf::Vector2f(rand() % 450 + 100,
                                                                                                    rand() % 450 +
                                                                                                    100)));
            enemies.push_back(ghoul);
        }
        sf::Clock clock;
        float deltaTime;
        std::list<std::shared_ptr<Bullet>> bullets;
        BulletsFactory bullFactory;
        //main loop
        while (window.isOpen()) {
            deltaTime = clock.restart().asSeconds();
            sf::Event e;
            restart = false;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    window.close();
                }
                //restart event
                if (e.type == sf::Event::KeyReleased && !hero[0]->isLife())
                    if (e.key.code == sf::Keyboard::R) {
                        restart = true;
                        window.close();
                    }
                if (e.type == sf::Event::KeyPressed)
                    if (e.key.code == sf::Keyboard::Enter) {
                        if (hero[0]->getType() == CharacterType::spaceCadet) {
                            short int bulletDirection;
                            if (hero[0]->getSource().y % 2 == 0) {
                                hero[0]->setSourceY(4);
                                bulletDirection = 1;
                            } else {
                                hero[0]->setSourceY(5);
                                bulletDirection = -1;
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
            //Azione Eroe
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                hero[0]->movement(sf::Vector2f(0, -1), arena);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                hero[0]->movement(sf::Vector2f(-1, 0), arena);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                hero[0]->movement(sf::Vector2f(0, 1), arena);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                hero[0]->movement(sf::Vector2f(1, 0), arena);
            }
            if (hero[0]->getType() != CharacterType::spaceCadet)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    hero[0]->setIsFighting(true);
                }

            //Movimento Nemici
            for (auto i = enemies.begin(); i != enemies.end(); i++) {
                if (!i->get()->isFighting()) {
                    if (std::abs(hero[0]->getPosition().x - i->get()->getPosition().x) <= 300
                        && std::abs(hero[0]->getPosition().y - i->get()->getPosition().y) <= 300) {
                        i->get()->setMoveStrategy(std::make_shared<Follow>());
                    } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
                } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
            }

            if (hero[0]->getType() == CharacterType::spaceCadet)
                update(bullets, hero, enemies, deltaTime, arena, lifeBar);
            else
                update(hero, enemies, deltaTime, arena, lifeBar);
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
    } while (restart);
    return 0;
}

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar) {

    //Update dei Nemici
    for (auto i = enemies.begin(); i != enemies.end();) {
        i->get()->movement(hero[0]->getPosition(), arena);
        i->get()->update(deltaTime);
        if (!(i->get()->isLife()))
            i = enemies.erase(i);
        i++;
    }

    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->isLegalFight(*hero[0])) {
            i->get()->fight(*hero[0]);
        }
    }

    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if (i->get()->getHp() <= 0)
            i->get()->kill();
    }

    //Update dei Proiettili
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

    //Update dell'Eroe
    if (hero[0]->getHp() <= 0)
        hero[0]->kill();
    if (!hero[0]->isLife()) {
        hero.pop_back();
        for (auto i = enemies.begin(); i != enemies.end(); i++)
            i->get()->setMoveStrategy(std::make_shared<Patrol>());
    } else
        hero[0]->update(deltaTime);
    lifeBar.update();
}

void update(std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map &arena, LifeBar &lifeBar) {
    //Update dei Nemici
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
        i->get()->movement(hero[0]->getPosition(), arena);
        i->get()->update(deltaTime);
        if (!(i->get()->isLife()))
            i = enemies.erase(i);
        i++;
    }

    if (hero[0]->isFighting()) {
        auto y = enemies.begin();
        while (y != enemies.end()) {
            if (hero[0]->isLegalFight(**y)) {
                hero[0]->fight(**y);
                break;
            }
            y++;
        }
    }

    //Update dell'Eroe
    if (hero[0]->getHp() <= 0)
        hero[0]->kill();
    if (!hero[0]->isLife()) {
        hero.pop_back();
        for (auto i = enemies.begin(); i != enemies.end(); i++)
            i->get()->setMoveStrategy(std::make_shared<Patrol>());
    } else
        hero[0]->update(deltaTime);
    lifeBar.update();

}
