//
// Created by cristian on 31/03/21.
//

#include "../header/Entity.h"

Entity::Entity(int width, int height, const sf::Time &animTime) : anim(sf::Vector2i(width, height)),
                                                                  Elements(width, height) {
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





