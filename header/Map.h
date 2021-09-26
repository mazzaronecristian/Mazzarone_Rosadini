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
#include <memory>
#include "Tile.h"

class Map : public sf::Drawable, public sf::Transformable {
public:
    explicit Map(int width = 30, int height = 20);

    void load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream &matrix);

    void load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream &matrix,
              std::ifstream &matrix1);


    Tile getTile(sf::Vector2i source);

    void openExitTile();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    int width, height;
    sf::Texture bg;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    std::vector<Tile> tiles;
    std::vector<Tile> tilesRiver;
};

#endif //MAZZARONE_ROSADINI_MAP_H
