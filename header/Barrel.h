//
// Created by cristian on 02/03/21.
//

#ifndef MAZZARONE_ROSADINI_BARREL_H
#define MAZZARONE_ROSADINI_BARREL_H

#include <memory>
#include "Potion.h"

class Barrel : public Entity {
public:
    explicit Barrel(PotionType type = PotionType::regular);

    void update(float deltaTime) override;

    bool kill(PotionType &type);

private:
    //FIXME
    std::shared_ptr<Potion> potion;
};


#endif //MAZZARONE_ROSADINI_BARREL_H
