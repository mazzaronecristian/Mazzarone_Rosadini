//
// Created by cristian on 06/09/21.
//

#ifndef MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
#define MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H

#include "UserInterface.h"
#include "LifeBar.h"
#include "Gif.h"
#include "Character.h"

class UserInterfaceFactory {
public:
    static LifeBar createLifeBar(Character *character, sf::Vector2f position, LifeBarType type);

    static Gif createGif(CharacterType type, sf::Vector2f position);

private:
    static std::string setBitMap(LifeBarType type);

    static std::string setBitMap(CharacterType type);
};


#endif //MAZZARONE_ROSADINI_USERINTERFACEFACTORY_H
