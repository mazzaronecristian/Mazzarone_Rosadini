//
// Created by Gianluca Rosadini on 16/03/21.
//

#ifndef MAZZARONE_ROSADINI_BULLET_H
#define MAZZARONE_ROSADINI_BULLET_H

#include <list>
#include "Entity.h"
#include "Map.h"

class Bullet : public Entity {
public:
    explicit Bullet(short int bulletDirection, float speed = 15);

    bool isCollide(const Entity *entity);

    bool isLegalMove(Map arena);

    void movement(const Map &arena);

    void update(float deltaTime) override;

    virtual ~Bullet();

private:
    float speed;
    const short int bulletDirection;
};


#endif //MAZZARONE_ROSADINI_BULLET_H
