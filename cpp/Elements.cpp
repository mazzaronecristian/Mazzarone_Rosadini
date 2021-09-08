//
// Created by Gianluca Rosadini on 03/08/21.
//

#include "../header/Elements.h"

Elements::~Elements() {
}

Elements::Elements(int width, int height) : width(width), height(height) {
}

bool Elements::load(const std::string &tileSet, sf::Vector2f position) {
    if (!Elements::tileSet.loadFromFile(tileSet))
        return false;
    sprite.setTexture(Elements::tileSet);
    sprite.setPosition(position);
    sprite.scale(1.4, 1.4);
    sprite.setTextureRect(sf::IntRect(source.x * width, source.y * height, width, height));
    return true;
}

void Elements::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Elements::setTileSet(const sf::Texture &tileSet) {
    Elements::tileSet = tileSet;
}

const sf::Vector2i &Elements::getSource() const {
    return source;
}

const sf::Sprite &Elements::getSprite() const {
    return sprite;
}

void Elements::setSourceY(const int y) {
    Elements::source.y = y;
}

void Elements::setSourceX(const int x) {
    Elements::source.x = x;
}


