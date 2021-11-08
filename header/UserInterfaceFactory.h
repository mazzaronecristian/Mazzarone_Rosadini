//
// Created by cristian on 06/09/21.
//

#ifndef MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
#define MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H

#include "UserInterface.h"
#include "LifeBar.h"
#include "Gif.h"
#include "Character.h"

enum class UserInterfaceType {
    lifeBar, gif
};

class UserInterfaceFactory {
public:
    LifeBar createLifeBar(Character *character, sf::Vector2f position);

    Gif createGif(CharacterType type, sf::Vector2f position);

private:
    std::string setBitMap(UserInterfaceType type);

    std::string setBitMap(UserInterfaceType type, CharacterType kind);
};


#endif //MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
