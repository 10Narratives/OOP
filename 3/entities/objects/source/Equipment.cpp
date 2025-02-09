//
// Created by vanish2 on 12.12.23.
//

#include "Equipment.h"

std::string Equipment::get_placement() const {
    return this->placement_;
}

int Equipment::get_defence() const {
    return this->defence_;
}

void Equipment::be_loaded(json data) {
    Object::be_loaded(data);
    this->placement_ = data["placement"].get<std::string>();
    this->defence_ = data["defence"].get<int>();
}

json Equipment::be_saved() const {
    json save_object = Object::be_saved();
    save_object["placement"] = this->placement_;
    save_object["defence"] = this->defence_;
    return this->defence_;
}
