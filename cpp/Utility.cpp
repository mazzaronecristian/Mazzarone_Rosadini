//
// Created by cristian on 29/12/21.
//

#include "../header/Utility.h"

void generateBarrels(std::list<std::shared_ptr<Barrel>> &barrels, const Map &arena) {
    PotionType T[3] = {PotionType::regular, PotionType::super, PotionType::max};
    for (int i = 0; i < 3; i++) {
        sf::Vector2f position = rightPosition(arena);
        std::shared_ptr<Barrel> barrel = (std::make_shared<Barrel>(
                ObjectsFactory::createBarrel(T[random() % 3], position)));
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
        std::shared_ptr<Potion> potion;
        potion = std::make_shared<Potion>(ObjectsFactory::createPotion(type, barrel.getPosition()));
        potions.push_back(potion);
    }
}

sf::Vector2f rightPosition(Map arena) {
    bool legalPosition = false;
    sf::Vector2f position;
    while (!legalPosition) {
        position = {(float) (random() % 450 + 300), (float) (random() % 450 + 100)};
        sf::Vector2i source = {(int) std::round(position.x / 32), (int) std::round(position.y / 32)};
        Tile tile = arena.getTile(source);
        if (tile.isWalkable())
            legalPosition = true;
    }
    return position;
}

void
heroAction(std::vector<std::shared_ptr<Player1>> hero, const Map &arena, std::list<std::shared_ptr<Potion>> &potions) {
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
}

void enemiesMovement(std::vector<std::shared_ptr<Player1>> hero, std::list<std::shared_ptr<Enemy>> &enemies) {
    for (auto &enemy: enemies) {
        if (std::abs(hero[0]->getPosition().x - enemy->getPosition().x) <= 300
            && std::abs(hero[0]->getPosition().y - enemy->getPosition().y) <= 300) {
            enemy->setMoveStrategy(std::make_shared<Follow>());
        } else enemy->setMoveStrategy(std::make_shared<Patrol>());
    }
}

void generateBoss(std::list<std::shared_ptr<Boss>> &boss, std::list<std::shared_ptr<LifeBar>> &lifeBars) {
    PlayersFactory factory;
    std::shared_ptr<Boss> b;
    b = std::make_shared<Boss>(factory.createBoss(CharacterType::cyclops));
    boss.push_back(b);
    for (auto &bos: boss) {
        bos->setMoveStrategy(std::make_shared<Follow>());
        std::shared_ptr<LifeBar> lifeBar = std::make_shared<LifeBar>(
                UserInterfaceFactory::createLifeBar(bos.get(), sf::Vector2f(600, 680), LifeBarType::cyclops));
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
    for (auto bos = boss.begin(); bos != boss.end(); bos++)
        finish = !bos->get()->isLife();
    if (finish)
        window.close();
    return restart;
}