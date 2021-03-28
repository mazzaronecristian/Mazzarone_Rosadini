//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_POTION_H
#define MAZZARONE_ROSADINI_POTION_H

#include <iostream>
#include "UseStrategy.h"
#include "Character.h"
class Potion {
public:
    Potion();

    Potion(std::string description);

    virtual ~Potion();

    //virtual void use(UseStrategy useStrategy);

    int use(int result);

    //getter
    const std::string &getDescription() const;

    void setDescription(const std::string &description);

private:
    std::string description;
};


#endif //MAZZARONE_ROSADINI_POTION_H
