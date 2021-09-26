//
// Created by Gianluca Rosadini on 20/09/21.
//

#include "../header/MapFactory.h"

Map MapFactory::createMap(short int numArena) {
    Map result;
    std::ifstream matrix = setMatrix(numArena);
    std::ifstream matrix1("matrix3.txt");
    result.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix, matrix1);
    return result;
}

std::ifstream MapFactory::setMatrix(short int numArena) {
    std::ifstream matrix;
    if (numArena == 1)
        matrix.open("./matrix2.txt");
    if (numArena == 2)
        matrix.open("./matrix2.txt");
    return matrix;
}
