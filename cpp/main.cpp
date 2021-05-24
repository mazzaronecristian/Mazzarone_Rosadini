
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
#include "../header/Bullet.h"

#include <cmath>
#include <list>

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
    std::list<Bullet>bullet;


    //main loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event e;
        while (window.pollEvent(e)){
            if (e.type == sf::Event::Closed){
                window.close();
            }
            if(e.type==sf::Event::KeyReleased)
                if(e.key.code==sf::Keyboard::Enter) {
                    short int bulletDirection;
                    if (hero.getSource().y % 2 == 0) {
                        hero.setSourceY(4);
                        bulletDirection = 1;
                    }else {
                        hero.setSourceY(5);
                        bulletDirection = -1;
                    }
                    Bullet *shot=new Bullet(bulletDirection);
                    if (!shot->Entity::load("../tileSets/bullet.png", sf::Vector2f(hero.getSprite().getPosition().x+(16 * (float)bulletDirection), hero.getSprite().getPosition().y)))
                        return -1;
                    hero.anim.setNFrame(8);
                    hero.anim.setSwitchTime(0.06);
                    shot->anim.setNFrame(3);
                    shot->anim.setSwitchTime(0.3);
                    bullet.push_back(*shot);
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

        if(std::abs(hero.getSprite().getPosition().x - ghoul.getSprite().getPosition().x)<=300
            && std::abs(hero.getSprite().getPosition().y - ghoul.getSprite().getPosition().y)<=300){
            ghoul.setMoveStrategy(std::make_shared<Follow>());
            ghoul.anim.setNFrame(8);
            ghoul.anim.setSwitchTime(0.06);
        }
        else
            ghoul.setMoveStrategy(std::make_shared<Stay>());

        ghoul.movement(hero.getSprite().getPosition().x, hero.getSprite().getPosition().y);

        hero.update(deltaTime);
        ghoul.update(deltaTime);

        for(auto i=bullet.begin(); i!=bullet.end(); ){
            Bullet b= *i;
            i->movement();
            i->update(deltaTime);
            if(!i->isLife())
                i = bullet.erase(i);
            else
                i++;
        }

        window.clear();
        window.draw(arena);
        window.draw(hero);
        window.draw(ghoul);

        //Bullet b = *bullet.begin();
        //window.draw(b);

        for(auto i:bullet){
            window.draw(i);
        }
        window.display();
}
    return 0;
};
