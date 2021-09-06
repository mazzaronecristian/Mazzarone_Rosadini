//
// Created by cristian on 23/06/21.
//

#include "../header/EntityFactory.h"

EntityFactory::EntityFactory() {}

std::string EntityFactory::setBitMap(EntityType type) {
    std::string result;

    if (type == EntityType::hero)
        result = "./tileSets/spaceCadet.png";
    if (type == EntityType::ghoul)
        result = "./tileSets/ghoul.png";
    if (type == EntityType::bullet)
        result = "./tileSets/bullet.png";

    return result;
}
