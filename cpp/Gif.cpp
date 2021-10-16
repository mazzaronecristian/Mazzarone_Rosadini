//
// Created by Gianluca Rosadini on 14/09/21.
//

#include "../header/Gif.h"


Gif::Gif(CharacterType type, int width, int height) : type(type), Entity(sf::Vector2i(width, height)) {
    setAnim(16, 0.06);
    sprite.setScale(5, 5);
}

CharacterType Gif::getType() const {
    return type;
}
