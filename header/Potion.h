//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_POTION_H
#define MAZZARONE_ROSADINI_POTION_H

#include <iostream>
#include "Entity.h"

enum class PotionType {
    regular = 30, super = 50, max = 120
};

class Potion : public Entity {
public:
    explicit Potion(PotionType type = PotionType::regular);

    virtual ~Potion();

    int use(int result);

    //getter
    PotionType getType() const;

private:
    PotionType type;
};


#endif //MAZZARONE_ROSADINI_POTION_H
