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
#include "../header/Bullet.h"

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
    Animation animationBullet;
    std::vector<Bullet>bullet;

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
            hero.anim.setNFrame(8);
            hero.anim.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero.movement(-1,0);
            hero.anim.setNFrame(8);
            hero.anim.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            hero.movement(0,1);
            hero.anim.setNFrame(8);
            hero.anim.setSwitchTime(0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.movement(1,0);
            hero.anim.setNFrame(8);
            hero.anim.setSwitchTime(0.06);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            bool bulletDirection;
            if (hero.getSource().y % 2 == 0) {
                hero.setSourceY(4);
                bulletDirection=true;
            }else {
                hero.setSourceY(5);
                bulletDirection=false;
            }
            Bullet shot(bulletDirection);
            if (!shot.Entity::load("../tileSets/bullet.png", hero.getSprite().getPosition()))
                return -1;
            hero.anim.setNFrame(8);
            hero.anim.setSwitchTime(0.06);
            animationBullet.setNFrame(3);
            animationBullet.setSwitchTime(6);
            //animationBullet.update(const_cast<sf::Vector2i &>(shot.getSource()),deltaTime);
            //animationBullet.applyToSprite(const_cast<sf::Sprite &>(shot.getSprite()));
            bullet.push_back(shot);
            }

        if(std::abs(hero.getSprite().getPosition().x - ghoul.getSprite().getPosition().x)<=300
            && std::abs(hero.getSprite().getPosition().y - ghoul.getSprite().getPosition().y)<=300){
            ghoul.setMoveStrategy(std::make_shared<Follow>());
            ghoul.anim.setNFrame(8);
            ghoul.anim.setSwitchTime(0.06);
        }
        else
            ghoul.setMoveStrategy(std::make_shared<Stay>());

        ghoul.movement(hero.getSprite().getPosition().x, hero.getSprite().getPosition().y);

        hero.anim.update(const_cast<sf::Vector2i &>(hero.getSource()), deltaTime);
        hero.anim.applyToSprite(const_cast<sf::Sprite &>(hero.getSprite()));

        ghoul.anim.update(const_cast<sf::Vector2i &>(ghoul.getSource()), deltaTime);
        ghoul.anim.applyToSprite(const_cast<sf::Sprite &>(ghoul.getSprite()));

        for(auto i=bullet.begin(); i!=bullet.end(); i++){
            i->movement();
            i->update(deltaTime);
            if(!i->isLife()){
                Bullet b = bullet.pop_back(i);
            }
        }
        window.clear();
        window.draw(arena);
        window.draw(hero);
        window.draw(ghoul);
        for(auto i:bullet)
            window.draw(i);
        window.display();
}
    return 0;
};
