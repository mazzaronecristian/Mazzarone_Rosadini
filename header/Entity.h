//
// Created by cristian on 31/03/21.
//

#ifndef MAZZARONE_ROSADINI_ENTITY_H
#define MAZZARONE_ROSADINI_ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Animation.h"
#include <iostream>
#include <cmath>
#include "Elements.h"

class Entity : public Elements {
public:
    explicit Entity(int width = 32, int height = 32, const sf::Time &animTime = sf::milliseconds(60));

    virtual ~Entity() = 0;

    virtual void update(float deltaTime);

    //Getter & Setter
    void setAnim(int nFrame, float switchTime);

    void setAnim(int nFrame, float switchTime, int action);

    bool isLife() const;

    sf::Vector2f getPosition();

protected:
    bool life;

private:
    Animation anim;
};


#endif //MAZZARONE_ROSADINI_ENTITY_H
