//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_TILE_H
#define MAZZARONE_ROSADINI_TILE_H

#include "iostream"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum class WalkableTiles {
    groundX = 8,
    groundY = 5
};

enum class ShootableTiles {
    groundX = 8,
    groundY = 5,

    //W is water
    W1X = 10,
    W1Y = 8,

    W2X = 11,
    W2Y = 8,

    W3X = 10,
    W3Y = 9,

    W4X = 11,
    W4Y = 9
};

class Tile : public sf::Drawable, public sf::Transformable {
public:
    Tile(int codeX, int codeY, bool walkable, sf::Vector2f position);

    void load(const sf::Texture &tileset);

    sf::Sprite &getSprite();

    bool isWalkable() const;

    const sf::Vector2f &getTilePosition() const;

private:
    sf::Vector2f position;
    bool walkable;
    int codeX, codeY;
    sf::Sprite sprite;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //MAZZARONE_ROSADINI_TILE_H
