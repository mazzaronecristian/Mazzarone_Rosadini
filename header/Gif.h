//
// Created by Gianluca Rosadini on 14/09/21.
//

#ifndef MAZZARONE_ROSADINI_GIF_H
#define MAZZARONE_ROSADINI_GIF_H

#include "Entity.h"


class Gif : public Entity {
public:
    void update(float deltaTime) override;

    Gif();

};


#endif //MAZZARONE_ROSADINI_GIF_H
