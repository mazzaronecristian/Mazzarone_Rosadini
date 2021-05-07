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
#include "../header/Animation.h"

#include <sstream>
#include <fstream>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "GAME");
    sf::RenderWindow &app = window;

    std::ifstream m_matrix("../matrix.txt");
    Map arena;
    if (!arena.load("../tileSets/map/background.png", "../tileSets/map/map.png", sf::Vector2u(32, 32), m_matrix))
        return -1;
    m_matrix.close();

    Player1 hero;
    if (!hero.Entity::load("../tileSets/spaceCadet.png", sf::Vector2f(100, 100)))
        return -1;

    srand(time(NULL));
    Enemy ghoul(std::make_shared<Patrol>());
    if (!ghoul.Entity::load("../tileSets/ghoul.png", sf::Vector2f(rand()%450+100, rand()%450+100)))
        return -1;
    sf::Clock clock;
    float deltaTime;
    Animation animationHero;
    Animation animationGhoul;

    //main loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event e;
        while (window.pollEvent(e)){
            if (e.type == sf::Event::Closed){
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            hero.movement(0,-1);
            animationHero.setNFrame(8);
            animationHero.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero.movement(-1,0);
            animationHero.setNFrame(8);
            animationHero.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            hero.movement(0,1);
            animationHero.setNFrame(8);
            animationHero.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.movement(1,0);
            animationHero.setNFrame(8);
            animationHero.setSwitchTime(0.06);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (hero.getSource().y % 2 == 0)
                hero.setSourceY(4);
            else
                hero.setSourceY(5);
            animationHero.setNFrame(6);
            animationHero.setSwitchTime(0.06);
        }

        if(std::abs(hero.getSprite().getPosition().x - ghoul.getSprite().getPosition().x)<=300
            && std::abs(hero.getSprite().getPosition().y - ghoul.getSprite().getPosition().y)<=300){
            ghoul.setMoveStrategy(std::make_shared<Follow>());
            animationGhoul.setNFrame(8);
            animationGhoul.setSwitchTime(0.06);
        }
        else
            ghoul.setMoveStrategy(std::make_shared<Stay>());

        ghoul.movement(hero.getSprite().getPosition().x, hero.getSprite().getPosition().y);

        animationHero.update(const_cast<sf::Vector2i &>(hero.getSource()), deltaTime);
        animationHero.applyToSprite(const_cast<sf::Sprite &>(hero.getSprite()));

        animationGhoul.update(const_cast<sf::Vector2i &>(ghoul.getSource()), deltaTime);
        animationGhoul.applyToSprite(const_cast<sf::Sprite &>(ghoul.getSprite()));

        window.clear();
        window.draw(arena);
        window.draw(hero);
        window.draw(ghoul);
        window.display();
    }
    return 0;
};
