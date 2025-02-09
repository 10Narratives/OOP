//
// Created by vanish2 on 06.12.23.
//

#ifndef LAB3_DRINKABLE_H
#define LAB3_DRINKABLE_H

#include "Creature.h"

class Drinkable {
public:
    /**
     * @brief Result of drinking
     * @return Primary object which contains information about result of drinking
     */
    virtual Primary be_drunk() = 0;
};

#endif //LAB3_DRINKABLE_H
