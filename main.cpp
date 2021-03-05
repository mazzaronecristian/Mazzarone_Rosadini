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
int main()
{
    Player1 gino = Player1();
    Potion heal = Potion();
    heal.setUseStrategy(HealUse());
    heal.use(heal.getUseStrategy());

    return 0;
}