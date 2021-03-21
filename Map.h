//
// Created by cristian on 19/03/21.
//

#ifndef WORKBANCH_MAP_H
#define WORKBANCH_MAP_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Map: public sf::Drawable, public sf::Transformable{
public:

    bool load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);


private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture bg;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif //WORKBANCH_MAP_H
