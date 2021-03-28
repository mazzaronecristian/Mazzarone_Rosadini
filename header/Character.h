//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Character: public sf::Drawable, public sf::Transformable {
public:
    explicit Character(int hp = 10, int damage = 5,sf::Time AnimTime = sf::milliseconds(60), float speed = 0.3, int sizeX = 32, int sizeY = 32);

    bool load(const std::string &tileSet, sf::Vector2f position);

    void movement(sf::Vector2f direction);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool isLegalMove(sf::Vector2f point);

    //virtual void specialAction();

    void receiveDamage(int damage);

    //getter
    int getHp() const;

    int getDamage() const;

    //setter
    void setHp(int hp);

    void setDamage(int damage);


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture tileSet;
    int hp, damage;
    float speed;
    enum action{stay, right, left, fight, die};
    sf::Vector2i source;
    sf::Sprite sprite;
    sf::Clock AnimClock; //Player Animation Clock
    sf::Time AnimTime; //Player Animation Time
};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
