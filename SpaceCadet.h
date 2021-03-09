//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_SPACECADET_H
#define MAZZARONE_ROSADINI_SPACECADET_H

#include "ActionStrategy.h"
class SpaceCadet : public ActionStrategy{
public:
    SpaceCadet();
    void specialAction(int posX, int posY) override;



};


#endif //MAZZARONE_ROSADINI_SPACECADET_H
