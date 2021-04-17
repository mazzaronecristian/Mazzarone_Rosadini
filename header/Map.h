//
// Created by cristian on 19/03/21.
//

#ifndef MAZZARONE_ROSADINI_MAP_H
#define MAZZARONE_ROSADINI_MAP_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <sstream>
#include <fstream>
#include "Tile.h"

class Map: public sf::Drawable, public sf::Transformable{
public:
    explicit Map(int width = 30, int height = 20);
    bool load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream& tile);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int width, height;
    int *level;
    std::vector<std::unique_ptr<Tile>> tiles;
    sf::Texture bg;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif //MAZZARONE_ROSADINI_MAP_H
