//
// Created by cristian on 02/03/21.
//

#include "../header/Potion.h"

Potion::Potion() {}


Potion::~Potion() {

}

Potion::Potion(std::string description) : description(description) {}

int Potion::use(int result) {
    result += 5;
    return result;
}

const std::string &Potion::getDescription() const {
    return description;
}

void Potion::setDescription(const std::string &description) {
    Potion::description = description;
}

