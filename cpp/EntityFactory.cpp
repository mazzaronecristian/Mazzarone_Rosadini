//
// Created by cristian on 23/06/21.
//

#include "../header/EntityFactory.h"

EntityFactory::EntityFactory() {}

std::unique_ptr<Entity> EntityFactory::createEntity(EntityType type) {
    std::unique_ptr<Entity> result;
    if(type==EntityType::hero){
        result = std::unique_ptr<Entity>(new Player1(std::make_shared<RangedAttack>()));
        result->load("./tileSets/spaceCadet.png", sf::Vector2f(100, 100));
    }
    if(type==EntityType::ghoul){
        result = std::unique_ptr<Entity>(new Enemy(std::make_shared<Patrol>()));
        result->load("./tileSets/ghoul.png", sf::Vector2f(rand()%450+100, rand()%450+100));
    }

    return result;
}

std::string EntityFactory::setBitMap(EntityType type) {
    std::string result;

    if(type == EntityType::hero)
        result = "./tileSets/spaceCadet.png";
    if(type == EntityType::ghoul)
        result = "./tileSets/ghoul.png";
    if(type == EntityType::bullet)
        result = "./tileSets/bullet.png";

    return result;
}
