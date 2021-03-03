//
// Created by cristian on 02/03/21.
//

#include "Potion.h"


Potion::~Potion() {

}

void Potion::use(UseStrategy useStrategy) {

}

Potion::Potion(const UseStrategy &useStrategy) : useStrategy(useStrategy) {}
