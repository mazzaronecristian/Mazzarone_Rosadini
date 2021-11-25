//
// Created by Gianluca Rosadini on 03/08/21.
//

#ifndef MAZZARONE_ROSADINI_ELEMENTS_H
#define MAZZARONE_ROSADINI_ELEMENTS_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Elements : public sf::Drawable, public sf::Transformable {
public:
    Elements(int width, int height);

    ~Elements() override = 0;

    virtual void load(const std::string &tiles, sf::Vector2f position);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    //Getter&Setter

    const sf::Sprite &getSprite() const;

    void setTileSet(const sf::Texture &tiles);

    const sf::Vector2i &getSource() const;

    void setSourceY(int y);

    void setSourceX(int x);

protected:
    int width, height;
    sf::Sprite sprite;
    sf::Texture tileSet;
    sf::Vector2i source = {0, 0};
};


#endif //MAZZARONE_ROSADINI_ELEMENTS_H
