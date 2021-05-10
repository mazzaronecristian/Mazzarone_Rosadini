//
// Created by cristian on 31/03/21.
//

#include "../header/Entity.h"

Entity::Entity(const sf::Time &animTime) {}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

bool Entity::load(const std::string &tileSet, sf::Vector2f position) {
    if(!Entity::tileSet.loadFromFile(tileSet))
        return false;
    sprite.setTexture(Entity::tileSet);
    //sprite.setColor(sf::Color(255,0,0));
    sprite.setPosition(position);
    sprite.scale(1.4, 1.4);
    sprite.setTextureRect(sf::IntRect (source.x * 32, source.y * 32, 32, 32));
    return true;
}

//Getter and Setter
const sf::Texture &Entity::getTileSet() const {
    return tileSet;
}

void Entity::setTileSet(const sf::Texture &tileSet) {
    Entity::tileSet = tileSet;
}

const sf::Vector2i &Entity::getSource() const {
    return source;
}

void Entity::setSource(const int x, const int y) {
    Entity::source.x = x;
    Entity::source.y = y;

}

const sf::Sprite &Entity::getSprite() const {
    return sprite;
}

void Entity::setSprite(const sf::Sprite &sprite) {
    Entity::sprite = sprite;
}

void Entity::setSourceX(const int x) {
    Entity::source.x = x;
}

void Entity::setSourceY(const int y) {
    Entity::source.y = y;
}


