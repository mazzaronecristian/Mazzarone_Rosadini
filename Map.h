//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_MAP_H
#define MAZZARONE_ROSADINI_MAP_H

#include "Tile.h"
class Map {
public:
    Map(int width, int height, const Tile &tiles);

private:
    int width, height;
    Tile tiles;
};


#endif //MAZZARONE_ROSADINI_MAP_H
