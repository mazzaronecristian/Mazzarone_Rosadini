//
// Created by cristian on 28/02/21.
//

#include "MoveStrategy.h"


void MoveStrategy::move(Character *hero, int *enemyX, int *enemyY) {
    int heroX, heroY;
    heroX = hero->getPosX();
    heroY = hero->getPosY();
    while(*enemyY != heroY){
        if(heroY > *enemyY)
            *enemyY++;
        else
            *enemyY--;
    }
    while(*enemyX != heroX){
        if(heroX > *enemyX)
            *enemyX++;
        else
            *enemyX--;
    }
}
