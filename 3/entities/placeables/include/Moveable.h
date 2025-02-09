//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_MOVEABLE_H
#define LAB3_MOVEABLE_H

#include <utility>

class Moveable {
public:
    virtual void be_moved(std::pair<int, int> new_coords) = 0;
};

#endif //LAB3_MOVEABLE_H
