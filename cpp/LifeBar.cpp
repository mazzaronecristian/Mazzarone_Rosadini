//
// Created by Gianluca Rosadini on 03/08/21.
//

#include "../header/LifeBar.h"

LifeBar::LifeBar(Character *character, int width, int height) : UserInterface(width, height), character(character) {
    bit = character->getHp() / 5;
}

void LifeBar::update() {
    if (character->getHp() < 120) {
        float offset = (float) character->getHp() / (float) bit;
        int x = static_cast<int>(offset) + 1;
        source.y = 5 - x;
    } else source.y = 0;
    if (character->getHp() <= 0)
        source.y = 5;
    sprite.setTextureRect(sf::IntRect(source.x * width, source.y * height, width, height));
}