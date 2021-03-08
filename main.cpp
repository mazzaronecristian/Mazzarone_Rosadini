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
int main()
{
    Character* hero;
    hero = new Player1();
    hero->setActionStrategy(SpaceCadet());
    return 0;
}