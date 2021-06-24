//
// Created by cristian on 24/06/21.
//

#include "../header/CharacterFactory.h"

CharacterFactory::CharacterFactory() {}

sf::Vector2f CharacterFactory::setPosition(EntityType type) {
    std::srand(time(NULL));
    sf::Vector2f position = {0,0};
    if(type == EntityType::hero)
        position = sf::Vector2f(100,100);
    if(type == EntityType::ghoul)
        position = sf::Vector2f(rand()%450+100, rand()%450+100);
    return position;


}

//std::shared_ptr<Character> CharacterFactory::createCharacter(EntityType type) {
//    std::shared_ptr<Character> result;
//    std::srand(std::time(nullptr));
//    sf::Vector2f position;
//    if(type==EntityType::hero){
//        result = std::shared_ptr<Character>(new Player1(std::make_shared<RangedAttack>()));
//        position = {100,100};
//    }
//    if(type==EntityType::ghoul){
//        result = std::shared_ptr<Character>(new Enemy(std::make_shared<Patrol>()));
//        position = sf::Vector2f(rand()%450+100, rand()%450+100);
//    }
//    result->load(setBitMap(type), position);
//    result->
//    return result;
//}
