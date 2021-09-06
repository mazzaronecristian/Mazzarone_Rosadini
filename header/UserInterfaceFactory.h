//
// Created by cristian on 06/09/21.
//

#ifndef MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
#define MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H

#include "UserInterface.h"
#include "ElementFactory.h"

class UserInterfaceFactory : public ElementFactory {
public:
    LifeBar createLifeBar(Character *character);

    std::string setBitMap(ElementType type) override;

    UserInterfaceFactory();
};


#endif //MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
