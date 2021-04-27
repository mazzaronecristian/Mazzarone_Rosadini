//
// Created by cristian on 02/03/21.
//

#include "../header/Tile.h"


void Tile::load(const sf::Texture &tileset, sf::Vector2f position) {
    sprite.setTexture(tileset);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (codeX*32,codeY*32,32,32));

}

void Tile::setSprite(const sf::Sprite &sprite) {
    Tile::sprite = sprite;
}

void Tile::setCodeY(int codeY) {
    Tile::codeY = codeY;
}

void Tile::setCodeX(int codeX) {
    Tile::codeX = codeX;
}

const sf::Sprite &Tile::getSprite() const {
    return sprite;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}
