//
// Created by cristian on 24/06/21.
//

#include "../header/CharacterFactory.h"

CharacterFactory::CharacterFactory() = default;

std::string CharacterFactory::setBitMap(CharacterType type) {
    std::string result;
    //heroes
    if (type == CharacterType::spaceCadet)
        result = "./tileSets/characters/spaceCadet.png";
    if (type == CharacterType::adventurer)
        result = "./tileSets/characters/adventurer.png";
    if (type == CharacterType::dwarf)
        result = "./tileSets/characters/dwarf.png";
    if (type == CharacterType::gladiator)
        result = "./tileSets/characters/gladiator.png";

    //enemies
    if (type == CharacterType::ghoul)
        result = "./tileSets/characters/ghoul.png";
    if (type == CharacterType::brain)
        result = "./tileSets/characters/brain.png";
    if (type == CharacterType::cobra)
        result = "./tileSets/characters/cobra.png";
    if (type == CharacterType::miniGolem)
        result = "./tileSets/characters/miniGolem.png";

    //boss
    if (type == CharacterType::cyclops)
        result = "./tileSets/characters/cyclops.png";

    return result;
}