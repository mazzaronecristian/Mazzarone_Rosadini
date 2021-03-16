//
// Created by Gianluca Rosadini on 16/03/21.
//

#include "SpaceCadet.h"

SpaceCadet::SpaceCadet() {

}

void SpaceCadet::teleport(int posX, int posY) {
    srand(time(NULL));
    posX += rand()%10-5;
    posY += rand()%10-5;

}

void SpaceCadet::fight(Character &enemy) {
    Player1::fight(enemy);
    Bullet shot(this->getPosX(), this->getPosY());
    while(shot.getPosX() != enemy.getPosX() || shot.getPosY() != enemy.getPosY()) {
        shot.setPosX(shot.getPosX() + 1);

    }
    enemy.setHp(enemy.getHp() - this->getDamage());

}
