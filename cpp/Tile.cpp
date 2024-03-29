//
// Created by cristian on 02/03/21.
//

#include "../header/Tile.h"

Tile::Tile(int codeX, int codeY, bool walkable, sf::Vector2f position) : codeX(codeX), codeY(codeY), walkable(walkable),
                                                                         position(position) {
}

void Tile::load(const sf::Texture &tileSet) {
    sprite.setTexture(tileSet);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(codeX * 32, codeY * 32, 32, 32));
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

sf::Sprite &Tile::getSprite() {
    return sprite;
}

bool Tile::isWalkable() const {
    return walkable;
}

const sf::Vector2f &Tile::getTilePosition() const {
    return position;
}

int Tile::getCodeX() const {
    return codeX;
}

int Tile::getCodeY() const {
    return codeY;
}


