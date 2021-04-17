#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../header/Map.h"
#include "../header/Character.h"
#include "../header/Player1.h"
#include "../header/Enemy.h"
#include "../header/Follow.h"
#include "../header/Patrol.h"
#include "../header/Stay.h"

#include <sstream>
#include <fstream>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "GAME");
    sf::RenderWindow &app = window;
    sf::RenderTexture texture;

    std::ifstream m_matrix("../matrix.txt");
    Map arena;
    if (!arena.load("../sprites/map/background.png", "../sprites/map/map.png", sf::Vector2u(32, 32), m_matrix))
        return -1;
    m_matrix.close();

    Player1 hero;
    if (!hero.Entity::load("../sprites/spaceCadet.png", sf::Vector2f(100, 100)))
        return -1;

    srand(time(NULL));
    Enemy ghoul(std::make_shared<Patrol>());
    if (!ghoul.Entity::load("../sprites/ghoul.png", sf::Vector2f(rand()%450+100, rand()%450+100)))
        return -1;

    //main loop
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e)){
            if (e.type == sf::Event::Closed){
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            hero.movement(0,-1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero.movement(-1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            hero.movement(0,1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.movement(1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            hero.fight(ghoul);
        }

        if(std::abs(hero.getSprite().getPosition().x - ghoul.getSprite().getPosition().x)<=300
            && std::abs(hero.getSprite().getPosition().y - ghoul.getSprite().getPosition().y)<=300)
            ghoul.setMoveStrategy(std::make_shared<Follow>());
        else
            ghoul.setMoveStrategy(std::make_shared<Stay>());

        ghoul.movement(hero.getSprite().getPosition().x, hero.getSprite().getPosition().y);


        window.clear();
        window.draw(arena);
        window.draw(hero);
        window.draw(ghoul);
        window.display();
    }
    return 0;
};
