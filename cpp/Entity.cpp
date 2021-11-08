//
// Created by cristian on 31/03/21.
//

#include "../header/Entity.h"

Entity::Entity(sf::Vector2i dimension, const sf::Time &animTime) : anim(dimension),
                                                                   Elements(dimension.x, dimension.y) {
    life = true;
}

void Entity::update(float deltaTime) {
    anim.update(source, deltaTime);
    anim.applyToSprite(sprite);
}

bool Entity::isLife() const {
    return life;
}

//Getter and Setter

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

Entity::~Entity() {
}

void Entity::load(const std::string &tileSet, sf::Vector2f position) {
    Elements::load(tileSet, position);
    if (height == 64)
        sprite.setOrigin((float) width / 2, (float) height / 2);
}





