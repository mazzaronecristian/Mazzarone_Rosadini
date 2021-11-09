//
// Created by cristian on 06/09/21.
//

#include "../header/UserInterfaceFactory.h"

LifeBar UserInterfaceFactory::createLifeBar(Character *character, sf::Vector2f position, LifeBarType type) {
    auto *lifeBar = new LifeBar(character);
    lifeBar->load(setBitMap(type), position);
    return *lifeBar;
}

std::string UserInterfaceFactory::setBitMap(LifeBarType type) {
    std::string result;
    if (type == LifeBarType::hero)
        result = "./tileSets/userInterface/lifeBarHero.png";
    if (type == LifeBarType::cyclops)
        result = "./tileSets/userInterface/lifeBarCyclops.png";
    return result;
}

Gif UserInterfaceFactory::createGif(CharacterType type, sf::Vector2f position) {
    Gif gif(type);
    gif.load(setBitMap(type), position);
    return gif;
}

std::string UserInterfaceFactory::setBitMap(CharacterType type) {
    std::string result;
    if (type == CharacterType::spaceCadet)
        result = "./tileSets/userInterface/gifs/spaceCadet.png";
    if (type == CharacterType::gladiator)
        result = "./tileSets/userInterface/gifs/gladiator.png";
    if (type == CharacterType::adventurer)
        result = "./tileSets/userInterface/gifs/adventurer.png";
    if (type == CharacterType::dwarf)
        result = "./tileSets/userInterface/gifs/dwarf.png";
    return result;
}
