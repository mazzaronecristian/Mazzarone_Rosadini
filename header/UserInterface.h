//
// Created by Gianluca Rosadini on 03/08/21.
//

#ifndef MAZZARONE_ROSADINI_USERINTERFACE_H
#define MAZZARONE_ROSADINI_USERINTERFACE_H

#include "Elements.h"

class UserInterface : public Elements {
public:
    UserInterface(int width, int height);

    ~UserInterface() override = 0;

    virtual void update() = 0;
};


#endif //MAZZARONE_ROSADINI_USERINTERFACE_H
