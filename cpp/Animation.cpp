//
// Created by cristian on 02/05/21.
//

#include "../header/Animation.h"

Animation::Animation(int nFrame, float switchTime): nFrame(nFrame), switchTime(switchTime) {
}

void Animation::update(sf::Vector2i &source, float deltaTime) {
    animTime += deltaTime;
    if (animTime >= switchTime) {
        animTime -= switchTime;
        source.x++;
        if (source.x >= nFrame){
            if (source.y%2 == 0)
                source = {0,0};
            else
                source = {0,1};
        }
        rect.left = source.x*rect.width;
        rect.top = source.y*rect.height;
    }
}

void Animation::applyToSprite(sf::Sprite &sprite) {
    sprite.setTextureRect(rect);
}

void Animation::setNFrame(int nFrame) {
    Animation::nFrame = nFrame;
}

void Animation::setAnimTime(float animTime) {
    Animation::animTime = animTime;
}

void Animation::setSwitchTime(float switchTime) {
    Animation::switchTime = switchTime;
}



