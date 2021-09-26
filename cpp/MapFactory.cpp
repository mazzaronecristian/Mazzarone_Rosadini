//
// Created by Gianluca Rosadini on 20/09/21.
//

#include <iostream>
#include "../header/MapFactory.h"

Map MapFactory::createMap(short int numArena) {
    Map result;
    std::ifstream matrix = setMatrix(numArena);
    std::ifstream shades = setShadesMatrix(numArena);
    result.load("./tileSets/map/background.png", "./tileSets/map/map.png", sf::Vector2u(32, 32), matrix, shades);
    return result;
}

std::ifstream MapFactory::setMatrix(short int numArena) {
    std::string path("./matrix");
    path.append(std::to_string(numArena)).append(".txt");
    std::ifstream matrix(path);
    return matrix;
}

std::ifstream MapFactory::setShadesMatrix(short numArena) {
    std::string path("./shades");
    path.append(std::to_string(numArena)).append(".txt");
    std::ifstream shades(path);
    return shades;
}
