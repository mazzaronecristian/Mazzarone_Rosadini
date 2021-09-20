//
// Created by cristian on 19/03/21.
//

#include "../header/Map.h"

Map::Map(int width, int height) : width(width), height(height) {
    tiles.reserve(width * height);
}

void
Map::load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream &matrix) {
    //load background image
    bg.loadFromFile(background);
    // load the tileset texture
    m_tileset.loadFromFile(tileSet);

    int codeX, codeY;
    bool walkable;

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            matrix >> codeX;
            matrix >> codeY;
            if (codeX == 8 && codeY == 5) {
                walkable = true;
            } else walkable = false;
            Tile tile(codeX, codeY, walkable, sf::Vector2f(x * 32, y * 32));
            tile.load(m_tileset);
            tiles.push_back(tile);
        }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Sprite background(bg);
    target.draw(background);

    for (int i = 0; i < width * height; i++)
        target.draw(tiles[i]);

}

Tile Map::getTile(sf::Vector2i source) {
    return tiles[source.y * width + source.x];
}




