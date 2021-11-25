//
// Created by Gianluca Rosadini on 20/09/21.
//

#ifndef MAZZARONE_ROSADINI_MAPFACTORY_H
#define MAZZARONE_ROSADINI_MAPFACTORY_H

#include "Map.h"

class MapFactory {
public:
    static Map createMap(short int numArena, Player1 &subject);

private:
    static std::ifstream setMatrix(short int numArena);

    static std::ifstream setShadesMatrix(short int numArena);

};


#endif //MAZZARONE_ROSADINI_MAPFACTORY_H
