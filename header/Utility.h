//
// Created by Gianluca Rosadini on 23/12/21.
//

#ifndef MAZZARONE_ROSADINI_UTILITY_H
#define MAZZARONE_ROSADINI_UTILITY_H

#endif //MAZZARONE_ROSADINI_UTILITY_H

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

void generateBarrels(std::list<std::shared_ptr<Barrel>> &barrels, const Map &arena);

void newPotion(std::list<std::shared_ptr<Potion>> &potions, Barrel &barrel);

sf::Vector2f rightPosition(Map arena);

void
heroAction(std::vector<std::shared_ptr<Player1>> hero, const Map &arena, std::list<std::shared_ptr<Potion>> &potions);

void enemiesMovement(std::vector<std::shared_ptr<Player1>> hero, std::list<std::shared_ptr<Enemy>> &enemies);

void generateEnemies(std::list<std::shared_ptr<Enemy>> &enemies, short int waveCounter,
                     const Map &arena); //generates waves of enemies

void generateBoss(std::list<std::shared_ptr<Boss>> &boss, std::list<std::shared_ptr<LifeBar>> &lifeBar);


void update(std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
            std::list<std::shared_ptr<Enemy>> &enemies, std::list<std::shared_ptr<Boss>> &boss, float deltaTime,
            Map &arena, std::list<std::shared_ptr<LifeBar>> &lifeBars, std::list<std::shared_ptr<Barrel>> &barrels,
            std::list<std::shared_ptr<Potion>> &potions, int numArena);

void draw(const std::list<std::shared_ptr<Bullet>> &bullets, std::vector<std::shared_ptr<Player1>> hero,
          const std::list<std::shared_ptr<Enemy>> &enemies, sf::RenderWindow &window, sf::RenderTexture &gameOver,
          Map &arena,
          const std::list<std::shared_ptr<LifeBar>> &lifeBars, const std::list<std::shared_ptr<Boss>> &boss,
          const std::list<std::shared_ptr<Barrel>> &barrels, const std::list<std::shared_ptr<Potion>> &potions);

bool checkRestart(sf::RenderWindow &window, std::vector<std::shared_ptr<Player1>> hero,
                  const std::list<std::shared_ptr<Boss>> &boss, short int &numArena, bool &finish);