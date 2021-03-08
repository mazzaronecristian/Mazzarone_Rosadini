//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_BARREL_H
#define MAZZARONE_ROSADINI_BARREL_H

#include "Potion.h"
class Barrel {
public:
    Barrel(int hp, const Potion &potion);

    virtual ~Barrel();

    void receiveDamage(int damage);
private:
    int hp;
    Potion* potion;
};


#endif //MAZZARONE_ROSADINI_BARREL_H
