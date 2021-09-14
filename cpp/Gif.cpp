//
// Created by Gianluca Rosadini on 14/09/21.
//

#include "../header/Gif.h"

void Gif::update(float deltaTime) {
    /*source.x ++;
    if(source.x ==15)
        source.x = 0;
    sprite.setTextureRect(sf::IntRect(source.x * width, source.y * height, width, height));*/
}

Gif::Gif() : Entity() {

    setAnim(16, 0.06);
    sprite.setScale(5, 5);

}

