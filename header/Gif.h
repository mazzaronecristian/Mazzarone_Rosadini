//
// Created by Gianluca Rosadini on 14/09/21.
//

#ifndef MAZZARONE_ROSADINI_GIF_H
#define MAZZARONE_ROSADINI_GIF_H

#include "Entity.h"
#include "Character.h"


class Gif : public Entity {
public:
    explicit Gif(CharacterType type, int width = 32, int height = 32);

    CharacterType getType() const;

private:
    CharacterType type;
};


#endif //MAZZARONE_ROSADINI_GIF_H
