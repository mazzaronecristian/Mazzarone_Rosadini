#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Character.h"
#include "Player1.h"
#include "Map.h"
#include "Tile.h"
#include "Potion.h"
#include "UseStrategy.h"
#include "HealUse.h"
#include "SpaceCadet.h"
#include "Enemy.h"

int main()
{
    Character* hero;
    Enemy* enemy;
    enemy = new Enemy();
    hero = new Player1();
    hero->setActionStrategy(SpaceCadet());
    hero->specialAction();
    enemy->fight(hero);

    return 0;
}