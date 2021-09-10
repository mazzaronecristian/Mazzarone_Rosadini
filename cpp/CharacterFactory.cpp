//
// Created by cristian on 24/06/21.
//

#include "../header/CharacterFactory.h"

CharacterFactory::CharacterFactory() {}

std::string CharacterFactory::setBitMap(CharacterType type) {
    std::string result;
    if (type == CharacterType::spaceCadet)
        result = "./tileSets/spaceCadet.png";
    if (type == CharacterType::ghoul)
        result = "./tileSets/ghoul.png";
    if (type == CharacterType::adventurer)
        result = "./tileSets/adventurer.png";
    if (type == CharacterType::brain)
        result = "./tileSets/brain.png";

    return result;
}