//
// Created by cristian on 02/03/21.
//

#include "Potion.h"
Potion::Potion() {}


Potion::~Potion() {

}

void Potion::use(UseStrategy useStrategy) {

}

Potion::Potion(const UseStrategy &useStrategy) : useStrategy(useStrategy) {}

void Potion::setUseStrategy(const UseStrategy &useStrategy) {
    Potion::useStrategy = useStrategy;
}

const UseStrategy &Potion::getUseStrategy() const {
    return useStrategy;
}

