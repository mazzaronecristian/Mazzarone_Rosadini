//
// Created by cristian on 06/09/21.
//

#include "../header/UserInterfaceFactory.h"

LifeBar UserInterfaceFactory::createLifeBar(Character *character) {
    LifeBar lifeBar(character);
    lifeBar.load(setBitMap(UserInterfaceType::lifeBar), sf::Vector2f(10, 680));
    return lifeBar;
}

std::string UserInterfaceFactory::setBitMap(UserInterfaceType type) {
    std::string result;
    if (type == UserInterfaceType::lifeBar)
        result = "./tileSets/userInterface/lifeBar.png";
    return result;
}

Gif UserInterfaceFactory::createGif(CharacterType type, sf::Vector2f position) {
    Gif gif;
    gif.load(setBitMap(UserInterfaceType::gif, type), position);
    return gif;
}

std::string UserInterfaceFactory::setBitMap(UserInterfaceType type, CharacterType kind) {
    std::string result;
    if (type == UserInterfaceType::gif) {
        if (kind == CharacterType::spaceCadet)
            result = "./tileSets/userInterface/gifs/spaceCadet.png";
        if (kind == CharacterType::gladiator)
            result = "./tileSets/userInterface/gifs/gladiator.png";
        if (kind == CharacterType::adventurer)
            result = "./tileSets/userInterface/gifs/adventurer.png";
        if (kind == CharacterType::dwarf)
            result = "./tileSets/userInterface/gifs/dwarf.png";
    }
    return result;
}
