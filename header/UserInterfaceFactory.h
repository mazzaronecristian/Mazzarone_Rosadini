//
// Created by cristian on 06/09/21.
//

#ifndef MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
#define MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H

#include "UserInterface.h"
#include "LifeBar.h"

enum class UserInterfaceType {
    lifeBar
};

class UserInterfaceFactory {
public:
    LifeBar createLifeBar(Character *character);

private:
    std::string setBitMap(UserInterfaceType type);
};


#endif //MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
