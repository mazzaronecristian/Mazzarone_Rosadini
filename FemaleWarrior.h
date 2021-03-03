//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_FEMALEWARRIOR_H
#define MAZZARONE_ROSADINI_FEMALEWARRIOR_H

#include "ActionStrategy.h"
class FemaleWarrior: public ActionStrategy {
public:
    FemaleWarrior();
    void specialAction() override;
};


#endif //MAZZARONE_ROSADINI_FEMALEWARRIOR_H
