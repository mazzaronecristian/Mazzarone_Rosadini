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
#include "../header/RangedAttack.h"

#include <cmath>
#include <list>
#include "memory"
void update(std::list<std::shared_ptr<Bullet>> &bullets, Player1 &hero, std::list<Enemy>  &enemies, float deltaTime);

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "GAME");
    sf::RenderWindow &app = window;

    std::ifstream m_matrix("../matrix.txt");
    Map arena;
    if (!arena.load("../tileSets/map/background.png", "../tileSets/map/map.png", sf::Vector2u(32, 32), m_matrix))
        return -1;
    m_matrix.close();
    Player1 hero(std::make_shared<RangedAttack>());
    if (!hero.Entity::load("../tileSets/spaceCadet.png", sf::Vector2f(100, 100)))
        return -1;

    srand(time(NULL));
    std::list<Enemy> enemies;
    for(int i = 0; i<10; i++){
        Enemy ghoul(std::make_shared<Patrol>());
        if (!ghoul.Entity::load("../tileSets/ghoul.png", sf::Vector2f(rand()%450+100, rand()%450+100)))
            return -1;
        enemies.push_back(ghoul);
    }

    sf::Clock clock;
    float deltaTime;
    std::list<std::shared_ptr<Bullet>>bullets;

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
                    std::shared_ptr<Bullet> shot(new Bullet(bulletDirection));
                    if (!shot->Entity::load("../tileSets/bullet.png", sf::Vector2f(hero.getSprite().getPosition().x+(16*(float)bulletDirection), hero.getSprite().getPosition().y+16)))
                        return -1;
                    hero.setAnim(8,0.06);
                    shot->setAnim(3,0.3);
                    bullets.push_back(shot);
                }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            hero.movement(sf::Vector2f (0,-1));
            hero.setAnim(8,0.06);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero.movement(sf::Vector2f (-1,0));
            hero.setAnim(8,0.06);

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            hero.movement(sf::Vector2f (0,1));
            hero.setAnim(8,0.06);

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.movement(sf::Vector2f (1,0));
            hero.setAnim(8,0.06);

        }
        for(auto i=enemies.begin(); i!=enemies.end(); i++){
            if(i->isLife()){
                if(std::abs(hero.getSprite().getPosition().x - i->getSprite().getPosition().x)<=300
                   && std::abs(hero.getSprite().getPosition().y - i->getSprite().getPosition().y)<=300){
                    i->setMoveStrategy(std::make_shared<Follow>());
                    i->setAnim(8,0.06);
                }
                else
                    i->setMoveStrategy(std::make_shared<Stay>());
            }
        }

        update(bullets, hero, enemies, deltaTime);

        window.clear();
        window.draw(arena);
        window.draw(hero);
        for(auto i:enemies) {
            window.draw(i);
        }
        for(auto i:bullets){
            window.draw(*i);
        }
        window.display();
}
    return 0;
};

void update( std::list<std::shared_ptr<Bullet>> &bullets, Player1 &hero, std::list<Enemy> &enemies, float deltaTime){
    hero.update(deltaTime);
    for(auto i=enemies.begin(); i!=enemies.end(); ){
        i->movement(hero.getSprite().getPosition());
        i->update(deltaTime);
        if(!(i->isLife())){
            i = enemies.erase(i);//TODO animazione della morte
        }
        i++;
    }

    for(auto i=bullets.begin(); i!=bullets.end(); ){
        i->get()->movement();
        i->get()->update(deltaTime);
        auto y = enemies.begin();
        while(y!=enemies.end()){
            if(i->get()->isCollide(*y)){
                hero.fight(*y);
                break;
            }
            y++;
        }
        if(!i->get()->isLife())
            i = bullets.erase(i);
        else i++;
    }
}
