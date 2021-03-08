//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_HEALUSE_H
#define MAZZARONE_ROSADINI_HEALUSE_H

#include "UseStrategy.h"
#include "Character.h"
#include "Player1.h"
class HealUse: public UseStrategy {
public:
    void use(Player1 hero) override;
};


#endif //MAZZARONE_ROSADINI_HEALUSE_H
