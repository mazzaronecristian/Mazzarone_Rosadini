//
// Created by Gianluca Rosadini on 16/03/21.
//

#ifndef MAZZARONE_ROSADINI_SPACECADET_H
#define MAZZARONE_ROSADINI_SPACECADET_H

#include "Player1.h"
#include "Bullet.h"

class SpaceCadet: public Player1 {
public:
    SpaceCadet();
    void fight(Character &enemy) override;
    void teleport(int posX, int posY);

};


#endif //MAZZARONE_ROSADINI_SPACECADET_H
