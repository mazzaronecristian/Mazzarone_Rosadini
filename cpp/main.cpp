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

#include <cmath>
#include <list>
#include <memory>

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::shared_ptr<Player1> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map arena);

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "GAME");
    PlayersFactory factory;
    std::ifstream m_matrix("./matrix.txt");
    Map arena;
    if (!arena.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), m_matrix))
        return -1;
    m_matrix.close();
    std::shared_ptr<Player1> hero = factory.createHero(EntityType::hero);
    srand(time(NULL));
    std::list<std::shared_ptr<Enemy>> enemies;
    for (int i = 0; i < 1; i++) {
        std::shared_ptr<Enemy> ghoul = factory.createEnemy(EntityType::ghoul,
                                                           sf::Vector2f(rand() % 450 + 100, rand() % 450 + 100));
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
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            if (e.type == sf::Event::KeyReleased)
                if (e.key.code == sf::Keyboard::Enter) {
                    short int bulletDirection;
                    if (hero->getSource().y % 2 == 0) {
                        hero->setSourceY(4);
                        bulletDirection = 1;
                    } else {
                        hero->setSourceY(5);
                        bulletDirection = -1;
                    }
                    std::shared_ptr<Bullet> shot = bullFactory.createBullet(EntityType::bullet, hero->getPosition(),
                                                                            bulletDirection);
                    hero->setAnim(8, 0.06);
                    shot->setAnim(3, 0.3);
                    bullets.push_back(shot);
                }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            hero->movement(sf::Vector2f(0, -1), arena);
            hero->setAnim(8, 0.06);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            hero->movement(sf::Vector2f(-1, 0), arena);
            hero->setAnim(8, 0.06);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            hero->movement(sf::Vector2f(0, 1), arena);
            hero->setAnim(8, 0.06);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero->movement(sf::Vector2f(1, 0), arena);
            hero->setAnim(8, 0.06);
        }

        for (auto i = enemies.begin(); i != enemies.end(); i++) {
            if (!i->get()->isFighting()) {
                if (std::abs(hero->getSprite().getPosition().x - i->get()->getSprite().getPosition().x) <= 300
                    && std::abs(hero->getSprite().getPosition().y - i->get()->getSprite().getPosition().y) <= 300) {
                    i->get()->setMoveStrategy(std::make_shared<Follow>());
                    i->get()->setAnim(8, 0.06);
                } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
            } else i->get()->setMoveStrategy(std::make_shared<Patrol>());
        }

        for (auto i = enemies.begin(); i != enemies.end(); i++) {
            if (i->get()->isLegalFight(*hero)) {
                i->get()->fight(*hero);
                i->get()->setAnim(8, 0.06);
            }
        }

        for (auto i = enemies.begin(); i != enemies.end(); i++) {
            if (i->get()->getHp() <= 0)
                i->get()->kill();
        }

        if (hero->getHp() <= 0)
            hero->kill();

        update(bullets, hero, enemies, deltaTime, arena);

        window.clear();
        window.draw(arena);
        window.draw(*hero);
        for (auto i:enemies) {
            window.draw(*i);
        }
        for (auto i:bullets) {
            window.draw(*i);
        }
        window.display();
    }
    return 0;
}

void update(std::list<std::shared_ptr<Bullet>> &bullets, std::shared_ptr<Player1> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, float deltaTime, Map arena) {
    hero->update(deltaTime);
    for (auto i = enemies.begin(); i != enemies.end();) {
        i->get()->movement(hero->getSprite().getPosition(), arena);
        i->get()->update(deltaTime);
        if (!(i->get()->isLife()))
            i = enemies.erase(i);
        i++;
    }

    for (auto i = bullets.begin(); i != bullets.end();) {
        i->get()->movement();
        i->get()->update(deltaTime);
        auto y = enemies.begin();
        while (y != enemies.end()) {
            if (i->get()->isCollide(**y)) {
                hero->fight(**y);
                break;
            }
            y++;
        }
        if (!i->get()->isLife())
            i = bullets.erase(i);
        else i++;
    }
}
