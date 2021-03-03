//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_GLADIATOR_H
#define MAZZARONE_ROSADINI_GLADIATOR_H

#include "ActionStrategy.h"
class Gladiator: public ActionStrategy {
public:
    Gladiator();
    void specialAction() override;

};


#endif //MAZZARONE_ROSADINI_GLADIATOR_H
