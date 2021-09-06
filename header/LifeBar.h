//
// Created by Gianluca Rosadini on 03/08/21.
//

#ifndef MAZZARONE_ROSADINI_LIFEBAR_H
#define MAZZARONE_ROSADINI_LIFEBAR_H

#include "UserInterface.h"
#include "Character.h"
#include "memory"

class LifeBar : public UserInterface {
public:
    explicit LifeBar(Character *character, int width = 251, int height = 32);

    void update() override;

private:
    Character *character;
    int bit;

};


#endif //MAZZARONE_ROSADINI_LIFEBAR_H
