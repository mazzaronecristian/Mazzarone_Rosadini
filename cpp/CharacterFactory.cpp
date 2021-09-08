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
    return result;
}