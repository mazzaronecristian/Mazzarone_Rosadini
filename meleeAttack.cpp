//
// Created by cristian on 08/03/21.
//

#include "meleeAttack.h"
#include <math.h>

void meleeAttack::attack(Character &enemy, Character &hero){
        if(sqrt((enemy.getPosX()+hero.getPosX())^2+(enemy.getPosY()+hero.getPosY())^2)==1)
            enemy.setHp(enemy.getHp()-hero.getDamage());
}
