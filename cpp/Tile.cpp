//
// Created by cristian on 02/03/21.
//

#include "../header/Tile.h"

Tile::Tile(int codeX, int codeY) : codeX(codeX), codeY(codeY){}

void Tile::load(const sf::Texture &tileset, sf::Vector2f position) {
    sprite.setTexture(tileset);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (codeX*32,codeY*32,32,32));
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

const sf::Sprite &Tile::getSprite() const {
    return sprite;
}
