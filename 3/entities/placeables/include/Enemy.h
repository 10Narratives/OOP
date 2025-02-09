//
// Created by vanish2 on 11.12.23.
//

#ifndef LAB3_ENEMY_H
#define LAB3_ENEMY_H


#include "Creature.h"
#include "Moveable.h"

class Enemy : public Creature, public Moveable {

public:
    Enemy() = default;
    Enemy(const Enemy& other);

    ~Enemy() override = default;

    int deal_damage() override;

    int resist() override;

    void be_moved(std::pair<int, int> new_coords) override;
};


#endif //LAB3_ENEMY_H
