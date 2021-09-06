//
// Created by cristian on 06/09/21.
//

#ifndef MAZZARONE_ROSADINI_ELEMENTFACTORY_H
#define MAZZARONE_ROSADINI_ELEMENTFACTORY_H

#include "memory"
#include "LifeBar.h"

enum class ElementType {
    hero, ghoul, bullet, lifeBar
};

class ElementFactory {
protected:
    virtual std::string setBitMap(ElementType type) = 0;
};


#endif //MAZZARONE_ROSADINI_ELEMENTFACTORY_H
