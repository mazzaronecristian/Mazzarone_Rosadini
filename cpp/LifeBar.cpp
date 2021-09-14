//
// Created by Gianluca Rosadini on 03/08/21.
//

#include "../header/LifeBar.h"

LifeBar::LifeBar(Character *character, int width, int height) : UserInterface(width, height),
                                                                character(character) {
    bit = character->getHp() / 5;
}

void LifeBar::update() {
    int i = 5;
    while (character->getHp() < bit * i) {
        i--;
        if (character->getHp() <= bit * i)
            source.y = 5 - i;
    }
    if (character->getHp() <= 0)
        source.y = 5;
    sprite.setTextureRect(sf::IntRect(source.x * width, source.y * height, width, height));
}

