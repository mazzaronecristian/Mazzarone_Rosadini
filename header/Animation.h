//
// Created by cristian on 02/05/21.
//

#ifndef MAZZARONE_ROSADINI_ANIMATION_H
#define MAZZARONE_ROSADINI_ANIMATION_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Animation {
public:
    explicit Animation(int nFrame = 3, float switchTime = 0.3);
    void update(sf::Vector2i &source, float deltaTime);
    void applyToSprite(sf::Sprite &sprite);

    //setter
    void setNFrame(int nFrame);

    void setSwitchTime(float switchTime);

    void setAnimTime(float animTime);

private:
    int nFrame;
    float animTime = 0.0f;
    float switchTime;
    sf::IntRect rect = sf::IntRect(0,0,32,32);
};


#endif //MAZZARONE_ROSADINI_ANIMATION_H
