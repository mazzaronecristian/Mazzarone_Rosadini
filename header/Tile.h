//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_TILE_H
#define MAZZARONE_ROSADINI_TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Tile: public sf::Drawable, public sf::Transformable {
public:
    void load(const sf::Texture& tileset, sf::Vector2f position);

    //setter
    void setSprite(const sf::Sprite &sprite);

    void setCodeY(int codeY);

    void setCodeX(int codeX);

    //getter
    const sf::Sprite &getSprite() const;

private:
    int codeX, codeY;
    sf::Texture texture;
    sf::Sprite sprite;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //MAZZARONE_ROSADINI_TILE_H
