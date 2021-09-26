//
// Created by cristian on 19/03/21.
//

#include <iostream>
#include "../header/Map.h"

Map::Map(int width, int height) : width(width), height(height) {
    tiles.reserve(width * height);
    tilesRiver.reserve(width * height);
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
            walkable = (codeX == 8 &&
                        codeY == 5); //set a tile walkable or not walkable. code=(8,5) corresponds to ground.
            Tile tile(codeX, codeY, walkable, sf::Vector2f(x * tileSize.x, y * tileSize.y));
            tile.load(m_tileset);
            tiles.push_back(tile);
        }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Sprite background(bg);
    target.draw(background);

    for (int i = 0; i < width * height; i++)
        target.draw(tilesRiver[i]);

    for (int i = 0; i < width * height; i++)
        target.draw(tiles[i]);

}

Tile Map::getTile(sf::Vector2i source) {
    return tiles[source.y * width + source.x];
}

void Map::openExitTile() {

    Tile tile(2, 4, false, tiles[239].getTilePosition());
    tile.load(m_tileset);
    tiles[239] = tile;

    tile = Tile(2, 5, false, tiles[269].getTilePosition());
    tile.load(m_tileset);
    tiles[269] = tile;

    tile = Tile(8, 5, true, tiles[299].getTilePosition());
    tile.load(m_tileset);
    tiles[299] = tile;

    tile = Tile(2, 6, false, tiles[329].getTilePosition());
    tile.load(m_tileset);
    tiles[329] = tile;

    tile = Tile(2, 7, false, tiles[359].getTilePosition());
    tile.load(m_tileset);
    tiles[359] = tile;

}

void Map::load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream &matrix,
               std::ifstream &matrix1) {
    //load background image
    bg.loadFromFile(background);
    // load the tileset texture
    m_tileset.loadFromFile(tileSet);

    int codeX, codeY;
    bool walkable;

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            matrix1 >> codeX;
            matrix1 >> codeY;
            walkable = (codeX == 8 &&
                        codeY == 5); //set a tile walkable or not walkable. code=(8,5) corresponds to ground.
            Tile tile(codeX, codeY, walkable, sf::Vector2f(x * tileSize.x, y * tileSize.y));
            tile.load(m_tileset);
            tilesRiver.push_back(tile);
        }

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            matrix >> codeX;
            matrix >> codeY;
            walkable = (codeX == 8 &&
                        codeY == 5); //set a tile walkable or not walkable. code=(8,5) corresponds to ground.
            Tile tile(codeX, codeY, walkable, sf::Vector2f(x * tileSize.x, y * tileSize.y));
            tile.load(m_tileset);
            tiles.push_back(tile);
        }

}




