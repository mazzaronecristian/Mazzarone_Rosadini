//
// Created by Gianluca Rosadini on 14/09/21.
//

#ifndef MAZZARONE_ROSADINI_GIF_H
#define MAZZARONE_ROSADINI_GIF_H

#include "Entity.h"
#include "Character.h"


class Gif : public Entity {
public:
    Gif(CharacterType type);

    CharacterType getType() const;

private:
    CharacterType type;
};


#endif //MAZZARONE_ROSADINI_GIF_H
