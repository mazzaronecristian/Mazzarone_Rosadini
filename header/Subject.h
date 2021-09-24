//
// Created by cristian on 24/09/21.
//

#ifndef MAZZARONE_ROSADINI_SUBJECT_H
#define MAZZARONE_ROSADINI_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify() = 0;
};


#endif //MAZZARONE_ROSADINI_SUBJECT_H
