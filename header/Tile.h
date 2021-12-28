//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_TILE_H
#define MAZZARONE_ROSADINI_TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Tile : public sf::Drawable, public sf::Transformable {
public:
    Tile(int codeX, int codeY, bool walkable, sf::Vector2f position);

    void load(const sf::Texture &tileSet);

    sf::Sprite &getSprite();

    bool isWalkable() const;

    const sf::Vector2f &getTilePosition() const;

    int getCodeX() const;

    int getCodeY() const;

private:
    sf::Vector2f position;
    bool walkable;
    int codeX, codeY;
    sf::Sprite sprite;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //MAZZARONE_ROSADINI_TILE_H
