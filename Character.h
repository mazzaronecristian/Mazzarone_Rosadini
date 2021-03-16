//
// Created by cristian on 28/02/21.
//

#ifndef MAZZARONE_ROSADINI_CHARACTER_H
#define MAZZARONE_ROSADINI_CHARACTER_H


class Character {
public:
    Character(int hp, int posX, int posY, int damage);

    virtual void specialAction();

    void receiveDamage(int damage);

    //getter
    int getHp() const;

    int getPosX() const;

    int getPosY() const;

    int getDamage() const;

    //setter
    void setHp(int hp);

    void setPosX(int posX);

    void setPosY(int posY);

    void setDamage(int damage);


private:
    int hp, posX, posY, damage;

};


#endif //MAZZARONE_ROSADINI_CHARACTER_H
