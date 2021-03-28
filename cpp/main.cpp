#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "../header/Map.h"
#include "../header/Character.h"
#include "../header/Player1.h"

#include <sstream>
#include<fstream>

int main() {
    sf::RenderWindow window(sf::VideoMode(960,640), "GAME");
    sf::RenderWindow &app = window;
    sf::RenderTexture texture;

    std::ifstream matrix("../matrix.txt");
    Map arena;
    if(!arena.load("../images/Map/background.png","../images/Map/map.png",
                   sf::Vector2u(32, 32),matrix ))
        return -1;
    matrix.close();

    Player1 hero;
    if (!hero.load("../images/spaceCadet.png", sf::Vector2f(100, 100)))
        return -1;

    //main loop
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            hero.moveUp();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero.moveLeft();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            hero.moveDown();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.moveRight();
        }
        window.clear();
        window.draw(arena);
        window.draw(hero);
        window.display();
    }
    return 0;
};
