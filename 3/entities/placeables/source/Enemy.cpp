//
// Created by vanish2 on 11.12.23.
//

#include "Enemy.h"

void Enemy::be_moved(std::pair<int, int> new_coords) {
    this->coords = new_coords;
}

int Enemy::deal_damage() {
    return this->get_secondary().bonus_damage * 5;
}

int Enemy::resist() {
    return this->get_secondary().bonus_damage;
}

Enemy::Enemy(const Enemy &other)  : Creature(other) {
    this->primary = other.primary;
    this->secondary = other.secondary;
    this->influence = other.influence;
    this->coords = other.coords;
    this->exp = other.exp;
}
