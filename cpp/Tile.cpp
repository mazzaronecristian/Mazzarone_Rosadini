//
// Created by cristian on 02/03/21.
//

#include "../header/Tile.h"

Tile::Tile(const Sprite &sprite) : sprite(sprite) {}

Tile::~Tile() {

}

const Sprite &Tile::getSprite() const {
    return sprite;
}

void Tile::setSprite(const Sprite &sprite) {
    Tile::sprite = sprite;
}
