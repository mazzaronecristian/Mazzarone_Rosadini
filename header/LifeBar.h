//
// Created by Gianluca Rosadini on 03/08/21.
//

#ifndef MAZZARONE_ROSADINI_LIFEBAR_H
#define MAZZARONE_ROSADINI_LIFEBAR_H

#include "Character.h"
#include "UserInterface.h"
#include "memory"

enum class LifeBarType {
    hero,
    cyclops
};

class LifeBar : public UserInterface {
public:
    explicit LifeBar(Character *character, int width = 251, int height = 32);

    void update() final;

private:
    Character *character;
    const int bit;

};


#endif //MAZZARONE_ROSADINI_LIFEBAR_H
