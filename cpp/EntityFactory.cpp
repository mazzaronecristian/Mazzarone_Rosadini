//
// Created by cristian on 23/06/21.
//

#include "../header/EntityFactory.h"

EntityFactory::EntityFactory() {}

std::string EntityFactory::setBitMap(ElementType type) {
    std::string result;

    if (type == ElementType::hero)
        result = "./tileSets/spaceCadet.png";
    if (type == ElementType::ghoul)
        result = "./tileSets/ghoul.png";
    if (type == ElementType::bullet)
        result = "./tileSets/bullet.png";

    return result;
}
