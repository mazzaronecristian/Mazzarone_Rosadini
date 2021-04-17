//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_TILE_H
#define MAZZARONE_ROSADINI_TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Tile {
public:

    Tile();
    virtual ~Tile();

private:
    sf::VertexArray vertice;
    sf::Texture texture;
};


#endif //MAZZARONE_ROSADINI_TILE_H
