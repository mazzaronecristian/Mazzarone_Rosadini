//
// Created by cristian on 28/02/21.
//

#include "SpaceCadet.h"
#include <ctime>
#include <cstdlib>

SpaceCadet::SpaceCadet() {

}

//Teletrasporto
void SpaceCadet::specialAction(int posX, int posY) {
    ActionStrategy::specialAction(posX, posY);
    srand(time(NULL));
    posX += rand()%10-5;
    posY += rand()%10-5;

}
