//
// Created by Gianluca Rosadini on 16/03/21.
//

#ifndef MAZZARONE_ROSADINI_BULLET_H
#define MAZZARONE_ROSADINI_BULLET_H

#include "Entity.h"

class Bullet: public Entity{
public:
    explicit Bullet(bool bulletDirection, float speed = 0.9);

    void movement();

    virtual ~Bullet();

private:
    float speed;
    const bool bulletDirection;
};


#endif //MAZZARONE_ROSADINI_BULLET_H
