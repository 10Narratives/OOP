//
// Created by vanish2 on 12.12.23.
//

#include "Weapon.h"

int Weapon::get_damage() const {
    return this->damage_;
}

void Weapon::be_loaded(json data) {
    Object::be_loaded(data);
    this->damage_ = data["damage"].get<int>();
}


