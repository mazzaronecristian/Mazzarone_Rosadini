//
// Created by cristian on 31/03/21.
//

#ifndef MAZZARONE_ROSADINI_ENTITY_H
#define MAZZARONE_ROSADINI_ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Entity: public sf::Drawable, public sf::Transformable {
public:
    explicit Entity(const sf::Time &animTime = sf::milliseconds(60), int sizeX = 1, int sizeY=0);

    bool load(const std::string &tileSet, sf::Vector2f position);

    void doAnimation();

    //Getter and Setter
    const sf::Texture &getTileSet() const;

    void setTileSet(const sf::Texture &tileSet);

    const sf::Vector2i &getSource() const;

    void setSourceX(const int x);

    void setSourceY(const int y);
    void setSource(const int x, const int y);

    const sf::Sprite &getSprite() const;

    void setSprite(const sf::Sprite &sprite);

    const sf::Clock &getAnimClock() const;

    void setAnimClock(const sf::Clock &animClock);

    const sf::Time &getAnimTime() const;

    void setAnimTime(const sf::Time &animTime);

protected:
    sf::Time AnimTime; //Player Animation Time
    sf::Texture tileSet;
    sf::Vector2i source;
    sf::Sprite sprite;
    sf::Clock AnimClock; //Player Animation Clock

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //MAZZARONE_ROSADINI_ENTITY_H
