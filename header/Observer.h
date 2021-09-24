//
// Created by cristian on 24/09/21.
//

#ifndef MAZZARONE_ROSADINI_OBSERVER_H
#define MAZZARONE_ROSADINI_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;
};


#endif //MAZZARONE_ROSADINI_OBSERVER_H
