//
// Created by cristian on 31/03/21.
//

#include "../header/Entity.h"

Entity::Entity(int width, int height, const sf::Time &animTime) : width(width), height(height),
                                                                  anim(sf::Vector2i(width, height)) {
    life = true;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

bool Entity::load(const std::string &tileSet, sf::Vector2f position) {
    if (!Entity::tileSet.loadFromFile(tileSet))
        return false;
    sprite.setTexture(Entity::tileSet);
    //sprite.setColor(sf::Color(255,0,0));
    sprite.setPosition(position);
    sprite.scale(1.4, 1.4);
    sprite.setTextureRect(sf::IntRect(source.x * width, source.y * height, width, height));
    return true;
}

//Getter and Setter
void Entity::setTileSet(const sf::Texture &tileSet) {
    Entity::tileSet = tileSet;
}

const sf::Vector2i &Entity::getSource() const {
    return source;
}

const sf::Sprite &Entity::getSprite() const {
    return sprite;
}

void Entity::setSourceY(const int y) {
    Entity::source.y = y;
}

void Entity::update(float deltaTime) {
    anim.update(source, deltaTime);
    anim.applyToSprite(sprite);
}

bool Entity::isLife() const {
    return life;
}

void Entity::setAnim(int nFrame, float switchTime) {
    anim.setNFrame(nFrame);
    anim.setSwitchTime(switchTime);
}

void Entity::setAnim(int nFrame, float switchTime, int action) {
    if (source.y != action) {
        source.x = 0;
    }
    source.y = action;
    anim.setNFrame(nFrame);
    anim.setSwitchTime(switchTime);
}

sf::Vector2f Entity::getPosition() {
    return sprite.getPosition();
}




