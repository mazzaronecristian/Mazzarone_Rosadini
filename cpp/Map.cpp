//
// Created by cristian on 19/03/21.
//

#include "../header/Map.h"

Map::Map(int width, int height) : width(width), height(height){
    tiles.reserve(width*height);
}


bool Map::load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream& matrix) {
    //load background image
    if(!bg.loadFromFile(background))
        return false;
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileSet))
        return false;

    int codeX, codeY;
    Tile tile;
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++){
            matrix>>codeX;
            matrix>>codeY;
            tile.setCodeX(codeX);
            tile.setCodeY(codeY);
            tile.load(m_tileset, sf::Vector2f(x * 32,y * 32));
            tiles.push_back(tile);
        }
    return true;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Sprite background(bg);
    target.draw(background);

    for(int i = 0; i<width*height; i++)
        target.draw(tiles[i]);

}


