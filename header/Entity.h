//
// Created by cristian on 31/03/21.
//

#ifndef MAZZARONE_ROSADINI_ENTITY_H
#define MAZZARONE_ROSADINI_ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Animation.h"
#include <iostream>
class Entity: public sf::Drawable, public sf::Transformable {
public:
    explicit Entity(int width = 32, int height = 32, const sf::Time &animTime = sf::milliseconds(60));

    bool load(const std::string &tileSet, sf::Vector2f position);

    virtual void update(float deltaTime);

    void setLife(bool life);


    //Getter and Setter
    void setAnim(int nFrame, float switchTime);

    const sf::Sprite &getSprite() const;

    void setSprite(const sf::Sprite &sprite);

    const sf::Texture &getTileSet() const;

    void setTileSet(const sf::Texture &tileSet);

    const sf::Vector2i &getSource() const;

    void setSourceX(const int x);

    void setSourceY(const int y);

    void setSource(const int x, const int y);

    const Animation &getAnim() const;

    bool isLife() const;

public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void draw(sf::RenderWindow& window);

protected:
    int width, height;
    sf::Sprite sprite;
    sf::Texture tileSet;
    sf::Vector2i source = {0,0};
    bool life;

private:
    Animation anim;
};


#endif //MAZZARONE_ROSADINI_ENTITY_H
