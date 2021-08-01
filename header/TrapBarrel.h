//
// Created by cristian on 08/03/21.
//

#ifndef MAZZARONE_ROSADINI_TRAPBARREL_H
#define MAZZARONE_ROSADINI_TRAPBARREL_H

#include "Barrel.h"
#include "Player1.h"

class TrapBarrel : public Barrel {
public:
    TrapBarrel(int hp, const Potion &potion);

    virtual ~TrapBarrel();

    void fight(Player1 hero);
};


#endif //MAZZARONE_ROSADINI_TRAPBARREL_H
