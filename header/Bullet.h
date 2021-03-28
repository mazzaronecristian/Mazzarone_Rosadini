//
// Created by Gianluca Rosadini on 16/03/21.
//

#ifndef MAZZARONE_ROSADINI_BULLET_H
#define MAZZARONE_ROSADINI_BULLET_H


class Bullet {
public:
    Bullet(int posX, int posY);

    virtual ~Bullet();

    //getter
    int getPosX() const;

    int getPosY() const;

    //setter
    void setPosX(int posX);

    void setPosY(int posY);


private:
    int posX, posY;

};


#endif //MAZZARONE_ROSADINI_BULLET_H
