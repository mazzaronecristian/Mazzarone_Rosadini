//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_POTION_H
#define MAZZARONE_ROSADINI_POTION_H

#include "UseStrategy.h"
class Potion {
public:
    Potion(const UseStrategy &useStrategy);

    virtual ~Potion();

    virtual void use(UseStrategy useStrategy);
private:
    UseStrategy useStrategy;
};


#endif //MAZZARONE_ROSADINI_POTION_H
