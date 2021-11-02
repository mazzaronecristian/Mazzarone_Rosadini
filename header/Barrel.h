//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_BARREL_H
#define MAZZARONE_ROSADINI_BARREL_H

#include "Potion.h"

class Barrel : public Entity {
public:
    explicit Barrel(PotionType type, int hp = 1);

    virtual ~Barrel();

    void receiveDamage(int damage);

    void update(float deltaTime) override;

    Potion &kill();

private:
    int hp;
    Potion *potion = nullptr;
};


#endif //MAZZARONE_ROSADINI_BARREL_H
