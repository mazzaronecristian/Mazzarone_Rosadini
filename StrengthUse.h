//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_STRENGTHUSE_H
#define MAZZARONE_ROSADINI_STRENGTHUSE_H

#include "UseStrategy.h"
#include "Character.h"
class StrengthUse: public UseStrategy {
public:
    int use() override;
};


#endif //MAZZARONE_ROSADINI_STRENGTHUSE_H
