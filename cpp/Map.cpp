//
// Created by cristian on 19/03/21.
//

#include <iostream>
#include "../header/Map.h"
#include "../header/Player1.h"

Map::Map(Player1 *subject, int width, int height) : width(width), height(height), subject(subject) {
    tiles.reserve(width * height);
    tilesShades.reserve(width * height);
}

void Map::load(const std::string &background, const std::string &tileSet, sf::Vector2u tileSize, std::ifstream &matrix,
               std::ifstream &shades) {
    //load background image
    bg.loadFromFile(background);
    // load the tileset texture
    m_tileSet.loadFromFile(tileSet);

    setTilesCode(matrix, tileSize, false);
    setTilesCode(shades, tileSize, true);
}
void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::Sprite background(bg);
    target.draw(background);
    drawTiles(target, true);
    drawTiles(target, false);
}

Tile Map::getTile(sf::Vector2i source) {
    return tiles[source.y * width + source.x];
}

void Map::openExitTile() {

    Tile tile(2, 4, false, tiles[239].getTilePosition());
    tile.load(m_tileSet);
    tiles[239] = tile;

    tile = Tile(2, 5, false, tiles[269].getTilePosition());
    tile.load(m_tileSet);
    tiles[269] = tile;

    tile = Tile(8, 5, true, tiles[299].getTilePosition());
    tile.load(m_tileSet);
    tiles[299] = tile;

    tile = Tile(2, 6, false, tiles[329].getTilePosition());
    tile.load(m_tileSet);
    tiles[329] = tile;

    tile = Tile(2, 7, false, tiles[359].getTilePosition());
    tile.load(m_tileSet);
    tiles[359] = tile;

}

void Map::drawTiles(sf::RenderTarget &target, bool shades) const {
    for (int i = 0; i < width * height; i++) {
        if (shades)
            target.draw(tilesShades[i]);
        else
            target.draw(tiles[i]);
    }
}

void Map::setTilesCode(std::ifstream &matrix, sf::Vector2u tileSize, bool shades) {
    int codeX, codeY;
    bool walkable;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            matrix >> codeX;
            matrix >> codeY;
            walkable = (codeX == 8 &&
                        codeY == 5); //set a tile walkable or not walkable. code=(8,5) corresponds to ground.
            Tile tile(codeX, codeY, walkable, sf::Vector2f((float) (x * tileSize.x), (float) (y * tileSize.y)));
            tile.load(m_tileSet);
            if (shades)
                tilesShades.push_back(tile);
            else
                tiles.push_back(tile);
        }
}
//Observer methods
void Map::detach() {
    subject->unsubscribe(this);
}

void Map::attach() {
    subject->subscribe(this);
}

Map::~Map() {
    detach();
}

void Map::update(int numArena) {
    if (numArena < 2 && subject->getKillCounter() == 20) {
        openExitTile();
    }
}

Tile Map::getTile(int i) {
    return tiles[i];
}